/// \file helper.h

/*!************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the Helper.
 *
 *	\class		Helper
 *
 **************************************************************************************************************/

#ifndef HELPER_H_
#define HELPER_H_

#include <opencv2/opencv.hpp>

struct settings
{
  std::string folder = "";
  std::string landmark_model = "lbfmodel.yaml";
  std::string caffe_config = "deploy.prototxt";
  std::string caffe_weights = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
  std::string haar_model = "haarcascade_frontalface_alt2.xml";
};

void parseArguments(int argc, char **argv, settings &s);

std::vector<cv::Mat> read(std::string folder, std::vector<std::string> patterns = {"/*.png", "/*.jpg", "/*.bmp"});

class Streamer
{
public:
  /*!************************************************************************************************************
   *
   *	\brief	Constructor method of Streamer.
   *
   **************************************************************************************************************/
  Streamer(std::string folder = "");

  /*!************************************************************************************************************
   *
   *	\brief	Destructor method of FacemarkDetector.
   *
   **************************************************************************************************************/
  virtual ~Streamer(void){};

  cv::Mat fetch(void);

private:
  cv::VideoCapture cam_;
  std::vector<cv::Mat> frames_;
};

#endif /* HELPER_H_ */