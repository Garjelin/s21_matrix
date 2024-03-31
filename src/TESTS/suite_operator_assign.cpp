#include <gtest/gtest.h>

#include "../S21_MATRIX_OOP_LIB/s21_matrix_oop.h"

TEST(matrix_tests_operator_assign, operator_assign_1) {
  MatrixNamespace::S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);

  MatrixNamespace::S21Matrix Matrix2(3, 4);
  Matrix2 = Matrix1;

  EXPECT_EQ(Matrix1.GetRows(), Matrix2.GetRows());
  EXPECT_EQ(Matrix1.GetCols(), Matrix2.GetCols());
  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix1.GetElement(i, j), Matrix2.GetElement(i, j));
    }
  }
}