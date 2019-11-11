//
// Created by Dan Orel on 2019-11-07.
//
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#ifndef BOUNDARYTRACING_BOUNDARY_TRACING_H
#define BOUNDARYTRACING_BOUNDARY_TRACING_H
void
    BoundaryTracing (
        const cv::Mat &Img,
        cv::Mat &ImgTrace,
        int startX,
        int startY,
        std::vector<cv::Point> &trace);

cv::Point
    FindClosest(
        const cv::Mat &Img);
#endif //BOUNDARYTRACING_BOUNDARY_TRACING_H
