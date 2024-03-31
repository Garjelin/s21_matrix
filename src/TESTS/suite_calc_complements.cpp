#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_calc_compements, calc_compements_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 3);
  double array1[9] = {1, 2, 3, 0, 4, 2, 5, 2, 1};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix_act_res = Matrix1.CalcComplements();

  MatrixNamespace::S21Matrix Matrix_exp_res(3, 3);
  double array2[9] = {0, 10, -20, 4, -14, 8, -8, -2, 4};
  Matrix_exp_res.fill_matrix(array2);

  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_calc_compements, calc_compements_2) {
  MatrixNamespace::S21Matrix Matrix1(1, 1);
  double array1[1] = {1};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix_act_res = Matrix1.CalcComplements();

  MatrixNamespace::S21Matrix Matrix_exp_res(1, 1);
  double array2[1] = {1};
  Matrix_exp_res.fill_matrix(array2);

  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_calc_compements, calc_compements_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  try {
    Matrix1.CalcComplements();
  } catch (const char *x) {
    EXPECT_STREQ("The matrix is not square", x);
  }
}