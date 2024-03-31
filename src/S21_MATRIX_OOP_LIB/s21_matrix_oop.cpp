#include "s21_matrix_oop.h"

#include <iomanip>
#include <iostream>

namespace MatrixNamespace {
S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double *[rows_];
  if (matrix_ == nullptr) throw "Memory allocation failed";
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_[i] == nullptr) throw "Memory allocation failed";
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 1) throw "Invalid number of rows";
  if (cols < 1) throw "Invalid number of columns";
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];
  if (matrix_ == nullptr) throw "Memory allocation failed";
  for (int i = 0; i < rows; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_[i] == nullptr) throw "Memory allocation failed";
  }
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.GetRows();
  cols_ = other.GetCols();
  matrix_ = new double *[rows_];
  if (matrix_ == nullptr) throw "Memory allocation failed";
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_[i] == nullptr) throw "Memory allocation failed";
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; ++i) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

double S21Matrix::GetElement(int i, int j) const {
  if (i > rows_ - 1) throw "Element is out of range in row";
  if (j > cols_ - 1) throw "Element is out of range in column";
  return matrix_[i][j];
}

void S21Matrix::SetRows(int rows) { ResizeMatrix(rows, cols_); }

void S21Matrix::SetElement(double value, int i, int j) {
  if (i > rows_ - 1) throw "Element is out of range in row";
  if (j > cols_ - 1) throw "Element is out of range in column";
  matrix_[i][j] = value;
}

void S21Matrix::SetCols(int cols) { ResizeMatrix(rows_, cols); }

void S21Matrix::ResizeMatrix(int rows, int cols) {
  if (rows < 1) throw "Invalid number of rows";
  if (cols < 1) throw "Invalid number of columns";

  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;

  rows_ = rows;
  cols_ = cols;
  matrix_ = new double *[rows_];
  if (matrix_ == nullptr) throw "Memory allocation failed";
  for (int i = 0; i < rows; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_[i] == nullptr) throw "Memory allocation failed";
  }
}

void S21Matrix::fill_matrix(double const array[]) {
  int k = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = array[k];
      k++;
    }
  }
}

// void S21Matrix::print_matrix() {
//   for (int i = 0; i < rows_; i++) {
//     std::cout << "|";
//     for (int j = 0; j < cols_; j++) {
//       std::cout << std::setw(8) << matrix_[i][j] << "|";
//     }
//     std::cout << std::endl;
//   }
// }
}  // namespace MatrixNamespace