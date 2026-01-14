#ifndef __solutore_h__
#define __solutore_h__
#include"funzioni.h"
class Solutore{

    public:
    Solutore(double a,double b){prec=a;nmax=b;};

    double GetPrec(){return prec;}
    double GetNmax(){return nmax;}
    void SetPrec(double x){prec=x;}
    void SetNmax(double x){nmax=x;}

    protected:
    double prec;
    double nmax;
};

class Bisezione:public Solutore{
    public:
    Bisezione(Solutore &s):Solutore(s){};
    double FoundZero(double,double,FunzioneBase& );
    private:
    double min;
    double max;

};

class Derivata:public Solutore{
    public:

    Derivata(Solutore &s):Solutore(s){};
    double Deriva(FunzioneBase&,double);

    private:

};

class Secante:public Solutore{
    public:
    Secante(Solutore& s):Solutore(s){};
    double FoundZero(double,double,FunzioneBase&);
    private:
};

double Bisezione::FoundZero(double xmin,double xmax,FunzioneBase& f){
    double iter=0;
    class Sgn s; 
    double c;
    double fc;
    if(xmin<xmax){
        min=xmin;
        max=xmax;
    } else {
        max=xmin;
        min=xmax;
    }
    double fb=f.Eval(max);
    double fa=f.Eval(min);

    while(iter<nmax && (max-min)>prec){
        c=(max+min)*0.5;
        fc=f.Eval(c);
        if(s.Eval(fa)*s.Eval(fc)<0){
            fb=fc;
            max=c;
        } else {
            min=c;
            fc=fa;
        }
        iter++;
    }
    return c;
    
}

double Secante::FoundZero(double x1g,double x2g,FunzioneBase& f){
    double x1;
    double x2;
    double iter=0;
    double x3;
    Sgn s;
    if(x1g<x2g){
        x1=x1g;
        x2=x2g;
    } else {
        x1=x2g;
        x2=x1g;
    }
    while(abs(x2-x1)>prec && iter<nmax){
        x3=x2-(f.Eval(x2)*(x2-x1)/(double)(f.Eval(x2)-f.Eval(x1)));      //da chiedere, qualche volta trova lo zero fuori dal mio intervallo richiesto
        if(s.Eval(x1)*s.Eval(x3)<=0){
            x2=x3;
        } else {
            x1=x3;
        }
        iter++;
        
    }
    return x3;
}

double Derivata::Deriva(FunzioneBase& f,double x){
    double val;
    val=f.Eval(x-2*prec)-8*f.Eval(x-prec)+8*f.Eval(x+prec)-f.Eval(x+2*prec);
    val=val/(double)(12*prec);
    return val;
}

#endif