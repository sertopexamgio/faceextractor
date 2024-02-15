# facesegmentation

This repository contains a face segmentation system in C++. 

To run the code first you need to build it by going inside the build forder and doing `make`
and then going inside the bin folder and run the executable `./face-segmentation`.

In this project, the facial segmentation of newborns needs to be carried out using machine learning
methods. With the help of the segmentation, the camera-based extraction of vital parameters for
this specific patient group can be made easier and more robust. Various frameworks for Python
can be used for implementation.

1. **Face detection:​** From a given image, the Regions Of Interest (ROI) - here faces - will be
    detected. This is done to discard parts of the image that are not relevant to our main task. 
Thus, only ROIs will be further processed to extract face characteristics (e.g. eyes,
    nose and mouth). Since this subtask is very crucial for the end result, different
    approaches have been tested here (Graph Segmentation, Haar Cascades, Deep Neural
    Network).
2. **Landmark extraction:​** From an image that depicts only a face, boundaries of different
    face characteristics e.g. left/right eye, nose, mouth, and chin will be extracted, by using
    the OpenCV Facemark API.
