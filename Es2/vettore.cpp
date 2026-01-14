#include"funzioni.h"

vettore::vettore(){
        n=0;
        A=NULL;
    }

vettore::vettore(unsigned int a){
    n=a;
    A=new double[n];
    for(int i=0;i<n;i++){
        A[i]=0;
    }
}

vettore::vettore(vettore& b){                   //costruttore di copia
    n=b.GetN();
    A=new double[n];
    for(int i=0;i<n;i++){
        A[i]=b.GetC(i);
    }

}

void vettore::Riordina() {
  for (int i = 0; i < (n - 1); i++) {
    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[i]) {
      Swap(A[i],A[j]);
      }
    }
  }
}

vettore& vettore:: operator=(const vettore& a){
    n=a.GetN();
    if(A) delete[]A;
    A=new double(n);
    for(int i=0;i<a.GetN();i++){
        A[i]=a.GetC(i);
    }
    return *this;
}

double& vettore:: operator[](unsigned int i) const {
    if(i<n){
        return A[i];
    } else {return A[n];}
}