#include"algebravettoriale.h"
int main(){
    vector<double>a{3,4,9};
    vector<double>b{5,6,9};
    vector<double>c;
    try{c=a+b;} catch (const char* msg){
        cout<<msg<<endl;
        exit(-1);
    }
    c=c/Norma(c);
    cout<<"versore del vettore somma:"<<endl;
    Print(c);

    return 0;
}