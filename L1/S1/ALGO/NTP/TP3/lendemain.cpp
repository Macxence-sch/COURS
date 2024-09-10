#include<iostream>
using namespace std; 

int main(){
    int annee,j,mois;
   


    cout<<"Donne ton mois en nombre : ";
    cin>>mois;
    cout<<"Donne ton jours en nombre : ";
    cin>>j;
    cout<<"Donne ton annee : ";
    cin>>annee;

    switch (mois)
    {
    case 1:
        if (j==31)
            cout<<"Demain il sera le 1 fevrier "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" janvier "<<annee;
        break;
    case 2:
        if (annee%4){
            if (annee%100){
                 if (j==28)
                     cout<<"Demain il sera le 1 mars "<<annee;
                else 
                    cout<<"Demain il sera le "<<j+1<<" fevrier "<<annee;
            }else{ 
                if (j==29)
                     cout<<"Demain il sera le 1 mars "<<annee;
                else 
                    cout<<"Demain il sera le "<<j+1<<" fevrier "<<annee;
            }
        }else{     
            if (j==28)
                     cout<<"Demain il sera le 1 mars "<<annee;
                else 
                    cout<<"Demain il sera le "<<j+1<<" fevrier "<<annee;
        }
        break;
    case 3:
        if (j==31)
            cout<<"Demain il sera le 1 avril "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" mars "<<annee;
        break;
    case 4:
        if (j==30)
            cout<<"Demain il sera le 1 mmai "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" avril "<<annee;
        break;
    case 5:
        if (j==31)
            cout<<"Demain il sera le 1 juin "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" mai "<<annee;
        break;
    case 6:
        if (j==30)
            cout<<"Demain il sera le 1 juillet "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" juin "<<annee;
        break;
    case 7:
        if (j==31)
            cout<<"Demain il sera le 1 aout "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" juillet "<<annee;
        break;
    case 8:
        if (j==31)
            cout<<"Demain il sera le 1 septembre "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" aout "<<annee;
        break;
    case 9:
        if (j==30)
            cout<<"Demain il sera le 1 octobre "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" septembre "<<annee;
        break;
    case 10:
        if (j==31)
            cout<<"Demain il sera le 1 novembre "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" octobre "<<annee;
        break;
    case 11:
        if (j==30)
            cout<<"Demain il sera le 1 decembre "<<annee;
        else 
            cout<<"Demain il sera le "<<j+1<<" novembre "<<annee;
        break;
    case 12:
        if (j==31)
            cout<<"Demain il sera le 1 janvier"<<annee+1;
        else 
            cout<<"Demain il sera le "<<j+1<<" decembre "<<annee;
        
    }
}