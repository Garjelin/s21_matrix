#include "s21_matrix_oop.h"

namespace MatrixNamespace {

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

}  // namespace MatrixNamespace