#include<iostream>
using namespace std; 

int main(){

    int qf,r,p; 

    cout<<"Donnez vos revenues imposable : ";
    cin>>r;
    cout<<"Vous vivez a combien ? : ";
    cin>>p;

    qf=r/p;

    if (qf<=1077)
        
        cout<<"Vous avez 0 euros d'impot !";
    
    else if (qf<=27478)
        
        cout<<"Vous payerez"<<(r*0.11)-(1185.47*p)<<" d'impot.";

        else if (qf<=78570)
        
            cout<<"Vous payerez "<<r*0.30-6406*p<<" dimpot";

            else if (qf<=168994)

                cout<<"Vous payerez "<<r*0.41-15048.99*p<<" d'impot";

                else 

                    cout<<"payez"<<r*0.45-21808.75*p;
}