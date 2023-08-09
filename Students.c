#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "etudiant.h"
#define T 42
int main(){

   Etudiant etudiant[T];
	FILE* file=fopen("etudiant.csv","r");
	if(file==NULL){
		perror("etudiant.csv");
		exit(1);
	}
	FILE* file1=fopen("etudiantTrier.csv","w+");
	if(file1==NULL){
		perror("etudiantTrier.csv");
		exit(1);
	}
	//saisir(etudiant,file);
	recuperation1(file,etudiant);
	triage(etudiant);
	fputs("Nom\tPrénom(s)\tDate de naissance\n",file1);
	for(int i=1;i<etudiant->size;i++)
	fprintf(file1,"%s,%s,%d%c%d%c%d\n",etudiant[i].nom,etudiant[i].prenom,etudiant[i].date[0],'/',etudiant[i].date[1],'/',etudiant[i].date[2]);
	//fputs("Nom\tPrénom(s)\tDate de naissance\n",file);
	fclose(file);
	fclose(file1);
  return 0;
  }
