#include "matrix.h"
#include <iostream>

int main (int argc, char **argv) {

  Matrix m1(2, 2);
  Matrix *m2 = Matrix::unit(2);
  Matrix *m3 = Matrix::random(2);

  std::cout << m1;
  std::cout << *m2;
  std::cout << *m3;
  std::cout << m1 + *m2 + *m3;

  std::cout << *m2 * *m2;

  double m4[9] = {
    1, 2, 3,
    2, 3, 1,
    3, 1, 2
  };

  std::cout << Matrix(m4, 3, 3);

  return 0;
}