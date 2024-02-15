/// \file face_detector.h

/*!************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the FaceDetector.
 *
 *	\class		FaceDetector
 *
 **************************************************************************************************************/

#ifndef FACEDETECTOR_H_
#define FACEDETECTOR_H_

#include <vector>
#include <opencv2/face.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/objdetect.hpp>

#include "face.h"

class FaceDetector
{
public:
	/*!************************************************************************************************************
	*
	*	\brief	Constructor method of FaceDetector.
	*
	*	\param[in]	model	A pretrained facedetector model.
	*
   **************************************************************************************************************/
	FaceDetector(void){};

	FaceDetector(std::string config, std::string weights);

	/*!************************************************************************************************************
	*
	*	\brief	Destructor method of FaceDetector.
	*
	**************************************************************************************************************/
	virtual ~FaceDetector(void){};

	void detect(cv::Mat img);

	std::vector<std::shared_ptr<Face>> faces(void);

	void draw(cv::Mat img, int delay = 1);

private:
	cv::dnn::Net model_;
	std::vector<std::shared_ptr<Face>> faces_;
};

#endif /* FACEDETECTOR_H_ */