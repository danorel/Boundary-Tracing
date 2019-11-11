#include <iostream>
#include "boundary_tracing.h"


int main() {
    std::string pathToImage ("/Users/danorel/Workspace/World of C/C++/KMA/MMPI/BoundaryTracing/");
    std::string image ("hand.jpg");
    std::string ImgLabel ("Original Image");
    std::string ImgTracedLabel ("Boundary Traced Image");

    cv::Mat Img = imread(
            pathToImage + image,
            cv::IMREAD_GRAYSCALE);
    cv::Mat BoundaryTracedImg (
            Img.rows,
            Img.cols,
            CV_8UC1,
            cv::Scalar(0));

    // Proving the vector, which will store the fully-connected path
    std::vector<cv::Point> motion;
    // Find the closes element of the image from the right-bottom corner
    motion.push_back(FindClosest(Img));
    while (true) {
        cv::Point temp = motion.at(motion.size() - 1);
        BoundaryTracing(
                Img,
                BoundaryTracedImg,
                temp.x,
                temp.y,
                motion);
        if (
                motion.size() > 2 &&
                motion.at(0).x == motion.at(motion.size() - 2).x &&
                motion.at(0).y == motion.at(motion.size() - 2).y &&
                motion.at(1).x == motion.at(motion.size() - 1).x &&
                motion.at(1).y == motion.at(motion.size() - 1).y) {
            break;
        }
    }

    imshow(
            ImgLabel,
            Img);
    imshow(
            ImgTracedLabel,
            BoundaryTracedImg);
    cv::waitKey(0);
    return 0;
}
