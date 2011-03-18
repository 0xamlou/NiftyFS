#include "CI.h"
#include "DD.h"
void InitCI(CI* Carte)
{
	*(Carte->sect) = FIN_CARTE;
}

bool InsererIndiceSecteurCI(CI* Carte,int IndiceSecteur)
{
	int i = 0;
	while(Carte->sect[i] != FIN_CARTE && i < TAILLE_MAX_FICHIER)
		i++;	
	if(i < TAILLE_MAX_FICHIER)
	{
		Carte->sect[i++] = IndiceSecteur;
		if(i < TAILLE_MAX_FICHIER)
			Carte->sect[i] = FIN_CARTE;
		return SUCCES;
	}
	else
		return ECHEC;

}
bool OterIndiceSecteurCI(CI* Carte,int NumeroEnregistrement)
{
	int i = NumeroEnregistrement + 1 ;
	if(NumeroEnregistrement >= TAILLE_MAX_FICHIER)
		return ECHEC;
	
	while(i < TAILLE_MAX_FICHIER && Carte->sect[i] != FIN_CARTE)
	{
		Carte->sect[i-1] = Carte->sect[i];
		i++;
	}
	if(i-1 < TAILLE_MAX_FICHIER)
		Carte->sect[i-1] = FIN_CARTE;
	return SUCCES;
}

bool ChargerCI(CI* Carte, int IndiceSecteur)
{
	return ReadSector(IndiceSecteur, Carte);
}

bool SauvegarderCI(CI* Carte, int IndiceSecteur)
{
	return WriteSector(IndiceSecteur, Carte);
}


