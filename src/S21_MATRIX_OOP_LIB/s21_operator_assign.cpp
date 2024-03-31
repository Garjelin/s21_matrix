#include "s21_matrix_oop.h"

namespace MatrixNamespace {

void S21Matrix::operator=(const S21Matrix &other) {
  ResizeMatrix(other.GetRows(), other.GetCols());
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      SetElement(other.GetElement(i, j), i, j);
    }
  }
}

}  // namespace MatrixNamespace