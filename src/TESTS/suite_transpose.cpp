#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_transpose, transpose_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  MatrixNamespace::S21Matrix Matrix_act_res = Matrix1.Transpose();

  MatrixNamespace::S21Matrix Matrix_exp_res(4, 3);
  double array2[12] = {1, 5, 9, 2, 6, 10, 3, 7, 11, 4, 8, 12};
  Matrix_exp_res.fill_matrix(array2);

  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}
