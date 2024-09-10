#include<iostream>
using namespace std;
int main(){
    int tgg,tg,tn,tp,nb,nb2;
    tgg=0;
    tg=0;
    tn=0;
    tp=0;
    nb2=1;
    while (nb2!=0){
        cout<<"Donnez le nombre de boites de disquette (multiple de 10) : ";
        cin>>nb;
        nb2=nb2-1;
        nb2=nb%10;
    }
    while (nb!=0){
    if(nb>=300){
        tgg=tgg+1;
        nb=nb-300;
    }else{
        if(nb>=100){
            tg=tg+1;
            nb=nb-100;
        }else{
            if (nb>=50){
                tn=tn+1;
                nb=nb-50;
            }else
                if (nb>=10){
                tp=tp+1;
                nb=nb-10;
                }           
        }}}
    cout<<"Expedition : ";
    if (tgg==1)
        cout<<"1 geant, ";
    if (tgg>1)
        cout<<tgg<<" geants, ";   
    if (tg==1)
        cout<<"1 grand, ";
    if (tg>1)
        cout<<tg<<" grands, "; 
    if (tn==1)
        cout<<"1 normal, ";
    if (tn>1)
        cout<<tn<<" normals, ";
    if (tp==1)
        cout<<"1 petite. ";
    if (tp>1)
        cout<<tp<<" petites. ";   
}       