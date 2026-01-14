#include"funzioni.h"

int main(int argc,char** argv){
    if(argc<2){
        cout<<"la sequenza d' ingresso è: <file_name> <ndata> <name_file_input>"<<endl;
        return -1;
    }
    char* filename=argv[1];
    vector<double>v=Read<double>(filename,atoi(argv[1]));
    //vector<double>v=ReadAll<double>(filename);//
    cout<<"Media: "<<Media(v)<<endl;
    cout<<"Varianza: "<<Varianza<double>(Media<double>(v),v)<<endl;
    cout<<"Mediana: "<<Mediana<double>(v)<<endl;

}