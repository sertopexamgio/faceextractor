/*-************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the FaceDetector.
 *
 **************************************************************************************************************/

#include "face_detector.h"

FaceDetector::FaceDetector(std::string config, std::string weights)
{
  model_ = cv::dnn::readNetFromCaffe(config, weights);
}

std::vector<std::shared_ptr<Face>> FaceDetector::faces(void) { return faces_; }

void FaceDetector::detect(cv::Mat img)
{
  faces_.clear();

  cv::Mat input_blob = cv::dnn::blobFromImage(img, 1, cv::Size(300, 300), cv::Scalar(104, 177, 123), false, false);
  model_.setInput(input_blob, "data");
  cv::Mat detection = model_.forward("detection_out");
  cv::Mat result(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

  for (size_t i = 0; i < result.rows; ++i)
  {

    float confidence = result.at<float>(i, 2);
    if (confidence < 0.4)
    { // too low confidence
      continue;
    }

    cv::Point tl(result.at<float>(i, 3) * img.cols, result.at<float>(i, 4) * img.rows);
    cv::Point br(result.at<float>(i, 5) * img.cols, result.at<float>(i, 6) * img.rows);

    if (br.x > img.cols || br.y > img.rows)
    { // detected ROI exceeds the image
      continue;
    }

    auto new_face = std::make_shared<Face>(cv::Rect(tl, br));
    new_face->setConfidence(confidence);

    faces_.push_back(new_face);
  }
}

void FaceDetector::draw(cv::Mat img, int delay)
{
  for (auto f : faces_)
  {
    f->draw(img);
  }

  cv::imshow("Facial Landmark Detection", img);
  cv::waitKey(delay);
}