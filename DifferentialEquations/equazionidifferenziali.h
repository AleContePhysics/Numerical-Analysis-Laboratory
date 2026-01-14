#ifndef __equazionidifferenziali_h__
#define __equazionidifferenziali_h__
#include "algebravettoriale.h"

class FunzioneBaseVettoriale {
public:
  virtual vector<double> Eval(double t, const vector<double> &v) const = 0;
};

//==========================//
// equazioni differenziali//
//==========================//

class OscillatoreArmonico : public FunzioneBaseVettoriale {
public:
  OscillatoreArmonico(double omega) { w = omega; }
  virtual vector<double> Eval(double t, const vector<double> &x) const override;

protected:
  double w;
};

class Pendolo : public FunzioneBaseVettoriale {
public:
  Pendolo(double lunghezza) { l = lunghezza; }
  virtual vector<double> Eval(double t, const vector<double> &x) const override;

protected:
  double l;
};

class OscillatoreSmorzatoForzato : public FunzioneBaseVettoriale {
public:
  OscillatoreSmorzatoForzato(double omega0, double gamma, double omega) {
    w = omega, y = gamma, w0 = omega0;
  }
  virtual vector<double> Eval(double t, const vector<double> &x) const override;

protected:
  double w0;
  double y;
  double w;
};

class MotoPianeta : public FunzioneBaseVettoriale {
public:
  MotoPianeta(double massa) { M = massa; }
  virtual vector<double> Eval(double t, const vector<double> &x) const override;

protected:
  double M;
  double G = 6.6742 * 1E-11;
};

class MotoPianetaPerturbato : public FunzioneBaseVettoriale {
public:
  MotoPianetaPerturbato(double massa) { M = massa; }
  virtual vector<double> Eval(double t, const vector<double> &x) const override;

protected:
  double M;
  double G = 6.6742 * 1E-11;
};

//==========================//
// Eval eq. differenziali//
//==========================//

vector<double> OscillatoreArmonico::Eval(double t,const vector<double> &x) const {
  vector<double> result(x.size());
  result[0] = x[1];
  result[1] = -w * w * x[0];
  return result;
}

vector<double> Pendolo::Eval(double t, const vector<double> &x) const {
  vector<double> result(x.size());
  result[0] = x[1];
  result[1] = -9.81 / l * sin(x[0]);
  return result;
};

vector<double> OscillatoreSmorzatoForzato::Eval(double t, const vector<double> &x) const {
  vector<double> result(x.size());
  result[0] = x[1];
  result[1] = -pow(w0, 2) * x[0] - y * x[1] + sin(w * t);
  return result;
};

vector<double> MotoPianeta::Eval(double t, const vector<double> &x) const {
  vector<double> result(x.size());
  result[0] = x[1];
  result[1] = -M * G * x[0] / pow(pow(x[0], 2) + pow(x[2], 2), 1.5);
  result[2] = x[3];
  result[3] = -M * G * x[2] / pow(pow(x[0], 2) + pow(x[2], 2), 1.5);
  return result;
};

vector<double> MotoPianetaPerturbato::Eval(double t, const vector<double> &x) const {
  vector<double> result(x.size());
  result[0] = x[1];
  result[1] = (x[0]/pow(pow(x[0],2)+pow(x[2],2),1.5))*(-M*G+(pow(10,58.5)/(5,9726 * 1E24*sqrt(pow(x[0],2)+pow(x[2],2)))));
  result[2] = x[3];
  result[3] = (x[2]/pow(pow(x[0],2)+pow(x[2],2),1.5))*(-M*G+(pow(10,58.5)/(5,9726 *1E24*sqrt(pow(x[0],2)+pow(x[2],2)))));
  return result;
};


#endif