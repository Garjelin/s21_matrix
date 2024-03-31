#include "s21_matrix_oop.h"

namespace MatrixNamespace {

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw "The matrix is not square";
  S21Matrix Matrix_res(rows_, cols_);
  if (rows_ == 1)
    Matrix_res.matrix_[0][0] = 1.0;
  else {
    for (int row = 0; row < rows_ && rows_ > 1; row++) {
      for (int col = 0; col < cols_; col++) {
        S21Matrix Matrix_minor(rows_ - 1, cols_ - 1);
        MatrixMinor(row, col, Matrix_minor);
        double determinant = Matrix_minor.Determinant();
        Matrix_res.matrix_[row][col] = determinant * powl(-1.0, row + col);
      }
    }
  }
  return Matrix_res;
}

void S21Matrix::MatrixMinor(int delet_row, int delet_col, S21Matrix& minor) {
  for (int row = 0, min_row = 0; row < rows_; row++) {
    if (row != delet_row) {
      for (int col = 0, min_col = 0; col < cols_; col++)
        if (col != delet_col) {
          minor.matrix_[min_row][min_col] = matrix_[row][col];
          min_col++;
        }
      min_row++;
    }
  }
}
}  // namespace MatrixNamespace