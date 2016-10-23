#ifndef CVDRAWER_H
#define CVDRAWER_H

#include <gtkmm.h>
#include <opencv2/opencv.hpp>

class CvDrawer : public Gtk::DrawingArea{
public:

	enum DRAW_MODE{
		SCALE,
		CENTER,
		CENTER_FIT,
	};

	CvDrawer();

	void setCvMat(const cv::Mat& mat);

	// Widget interface
protected:
	bool on_draw(const::Cairo::RefPtr<Cairo::Context> &cr) override;

	cv::Mat mat;
	DRAW_MODE drawMode;
};

#endif // CVDRAWER_H
