#include "s21_matrix_oop.h"

namespace MatrixNamespace {

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ != other.GetCols()) throw "A.rows are not equal B.cols";
  S21Matrix Matrix_copy(*this);

  int rows = rows_;
  int cols = other.GetCols();
  ResizeMatrix(rows, cols);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0;
      for (int k = 0; k < other.GetRows(); k++) {
        matrix_[i][j] += Matrix_copy.GetElement(i, k) * other.GetElement(k, j);
      }
    }
  }
}

}  // namespace MatrixNamespace
