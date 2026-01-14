#include"lib.h"
int main(){

    Function g;
    Solutore s(0.000001,1000);
    Bisezione b(s);
    double pi=3.14159;
    for(int i=0;i<20;i++){
        double x=b.FoundZero(-pi*0.5+pi*i,pi*0.5+pi*i,g);
        cout<<"lo zero numero "<<i+1<<" è in: "<<x<<endl;
    }
    return 0;
}