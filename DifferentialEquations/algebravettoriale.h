#ifndef __algebravettoriale_h__
#define __algebravettoriale_h__
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template <typename T>
inline vector<T> operator+(const vector<T> &, const vector<T> &);
template <typename T>
inline vector<T> operator-(const vector<T> &, const vector<T> &);
template <typename T> inline T operator*(const vector<T> &, const vector<T> &);
template <typename T> inline vector<T> operator*(const vector<T> &, T);
template <typename T> inline vector<T> operator*(T, const vector<T> &);
template <typename T> inline vector<T> operator/(const vector<T> &, T);
template <typename T>
inline vector<T> operator+=(vector<T> &, const vector<T> &);
template <typename T> inline T Norma(const vector<T> &, const vector<T> &);
template <typename T> inline T Norma(const vector<T> &);
template <typename T> void Print(vector<T> &);

template <typename T>
inline vector<T> operator+(const vector<T> &a,const vector<T> &b) { // sum of vectors//
  if (a.size() != b.size())
    throw "Dimensione dei vettori diversa";
  vector<T> result(a.size());
  transform(a.begin(), a.end(), b.begin(), result.begin(), plus<T>());
  return result;
}

template <typename T>
inline vector<T> operator-(const vector<T> &a,const vector<T> &b) { // difference between vectors//
  if (a.size() != b.size())
    throw "Dimensione dei vettori diversa";
  vector<T> result(a.size());
  transform(a.begin(), a.end(), b.begin(), result.begin(), minus<T>());
  return result;
}

template <typename T>
inline T operator*(const vector<T> &a, const vector<T> &b) { // inner product//
  if (a.size() != b.size())
    throw "Dimensione dei vettori diversa";
  T sum = 0;
  sum = inner_product(begin(a), end(a), begin(b), 0.);
  return sum;
}

template <typename T>
inline vector<T> operator*(const vector<T> &a, T c) { // vector*scalar//
  vector<T> result(a.size());
  transform(begin(a), end(a), begin(result), [&c](T x) { return x * c; });
  return result;
}

template <typename T>
inline vector<T> operator*(T c, const vector<T> &a) { // scalar*vector//
  vector<T> result(a.size());
  transform(begin(a), end(a), begin(result), [&c](T x) { return x * c; });
  return result;
}

template <typename T>
inline vector<T> operator/(const vector<T> &a, T c) { // vector/scalar//
  vector<T> result(a.size());
  transform(begin(a), end(a), begin(result), [&c](T x) { return x / c; });
  return result;
}

template <typename T>
inline vector<T> operator+=(vector<T> &a,const vector<T> &b) { // vettore+=vettore//
  if (a.size() != b.size())
    throw "Dimensione dei vettori diversa";
  vector<T> result(a.size());
  transform(a.begin(), a.end(), b.begin(), result.begin(), plus<T>());
  a = result;
  return a;
}

template <typename T>
inline T Norma(const vector<T> &a,const vector<T> &b) { // norma fra due vettori//
  if (a.size() != b.size())
    throw "Dimensione dei vettori diversa";
  T norme = sqrt(a * b);
  return norme;
}

template <typename T>
inline T Norma(const vector<T> &a) { // norma di un vettore//
  T norme = sqrt(a * a);
  return norme;
}

template <typename T> void Print(vector<T> &a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
}

#endif
