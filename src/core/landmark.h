/// \file landmark.h

/*!************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the Landmark.
 *
 *	\class		Landmark
 *
 **************************************************************************************************************/

#ifndef LANDMARK_H_
#define LANDMARK_H_

#include <opencv2/face.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

class Landmark
{
public:
  /*!************************************************************************************************************
   *
   *	\brief	Constructor method of FacemarkDetector.
   *
   **************************************************************************************************************/
  Landmark(std::vector<cv::Point2f> contour) : contour_(contour){};

  Landmark(void){};

  /*!************************************************************************************************************
   *
   *	\brief	Destructor method of FacemarkDetector.
   *
   **************************************************************************************************************/
  virtual ~Landmark(void){};

  void draw(cv::Mat img);

private:
  std::vector<cv::Point2f> contour_;
};

#endif /* LANDMARK_H_ */