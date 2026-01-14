#include "TApplication.h"
#include "TAxis.h"
#include "TCanvas.h"
#include "TF1.h"
#include "TGraph.h"
#include "TLegend.h"
#include "algebravettoriale.h"
#include "algoritmieqdiff.h"
#include "equazionidifferenziali.h"

int main() {
  TApplication app("app", 0, 0);
  RungeKutta Paul;
  TGraph Grafico;
  TGraph Grafico2;

  double d = 147098074000;
  double v = 30287;
  vector<double> x{d, 0, 0, v};
  double t = 0.;
  double h = 864000;
  double tmax = 315360000;
  double M = 1.98844 * 1E30;
  int nmax = int(tmax / h + 0.5);
  MotoPianeta Terra(M);
  MotoPianetaPerturbato Terra2(M);
  for (int i = 0; i < nmax; i++) {
    Grafico.SetPoint(i, x[0], x[2]);
    x = Paul.Passo(t, x, h, Terra);
    t += h;
  }
  
  //Grafico Orbita Normale//
  TCanvas c("Grafico", "Grafico", 1000, 1000);
  c.cd();
  Grafico.GetXaxis()->SetTitle("Distanza x [m]");
  Grafico.GetYaxis()->SetTitle("Distanza y [m]");
  Grafico.SetTitle("Orbita Terra");
  Grafico.GetYaxis()->SetRangeUser(-1.6 * 10E10, 1.6 * 10E10);
  Grafico.GetXaxis()->SetRangeUser(-1.6 * 10E10, 1.6 * 10E10);
  Grafico.Draw("AL");
  c.Print("Orbita.pdf");


  t=0,x[0]=d,x[1]=0,x[2]=0,x[3]=v;
  tmax= 3153600000;
  nmax = int(tmax / h + 0.5);
   for (int i = 0; i < nmax; i++) {
    Grafico2.SetPoint(i, x[0], x[2]);
    x = Paul.Passo(t, x, h, Terra2);
    t += h;
  }

  //Grafico Orbita Perturbata//
  TCanvas c2("Grafico2", "Grafico", 800, 800);
  c2.cd();
  Grafico2.GetXaxis()->SetTitle("Distanza x [m]");
  c2.SetGrid();
  Grafico2.GetYaxis()->SetTitle("Distanza y [m]");
  Grafico2.SetTitle("Orbita Terra Perturbata");
  Grafico2.GetYaxis()->SetRangeUser(-2.5 * 10E10, 2.5 * 10E10);
  Grafico2.GetXaxis()->SetRangeUser(-2.5 * 10E10, 2.5 * 10E10);
  Grafico2.Draw("AL");
  c2.Print("OrbitaPerturbata.pdf");
  app.Run();
}