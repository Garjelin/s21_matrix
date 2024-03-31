#ifndef MATRIX_H_
#define MATRIX_H_

#include <math.h>
#include <stdio.h>

namespace MatrixNamespace {
class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  int GetRows() const;
  int GetCols() const;
  double GetElement(int i, int j) const;
  void SetRows(int rows);
  void SetCols(int cols);
  void ResizeMatrix(int rows, int cols);
  void SetElement(double value, int i, int j);

  void fill_matrix(double const array[]);
  void print_matrix();

  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  void MatrixMinor(int delet_row, int delet_col, S21Matrix &minor);
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  bool operator==(const S21Matrix &other);
  void operator=(const S21Matrix &other);
  void operator+=(const S21Matrix &other);
  void operator-=(const S21Matrix &other);
  void operator*=(const S21Matrix &other);
  double &operator()(int i, int j);
};
}  // namespace MatrixNamespace

#endif
