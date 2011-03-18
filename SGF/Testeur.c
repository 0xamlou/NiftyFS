#include <stdio.h>
#include "DD.h"
#include "TOS.h"
#include "CI.h"
main()
{
//	MakeHD("one.hd", 5);
	ProbeHD("one.hd");
	char datum[16], rep = 1 ;
	int N;
	CI Carte;
	InitCI(&Carte);SauvegarderCI(&Carte, 0);
	DisplayData(&Carte);
	while(rep)
	{
		ChargerCI(&Carte, 0);
		scanf("%d", &rep);
		if(rep == 1)
		{
			
			scanf("%d", &N);
			InsererIndiceSecteurCI(&Carte, N);
			DisplayData(&Carte);
			
		}
		else if(rep == 2)
		{
			scanf("%d", &N);
			OterIndiceSecteurCI(&Carte, N);
			DisplayData(&Carte);
		}
		SauvegarderCI(&Carte, 0);
	}




/*while(rep)
	{
		printf("Vous voulez:\n1.Lire Secteur\n2.Ecrire Secteur\n");
		scanf("%d", &rep);
		if(rep == 1)
		{
			printf("Entrez le numéro du secteur\n");
			scanf("%d", &NumSect);
			ReadSector(NumSect, datum);
			DisplayData(datum);
		}
		else if (rep == 2)
		{
			printf("Entrez enregistrement: ");
			scanf("%s", datum);
			printf("Entrez le numéro du secteur\n");
			scanf("%d", &NumSect);
			WriteSector(NumSect, datum);
			DisplayData(datum);
		}
	}	
*/
//	ReadSector(0, datum);
//	DisplayData(datum);
//	char String[16] = "Calypsus";
//	WriteSector(3, String);
}


