#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdbool.h>

int* rand_array(int size) {
    
    int* tabb = (int*) malloc(size * sizeof(int));
    assert(tabb != NULL); 

    
    for (int i = 0; i < size; i++) {
        tabb[i] = rand() % 16;
    }
   
    return tabb; 
}

void display_array(int *tab, int size){


    for (int i = 0; i < size; i++) {
        printf("%d  ", tab[i]);
    }
    printf("\n");
    return;
}

void retourner_tableau(int *tab, int size){
    int temp;

    for (int i=0; i <= size/2 ; i++){
        temp=tab[i];
        tab[i]=tab[size-i-1];
        tab[size-i-1]=temp;
    }
    return;
}


void zero_droite(int *tab, int size){       //CODE PROF
    int p1 = 0;
    int p2 = size-1;

    while ((p1 < p2) && (p1 < size)){
        while ((p2 >= p1) && (tab[p2] == 0)){
         p2--;
    }

    if (tab[p1]== 0){

        tab[p1] = tab[p2];
        tab[p2] = 0;
    }
    p1++;
    }
}

/*void zero_droite(int *tab, int size){
    int a=size-1;
    int i=0;
    while (i<a){
        if (tab[i]==0){
            tab[i]=tab[a];          MON CODE 
            tab[a]=0; 
            a=a-1;        
        }
        i=i+1;
    }
    return;
}*/

void separer_pairs_impairs(int *tab, int size){
    int droite = size-1;
    int gauche = 0;
    int temp;

    while(gauche<=droite){
        
        while (tab[droite] %2 != 0)
        {
        droite = droite -1;
        }
        while (tab[gauche] % 2 == 0)
        {
        gauche = gauche +1;
        }
        
        temp=tab[droite];
        tab[droite]=tab[gauche];
        tab[gauche]=temp;
    }

}

void trie_insertion(int *tab, int size){
    
    for (int i=0; i<=size-1; i++){
        int x = tab[i];
        int j=i;
        while (j>0 && tab[j-1]>x){
            tab[j] = tab[j-1];
            j=j-1;

        }
        tab[j]=x;
    }
}

void trouverlevingt(int *tab,int size){
    int a=0;
    int b=1;
    int bol = 0;
    while (bol==0 && a<size-1){
        
        if (tab[size-b]+tab[a]==20){
            bol=1;
            printf(" %d pos : %d\n",tab[size-b],size-b);
            printf(" %d pos : %d\n",tab[a],a);
        }
        else {
            if (tab[size-b]+tab[a]>20){
                b = b +1;
            }else {
                a = a +1;
                }
        
        }
    }


}






/*void trouverlevingt(int *tab,int size){
    int temp;
    int trouve;
    int j;
    

    int i=size-1;
    while (i<0 || trouve !=1){
        
    temp=tab[i];                                    //CODE QUI FONCTIONNE 
                                                    MAIS QUI EN DEMANDE TROp
    j=size-1;
        while ((temp + tab[j]!=20) || (j<0)){
            j=j-1;
            if (temp + tab[j]==20){
            trouve = 1;
        }
    }
    i=i-1;
    
    }
    if (trouve == 1){
        printf("\n Premier element : %d en position : %d",temp,i+1);
        printf("\n Deuxieme element : %d en position : %d",tab[j],j);
    }else{
        printf("\nIl n'y a pas d'elements qui font 20 ");
    }
}*/


int main() {
    srand(time(NULL)); 
    int size = 16;
   
    int* tab = rand_array(size);
    printf("\nTableau de base : \n");
    display_array(tab,size);
    retourner_tableau(tab,size);
    printf("\nTableau retourner : \n");
    display_array(tab,size);
    zero_droite(tab,size);
    printf("\nLes 0 à droite : \n");
    display_array(tab,size);
    separer_pairs_impairs(tab,size);
    printf("\nSeparer pair (gauche) et impair (droite) : \n");
    display_array(tab,size);
    trie_insertion(tab,size);
    printf("\nTrie par insertion :\n");
    display_array(tab,size);
    trouverlevingt(tab,size);
   


    free(tab);
   
    return 0;
}