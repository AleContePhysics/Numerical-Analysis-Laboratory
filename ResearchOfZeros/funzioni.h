#ifndef __funzioni_h__
#define __funzioni_h__
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

class Retta:public FunzioneBase{
    public:
    Retta(double g,double h){m=g;q=h;}
    double Eval(double x){
        double f=m*x+q;
        return f;
    }
    protected:
    double m;
    double q;
};

class Parabola:public FunzioneBase{
    public:
    Parabola(double x,double y,double z){
        a=x;
        b=y;
        c=z;
    }
    virtual double Eval(double x){
        double f=a*pow(x,2)+b*x+c;
        return f;
    }
    protected:
    double a;
    double b;
    double c;
};

class Seno:public FunzioneBase{
    public:
    Seno(){c=1;}
    Seno(double a){c=a;}
    virtual double Eval(double x){
        double f=sin(c*x);
        return f;
    }
    private:
    double c;
};

class Coseno:public FunzioneBase{
    public:
    Coseno(double x){c=x;}
    Coseno(){c=1;}
    virtual double Eval(double x){
        double f=cos(c*x);
        return f;
    }
    private:
    double c;
};

class Tangente:public FunzioneBase{
    public:
    Tangente(){c=1;}
    Tangente(double a){c=a;}
    virtual double Eval(double x){
        double f=tan(c*x);
        return f;
    }
    private:
    double c;
};

class Arcotangente:public FunzioneBase{
    public:
    Arcotangente(){c=1;}
    Arcotangente(double a){c=a;}
    virtual double Eval(double x){
        double f=atan(c*x);
        return f;
    }
    private:
    double c;
};


#endif