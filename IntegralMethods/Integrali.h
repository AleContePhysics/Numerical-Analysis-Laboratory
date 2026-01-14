#ifndef __Integrali_h__
#define __Integrali_h__
#include "funzioni.h"
#include<vector>
#include<cmath>

class Integrali {

public:
  Integrali(double c, double d) {
    if (c <= d) {
      a = c;
      b = d;
      sgn = 1;
    } else {
      a = d;
      b = c;
      sgn = -1;
    }
  };
  double GetPrec() { return h; }
  double GetNmax() { return nmax; }
  void SetPrec(double x) { h = x; }
  void SetNmax(double x) { nmax = x; }
  double virtual Integra(FunzioneBase &, double) = 0;
  double virtual Integra(FunzioneBase&,unsigned int)=0;

protected:
  double h = 0;
  double nmax = 0;
  double a;
  double b;
  double I = 0;
  double sgn;
};


class Trapezoidi : public Integrali {
public:
  Trapezoidi(double c, double d) : Integrali(c, d){};
  double virtual Integra(FunzioneBase &, double) override;
  double virtual Integra(FunzioneBase&,unsigned int)override;
};

double Trapezoidi::Integra(FunzioneBase &f,unsigned int n){
    I=0;
    h=(b-a)/(double)n;
    for(int i=0;i<n;i++) {
    I = I + f.Eval(a+i*h);
    }
    I = (I + 0.5 * f.Eval(a) + 0.5 * f.Eval(b)) * h * sgn;
    return I;

}

double Trapezoidi::Integra(FunzioneBase &f, double prec) {
  vector<double> In;
  I = 0;
  unsigned int i = 0;
  double h;
  double sum = f.Eval(b) + f.Eval(a) / 2.;
  I = sum * (b - a);
  In.push_back(I);
  do {
    i++;
    nmax = pow(2, i);
    h = (b - a) / nmax;
    for (int k = 1; k < nmax; k = k + 2) {
      sum = sum + f.Eval(a + (k * h));
    }
    I = sum * (b - a) / nmax;
    In.push_back(I);

  } while ((4./3.)*abs(In[i] - In[i-1]) > prec);

  return In[i];
}


#endif