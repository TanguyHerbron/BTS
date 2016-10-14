/******************************************************
Fichier : semtools.h
Boite a outils pour manipuler des semaphores
******************************************************/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#ifndef _SEMTOOLS_H
#define _SEMTOOLS_H
// identifiant de semaphore
int id_sem;
// fixe la valeur du sempahore
int fixe_valeursem();
// supprime le semaphore
void supp_valeursem();
// modification de la valeur du semaphore de -1 (attente)
int P();
// modification de la valeur du semaphore de 1 (sem dispo)
int V();

#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
       /* l'union semun est d�finie par l'inclusion de <sys/sem.h> */
       #else
       /* d'apr�s X/OPEN il faut la d�finir nous-m�mes */
       union semun {
             int val;                  /* valeur pour SETVAL */
             struct semid_ds *buf;     /* buffer pour IPC_STAT, IPC_SET */
             unsigned short *array;    /* table  pour GETALL, SETALL */
                                       /* Sp�cificit� Linux : */
             struct seminfo *__buf;    /* buffer pour IPC_INFO */
       };
#endif
#endif