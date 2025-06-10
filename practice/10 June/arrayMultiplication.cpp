// Array Multiplication

#include <iostream>
#include <vector>

int main()
{
  int rows_1, cols_1;
  int rows_2, cols_2;

  std::cout << "Enter number of rows for matrix 1: ";
  std::cin >> rows_1;

  std::cout << "Enter number of cols for matrix 1: ";
  std::cin >> cols_1;

  std::cout << "Enter number of rows for matrix 2: ";
  std::cin >> rows_2;

  std::cout << "Enter number of cols for matrix 2: ";
  std::cin >> cols_2;

  if (cols_1 != rows_2)
  {
    std::cout << "Columns of matrix 1 and rows of matrix 2 should be equal";
    return 0;
  }

  int matrix_one[rows_1][cols_1];
  int matrix_two[rows_2][cols_2];

  for (int i = 0; i < rows_1; i++)
  {
    for (int j = 0; j < cols_1; j++)
    {
      std::cout << "Enter the " << i << " - " << j << " element: ";
      std::cin >> matrix_one[i][j];
    }
  }

  for (int i = 0; i < rows_2; i++)
  {
    for (int j = 0; j < cols_2; j++)
    {
      std::cout << "Enter the " << i << " - " << j << " element: ";
      std::cin >> matrix_two[i][j];
    }
  }

  std::cout << "Matrix 1:" << std::endl;
  for (int i = 0; i < rows_1; i++)
  {
    for (int j = 0; j < cols_1; j++)
    {
      std::cout << matrix_one[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "Matrix 2:" << std::endl;
  for (int i = 0; i < rows_2; i++)
  {
    for (int j = 0; j < cols_2; j++)
    {
      std::cout << matrix_two[i][j] << " ";
    }
    std::cout << std::endl;
  }

  int result[rows_1][cols_2];

  for (int i = 0; i < rows_1; i++)
  {
    for (int j = 0; j < cols_2; j++)
    {
      result[i][j] = 0;
      for (int k = 0; k < cols_1; k++)
      {
        result[i][j] += matrix_one[i][k] + matrix_two[k][j];
      }
    }
  }

  std::cout << "Resultant Matrix:" << std::endl;
  for (int i = 0; i < rows_1; i++)
  {
    for (int j = 0; j < cols_2; j++)
    {
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}