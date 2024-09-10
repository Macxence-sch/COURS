#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int nombre_alea(int maxi) {
    time_t t;
    t = time(&t);
    srand(t);
    return(rand()%maxi);
}


int main() {
    int nb,n,a,b;

    cout<<"On va jouer, donne un nopbre max :"<<endl;
    cin>>nb;

    a=nombre_alea(nb);

    while (b!=a){
        cout<<"Donne un nomrbe entre 0 et "<<nb<<endl;
        cin>>b;

        if(b<a)
            cout<<"Tu es en dessous"<<endl;
        if(b>a) 
            cout<<"Tu es au dessus"<<endl;
    }
    cout<<"GG tu as trouve";

}
