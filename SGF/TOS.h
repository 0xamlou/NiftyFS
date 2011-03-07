#include "types.h"
#define OCCUPE 0
#define LIBRE 1
#define TAILLE_DD 50
#define EMPLACEMENT_TOS 2

char TOS[TAILLE_DD];

void InitTOS();

int ChercheSecteurVideTOS();

int EspaceVide();

bool OccuperSecteur(int Indice);

bool LibererSecteur(int Indice);

bool SauvegarderTOS();

bool ChargerTOS();
