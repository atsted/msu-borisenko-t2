#include "matrix.h"
#include <iostream>

void assert(double target, double value) {
  if (fabs(target - value) < 1e-6) {
    std::cout << value << " ok" << std::endl;
  } else {
    std::cout << "fail: " + std::to_string(target) + " is not equal to " + std::to_string(value) << std::endl;
  }
}

int main (int argc, char **argv) {

  Matrix m1(2, 2);
  Matrix m2 = Matrix::unit(2);
  Matrix m3 = Matrix::random(2);

  std::cout << " == Testing Sum and Mult ==" << std::endl;
  std::cout << "A:" << std::endl;
  std::cout << m1;
  std::cout << std::endl << "B:" << std::endl;
  std::cout << m2;
  std::cout << std::endl << "C:" << std::endl;
  std::cout << m3;
  std::cout << std::endl << "A + B + C:" << std::endl;
  std::cout << m1 + m2 + m3;
  std::cout << std::endl << "C * C:" << std::endl;
  std::cout << m3 * m3;
  std::cout << std::endl;

  double m[16] = {
    1, 0, 3, 7,
    0, 1, 1, 4,
    3, 1, 2, 0,
    1, 0, 1, 1
  };

  std::cout << " == Testing Det ==" << std::endl;
  assert(Matrix::det(Matrix(m, 1, 1)), 1);
  assert(Matrix::det(Matrix(m, 2, 2)), 7);
  assert(Matrix::det(Matrix(m, 3, 3)), 80);
  assert(Matrix::det(Matrix(m, 4, 4)), -2);
  std::cout << std::endl;

  std::cout << " == Testing Inverse ==" << std::endl;

  double __m[] = {
    -1, 2, -2,
    2, -1, 5,
    3, -2, 4
  };

  Matrix A(__m, 3, 3);
  Matrix B = A.inverse();

  std::cout << "matrix (A):" << std::endl << A << std::endl;
  std::cout << "inverse matrix (B):" << std::endl << B << std::endl;
  std::cout << "production (A * B):" << std::endl << A * B << std::endl;
  std::cout << "production (B * A):" << std::endl << B * A << std::endl;


  double _m[] = {
    1, 1, 1, 1,
    2, 2, 2, 2,
    3, 3, 3, 3,
    4, 4, 4, 4
  };

  std::cout << " == Testing Transposition ==" << std::endl;
  std::cout << "Origin:" << std::endl << Matrix(_m, 4, 4) << std::endl;
  
  Matrix C(_m, 2, 4);
  std::cout << "C" << std::endl << C << std::endl;
  std::cout << "C^T" << std::endl << C.transpose();

  return 0;
}