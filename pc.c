#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pc.h"
#define T 27
int main(){
	char chaine[256];
	Pc pc[T];
	FILE* file=fopen("PC.csv","r");
	if(file==NULL){
		perror("PC.csv");
		exit(1);
	}
	FILE* fp=fopen("ordi.csv","w");
	if(fp==NULL){
		perror("ordi.csv");
		exit(1);
	}
	int i=0;

	while(i<T && fgets(chaine,255,file)){
		if(file){
			printf("%s",chaine);
			sscanf(chaine,"%[^,],%[^,],%[^,]",pc[i].marque,pc[i].etiq,pc[i].mac);
			i++;
		}
	}
//	saisir(pc,file);
	triage(pc);
	for(int j=0;j<T;j++){
		fprintf(fp,"%s,%s,%s",pc[j].marque,pc[j].etiq,pc[j].mac);
	}
	fclose(file);
	fclose(fp);
	return 0;
}

Pc *triage(Pc *pc){
	for(int j=1;j<T;j++){
		for(int k=j;k<T;k++){
			if(strcmp(pc[j].marque, pc[k].marque)>0){
				Pc tmp=pc[j];
				pc[j]=pc[k];
				pc[k]=tmp;
				
			}
		}
	}
	for(int j=0;j<T;j++){
		printf("%s\n",pc[j].etiq);
	}
	return pc;
}

Pc *saisir(Pc *pc,FILE *file){	
	fputs("Marque\tEtiquette\tAdresse MAC\n",file);
	for(int i=0;i<T;i++){
		if((i+1)<10){
			printf("Pour le pc n°0%d:\n",i+1);
		}
		else{
			printf("Pour le pc n°%d:\n",i+1);
		}	
		printf("Entrez l'etiquette du pc:");scanf("%s",pc[i].etiq);
		printf("Entrez l'adrese MAC du pc:");scanf("%s",pc[i].mac);
		printf("Entrez le marque du pc:");scanf("%s",pc[i].marque);
		fprintf(file,"%s\t%s\t%s\n",pc[i].marque,pc[i].etiq,pc[i].mac);
	}
	return pc;
}

