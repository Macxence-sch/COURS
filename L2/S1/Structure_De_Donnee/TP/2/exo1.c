#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NBRMAX 100

int main(){
    bool t[NBRMAX + 1];
    for (int i=0; i<= NBRMAX; i++) {t[i]=true;}
    

    int k = 1;
    while (true){
        
        while (k < NBRMAX){
            k++;
            if (t[k]) break;
        }

        if (k==NBRMAX) break;

        int d = 1;
        int c = 1;

        while (d <= NBRMAX){
            if (t[d]){
                c++;
                if (c%k==0) {t[d]=false;}
            }
            d++;
        }
    }

    for (int i = 0; i < NBRMAX; i++)
    {
        if (t[i]==false){
            printf("%d ",i);
        }
    }
    
}