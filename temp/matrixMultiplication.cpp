#include <iostream>
#include <vector>

int main()
{
  std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> b = {{11, 21, 31}, {41, 51, 61}, {71, 81, 91}};
  std::vector<std::vector<int>> c(3, std::vector<int>(3, 0));

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      std::cout << c[i][j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  return 0;
}