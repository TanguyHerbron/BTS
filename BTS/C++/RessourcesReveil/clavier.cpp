/**************************************************************************
   Classe Clavier
   Auteur : Philippe CRUCHET - Janvier 2015
   R�le   : Permet de g�rer les touches du clavier de l'horloge.

   Projet : horloge
   IDE    : Code::Blocks sous linux utilisation de termios
 *************************************************************************/

#include "clavier.h"

Clavier::Clavier()
/*
 *	R�le : Initialisation du clavier
 */
{
    tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_lflag &= ~ISIG;
    new_settings.c_oflag &= ~NL0;
    new_settings.c_oflag &= ~CR0;
    new_settings.c_oflag &= ~TAB0;
    new_settings.c_oflag &=~BS0;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    cfsetospeed (&new_settings, B230400);
    cfsetispeed(&new_settings, 0);
    tcsetattr(0, TCSANOW, &new_settings);
}


Clavier::~Clavier()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}

char Clavier::kbhit()
/*
 *	R�le : Lit si une touche est enfonc�e
 *         Fonction non bloquante.
 *
 * Param�tre de retour 0 si aucune touche n'est enfonc�e,
 *                     sinon le code de la touche.
 */
{
    char ch = 0;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0,TCSANOW, &new_settings);
    read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0,TCSANOW, &new_settings);
    return ch;
}

TOUCHES_CLAVIER Clavier::ScruterClavier()
{
    char touche = kbhit();
    TOUCHES_CLAVIER retour;
    switch (touche)
    {
        case '\n':
        case '\r': retour = FIN ;
            break;
        case ' ' : retour = MODE ;
            break;
        case '+' : retour = PLUS ;
            break;
        case '-' : retour = MOINS ;
            break;
        default : retour = AUCUNE ;
    }

    return retour ;
}
