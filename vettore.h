#ifndef __vettore_h__
#define __vettore_h__
#include"funzioni.h"


class vettore{

    public:

    vettore();                              //costruttori
    vettore(unsigned int);
    vettore(vettore&);
    vettore& operator=(const vettore&);
    double& operator[](unsigned int) const;

    ~vettore(){                              //distruttore per deallocare la memoria
        delete[]A;
    }

    int GetN()const{return n;}
    void SetC(double a,unsigned int i){A[i]=a;}
    double GetC(unsigned int i)const {return A[i];}
    void Riordina();

    private:
    
    int n;
    double* A;
};

#endif