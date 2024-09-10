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

int main(){
    int d,c,b,a,z;
    float ptt;
    ptt=0;
    b=0;
    z=0;


    while (z!=20){
        a=nombre_alea(10);
        b=nombre_alea(10);
        d=a*b;
        cout<<"Que font "<<a<<" x "<<b<<" ? : "<<endl;
        cin>>c;

        if (c==d){
            cout<<"bien joué, du premier coup !! "<<endl;
            ptt=ptt+1;
            z=z+1;
        }
        else{   
            cout<<"Dexieme chances, que font "<<a<<" x "<<b<<" ? : "<<endl;
            cin>>c;
            if (c==d){
                cout<<"bien joué, du deuxieme coup !! "<<endl;
                ptt=ptt+0.50;
                z=z+1;
            }
            else{    
                cout<<"Troisieme chances, que font "<<a<<" x "<<b<<" ? : "<<endl;
                cin>>c;
               
                if (c==d){
                    cout<<"bien joué, du troisieme coups !! "<<endl;
                    ptt=ptt+0.25;
                    z=z+1;
                }
                 else    
                    cout<<"Dommage, tu n'as pas trouvé, cela fait "<<d<<endl;
            }
        }   
    }
    cout<<"C'est fini"<<endl;
    cout<<"Tu as "<<ptt<<" points";
}