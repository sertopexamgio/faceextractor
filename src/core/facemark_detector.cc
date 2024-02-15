/*-************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the FacemarkDetector.
 *
 **************************************************************************************************************/

#include "facemark_detector.h"

FacemarkDetector::FacemarkDetector(std::string model)
{
	facemark_ = cv::face::FacemarkLBF::create();
	facemark_->loadModel(model);
}

void FacemarkDetector::detect(cv::Mat img, std::vector<std::shared_ptr<Face>> faces)
{
	if (faces.empty())
	{
		return;
	}

	std::vector<cv::Rect> roi;
	for (auto const &f : faces)
	{
		roi.push_back(*f);
	}

	std::vector<std::vector<cv::Point2f>> contours;
	facemark_->fit(img, roi, contours);

	for (size_t i = 0; i < faces.size(); ++i)
	{
		faces[i]->setLandmark(Landmark(contours[i]));
	}
}