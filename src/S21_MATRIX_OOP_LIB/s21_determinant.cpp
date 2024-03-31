#include "s21_matrix_oop.h"

namespace MatrixNamespace {

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw "The matrix is not square";
  S21Matrix Matrix_copy(*this);
  int sign = 1;
  double result = 1.0;
  //метод гауса определитель
  for (int rows = 0; rows < Matrix_copy.rows_ - 1 && result; rows++) {
    int i_triangle = 0, zero_column = 1;
    double *no_zero_pointer = NULL;
    for (i_triangle = rows, zero_column = 1; i_triangle < Matrix_copy.rows_;
         i_triangle++) {
      if (Matrix_copy
              .matrix_[i_triangle][rows]) {  //проверяем проходя вниз по столбцу
        no_zero_pointer =
            Matrix_copy
                .matrix_[i_triangle];  //адрес строки с ненулевым элементом
        zero_column = 0;
        break;
      }
    }
    //если элемент диагонали равен нулю и есть ненулевой элемент в другой строке
    //в этом столбце
    if (Matrix_copy.matrix_[rows][rows] == 0.0 && no_zero_pointer != NULL) {
      Matrix_copy.matrix_[i_triangle] =
          Matrix_copy.matrix_[rows];  //меняем строки местами
      Matrix_copy.matrix_[rows] = no_zero_pointer;
      sign = -sign;  // меняется знак оперделителя если меняем строки местами
    }

    if (zero_column) {  //если все нули в столбце, опеределитель 0
      result = 0.0;
    } else {
      for (int i = rows + 1; i < Matrix_copy.rows_;
           i++) {  //изменяем строку, где вставляем ноль
        double k =
            Matrix_copy.matrix_[i][rows] / Matrix_copy.matrix_[rows][rows];
        for (int j = rows; j < Matrix_copy.cols_; j++)
          Matrix_copy.matrix_[i][j] -= Matrix_copy.matrix_[rows][j] * k;
      }
    }
  }
  for (int i = 0; i < rows_; i++) result *= Matrix_copy.matrix_[i][i];
  result *= sign;
  return result;
}
}  // namespace MatrixNamespace

// int s21_determinant(matrix_t *A, double *result) {
//   if (validate_matrix(A) || result == NULL) return INCORRECT_MATRIX;
//   if (A->rows != A->columns) return CALC_ERROR;

//   matrix_t copy;
//   copy_matrix_func(A, &copy);
//   int sign = 1;
//   *result = 1.0;
//   //метод гауса определитель
//   for (int rows = 0; rows < copy.rows - 1 && *result; rows++) {
//     int i_triangle = 0, zero_column = 1;
//     double *no_zero_pointer = NULL;
//     for (i_triangle = rows, zero_column = 1; i_triangle < copy.rows;
//          i_triangle++) {
//       if (copy.matrix[i_triangle][rows]) {  //проверяем проходя вниз по
//       столбцу
//         no_zero_pointer =
//             copy.matrix[i_triangle];  //адрес строки с ненулевым элементом
//         zero_column = 0;
//         break;
//       }
//     }
//     //если элемент диагонали равен нулю и есть ненулевой элемент в другой
//     строке
//     //в этом столбце
//     if (copy.matrix[rows][rows] == 0.0 && no_zero_pointer != NULL) {
//       copy.matrix[i_triangle] = copy.matrix[rows];  //меняем строки местами
//       copy.matrix[rows] = no_zero_pointer;
//       sign = -sign;  // меняется знак оперделителя если меняем строки местами
//     }

//     if (zero_column) {  //если все нули в столбце, опеределитель 0
//       *result = 0.0;
//     } else {
//       for (int i = rows + 1; i < copy.rows;
//            i++) {  //изменяем строку, где вставляем ноль
//         double k = copy.matrix[i][rows] / copy.matrix[rows][rows];
//         for (int j = rows; j < copy.columns; j++)
//           copy.matrix[i][j] -= copy.matrix[rows][j] * k;
//       }
//     }
//   }
//   for (int i = 0; i < A->rows; i++) *result *= copy.matrix[i][i];
//   *result *= sign;
//   s21_remove_matrix(&copy);
//   return OK;
// }

// void copy_matrix_func(matrix_t *A, matrix_t *copy) {
//   s21_create_matrix(A->rows, A->columns, copy);
//   for (int i = 0; i < copy->rows; i++)
//     for (int j = 0; j < copy->rows; j++) copy->matrix[i][j] =
//     A->matrix[i][j];
// }