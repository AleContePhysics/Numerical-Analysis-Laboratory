#include"algebravettoriale.h"
#include"equazionidifferenziali.h"
#include"algoritmieqdiff.h"

int main(int argc, const char **argv) {
  if (argc != 2) {
    cout << "struttura file: <filename> <passo h>" << endl;
    return -1;
  }
  vector<double> x{0., 1.};
  double t = 0.;
  double h = atof(argv[1]);
  double tmax = 70.0;
  int nmax = int(tmax / h + 0.5);
  RungeKutta Paul;
  OscillatoreArmonico osc(1.);
  for (int i = 0; i < nmax; i++) {
    x = Paul.Passo(t, x, h, osc);
    t += h;
  }
}