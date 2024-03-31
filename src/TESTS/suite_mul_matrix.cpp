#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_mul_matrix, mul_matrix_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(4, 3);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  Matrix1.MulMatrix(Matrix2);

  MatrixNamespace::S21Matrix Matrix3(3, 3);
  double array3[12] = {70, 80, 90, 158, 184, 210, 246, 288, 330};
  Matrix3.fill_matrix(array3);
  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix3.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_mul_matrix, mul_matrix_2) {
  MatrixNamespace::S21Matrix Matrix1(3, 2);
  double array1[12] = {1, 4, 2, 5, 3, 6};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(2, 3);
  double array2[12] = {1, -1, 1, 2, 3, 4};
  Matrix2.fill_matrix(array2);

  Matrix1.MulMatrix(Matrix2);

  MatrixNamespace::S21Matrix Matrix3(3, 3);
  double array3[12] = {9, 11, 17, 12, 13, 22, 15, 15, 27};
  Matrix3.fill_matrix(array3);
  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix3.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_mul_matrix, mul_matrix_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(4, 3);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1.MulMatrix(Matrix2));
}

TEST(matrix_tests_mul_matrix, mul_matrix_4) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  try {
    Matrix1.MulMatrix(Matrix2);
  } catch (const char *x) {
    EXPECT_STREQ("A.rows are not equal B.cols", x);
  }
}