#ifndef __algoritmieqdiff_h__
#define __algoritmieqdiff_h__

#include "equazionidifferenziali.h"

class EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h,const FunzioneBaseVettoriale &f) = 0;
};

class Eulero : public EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h, FunzioneBaseVettoriale &f) {
    return x + (f.Eval(t, x)) * h;
  }
};

class RungeKutta : public EquazioneDifferenzialeBase {
public:
  virtual vector<double> Passo(double t, const vector<double> &x, double h,const FunzioneBaseVettoriale &f) {
    vector<double> K1 = f.Eval(t, x);
    vector<double> K2 = f.Eval(t + (h * 0.5), x + (h * 0.5 * K1));
    vector<double> K3 = f.Eval(t + (h * 0.5), x + (h * 0.5 * K2));
    vector<double> K4 = f.Eval(t + h, x + (h * K3));
    return x + (h / 6.) * (K1 + 2. * K2 + 2. * K3 + K4);
  }

protected:
};

#endif