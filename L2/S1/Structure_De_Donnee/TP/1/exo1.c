#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

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

void zero_droite(int *tab, int size){
    int a=size-1;
    int i=0;
    while (i<a){
        if (tab[i]==0){
            tab[i]=tab[a];
            tab[a]=0; 
            a=a-1;        
        }
        i=i+1;
    }
    return;
}

void separer_pairs_impairs(int *tab, int size){
    int droite = size -1;
    int gauche = 0;
    int temp;

    while(gauche<droite+1){
        
        while (tab[droite] %2 != 0)
        {
        droite = droite -1;
        }
        while (tab[gauche] % 2 == 0)
        {
        gauche = gauche+1;
        }
        
        temp=tab[droite];
        tab[droite]=tab[gauche];
        tab[gauche]=temp;
    }

}


int main() {
    srand(time(NULL)); 
    int size = 15;
   
    int* tab = rand_array(size);
    display_array(tab,size);
    retourner_tableau(tab,size);
    display_array(tab,size);
    zero_droite(tab,size);
    display_array(tab,size);
    separer_pairs_impairs(tab,size);
    display_array(tab,size);

    free(tab);
   
    return 0;
}