#include "matrix.h"

Matrix Matrix::unit(int size) {
  Matrix result(size, size);
  for (int i = 0; i < size; i++) {
    result[i][i] = 1;
  }
  return result;
}

double Matrix::det(const Matrix &m) {
  int n = m.rows();
  if (n != m.columns() || n == 0) return 0;
  if (n == 1) return m[0][0];
  if (n == 2) return m[0][0] * m[1][1] - m[0][1] * m[1][0];
  Matrix _m(m);
  double det = 1;
  for (int i = 0; i < n; i++) {
    int k = i;
    for (int j = i + 1; j < n; j++) {
      if (fabs(_m[j][i]) > fabs(_m[k][i])) {
        k = j;
      }
    }
    if (fabs(_m[k][i]) < EPS) {
      det = 0;
      break;
    }
    for (int j = 0; j < n; j++) {
      double t = _m[i][j];
      _m[i][j] =_m[k][j];
      _m[k][j] = t;
    }
    if (i != k) {
      det = -det;
    }
    det *= _m[i][i];
    for (int j = i + 1; j < n; j++) {
      _m[i][j] /= _m[i][i];
    }
    for (int j = 0; j < n; j++) {
      if (j != i && fabs(_m[j][i]) > EPS) {
        for (int k = i + 1; k < n; k++) {
          _m[j][k] -= _m[i][k] * _m[j][i];
        }
      }
    }
  }
  return det;
}

double Matrix::complement(int row, int col) {
  double *t = new double[(m - 1) * (n - 1)];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      t[(m - 1) * i + j] = this->at(i, j);
    }
    for (int j = col + 1; j < n; j++) {
      t[(m - 1) * i + j - 1] = this->at(i, j);
    }
  }
  for (int i = row + 1; i < m; i++) {
    for (int j = 0; j < col; j++) {
      t[(m - 1) * (i - 1) + j] = this->at(i, j);
    }
    for (int j = col + 1; j < n; j++) {
      t[(m - 1) * (i - 1) + j - 1] = this->at(i, j);
    }
  }
  int sgn = (row + col) % 2 ? -1 : 1;
  return sgn * Matrix(t, m - 1, n - 1).det();
}

double Matrix::det() {
  return Matrix::det(*this);
}

Matrix Matrix::inverse() {
  double D = this->det();
  if (fabs(D) < EPS) {
    throw std::runtime_error("Matrix is not inversable");
  }
  Matrix r(this->m, this->n);
  Matrix t = this->transpose();
  for (int i = 0; i < this->m; i++) {
    for (int j = 0; j < this->n; j++) {
      r[i][j] = t.complement(i, j) / D;
    }
  }
  return r;
}

Matrix Matrix::transpose() {
  Matrix M(this->n, this->m);
  for (int i = 0; i < this->n; i++) {
    for (int j = 0; j < this->m; j++) {
      M[i][j] = (*this)[j][i];
    }
  }
  return M;
}

Matrix Matrix::random(int size) {
  return Matrix::random(size, size);
}

Matrix Matrix::random(int m, int n) {
  srand(time(0));
  Matrix result(m, n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      result[i][j] = rand();
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
  Matrix result(lhs.rows(), rhs.columns());
  for (int i = 0; i < lhs.rows(); i++) {
    for (int j = 0; j < rhs.columns(); j++) {
      double s = 0;
      for (int k = 0; k < lhs.columns(); k++) {
        s += lhs[i][k] * rhs[k][j];
      }
      result[i][j] = s;
    }
  }
  return result;
}

const Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
  Matrix result(lhs);
  result += rhs;
  return result;
}

std::ostream & operator<<(std::ostream &os, const Matrix &rhs) {
  for (int i = 0; i < rhs.m; i++) {
    for (int j = 0; j < rhs.n; j++) {
      os << rhs[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}
