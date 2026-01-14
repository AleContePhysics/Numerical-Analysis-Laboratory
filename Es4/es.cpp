#include "funzioni.h"
#include <iostream>     
#include <algorithm>   
#include <vector>  
#include<numeric> 

int main () {
    vector<double>v={1,2,3,4,5};
    vector<double>a(5);
    copy(v.begin(),v.end(),a.begin());
    
    for(auto it=a.begin();it!=a.end();it++){
        cout<<*it<<endl;
    }

    //double media=accumulate(a.begin(),a.end(),-15.3);
    //cout<<"media: "<<media<<endl;
    return 0;
}
 