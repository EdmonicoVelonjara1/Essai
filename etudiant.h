
typedef struct Etudiant{
	char nom[100];
	char prenom[256];
	int date[3];
	int size;
}Etudiant;

Etudiant *saisir(Etudiant *et,FILE* file);
Etudiant *recuperation1(FILE *file,Etudiant *et);
Etudiant *triage(Etudiant *et);
