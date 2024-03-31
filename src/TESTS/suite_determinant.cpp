#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_determinant, determinant_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 3);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix1.fill_matrix(array1);

  double det = Matrix1.Determinant();
  EXPECT_EQ(0, det);
}

TEST(matrix_tests_determinant, determinant_2) {
  MatrixNamespace::S21Matrix Matrix1(4, 4);
  double array1[16] = {4, 5, 6, 7, 1, 2, 3, 5, 9, 7, 5, 2, 9, 6, 5, 1};
  Matrix1.fill_matrix(array1);

  double det = Matrix1.Determinant();
  EXPECT_NEAR(-28, det, 1e-7);
}

TEST(matrix_tests_determinant, determinant_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 3);
  double array1[12] = {0, 2, 3, 0, 5, 6, 0, 8, 9};
  Matrix1.fill_matrix(array1);

  double det = Matrix1.Determinant();
  EXPECT_EQ(0, det);
}

TEST(matrix_tests_determinant, determinant_4) {
  MatrixNamespace::S21Matrix Matrix1(4, 4);
  double array1[16] = {4, 5, 6, 7, 1, 2, 3, 5, 9, 7, 5, 2, 9, 6, 5, 1};
  Matrix1.fill_matrix(array1);

  EXPECT_NO_THROW(Matrix1.Determinant());
}

TEST(matrix_tests_determinant, determinant_5) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  try {
    Matrix1.Determinant();
  } catch (const char *x) {
    EXPECT_STREQ("The matrix is not square", x);
  }
}
