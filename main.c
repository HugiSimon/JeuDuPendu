#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 11

void longeurMot(int *, char[]);
void demanderMot(char[], char[]);
void ecrirePendu(int);
void ecrireMot(char[], char[]);
void lireLettre(int *, char[], char[]);
void comptageVie(int, int *, int *);

int main()
{
    char s_mot[MAX], c_lettre, s_mot2[MAX];
    int etat=0, n_vie=0, n_k=0;

    demanderMot(s_mot, s_mot2);

    while (etat == 0) {

        ecrirePendu(n_vie);

        ecrireMot(s_mot, s_mot2);

        lireLettre(&n_k, s_mot, s_mot2);

        comptageVie(n_k, &n_vie, &etat);
    }
    printf("Le mot etait %s \n", s_mot);
    return 0;
}

void longeurMot(int *n_i, char s_mot[MAX]){

    *n_i=strlen(s_mot);
}

void demanderMot(char s_mot[MAX], char s_mot2[MAX]){

    int n_i, n_j;

    do {
        printf("Ecrire un mot de pas de plus de %d caractere \n", MAX-1);
        scanf("%s", s_mot);
    }while (strlen(s_mot) > MAX-1);

    longeurMot(&n_i, s_mot);

    for (n_j=0;n_j < n_i;n_j++) {
        s_mot2[n_j] = s_mot[n_j];
    }
}

void ecrirePendu(int n_vie){

    system("cls");
    if(n_vie >= 3) {
        printf("______");
    }
    printf("\n");
    if(n_vie >= 2) {
        printf(" |");
        if(n_vie >= 4) {
            printf("    |");
        }
    }
    printf("\n");
    if(n_vie >= 2) {
        printf(" |");
        if (n_vie >= 5) {
            printf("    o");
        }
    }
    printf("\n");
    if(n_vie >= 2) {
        printf(" |");
        if(n_vie >= 6) {
            printf("   /");
            if(n_vie >= 7) {
                printf("|");
                if(n_vie >= 8) {
                    printf("\\");
                }
            }
        }
    }
    printf("\n");
    if(n_vie >= 2) {
        printf(" |");
        if(n_vie >= 9) {
            printf("   /");
            if(n_vie >= 10) {
                printf(" \\");
            }
        }
    }
    printf("\n");
    if(n_vie >= 1) {
        printf("_|_");
    }
    printf("\n\n");
}

void ecrireMot(char s_mot[MAX], char s_mot2[MAX]){

    int n_k, n_j, n_i;
    char c_lettre;

    longeurMot(&n_i, s_mot);

    n_k=0;
    for (n_j=0;n_j < n_i;n_j++) {
        c_lettre = s_mot2[n_j];
        if (c_lettre == '*') {
            printf("%c ", s_mot[n_j]);
        }else{
            printf("_ ");
            n_k++;
        }
    }
    if (n_k <= 0) {
        printf("\n\nBravo c'est gagne !!!\n");
        exit(0);
    }
}

void lireLettre(int *n_k, char s_mot[MAX], char s_mot2[MAX]){

    int n_j, n_i;
    char c_lettre;

    longeurMot(&n_i, s_mot);

    printf("\nDonne une lettre\n");
    scanf(" %c", &c_lettre);
    *n_k=0;
    for (n_j=0;n_j < n_i;n_j++) {
        if (c_lettre == s_mot2[n_j]) {
            s_mot2[n_j]='*';
            *n_k=1;
        }
    }
}

void comptageVie(int n_k, int *n_vie, int *etat){
    if (n_k == 0) {
        *n_vie=*n_vie+1;

        if (*n_vie == 11) {
            *etat=1;
        }
    }
}
