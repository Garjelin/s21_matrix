# s21_matrix
> [!NOTE]
> C++ language
## Implementation of the s21_matrix_oop.h library
### An example of a matrix class in C++
```
class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void SumMatrix(const S21Matrix& other); 
        // Other methods..
}
```
### Matrix operations
|	Operation	|	Description	|	Exceptional situations	|
|------------|------------|------------|
|	bool EqMatrix(const S21Matrix& other)	|	Checks matrices for equality with each other.	|		|
|	void SumMatrix(const S21Matrix& other)	|	Adds the second matrix to the current one	|	different matrix dimensions.	|
|	void SubMatrix(const S21Matrix& other)	|	Subtracts another matrix from the current one	|	different matrix dimensions.	|
|	void MulNumber(const double num)	|	Multiplies the current matrix by a number.	|		|
|	void MulMatrix(const S21Matrix& other)	|	Multiplies the current matrix by the second matrix.	|	The number of columns of the first matrix is not equal to the number of rows of the second matrix.	|
|	S21Matrix Transpose()	|	Creates a new transposed matrix from the current one and returns it.	|		|
|	S21Matrix CalcComplements()	|	Calculates the algebraic addition matrix of the current one and returns it.	|	The matrix is not square.	|
|	double Determinant()	|	Calculates and returns the determinant of the current matrix.	|	The matrix is not square.	|
|	S21Matrix InverseMatrix()	|	Calculates and returns the inverse matrix.	|	Matrix determinant is 0.	|
						
|	Method	|	Description	|	
|------------|------------|
|	S21Matrix()	|	A basic constructor that initialises a matrix of some predefined dimension.	|	
|	S21Matrix(int rows, int cols)	|	Parametrized constructor with number of rows and columns.	|	
|	S21Matrix(const S21Matrix& other)	|	Copy constructor.	|	
|	S21Matrix(S21Matrix&& other)	|	Move constructor.	|	
|	~S21Matrix()	|	Destructor.	|	
						
|	Operator	|	Description	|	Exceptional situations	|
|------------|------------|------------|
|	+	|	Addition of two matrices.	|	Different matrix dimensions.	|
|	-	|	Subtraction of one matrix from another.	|	Different matrix dimensions.	|
|	*	|	Matrix multiplication and matrix multiplication by a number.	|	The number of columns of the first matrix does not equal the number of rows of the second matrix.	|
|	==	|	Checks for matrices equality (EqMatrix).	|		|
|	=	|	Assignment of values from one matrix to another one.	|		|
|	+=	|	Addition assignment (SumMatrix)	|	different matrix dimensions.	|
|	-=	|	Difference assignment (SubMatrix)	|	different matrix dimensions.	|
|	*=	|	Multiplication assignment (MulMatrix/MulNumber).	|	The number of columns of the first matrix does not equal the number of rows of the second matrix.	|
|	(int i, int j)	|	Indexation by matrix elements (row, column).	|	Index is outside the matrix.	|

### Requirements:
* The program must be developed in C++ language of C++17 standard using gcc compiler;
* The program code must be located in the src folder;
* When writing code it is necessary to follow the Google style;
* Implement the matrix as an S21Matrix class;
* Use only the matrix_, rows_ and cols_ fields as private;
* Implement the access to private fields rows_ and cols_ via accessor and mutator. If the matrix increases in size, it is filled with zeros. If it decreases in size, the excess is simply discarded;
* Make it as a static library (with s21_matrix_oop.h header file);
* Implement the operations described above;
* Overload the operators according to the table in the chapter above;
* Prepare full coverage of library functions code with unit-tests using the GTest library;
* Provide a Makefile for building the library and tests (with targets all, clean, test, s21_matrix_oop.a).
