#include <iostream>
#include <opencv2/opencv.hpp>

/**
 * @brief Default image data with values equal to 1 converted to 255.
 */
unsigned char defaultImageData[12][12] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 255, 255, 255, 255, 0, 0, 0, 0},
    {0, 0, 0, 255, 255, 255, 255, 255, 255, 0, 0, 0},
    {0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0},
    {0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0},
    {0, 0, 255, 255, 255, 255, 255, 255, 255, 255, 0, 0},
    {0, 0, 0, 255, 255, 255, 255, 255, 255, 255, 0, 0},
    {0, 0, 0, 0, 255, 255, 255, 255, 255, 0, 0, 0},
    {0, 0, 0, 0, 0, 255, 255, 255, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

/**
 * @brief Prints the matrix representation of the image.
 *
 * @param image The image matrix.
 * @param N Size of the image matrix.
 */
void printImageMatrix(cv::Mat image, int N = 12)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int pixel_value = static_cast<int>(image.at<uchar>(i, j));
      std::cout << pixel_value << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Generates a circular image with given size.
 *
 * @param N Size of the image.
 * @return Generated image matrix.
 */
cv::Mat generateImage(int N)
{
  cv::Mat image(N, N, CV_8UC1, cv::Scalar(0));

  int center_x = N / 2;
  int center_y = N / 2;
  int radius = N / 4;

  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int distance = (i - center_x) * (i - center_x) + (j - center_y) * (j - center_y);
      if (distance <= radius * radius)
      {
        image.at<uchar>(i, j) = 255;
      }
    }
  }

  return image;
}

int main()
{
  const int N = 12;
  // cv::Mat image = generateImage(N);
  cv::Mat image(N, N, CV_8UC1, defaultImageData);

  std::cout << "image" << std::endl;
  printImageMatrix(image, N);
  cv::imwrite("../images/image.png", image);

  int scale = 1;
  int delta = 0;
  cv::Mat grad;
  cv::Mat grad_x, grad_y;
  cv::Mat abs_grad_x, abs_grad_y;

  cv::Sobel(image, grad_x, CV_16S, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT);
  cv::imwrite("../images/grad_x.png", grad_x);
  std::cout << "grad_x" << std::endl;
  printImageMatrix(grad_x, N);

  cv::Sobel(image, grad_y, CV_16S, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT);
  cv::imwrite("../images/grad_y.png", grad_y);
  std::cout << "grad_y" << std::endl;
  printImageMatrix(grad_y, N);

  cv::convertScaleAbs(grad_x, abs_grad_x);
  cv::imwrite("../images/abs_grad_x.png", abs_grad_x);
  std::cout << "abs_grad_x" << std::endl;
  printImageMatrix(abs_grad_x, N);

  cv::convertScaleAbs(grad_y, abs_grad_y);
  cv::imwrite("../images/abs_grad_y.png", abs_grad_y);
  std::cout << "abs_grad_y" << std::endl;
  printImageMatrix(abs_grad_y, N);

  cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);
  cv::imwrite("../images/grad.png", grad);
  std::cout << "grad" << std::endl;
  printImageMatrix(grad, N);

  return 0;
}
