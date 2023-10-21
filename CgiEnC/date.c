#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

int nblinerecover(){
	FILE *f = fopen("/var/log/auth.log" , "r");
	int nb=0;
	//char *linerecover = (char*)malloc(sizeof(char)*600);
	while(!feof(f)){
		//fgets(linerecover,255,f);
		char s = fgetc(f);
        if(s=='\n')
        nb++;
	}
	fclose(f);
	return nb;
}
//La fonction qui génère le jour en Malagasy
void dayGenerate(char month[12][6],char *monthEnter,char days[7][20],int day,char *jour,int finMois[12],int sevenFirstDaysYear[7]){
    int annee = 2023;
    int numMonth = 0;
    int rangDay = 0;
    for(int i=0;i<12;i++){
        if(strcasecmp(monthEnter,*(month+i))==0){
            numMonth = i;
            break;
        }
    }
    for(int i=11;i>=0;i--){
        if(i>=numMonth){
            rangDay += finMois[i];
        }
    }
    rangDay = 365 - rangDay + day;
    rangDay %=7;
    for(int i=0;i<7;i++){
        if(rangDay==sevenFirstDaysYear[i]){
            strcpy(jour , *(days+i));
            break;
        }
    }
}

//Traduire le mois en Malgache
void translateMonthMalagasy(char *month,char tabMonth[12][6]){
    for(int i=0;i<12;i++){
        int comp = strcmp(month,*(tabMonth+i));
        if(comp==0){
            switch(i){
                case 0: strcpy(month,"Janoary");
                break;
                case 1: strcpy(month,"Febroary");
                break;
                case 2: strcpy(month,"Martsa");
                break;
                case 3: strcpy(month,"Aprily");
                break;
                case 4: strcpy(month,"Mey");
                break;
                case 5: strcpy(month,"Jona");
                break;
                case 6: strcpy(month,"Jolay");
                break;
                case 7: strcpy(month,"Aogositra");
                break;
                case 8: strcpy(month,"Septambra");
                break;
                case 9: strcpy(month,"Oktobra");
                break;
                case 10: strcpy(month,"Novambra");
                break;
                case 11: strcpy(month,"Desambra");
                break;   
            }
        }
    }
}

/*-----------------------------------------------------------------------------------------------------------------------*/

//La fonction principale

// int main(){
//     int dayEndMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//     int sevenFirstDaysYear[7] = {0,1,2,3,4,5,6};
//     char month[12][6]={"Jan","Feb","Mar","Apr","May","jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//     char days[7][20]={"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
//     char *day = (char*)malloc(sizeof(char)*20);
//     char *monthEnter = (char*)malloc(sizeof(char)*10);
//     int dayEnter = 0;

//     printf("Entrez le mois:");scanf("%s",monthEnter);
//     printf("Entrez le numero du jour:");scanf("%d",&dayEnter);
 
//     //Appel de la fonction récuperatrice du nombre de la fin du mois
//     int dernierJourMois = 0;
//     dayGenerate(month,monthEnter,days,dayEnter,day,dayEndMonths,sevenFirstDaysYear);

//     translateMonthMalagasy(monthEnter,month);
//     //printf("mois = %s %d \n",monthEnter,dernierJourMois);
//     printf("%s, %d %s 2023\n",day,dayEnter,monthEnter);
//     return 0;
// }
 