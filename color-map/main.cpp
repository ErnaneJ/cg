#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>

/**
 * @brief Creates a color map with N entries, mapping M RGB colors to gray tones.
 *
 * @param M The number of RGB colors.
 * @param N The number of entries in the color map.
 * @return A 2D vector representing the color map.
 */
std::vector<std::vector<int>> createColorMap(int M, int N)
{
  std::vector<std::vector<int>> colorMap(N, std::vector<int>(3));
  int step = M / N;
  int grayTone;

  for (int i = 0; i < N; ++i)
  {
    grayTone = i * step;
    colorMap[i][0] = grayTone;
    colorMap[i][1] = grayTone;
    colorMap[i][2] = grayTone;
  }

  return colorMap;
}

/**
 * @brief Main function.
 */
int main()
{
  int M = 256;
  int N = 100;

  std::vector<std::vector<int>> colorMap = createColorMap(M, N);

  std::cout << std::endl
            << "Color-map result:" << std::endl
            << std::endl;
  for (int i = 0; i < N; ++i)
  {
    std::cout << "Entry " << i << ": (" << colorMap[i][0] << ", " << colorMap[i][1] << ", " << colorMap[i][2] << ");" << std::endl;
  }

  std::cout << std::endl;

  cv::Mat image(100, 100, CV_8UC3);
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < N; ++j)
    {
      image.at<cv::Vec3b>(i, j)[0] = colorMap[j][0];
      image.at<cv::Vec3b>(i, j)[1] = colorMap[j][1];
      image.at<cv::Vec3b>(i, j)[2] = colorMap[j][2];
    }
  }

  cv::imwrite("../images/color-map.png", image);
  cv::waitKey(0);

  return 0;
}
