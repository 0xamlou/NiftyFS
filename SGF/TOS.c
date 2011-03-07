#include "TOS.h"
void InitTOS()
{
	int i ;
	for(i = 0 ;  i < TAILLE_DD; i++)
		TOS[i] = LIBRE;
}


int ChercheSecteurVideTOS()
{
	int i = 0 ;
	while(TOS[i++] == OCCUPE);
	
	return i - 1 ;
}


int EspaceVide()
{
	int i = 0, EspaceV = 0 ;
	for(; i < TAILLE_DD; i++ )
		if ( TOS[i] == LIBRE) EspaceV++;
		
	return EspaceV;
}

int OccuperSecteur(int Indice)
{
	if (Indice >= TAILLE_DD)
		return ECHEC;
	else
		TOS[Indice] = OCCUPE;
}

int LibererSecteur(int Indice)
{
	if (Indice >= TAILLE_DD)
		return ECHEC;
	else
		TOS[Indice] = LIBRE;
}

bool SauvegarderTOS()
{
	EcrireSecteur(void* Enregistrement)
}

bool ChargerTOS()
{
}

