/*
	-> On suppose que tous les enregistrements sont de même taille (SECT_SIZE) qu'un secteur du disque .
	-> Un disque est modélisé en un fichier situé dans le même repertoire que l'éxécutable de ce programme .
*/

#include <stdio.h>
#include "DD.h"

void strcpy(char* A, char* B)
{
	while(*B)
		*(A++) = *(B++); 
}

void ProbeHD(char* Name)
{
	int i = 0 ;
	strcpy(OurHD.Name, Name);
}

void MakeHD(char* Name, unsigned NSects)
{
	strcpy(OurHD.Name, Name);
	OurHD.Handle = fopen(Name, "wb+");
	Sector Datum ;
	int i = 0 ;
	while(i < SECT_SIZE)
		Datum.data[i++] = 0 ;
	i = 0;
	while(i++ < NSects)
		fwrite(&Datum, sizeof(Sector), 1, OurHD.Handle);

	fclose(OurHD.Handle);
}

void WriteSector(int SectIndex, void* Data )
{
	OurHD.Handle = fopen(OurHD.Name, "r+");
	fseek (OurHD.Handle, SectIndex * SECT_SIZE, SEEK_SET);
	fwrite(Data, SECT_SIZE, 1,OurHD.Handle);
	fclose(OurHD.Handle);
}

void ReadSector(int SectIndex, void* Data)
{
	OurHD.Handle = fopen(OurHD.Name, "r+");
	fseek (OurHD.Handle, SectIndex * SECT_SIZE, SEEK_SET);
	fread(Data, SECT_SIZE, 1,OurHD.Handle);
	fclose(OurHD.Handle);
}

void DisplayData(void* Data)
{
	
	void* Datend = Data + SECT_SIZE ;
	printf("DATA : ");
	for(; Data < Datend; Data++)
		printf("%.2x ",*((char*)Data));
	puts("");
}


