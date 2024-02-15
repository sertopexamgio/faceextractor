/// \file facemark_detector.h

/*!************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the FacemarkDetector.
 *
 *	\class		FacemarkDetector
 *
 **************************************************************************************************************/

#ifndef FACEMARKDETECTOR_H_
#define FACEMARKDETECTOR_H_

#include <opencv2/face.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

#include "landmark.h"
#include "face.h"

class FacemarkDetector
{

public:
  /*!************************************************************************************************************
   *
   *	\brief	Constructor method of FacemarkDetector.
   *
   **************************************************************************************************************/
  FacemarkDetector(std::string model);

  /*!************************************************************************************************************
   *
   *	\brief	Destructor method of FacemarkDetector.
   *
   **************************************************************************************************************/
  virtual ~FacemarkDetector(void){};

  void detect(cv::Mat img, std::vector<std::shared_ptr<Face>> faces);

private:
  cv::Ptr<cv::face::FacemarkLBF> facemark_;
};

#endif /* FACEMARKDETECTOR_H_ */