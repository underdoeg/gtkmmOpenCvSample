#ifndef WINDOW_H
#define WINDOW_H

#include "CvDrawer.h"
#include "gtkmm.h"
#include <opencv2/opencv.hpp>
#include <thread>
#include <atomic>
#include <mutex>

class Window: public Gtk::Window{
public:
    Window();
	~Window();

	cv::VideoCapture cam;
	cv::Mat camMatThread;
	cv::Mat camMat;
	CvDrawer camDrawer;
	std::thread camThread;
	std::mutex camMutex;
	std::atomic_bool camClose;

	Glib::Dispatcher signalCamFrame;

};

#endif // WINDOW_H
