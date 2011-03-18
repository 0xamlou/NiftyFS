#include "TOS.h"
#include "DD.h"

void InitTOS()
{
	int i ;
	for(i = 0 ;  i < OurHD.Size; i++)
		TOS[i] = LIBRE;
}

int ChercherSecteurVideTOS()
{
	int i = 0 ;
	while(TOS[i++] == OCCUPE);
	
	return i - 1 ;
}

int EspaceVide()
{
	int i = 0, EspaceV = 0 ;
	for(; i < OurHD.Size; i++ )
		if ( TOS[i] == LIBRE) EspaceV++;
		
	return EspaceV;
}

bool OccuperSecteur(int Indice)
{
	if (Indice >= OurHD.Size)
		return ECHEC;
	else
		TOS[Indice] = OCCUPE;
}

bool LibererSecteur(int Indice)
{
	if (Indice >= OurHD.Size)
		return ECHEC;
	else
		TOS[Indice] = LIBRE;
}

bool ChargerTOS()
{
	return ReadSector(OurHD.Size - 1, &TOS);
}

bool SauvegarderTOS()
{
	return WriteSector(OurHD.Size - 1, &TOS);
}

