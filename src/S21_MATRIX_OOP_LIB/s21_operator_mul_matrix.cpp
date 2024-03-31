#include "s21_matrix_oop.h"

namespace MatrixNamespace {

void S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); }

}  // namespace MatrixNamespace