#include <stdio.h>
#include <stdlib.h>

int main()
{
    char note;

    printf("Entrer la note en minuscule:");
    scanf("%c", &note);
    switch (note){
    case 'a':
        printf("Votre note est entre 16 et 20.\n");
    break;
    case 'b':
        printf("Votre note est entre 12 et 16.\n");
    break;
    case 'c':
        printf("Votre note est entre 8 et 12.\n");
    break;
    case 'd':
        printf("Votre note est entre 4 et 8.\n");
    break;
    case 'e':
        printf("Votre note est entre 0 et 4.\n");
    break;
    default:
        printf("Vous n'avez pas entrer de valeur correcte.\n");
    }

}
