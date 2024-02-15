#include "face.h"

void Face::setConfidence(float c)
{
	confidence_ = c;
}

void Face::setLandmark(Landmark l)
{
	landmark_ = l;
}

void Face::draw(cv::Mat img)
{
	landmark_.draw(img);
	cv::rectangle(img, *this, cv::Scalar(255));

	// display confidence
	std::string text = std::to_string(confidence_);
	text.resize(5);
	cv::putText(img, text, this->tl(), cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cv::Scalar(0, 0, 255));
}