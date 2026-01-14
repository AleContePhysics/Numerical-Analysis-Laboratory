#ifndef __random_h__
#define __random_h__
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include "funzioni.h"
#include <time.h>

using namespace std;

class RandomGen {

public:
  RandomGen(unsigned int y) { 
    seed = y;
    a = 1664525;
    c = 1013904223;
    m = pow(2,31);
    }

  void SetA(unsigned int t) { a = t; }
  void SetC(unsigned int b) { c = b; }
  void SetM(unsigned int d) { m = d; }

  double Rand();               // distribuzione uniforme tra 0 e 1
  double Unif(double, double); // distribuzione uniforme tra xmin e xmax
  double Exp(double );   // distribuzione esponenziale con costante lambda
  double Gaussian(double, double); // distribuzione gaussiana (Box-Muller)
  double GeneralFunctionAR(double,double,FunzioneBase&,double); //distribuzione gaussiana (Accept-Reject)

  private:
  unsigned int a, c, m;
  unsigned int seed;
};

//====================//
// Definizioni Metodi//
//====================//

double RandomGen::Rand() {
  unsigned int x0 = seed;
  double x = ((a * x0 + c) % m) / (double)m;
  seed=(a * x0 + c) % m;
  return x;
}

double RandomGen::Unif(double xmin, double xmax) {
  double x=Rand();
  x = x * (xmax - xmin) + xmin;
  return x;
}

double RandomGen::Exp(double lambda) {
  double x=Rand();
  x = -(1 / lambda) * log(1 - x);
  return x;
}

double RandomGen::GeneralFunctionAR(double xmin,double xmax,FunzioneBase& f,double max){
  double y;
  double x;
    do{
      x=Rand();
      x = x * (xmax - xmin) + xmin;
      y=Rand();
      y=y*max;
  } while(y>f.Eval(x));
  return x;
}

double RandomGen::Gaussian(double mean,double sigma){
  double s=Rand();
  double t=Rand();
  double x=sqrt(-2.*log(1.-s))*cos(2.*M_PI*t);
  return mean+x*sigma; 
}


#endif
