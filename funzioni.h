#ifndef __funzioni_h__
#define __funzioni_h__
#include<iostream>
#include<cmath>
#include<fstream>
#include"vettore.h"
using namespace std;

void Read(const char*,unsigned int,vettore&);
double Media(const vettore& );
double Varianza(double, vettore&);
double Mediana(vettore&);
void Swap(double &, double &);
void Print(vettore&);
void Print(vettore&,const char*);
#endif