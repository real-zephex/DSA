// Array Multiplication

#include <iostream>

int main()
{
  // Matrix dimensions
  int rows1, cols1, rows2, cols2;

  std::cout << "Enter the number of rows and columns for the first matrix\n";
  std::cout << "Rows: ";
  std::cin >> rows1;
  std::cout << "Columns: ";
  std::cin >> cols1;

  std::cout << "Enter the number of rows and columns for the second matrix\n";
  std::cout << "Rows: ";
  std::cin >> rows2;
  std::cout << "Columns: ";
  std::cin >> cols2;

  if (cols1 != rows2)
  {
    std::cout << "Matrix multiplication is not possible with these dimensions." << "\n";
    return 1;
  }

  int matrix1[rows1][cols1] = {};
  int matrix2[rows2][cols2] = {};
  int result[rows1][cols2] = {};

  std::cout << "Enter the elements for the first matrix\n";
  for (int i = 0; i < rows1; i++)
  {
    for (int j = 0; j < cols1; j++)
    {
      std::cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
      std::cin >> matrix1[i][j];
    }
  }

  std::cout << "Enter the elements for the second matrix\n";
  for (int i = 0; i < rows2; i++)
  {
    for (int j = 0; j < cols2; j++)
    {
      std::cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
      std::cin >> matrix2[i][j];
    }
  }

  // Matrix Multiplication Logic
  for (int i = 0; i < rows1; i++)
  {
    for (int j = 0; j < cols2; j++)
    {
      for (int k = 0; k < cols1; k++)
      {
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }

  for (int i = 0; i < rows1; i++)
  {
    for (int j = 0; j < cols2; j++)
    {
      std::cout << result[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}