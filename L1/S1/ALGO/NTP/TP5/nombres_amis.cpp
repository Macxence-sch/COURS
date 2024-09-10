#include<iostream>
using namespace std;

int diviseur(int a){
    int somme,i;
    somme=0;

    for (i=1; i = a; i++){
        if (a%i==0)
        somme=somme+i;
    }
    cout<<somme;
}

int main(){
    const int N = 500;
    int x,y,z,g,nb;
    int tab[N];

    cout<<"Donnez un nombre max : "<<endl;
    cin>>x;

    nb=0;

    for (g=1; g=x;g++){
        nb=nb+1;
        y=diviseur(g);
        tab[g]=y;
    }

    for (int z=1; z=nb; z++){
        cout<<tab[z];
    }
}