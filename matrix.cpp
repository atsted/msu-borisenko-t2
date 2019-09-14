#include "matrix.h"

Matrix * Matrix::unit(int size) {
  Matrix *result = new Matrix(size, size);
  for (int i = 0; i < size; i++) {
    result->at(i, i) = 1;
  }
  return result;
}

double Matrix::det(const Matrix &m) {
  double d = 1;

  for (int i = 0; i < m.rows(); i++) {
    d *= m.at(i, i);
  }
  return d;
}

Matrix * Matrix::random(int size) {
  return Matrix::random(size, size);
}

Matrix * Matrix::random(int m, int n) {
  srand(time(0));
  Matrix *result = new Matrix(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      result->at(i, j) = rand();
    }
  }
  return result;
}

Matrix & Matrix::operator+=(const Matrix &rhs) {
  for (int i = 0; i < m * n; i++) {
    buf[i] += rhs.buf[i];
  }
  return *this;
}

const Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
  Matrix *result = new Matrix(lhs.rows(), rhs.columns());
  for (int i = 0; i < lhs.rows(); i++) {
    for (int j = 0; j < rhs.columns(); j++) {
      double s = 0;
      for (int k = 0; k < lhs.columns(); k++) {
        s += lhs.at(i, k) * rhs.at(k, j);
      }
      result->at(i, j) = s;
    }
  }
  return *result;
}

const Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
  Matrix *result = new Matrix(lhs);
  *result += rhs;
  return *result;
}

std::ostream & operator<<(std::ostream &os, const Matrix &rhs) {
  for (int i = 0; i < rhs.m; i++) {
    for (int j = 0; j < rhs.n; j++) {
      os << rhs.buf[rhs.m * i + j] << " ";
    }
    os << std::endl;
  }
  return os;
}
