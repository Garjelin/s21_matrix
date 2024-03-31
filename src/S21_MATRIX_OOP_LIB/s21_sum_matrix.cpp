#include "s21_matrix_oop.h"

namespace MatrixNamespace {

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.GetRows()) throw "Different matrix dimensions";
  if (cols_ != other.GetCols()) throw "Different matrix dimensions";
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

}  // namespace MatrixNamespace