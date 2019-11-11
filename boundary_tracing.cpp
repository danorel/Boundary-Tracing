//
// Created by Dan Orel on 2019-11-07.
//
#include "boundary_tracing.h"

int directionBegin = 7;
int directionNext = (directionBegin + 6) % 8;

void
    BoundaryTracing (
        const cv::Mat &Img,
        cv::Mat &ImgTrace,
        int startX,
        int startY,
        std::vector<cv::Point> &trace) {
    cv::Point direction;
    if ((startX >= 0) && (startY >= 0) && (startX < Img.rows) && (startY < Img.cols)) {
        if (directionNext == 3) {
            if (((startX - 1 >= 0) && (startY - 1 >= 0)) && (Img.data[(startX - 1) * Img.cols + (startY - 1)] == 255)) {
                direction.x = startX - 1;
                direction.y = startY - 1;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 3;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 3;
                directionNext = 4;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 2) {
            if ((startX - 1 >= 0) && (Img.data[(startX - 1) * Img.cols + startY] == 255)) {
                direction.x = startX - 1;
                direction.y = startY;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 2;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 2;
                directionNext = 3;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 1) {
            if (((startX - 1 >= 0) && (startY + 1 < Img.cols)) && (Img.data[(startX - 1) * Img.cols + (startY + 1)] == 255)) {
                direction.x = startX - 1;
                direction.y = startY + 1;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 1;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 1;
                directionNext = 2;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 4) {
            if ((startY - 1 >= 0) && (Img.data[startX * Img.cols + (startY - 1)] == 255)) {
                direction.x = startX;
                direction.y = startY - 1;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 4;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 4;
                directionNext = 5;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 0) {
            if ((startY + 1 < Img.cols) && (Img.data[startX * Img.cols + (startY + 1)] == 255)) {
                direction.x = startX;
                direction.y = startY + 1;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 0;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 0;
                directionNext = 1;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 5) {
            if (((startX + 1 < Img.rows) && (startY - 1 >= 0)) && (Img.data[(startX + 1) * Img.cols + (startY - 1)] == 255)) {
                direction.x = startX + 1;
                direction.y = startY - 1;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 5;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else

                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 5;
                directionNext = 6;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 6) {
            if ((startX + 1 < Img.rows) && (Img.data[(startX + 1) * Img.cols + startY] == 255)) {
                direction.x = startX + 1;
                direction.y = startY;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 6;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 6;
                directionNext = 7;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        } else if (directionNext == 7) {
            if (((startX + 1 < Img.rows) && (startY + 1 < Img.cols)) && (Img.data[(startX + 1) * Img.cols + (startY + 1)] == 255)) {
                direction.x = startX + 1;
                direction.y = startY + 1;
                trace.push_back(direction);
                ImgTrace.data[direction.x * Img.cols + direction.y] = 255;
                directionBegin = 7;
                if(directionBegin % 2 == 0)
                    directionNext = (directionBegin + 7) % 8;
                else
                    directionNext = (directionBegin + 6) % 8;
            } else {
                directionBegin = 7;
                directionNext = 0;
                BoundaryTracing(
                        Img,
                        ImgTrace,
                        startX,
                        startY,
                        trace);
            }
        }
    }
}

cv::Point
    FindClosest(
        const cv::Mat &Img) {
    const uchar WHITE = 255;
    cv::Point closest = cv::Point();
    for (int i = (Img.rows * Img.cols) - 1; i >= 0; i--) {
        if (Img.data[i] == WHITE) {
            closest.x = i / Img.cols;
            closest.y = i % Img.cols;
            break;
        }
    }
    return closest;
}
