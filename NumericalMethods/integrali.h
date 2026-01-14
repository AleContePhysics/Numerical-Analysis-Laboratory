#ifndef __integrali_h__
#define __integrali_h__
#include<iostream>
#include"random.h"
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class IntegraliMC{
    public:

    IntegraliMC(unsigned int seed):Gen(seed){
        errore=0;
    };
    double GetErr(){return errore;}
    unsigned int GetN(){return punti;}
    virtual double Integra(FunzioneBase& f,double inf,double sup,unsigned int punti,double fmax)=0;

    protected:

    RandomGen Gen;
    double errore;
    unsigned int punti;

};

class IntegratoreMedia:public IntegraliMC{
    public:
    IntegratoreMedia(unsigned int seed):IntegraliMC(seed){};
    virtual double Integra(FunzioneBase& f,double inf,double sup,unsigned int punti,double fmax)override;

};

class IntegratoreHM : public IntegraliMC{
    public:
    IntegratoreHM(unsigned int seed):IntegraliMC(seed){};
    virtual double Integra(FunzioneBase& f,double inf,double sup,unsigned int punti,double fmax)override;

};

double IntegratoreMedia::Integra(FunzioneBase& f,double inf,double sup,unsigned int punti,double fmax){
    double I=0,x,g,sum=0,sigmaf,sigmaI;
    for(unsigned int i=0;i<punti;i++){
        x=Gen.Unif(inf,sup);
        if(fmax==0){
            sum+=pow(f.Eval(x)-(f.Eval(sup)+f.Eval(inf))/2.,2);
        }
        g=f.Eval(x);
        I+=g;
    }
    if (fmax==0){
        sigmaf=sqrt((1./double(punti-1.))*sum);
        sigmaI=(sigmaf*(sup-inf))/(double)sqrt(punti);
    }
    errore=sigmaI;
    return I=I*(sup-inf)/(double)punti;
}

double IntegratoreHM::Integra(FunzioneBase& f,double inf,double sup,unsigned int punti,double fmax){
    double I,x,y,k=0;
    for(unsigned int i=0;i<punti;i++){
        x=Gen.Unif(inf,sup);
        y=Gen.Unif(0.,fmax);
        if(f.Eval(x)>y){
            k++;
        }
    }
    I=(sup-inf)*fmax*(k/(double)punti);
    return I;
}



#endif