#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

void fscanst(MitSt *ms,FILE*pt,const int NB_ST){
	fprintf(pt,"Nom,Prénom(s),Date de naissance,Email,URL github,Mention\n");
	for(int i=0;i<NB_ST;i++){
		printf("Entrez nom d'un étudiant: ");
		scanf("%s",ms[i].name);
		printf("Entrez son prénom(s): ");
		getchar();
		fgets(ms[i].fName,49,stdin);
		ms[i].fName[strcspn(ms[i].fName,"\n")]='\0';

		printf("Entrez sa date se naissance: ");
		scanf("%s",ms[i].birth);
		printf("Entrez son adresse e-mail: ");
		scanf("%s",ms[i].eMail);
		printf("Son Url Github: ");
		scanf("%s",ms[i].urlGit);
		strcpy((ms+i)->mention,"MIT");
	}
	for(int i=0;i<=NB_ST;i++){
		fprintf(pt,"%s,%s,%s,%s,%s,%s\n",ms[i].name,ms[i].fName,ms[i].birth,ms[i].eMail,ms[i].urlGit,ms[i].mention);
	}
}

void strecover(MitSt *ms,FILE *fp,const int NB_ST){
	char strRecuperator[256];
	int i=0;
	while(i< NB_ST ){
		if(fp){
			if(!feof(fp))
				fgets(strRecuperator,255,fp);
		}
		sscanf(strRecuperator,"%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",ms[i].name,ms[i].fName,ms[i].birth,ms[i].eMail,ms[i].urlGit,ms[i].mention);
		i++;
	}
	for(int j=0;j<NB_ST;j++){
		 printf("%s %s %s %s %s %s\n",ms[j].name,ms[j].fName,ms[j].birth,ms[j].eMail,ms[j].urlGit,ms[j].mention);
	}
}
void desortst(MitSt *ms,const int NB_ST){
	 for(int i=1;i<NB_ST;i++){
                for(int j=1;j<NB_ST;j++){
                        if(strcmp(ms[i].name,ms[j].name)>0){
                                MitSt tmp = ms[i];
                                ms[i] = ms[j];
                                ms[j] = tmp;
                        }
                }
        }
        printf("------------------------------------------------------------------------------\n");
        for(int j=0;j<NB_ST;j++){
                printf("%s %s %s %s %s %s\n",ms[j].name,ms[j].fName,ms[j].birth,ms[j].eMail,ms[j].urlGit,ms[j].mention);
        }

}

void insortst(MitSt *ms,const int NB_ST){
	for(int i=1;i<NB_ST;i++){
		for(int j=1;j<NB_ST;j++){
			if(strcmp(ms[i].name,ms[j].name)<0){
				MitSt tmp = ms[i];
				ms[i] = ms[j];
				ms[j] = tmp;
			}
		}
	}
	printf("------------------------------------------------------------------------------\n");
	for(int j=0;j<NB_ST;j++){
                 printf("%s %s %s %s %s %s\n",ms[j].name,ms[j].fName,ms[j].birth,ms[j].eMail,ms[j].urlGit,ms[j].mention);
        }
}
void fmovest(MitSt *ms,FILE *file,const int NB_ST){
	for(int i=0;i<NB_ST;i++){
		  fprintf(file,"%s,%s,%s,%s,%s,%s\n",ms[i].name,ms[i].fName,ms[i].birth,ms[i].eMail,ms[i].urlGit,ms[i].mention);
        }
}
