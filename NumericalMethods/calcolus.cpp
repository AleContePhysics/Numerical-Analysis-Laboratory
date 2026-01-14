#include "integrali.h"
#include <vector>
#include<fstream>

int main(int argc,char** argv){
    clock_t start,end;
    double tempo;
    start=clock();
    if(argc!=3){
        cout<<"struttura file: <"<<argv[0]<<"> <Metodo: HM / Media> <Precisione>"<<endl;
        return -1;
    }
    string Metodo=argv[1];
    double h=atof(argv[2]);
    if(Metodo!="HM" && Metodo!="Media"){
        cout<<"Metodi accettati: <Metodo: HM / Media>"<<endl;
        return -1;
    }
    vector<int>N{100,500,1000,5000,10000,50000,100000};
    Seno s;
    double k;

    if(Metodo=="Media"){
        IntegratoreMedia Integral(1);
        for(unsigned int n=1;n<=N.size();n++){
            ofstream out;
            out.open("Integrali/Media_N="+to_string(N[n-1])+".dat");
            for(unsigned int i=0;i<10000;i++){
                k=Integral.Integra(s,0.,M_PI,N[n-1],double(i));
                out<<k<<endl;
            }
            out.close();
        } 
    }  
    if(Metodo=="HM"){
        IntegratoreHM Integral(1);
        for(unsigned int n=1;n<=N.size();n++){
            ofstream out;
            out.open("Integrali/HM_N="+to_string(N[n-1])+".dat");
            for(unsigned int i=0;i<10000;i++){
                k=Integral.Integra(s,0.,M_PI,N[n-1],1.);
                out<<k<<endl;
            }
            out.close();
        }  
    }
    
    end=clock();
    tempo=((double)(end-start))/CLOCKS_PER_SEC;
    cout<<"tempo: "<<tempo<<endl;
    return 0;
}