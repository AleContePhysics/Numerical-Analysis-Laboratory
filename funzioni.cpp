#include"funzioni.h"

void Read(const char* filename,unsigned int n,vettore& a){
    ifstream in;
    in.open(filename);
    if(!in){
        cout<<"cannot open the input file"<<endl;
        exit(1);
    } else {
        for(int i=0;i<n;i++){
            double b=0;
            in>>b;
            a.SetC(b,i);
            if(in.eof()){
                cout<<"hai inserito troppi valori"<<endl;
                exit(2);
            }
        }
    
    }
    in.close();

}

double Media(const vettore& a) {
  double sum = 0.0;
  for (int i = 0; i < a.GetN(); i++) {
    sum = sum + a.GetC(i);
  }
  sum = sum / (double)(a.GetN());
  return sum;
}

double Varianza(double media, vettore& a) {
  double var = 0;
  for (int i = 0; i < a.GetN(); i++) {
    var = var + ((media - a.GetC(i)) * (media - a.GetC(i)));
  }
  var = var / (double)(a.GetN());
  return var;
}

double Mediana(vettore& a) {
  double mediana;
  if (a.GetN() % 2 == 0) {
    mediana = a.GetC((a.GetN() + 1) / 2);
  } else {
    mediana = a.GetC(a.GetN() / 2) + a.GetC((a.GetN() / 2) + 1);
  }
  return mediana;
}

void Swap(double &a, double &b) {
  double c = a;
  a = b;
  b = c;
}

void Print(vettore& a){
    for(int i=0;i<a.GetN();i++){
        cout<<i+1<<": "<<a.GetC(i)<<endl;
    }
}

void Print(vettore& a,const char* fileout) {
    ofstream out;
    out.open(fileout);
    for (int i = 0; i < a.GetN(); i++) {
    out <<i+1<<": "<< a.GetC(i) << endl;
  }
}


