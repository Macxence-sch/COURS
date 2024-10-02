#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct chainon {
    int data;
    struct chainon* next;
} chainon_t;

typedef chainon_t* liste_t;

chainon_t * ajouter_chainon(int data, liste_t *l){
    chainon_t *a = malloc(sizeof(chainon_t));
    a->data = data;
    a->next = *l;
    *l = a;
}

chainon_t * affichierchainon(liste_t *l){
    chainon_t *a = *l;
    if (a->next == NULL){
        printf("%d ",a->data);
        return;
    }else{
        printf("%d ",a->data); 
        affichierchainon(a->next);
    }
}

int main(){
    
    int data = 19;
    liste_t l = NULL;

    ajouter_chainon(data,&l);
    affichierchainon(&l);


}


//Création d'un nouveau chainon 
//Initialisation de la valeur du chaînon à partir de la donnée fournie 
//initialisation du pointeur next vers le début de la liste de travail 
//mise a jour de la liste pour la faire pointer vers le nouveau chainon