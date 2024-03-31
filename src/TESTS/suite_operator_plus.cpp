#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_operator_plus, operator_plus_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  MatrixNamespace::S21Matrix Matrix_act_res = Matrix1 + Matrix2;

  MatrixNamespace::S21Matrix Matrix_exp_res(3, 4);
  double array3[12] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_plus, operator_plus_2) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 + Matrix2);
}

TEST(matrix_tests_operator_plus, operator_plus_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  try {
    MatrixNamespace::S21Matrix Matrix_act_res = Matrix1 + Matrix2;
  } catch (const char *x) {
    EXPECT_STREQ("Different matrix dimensions", x);
  }
}

TEST(matrix_tests_operator_plus, operator_plus_4) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix2(3, 3);
  double array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix2.fill_matrix(array2);

  try {
    MatrixNamespace::S21Matrix Matrix_act_res = Matrix1 + Matrix2;
  } catch (const char *x) {
    EXPECT_STREQ("Different matrix dimensions", x);
  }
}
