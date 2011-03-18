#include "types.h"
#define TAILLE_MAX_FICHIER 4
#define FIN_CARTE -1
typedef struct{
	unsigned char sect[TAILLE_MAX_FICHIER];
}CI;
void InitCI();
bool InsererIndiceSecteurCI(CI* Carte, int IndiceSecteur);
bool OterIndiceSecteurCI(CI* Carte, int IndiceConcerne);
bool ChargerCI(CI* Carte, int IndiceSecteur);
bool SauvegarderCI(CI* Carte, int IndiceSecteur);

