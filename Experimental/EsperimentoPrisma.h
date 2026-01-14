#ifndef __EsperimentoPrisma_h__
#define __EsperimentoPrisma_h__

#include<iostream>
#include<time.h>
#include "random.h"
using namespace std;

class EsperimentoPrisma{

    public:

    EsperimentoPrisma(unsigned int seed);

    void Analizza();
    void Esegui();
    double GetLambda1(){return lambda1;}
    double GetLambda2(){return lambda2;}
    double GetA(){return A;}
    double GetB(){return B;}
    double GetAmis(){return Amis;}
    double GetBmis(){return Bmis;}
    double GetTheta1(){return th1;}
    double GetTheta2(){return th2;}
    double GetTheta0(){return th0;}
    double Getn1(){return n1;}
    double Getn2(){return n2;}
    double GetDeltam1(){return deltam1;}
    double GetDeltam2(){return deltam2;}
    double GetDeltam1mis(){return deltam1mis;}
    double GetDeltam2mis(){return deltam2mis;}
    double GetTheta0mis(){return th0mis;}
    double GetTheta1mis(){return th1mis;}
    double GetTheta2mis(){return th2mis;}
    double Getn1mis(){return n1mis;}
    double Getn2mis(){return n2mis;}
    double GetAlpha(){return alpha;}
    double GetSigmat(){return sigmat;}

    private:

    RandomGen Gen;
    double lambda1, lambda2, alpha, sigmat;
    double A, Amis;       //coefficiente A//
    double B, Bmis;       //coefficiente B//
    double n1, n1mis;     //indice di rifrazione di lambda max//
    double n2, n2mis;     //indice di rifrazione di lambda min//
    double deltam1, deltam1mis;   //angolo di deviazione minima per lambda max//
    double deltam2, deltam2mis;   //angolo di deviazione minima per lambda min//
    double th0, th0mis;   //angolo corrispondente al fascio non deflesso in assenza del prisma//
    double th1, th1mis;   //angolo corrispondente alla deviazione minima della riga del giallo(lambda max)//
    double th2, th2mis;   //angolo corrispondente alla deviazione minima della riga del viola(lambda min)//
};

EsperimentoPrisma::EsperimentoPrisma(unsigned int seed):Gen(seed){
    lambda1=579.1E-9;
    lambda2=404.7E-9;
    alpha=60.*M_PI/180.;
    sigmat=0.3E-3;
    A=2.7;
    B=60000E-18;
    //calcolo gli indici di rifrazione//
    n1=sqrt(A+B/pow(lambda1,2));
    n2=sqrt(A+B/pow(lambda2,2));
    //calcolo gli angoli di deviazione deltam//
    deltam1=2.*asin( n1 * sin (0.5 * alpha) ) - alpha ;
    deltam2=2.*asin( n2 * sin (0.5 * alpha) ) - alpha ;
    //scelgo un theta0 arbitrario e calcolo gli angoli di deviazione theta//
    th0=M_PI/2.;
    th1=th0+deltam1;
    th2=th0+deltam2;
}

void EsperimentoPrisma::Esegui(){

    th0mis=Gen.Gaussian(th0,sigmat);
    th1mis=Gen.Gaussian(th1,sigmat);
    th2mis=Gen.Gaussian(th2,sigmat);
}

void EsperimentoPrisma::Analizza(){
    deltam1mis=th1mis-th0mis;
    deltam2mis=th2mis-th0mis;
    n1mis=sin((deltam1mis+alpha)/2.)/sin(alpha/2.);
    n2mis=sin((deltam2mis+alpha)/2.)/sin(alpha/2.);
    Amis=(pow(lambda2,2)*pow(n2mis,2)-pow(lambda1,2)*pow(n1mis,2))/(pow(lambda2,2)-pow(lambda1,2));
    Bmis=(pow(n2mis,2)-pow(n1mis,2))/((1./pow(lambda2,2))-(1./pow(lambda1,2)));
}

#endif