#include<iostream>
using namespace std; 

int main(){ 
    int annee,a,b,c,d,e,j; 

    cout<<"Donnez votre année ";
    cin>>annee;

    a=annee%19;
    b=annee%4;
    c=annee%7;
    d=(19*a+24)%30;
    e=(2*b+4*c+6*d+5)%7;

    j=22+d+e;

    j=j-31;

    cout<<"Paque sera le "<<j<<" avril "<<annee;

}