#include "types.h"
#include "DD.h"
#define OCCUPE 0
#define LIBRE 1

unsigned char TOS[SECT_SIZE];

void InitTOS();

int ChercherSecteurVideTOS();

int EspaceVide();

bool OccuperSecteur(int Indice);

bool LibererSecteur(int Indice);

bool SauvegarderTOS();

bool ChargerTOS();

int ValeurBitTOS(int Indice);

void ActiverBitTOS(int Indice);
