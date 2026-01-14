#include "Integrali.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "funzioni.h"
int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "struttura del file: <filename> <accuracy> " << endl;
    return -1;
  }
  TApplication app("app",0,0);
  TGraph pippo;
  unsigned int nmax=2000;
  double h = atof(argv[1]);
  double a = -M_PI;
  double b = M_PI;
  Parabola p(1,0,0);
  Seno s;
  Trapezoidi t(a, b);
  double I = t.Integra(p, h);
  cout<<I<<endl;

  return 0;
}
