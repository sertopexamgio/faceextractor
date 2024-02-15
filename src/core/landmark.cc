/*-************************************************************************************************************
 *
 *	\brief  A class to store the characteristics of the Landmark.
 *
 **************************************************************************************************************/

#include "landmark.h"

using namespace cv;

// Left jaw line 	  	  0   -   7
// Chin 				        8
// Right jaw line 		  9   -   16
// Left eyebrow 	  	  17  -   21
// Right eyebrow 	  	  22  -   26
// Bridge of nose 		  27  -   30
// Bottom of nose 	    31  -   35
// Left eye 			      36  -   41
// Right eye 		    	  42  -   47
// Outer edge of lips	  48  -   59
// Inner edge of lips	  60  -   67
uint start_id[] = {0, 17, 22, 27, 30, 36, 42, 48, 60};
uint end_id[] = {16, 21, 26, 29, 35, 41, 47, 59, 67};
bool closed[] = {false, false, false, false, true, true, true, true, true};
Scalar colors[] = {
    Scalar(19, 199, 109), Scalar(79, 76, 240), Scalar(230, 159, 23),
    Scalar(168, 100, 168), Scalar(158, 163, 32), Scalar(163, 38, 32),
    Scalar(180, 42, 220), Scalar(255, 200, 0), Scalar(255, 130, 100)};

void Landmark::draw(Mat img)
{
  if (contour_.size() != 68)
  {
    return;
  }

  for (size_t i = 0; i < 9; ++i)
  {
    std::vector<Point> points;
    for (size_t j = start_id[i]; j <= end_id[i]; ++j)
    {
      points.push_back(contour_[j]);
    }

    if (closed[i])
    {
      const Point *ppt[1] = {&points[0]};
      int n_segments = points.size();
      fillPoly(img, ppt, &n_segments, 1, colors[i]);
    }
    else
    {
      polylines(img, points, false, colors[i], 2, 16);
    }
  }
}