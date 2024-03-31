#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_inverse, inverse_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 3);
  double array1[9] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix_act_res = Matrix1.InverseMatrix();

  MatrixNamespace::S21Matrix Matrix_exp_res(3, 3);
  double array2[9] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  Matrix_exp_res.fill_matrix(array2);

  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_NEAR(Matrix_exp_res.GetElement(i, j),
                  Matrix_act_res.GetElement(i, j), 1e-7);
    }
  }
}

TEST(matrix_tests_inverse, inverse_2) {
  MatrixNamespace::S21Matrix Matrix1(3, 3);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix1.fill_matrix(array1);

  try {
    Matrix1.InverseMatrix();
  } catch (const char *x) {
    EXPECT_STREQ("Matrix determinant is 0", x);
  }
}

TEST(matrix_tests_inverse, inverse_3) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  try {
    Matrix1.InverseMatrix();
  } catch (const char *x) {
    EXPECT_STREQ("The matrix is not square", x);
  }
}