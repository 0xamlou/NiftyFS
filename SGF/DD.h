#define SECT_SIZE 16
void strcpy(char*, char*);
void MakeHD(char* Name, unsigned NSects);	//Cree un nouveau disque dur virtuel . Name est le nom du fichier, NSects le nombre de secteurs.
void WriteSector(int SectIndex, void* Data );	//Ecrit un enregistrement Data au secteur numero SectIndex . Data doit être de taille SECT_SIZE (en l'occurence 16)
void ReadSector(int SectIndex, void* Data);	//Antipode de WriteSector.Lit le secteur numéro SectIndex dans un enregistrement à l'adresse Data.
void ProbeHD(char* Name);	//Detecte un disque dur existant où Name est le nom du fichier disque .
void DisplayData(void* Data);	//Affiche le contenu d'un enregistrement .

typedef struct{
	char data[SECT_SIZE];
}Sector;

typedef struct{
	char Name[15];	//Déclaration du disque dur virtuel.
	FILE* Handle;
}HardDrive;

HardDrive OurHD;
