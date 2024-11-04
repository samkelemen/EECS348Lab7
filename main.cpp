
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  void readFromStdin() {
    // Iterate over the rows of the txt file
    for (int i = 0; i < SIZE; i++) {
      // Iterate over the columns of the txt file
      for (int j = 0; j < SIZE; j++) {
        // Read a value from stdin and store it in the matrix
        std::cin >> data[i][j];
      }
    }
  }

  // 2. Display a matrix
  void display() const {
    // Iterate over the rows of the matrix
    for (int i = 0; i < SIZE; i++) {
      // Iterate of the columns of the matrix
      for (int j = 0; j < SIZE; j++) { 
        // Print the given element of the matrix
        std::cout << data[i][j] << " ";
      }
      // Print a new line after each row
      std::cout << std::endl;
    }
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    Matrix result;
    // Iterate over the rows of the matrix
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        // Add each element of the matrix with the other same element of the other matrix
        result.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return result;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
    Matrix result;

    // Iterate over the rows of the matrix
    for (int i = 0; i < SIZE; i++) {
      // Iterate over the columns of the matrix
      for (int j = 0; j < SIZE; j++) {
        // Initialize the sum of the product of the elements of each row/column
        int sum = 0;
        // Iterate over the elements of each row/column
        for (int k = 0; k < SIZE; k++) {
          // Multiply the elements of each row/column and add it to the sum
          sum += data[i][k] * other.data[k][j];
        }
        // Store the sum in the result matrix
        result.data[i][j] = sum;
      }
    }
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const {
    // Initialze the sum of the diagonal elements to zero
    int sum = 0;
    // Iterate over the diagonal elements of the matrix
    for (int i = 0; i < SIZE; i++) {
      // Add the diagonal elements to the sum
      sum += data[i][i];
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    // Check if the row indices are valid
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
      // Swap the rows of the matrix
      for (int i = 0; i < SIZE; i++) {
        // Swap the elements of the rows
        int temp = data[row1][i];
        data[row1][i] = data[row2][i];
        data[row2][i] = temp;  
      }
    }
  }
};

int main() {
  // The description of the user input was unclear, but the code should be straight forward to interact with
  Matrix mat1;
  cout << "Enter values for Matrix 1 (" << SIZE << " by " << SIZE << ") seperated by spaces:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2 (" << SIZE << " by " << SIZE << ") seperated by spaces:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
