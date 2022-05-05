#ifndef _LIVREDECOMPTE_H_
#define _LIVREDECOMPTE_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX_COMPTES 1000

#define SEM_KEY 369
#define PERM 0666
#define SHM_KEY 248

#endif