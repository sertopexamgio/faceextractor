/// \file face.h

/*!************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the Face.
 *
 *	\class	Face
 *
 **************************************************************************************************************/

#ifndef FACE_H_
#define FACE_H_

#include <opencv2/opencv.hpp>

#include "landmark.h"

class Face : public cv::Rect
{
public:
	/*!************************************************************************************************************
	*
	*	\brief	Constructor method of Face.
	*
	**************************************************************************************************************/
	Face(cv::Rect const &r) : cv::Rect(r) { confidence_ = -1; };

	/*!************************************************************************************************************
	*
	*	\brief	Destructor method of Face.
	*
	**************************************************************************************************************/
	virtual ~Face(void){};

	void setConfidence(float c);
	void setLandmark(Landmark l);

	void draw(cv::Mat img);

private:
	float confidence_;
	Landmark landmark_;
};

#endif /* FACE_H_ */