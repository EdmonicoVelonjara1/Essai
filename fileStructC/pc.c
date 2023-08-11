#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pc.h"

void triage(Pc *pc,const int NB_PC){
	for(int j=1;j<NB_PC;j++){
		for(int k=j;k<NB_PC;k++){
			if(strcmp(pc[j].etiq, pc[k].etiq)>0){
				Pc tmp=pc[j];
				pc[j]=pc[k];
				pc[k]=tmp;
			}
		}
	}
	printf("----------------------------------------------------------------------\n");
	for(int j=0;j<= NB_PC;j++){
		printf("%s %s %s \n",pc[j].etiq,pc[j].marque,pc[j].mac);
	}
}

void saisir(Pc *pc,FILE *file,const int NB_PC){
	fprintf(file,"Marque,Etiquette,Adresse MAC\n");
	for(int i=0;i<NB_PC;i++){
		if((i+1)<10){
			printf("Pour le pc n°0%d:\n",i+1);
		}
		else{
			printf("Pour le pc n°%d:\n",i+1);
		}
		printf("Entrez l'etiquette du pc:");scanf("%s",pc[i].etiq);
		printf("Entrez l'adrese MAC du pc:");scanf("%s",pc[i].mac);
		printf("Entrez le marque du pc:");scanf("%s",pc[i].marque);
		fprintf(file,"%s,%s,%s\n",pc[i].marque,pc[i].etiq,pc[i].mac);
	}
}

