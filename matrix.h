#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstring>
#include <ctime>

class Matrix {

private:

  int m;
  int n;
  double *buf;

public:

  Matrix(int m = 0, int n = 0) : m(m), n(n) {
    buf = new double[m * n];
    memset(buf, 0, m * n * sizeof(double));
  }

  Matrix(const Matrix &obj) : m(obj.m), n(obj.n) {
    buf = new double[m * n];
    memcpy(buf, obj.buf, m * n * sizeof(double));
  }

  Matrix(double array[], int m = 0, int n = 0) : m(m), n(n) {
    buf = new double[m * n];
    memcpy(buf, array, m * n * sizeof(double));
  }

  ~Matrix() {
    delete buf;
  }

  inline double & at(int i, int j) const {
    return this->buf[m * i + j];
  }

  inline int rows() const {
    return this->m;
  }

  inline int columns() const {
    return this->n;
  }

  static Matrix * unit(int);
  static Matrix * random(int);
  static Matrix * random(int, int);
  static double det(const Matrix &);

  Matrix & operator+=(const Matrix &);

  friend const Matrix operator+(const Matrix &, const Matrix &); 
  friend const Matrix operator*(const Matrix &, const Matrix &);
  friend std::ostream & operator<<(std::ostream &, const Matrix &);

};

#endif