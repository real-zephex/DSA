// Array Addition

#include <iostream>

int main()
{
  int rows, cols;

  std::cout << "Enter rows and cols for the matrix 1: ";
  std::cin >> rows >> cols;

  int matrix_1[rows][cols];
  int matrix_2[rows][cols];

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cout << "Enter the " << i << " - " << j << " element: ";
      std::cin >> matrix_1[i][j];
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cout << "Enter the " << i << " - " << j << " element: ";
      std::cin >> matrix_2[i][j];
    }
  }

  int result[rows][cols];
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      result[i][j] = matrix_1[i][j] + matrix_2[i][j];
    }
  }

  std::cout << "Resultant matrix:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }
}