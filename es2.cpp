#include"funzioni.h"
#include"vettore.h"
int main(int argc,char** argv){
    if(argc<3){
        cout<<"struttura del programma: <filename> <n_elements> <filename_input>"<<endl;
    }
    unsigned int n=atoi(argv[1]);
    char* filename=argv[2];
    vettore a(n);
    Read("data.dat",n,a);
    a.Riordina();
    cout<<"Media: "<<Media(a)<<endl;
    cout<<"Varianza: "<<Varianza(Media(a),a)<<endl;
    cout<<"Mediana: "<<Mediana(a)<<endl;
    Print(a);
    Print(a,"output.dat");
}