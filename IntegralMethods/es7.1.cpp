#include"lib.h"
#include"Integrali.h"
using namespace std;
int main(int argc, char** argv){
    if(argc<3){
        cout<<"struttura: <filename> <xin> <xfin> <npassaggi>"<<endl;
        return -1;
    }
    double a=atof(argv[1]);
    double b=atof(argv[2]);
    double n=atof(argv[3]);
    Seno s;
    Simpson y(a,b);
    double I=y.Integra(s,n);
    cout<<"I Omer Simpson:"<<I<<endl;

    return 0;
}






