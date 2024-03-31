#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_operator_equal, operator_equal_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, true);
  EXPECT_EQ(Matrix2 == Matrix1, true);
}

TEST(matrix_tests_operator_equal, operator_equal_2) {
  MatrixNamespace::S21Matrix Matrix1(2, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, false);
  EXPECT_EQ(Matrix2 == Matrix1, false);
}

TEST(matrix_tests_operator_equal, operator_equal_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 3);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, false);
  EXPECT_EQ(Matrix2 == Matrix1, false);
}

TEST(matrix_tests_operator_equal, operator_equal_4) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, false);
  EXPECT_EQ(Matrix2 == Matrix1, false);
}