#include "Window.h"

Window::Window(){
	cam.open(0);

	set_default_size(1920, 1080);

	cam.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);

	add(camDrawer);

	show_all();

	//listen for camera in thread
	camThread = std::thread([&]{
		cv::Mat m;
		camClose = false;
		while(cam.isOpened() && !camClose){
			if(cam.read(m)){
				camMutex.lock();
				camMatThread = m.clone();
				camMutex.unlock();
				signalCamFrame.emit();
			}
		}
	});

	//copy camera mat in thread
	signalCamFrame.connect([&]{
		camMutex.lock();
		camMat = camMatThread.clone();
		camMutex.unlock();

		camDrawer.setCvMat(camMat);
	});
}

Window::~Window(){
	camClose = true;
	if(camThread.joinable())
		camThread.join();
	cam.release();
}
