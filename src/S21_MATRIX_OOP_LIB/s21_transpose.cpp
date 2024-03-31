#include "s21_matrix_oop.h"

namespace MatrixNamespace {

S21Matrix S21Matrix::Transpose() {
  S21Matrix Matrix_res(GetCols(), GetRows());
  for (int i = 0; i < GetCols(); i++) {
    for (int j = 0; j < GetRows(); j++) {
      Matrix_res.matrix_[i][j] = matrix_[j][i];
    }
  }
  return Matrix_res;
}

}  // namespace MatrixNamespace
