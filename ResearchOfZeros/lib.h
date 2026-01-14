#include<iostream>
#include<cmath>
using namespace std;


class FunzioneBase{

    public:
    virtual double Eval(double x)=0;

};
class Sgn:public FunzioneBase{                
    public:
    double sgn(double x){
        if(x>0){
        return 1;
    } else {return -1;}}
    virtual double Eval(double x){return sgn(x);}
};
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


class Function:public FunzioneBase{
    public:
    Function(){}
    virtual double Eval(double x){
        double j=x*cos(x)-sin(x);
        return j;
    }
};