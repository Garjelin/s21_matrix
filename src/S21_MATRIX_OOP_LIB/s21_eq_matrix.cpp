#include "s21_matrix_oop.h"

namespace MatrixNamespace {

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.GetRows()) return false;
  if (cols_ != other.GetCols()) return false;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (round(matrix_[i][j] * pow(10, 7)) !=
          round(other.matrix_[i][j] * pow(10, 7))) {
        return false;
      }
    }
  }
  return true;
}

}  // namespace MatrixNamespace