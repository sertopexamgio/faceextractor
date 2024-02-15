/*-******************************************************************************************************
 *
 *	\brief  Helper functions.
 *
 ********************************************************************************************************/

#include "helper.h"

#include <boost/algorithm/string/predicate.hpp>

void parseArguments(int argc, char **argv, settings &s)
{
  // parse given arguments
  for (size_t i = 1; i < argc; ++i)
  {
    std::string argument = argv[i];

    if (boost::starts_with(argument, "--caffe_config="))
    {
      s.caffe_config = argument.substr(strlen("--caffe_config="));
    }
    else if (boost::starts_with(argument, "--caffe_weights="))
    {
      s.caffe_weights = argument.substr(strlen("--caffe_weights="));
    }
    else if (boost::starts_with(argument, "--land="))
    {
      s.landmark_model = argument.substr(strlen("--land="));
    }
    else if (boost::starts_with(argument, "--dir="))
    {
      s.folder = argument.substr(strlen("--dir="));
    }
  }
}

std::vector<cv::Mat> read(std::string folder, std::vector<std::string> patterns)
{
  std::vector<cv::String> filenames;
  std::vector<cv::Mat> images;

  for (auto const pattern : patterns)
  {
    cv::glob(folder + pattern, filenames);

    for (auto const &filename : filenames)
    {
      images.push_back(cv::imread(filename));
    }
  }

  std::cout << images.size() << " images have been read." << std::endl;

  return images;
}

Streamer::Streamer(std::string folder)
{
  if (!folder.empty())
  {
    std::cout << "Reading images..." << std::endl;
    frames_ = read(folder);
    return;
  }

  cam_ = cv::VideoCapture(0);
}

cv::Mat Streamer::fetch(void)
{
  cv::Mat frame;

  if (!frames_.empty())
  { // a directory of images has been given
    frame = frames_.back();
    frames_.pop_back();
  }
  else
  { // camera mode
    cam_.read(frame);
  }

  return frame;
}