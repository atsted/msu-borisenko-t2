#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <ctime>
#include <cmath>
#include <vector>

const double EPS = 1e-6;

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
    for (int i = 0; i < m * n; i++) {
      buf[i] = obj.buf[i];
    }
  }

  Matrix(double array[], int m = 0, int n = 0) : m(m), n(n) {
    buf = new double[m * n];
    for (int i = 0; i < m * n; i++) {
      buf[i] = array[i];
    }
  }

  ~Matrix() {
    delete []buf;
  }

  double * operator[](size_t idx) {
    return buf + n * idx;
  }

  const double * operator[](size_t idx) const {
    return buf + n * idx;
  } 

  inline double at(int i, int j) const {
    if (i >= m) {
      throw std::out_of_range(
        "Max value of i is " + std::to_string(m - 1) + ", got " + std::to_string(i)
      );
    }
    if (j >= n) {
      throw std::out_of_range(
        "Max value of j is " + std::to_string(n - 1) + ", got " + std::to_string(j)
      );
    }
    return buf[m * i + j];
  }

  inline int rows() const {
    return m;
  }

  inline int columns() const {
    return n;
  }

  static Matrix unit(int);
  static Matrix random(int);
  static Matrix random(int, int);
  static double det(const Matrix &);

  double det();
  double complement(int, int);
  Matrix inverse();
  Matrix transpose();
  Matrix & operator+=(const Matrix &);

  friend const Matrix operator+(const Matrix &, const Matrix &); 
  friend const Matrix operator*(const Matrix &, const Matrix &);
  friend std::ostream & operator<<(std::ostream &, const Matrix &);

};

#endif