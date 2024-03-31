#include "s21_matrix_oop.h"

namespace MatrixNamespace {

double& S21Matrix::operator()(int i, int j) {
  if (i > rows_ - 1) throw "Element is out of range in row";
  if (j > cols_ - 1) throw "Element is out of range in column";
  return matrix_[i][j];
}

}  // namespace MatrixNamespace