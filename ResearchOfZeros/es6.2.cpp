#include"funzioni.h"
#include"solutore.h"

int main(){

    Retta g(2,2);
    Parabola p(3,4,-5);
    Coseno c;
    Solutore s(0.00005,30);
    Secante t(s);
    Bisezione b(s);
    Derivata d(s);
    double j=b.FoundZero(-6,0,p);
    cout<<"bisezione x="<<j<<endl;
    double u=t.FoundZero(-3,0,p);
    cout<<"secante x="<<u<<endl;



    //double y=d.Deriva(p,1.57);
    //cout<<"la derivata in "<<1.57<<" è:"<<y<<endl;
    return 0;
}