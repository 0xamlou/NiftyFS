/*
	-> On suppose que tous les enregistrements sont de même taille (SECT_SIZE) qu'un secteur du disque .
	-> Un disque est modélisé en un fichier situé dans le même repertoire que l'éxécutable de ce programme .
*/
#include "DD.h"

void strcpy_(char* A, char* B)
{
	while(*B)
		*(A++) = *(B++);
}

void ProbeHD(char* Name)
{
	printf("Probing disk %s..\n", Name);
	strcpy_(OurHD.Name, Name);
	OurHD.Handle = fopen(Name, "rb");
	fseek(OurHD.Handle, 0, SEEK_END);
	OurHD.Size = ftell(OurHD.Handle) / SECT_SIZE ;
	fclose(OurHD.Handle);
	printf("Probed disk %s (%d sectors)\n", OurHD.Name, OurHD.Size );
}

void MakeHD(char* Name, unsigned NSects)
{
	strcpy_(OurHD.Name, Name);
	OurHD.Size = NSects;
	OurHD.Handle = fopen(Name, "wb+");
	Sector Datum;
	int i = 0 ;
	while(i < SECT_SIZE)
		Datum.data[i++] = 0 ;
	i = 0;
	while(i++ < NSects)
		fwrite(&Datum, sizeof(Sector), 1, OurHD.Handle);

	fclose(OurHD.Handle);
}

bool WriteSector(int SectIndex, void* Data )
{
	if (SectIndex >= OurHD.Size)
		return ECHEC;
	OurHD.Handle = fopen(OurHD.Name, "r+");
	fseek (OurHD.Handle, SectIndex * SECT_SIZE, SEEK_SET);
	fwrite(Data, SECT_SIZE, 1,OurHD.Handle);
	fclose(OurHD.Handle);
	return SUCCES;
}

bool ReadSector(int SectIndex, void* Data)
{
	if (SectIndex >= OurHD.Size)
		return ECHEC;
	OurHD.Handle = fopen(OurHD.Name, "r+");
	fseek (OurHD.Handle, SectIndex * SECT_SIZE, SEEK_SET);
	fread(Data, SECT_SIZE, 1,OurHD.Handle);
	fclose(OurHD.Handle);
	return SUCCES;
}

void DisplayData(void* Data)
{
	
	void* Datend = Data + SECT_SIZE ;
	printf("DATA : ");
	for(; Data < Datend; Data++)
		printf("%.2x ",*((unsigned char*)Data));
	puts("");
}


