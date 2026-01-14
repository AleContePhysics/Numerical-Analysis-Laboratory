#ifndef __funzioni_h__
#define __funzioni_h__
#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<numeric>
#include"TApplication.h"
#include"TCanvas.h"
#include"TGraph.h"
using namespace std;

template <typename T>vector<T> Read(const char*,unsigned int);
template <typename T>T Media(const vector<T>& );
template <typename T>T Varianza(T, vector<T>&);
template<typename T> T Mediana(vector<T>&);
template <typename T>void Print(vector<T>&);
template <typename T>void Print(vector<T>&,const char*);
template <typename T>vector<T> ReadAll(const char*);


template <typename T>vector<T> Read(const char* filename,unsigned int n){
    ifstream in;
    in.open(filename);
    vector<T>v;
    if(!in){
        cout<<"cannot open the input file"<<endl;
        exit(1);
    } else {
        for(int i=0;i<n;i++){
          T b;
          in>>b;
          v.push_back(b);
          if(in.eof()){
            cout<<"non ci sono abbastanza dati"<<endl;
            exit(1);
          }
          }
        }
    
    in.close();
    return v;

};

template <typename T>T Media(const vector<T>& a) {
  double sum =accumulate(a.begin(),a.end(),0.0)/(double)a.size();
  return sum;
};

template <typename T>T Varianza(T media, vector<T>& a) {
  double var = 0;
  for (int i = 0; i < a.size(); i++) {
    var = var + ((media - a[i]) * (media - a[i]));
  }
  var = var / (double)(a.size());
  return var;
};

template<typename T> T Mediana(vector<T>& a) {
  sort(a.begin(),a.end());
  T mediana=0;
  if (a.size() % 2 == 0) {
    mediana = a[(a.size() + 1) / 2];
  } else {
    mediana = a[a.size() / 2] + a[(a.size() / 2) + 1];
  }
  return mediana;
};



template <typename T>void Print(vector<T>& a){
    for(int i=0;i<a.size();i++){
        cout<<i+1<<": "<<a[i]<<endl;
    }
};

template <typename T>void Print(vector<T>& a,const char* fileout) {
    ofstream out;
    out.open(fileout);
    for (int i = 0; i < a.size(); i++) {
    out <<i+1<<": "<< a[i] << endl;
  }
};

template <typename T>vector<T> ReadAll(const char* filename){
    ifstream in;
    in.open(filename);
    vector<T>v;
    if(!in){
        cout<<"cannot open the input file"<<endl;
        exit(1);
    } else {
        while(in.eof()==false){
          T b;
          in>>b;
          v.push_back(b);
          }
        }
    
    in.close();
    return v;

};




#endif