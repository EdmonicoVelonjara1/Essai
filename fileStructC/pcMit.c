
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pc.h"
#define NB_PC 27

int main(){
	int choix=0;
	printf("Le fichier est déja édité: Tapez (1) si Oui sinon (0) ");
	scanf("%d",&choix);

	char chaine[256];
	Pc pc[NB_PC];
if(choix==1){
	FILE* file=fopen("pc.csv","w");
	if(file==NULL){
		perror("pc.csv");
		exit(1);
	}
    	saisir(pc,file,NB_PC);
	fclose(file);
}
if(choix==0){
	printf("Donc le fichier est déjà édité!");
}
	 FILE* pt=fopen("pc.csv","r");
        if(pt == NULL){
                perror("pc.csv");
                exit(1);
        }

	int i=0;
	while(i<= NB_PC ){
		fgets(chaine,255,pt);
		if(pt){
			printf("%s\n",chaine);
			sscanf(chaine,"%[^,],%[^,],%s",pc[i].marque,pc[i].etiq,pc[i].mac);
			i++;
		}
	}
	fclose(pt);

	FILE* fp=fopen("ordi.csv","w");
        if(fp==NULL){
                perror("ordi.csv");
                exit(1);
        }

	triage(pc,NB_PC);
	for(int j=0;j<= NB_PC;j++){
		fprintf(fp,"%s,%s,%s\n",pc[j].marque,pc[j].etiq,pc[j].mac);
	}
	fclose(fp);
	return 0;
}
