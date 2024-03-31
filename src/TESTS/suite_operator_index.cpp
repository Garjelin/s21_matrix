#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_operator_index, operator_index_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  Matrix1(1, 2) = 99;

  MatrixNamespace::S21Matrix Matrix_exp_res(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 99, 8, 9, 10, 11, 12};
  Matrix_exp_res.fill_matrix(array2);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_index, operator_index_2) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  EXPECT_NO_THROW(Matrix1(1, 2) = 99);
}

TEST(matrix_tests_operator_index, operator_index_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  try {
    Matrix1(5, 3) = 99;
  } catch (const char *x) {
    EXPECT_STREQ("Element is out of range in row", x);
  }
}

TEST(matrix_tests_operator_index, operator_index_4) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  try {
    Matrix1(2, 5) = 99;
  } catch (const char *x) {
    EXPECT_STREQ("Element is out of range in column", x);
  }
}
