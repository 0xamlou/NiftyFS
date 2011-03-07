/*
	-> On suppose que tous les enregistrements sont de même taille (SECT_SIZE) qu'un secteur du disque .
	-> Un disque est modélisé en un fichier situé dans le même repertoire que l'éxécutable de ce programme .
*/

#include <stdio.h>
#include "DD.h"
#define SECT_SIZE 16


void ProbeHD(char* Name)
{
	NewHD = fopen(Name, "r+b");
}

void MakeHD(char* Name, unsigned NSects)
{
	NewHD = fopen(Name, "wb+");
	int i = 0 ;
	Sector Datum ;
	while(i++ < NSects)
		fwrite(&Datum, sizeof(Sector), 1, NewHD);
}

void WriteSector(int SectIndex, void* Data )
{
	fseek (NewHD, SectIndex * SECT_SIZE, SEEK_SET);
	fwrite(Data, SECT_SIZE, 1,NewHD);
}

void ReadSector(int SectIndex, void* Data)
{
	fseek (NewHD, SectIndex * SECT_SIZE, SEEK_SET);
	fread(Data, SECT_SIZE, 1,NewHD);
}

void DisplayData(void* Data)
{
	
	void* Datend = Data + SECT_SIZE ;
	printf("DATA : ");
	for(; Data < Datend; Data++)
		printf("%.2x ",*((char*)Data));
	puts("");
}


