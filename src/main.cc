#include "core/face_detector.h"
#include "core/facemark_detector.h"
#include "core/helper.h"

int main(int argc, char **argv)
{
	// configure the settings
	settings s;
	parseArguments(argc, argv, s);

	// initialise the needed detectors
	Streamer streamer(s.folder);
	FaceDetector face_detector(s.caffe_config, s.caffe_weights);
	FacemarkDetector facemark_detector(s.landmark_model);

	for (cv::Mat frame = streamer.fetch(); !frame.empty(); frame = streamer.fetch())
	{
		// detect faces in the given frame
		face_detector.detect(frame);

		// detect facial landmarks
		facemark_detector.detect(frame, face_detector.faces());

		// show results
		face_detector.draw(frame, s.folder.empty());
	}

	return 0;
}