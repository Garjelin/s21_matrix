#include "s21_matrix_oop.h"

namespace MatrixNamespace {

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) throw "The matrix is not square";
  double determinant = Determinant();
  if (fabsl(determinant) <= 1.0E-7) throw "Matrix determinant is 0";
  S21Matrix complements = CalcComplements();
  S21Matrix Matrix_res = complements.Transpose();
  Matrix_res.MulNumber(1.0 / determinant);
  return Matrix_res;
}
}  // namespace MatrixNamespace
