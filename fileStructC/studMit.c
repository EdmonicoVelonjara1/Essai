#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#define NB_ST 43

int main(){
	MitSt ms[NB_ST];
	int choix=0;
	printf("Tapez (1) pour éditer et (0) pour passer au triage\n ");
	scanf("%d",&choix);
if(choix==1){
	 FILE* pt=NULL;
        pt = fopen ("mit.csv","w");
        if(pt==NULL){
                perror("mit.csv");
        	exit(1);
	}
	fscanst(ms,pt,NB_ST);
	fclose(pt);
}
if(choix==0){
	printf("On va passer directement au triage!\n");
}
	FILE* fp=NULL;
	fp = fopen ("mit.csv","r");
	if(fp==NULL){
		perror("mit.csv");
		exit(1);
	}

	strecover(ms,fp,NB_ST);
	fclose(fp);
	insortst(ms,NB_ST);
	FILE* file = NULL;
        file = fopen ("mit2.csv","w");
        if(file == NULL){
                perror("mit2.csv");
                exit(1);
        }
	fmovest(ms,file,NB_ST);
	fclose(file);
	return 0;
}
