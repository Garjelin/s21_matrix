#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_create, create_1) {
  EXPECT_NO_THROW(MatrixNamespace::S21Matrix Matrix(3, 4));
}

TEST(matrix_tests_create, create_2) {
  EXPECT_NO_THROW(MatrixNamespace::S21Matrix Matrix);
}

TEST(matrix_tests_create, create_3) {
  try {
    MatrixNamespace::S21Matrix Matrix(0, 4);
  } catch (const char *x) {
    EXPECT_STREQ("Invalid number of rows", x);
  }
}

TEST(matrix_tests_create, create_4) {
  try {
    MatrixNamespace::S21Matrix Matrix(3, 0);
  } catch (const char *x) {
    EXPECT_STREQ("Invalid number of columns", x);
  }
}

TEST(matrix_tests_create, create_5) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);

  MatrixNamespace::S21Matrix Matrix2(Matrix1);

  EXPECT_EQ(Matrix1.GetRows(), Matrix2.GetRows());
  EXPECT_EQ(Matrix1.GetCols(), Matrix2.GetCols());
  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix1.GetElement(i, j), Matrix2.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_create, create_6) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);
  try {
    Matrix1.GetElement(3, 1);
  } catch (const char *x) {
    EXPECT_STREQ("Element is out of range in row", x);
  }
}

TEST(matrix_tests_create, create_7) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);
  try {
    Matrix1.GetElement(2, 4);
  } catch (const char *x) {
    EXPECT_STREQ("Element is out of range in column", x);
  }
}

TEST(matrix_tests_create, create_8) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);

  int rows = Matrix1.GetRows();
  int cols = Matrix1.GetCols();
  double array2[rows][cols] = {0};
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      array2[i][j] = Matrix1.GetElement(i, j);
    }
  }
  MatrixNamespace::S21Matrix Matrix2(std::move(Matrix1));

  EXPECT_EQ(rows, Matrix2.GetRows());
  EXPECT_EQ(cols, Matrix2.GetCols());
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      EXPECT_EQ(array2[i][j], Matrix2.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_resize, resize_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);
  EXPECT_NO_THROW(Matrix1.ResizeMatrix(2, 2));
}

TEST(matrix_tests_resize, resize_2) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);

  try {
    Matrix1.ResizeMatrix(0, 2);
  } catch (const char *x) {
    EXPECT_STREQ("Invalid number of rows", x);
  }
}

TEST(matrix_tests_resize, resize_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);

  try {
    Matrix1.ResizeMatrix(2, 0);
  } catch (const char *x) {
    EXPECT_STREQ("Invalid number of columns", x);
  }
}

TEST(matrix_tests_mutator, set_rows_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  Matrix1.SetRows(5);
  EXPECT_EQ(5, Matrix1.GetRows());
}

TEST(matrix_tests_mutator, set_cols_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  Matrix1.SetCols(5);
  EXPECT_EQ(5, Matrix1.GetCols());
}