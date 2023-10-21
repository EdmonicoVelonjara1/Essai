#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

typedef struct {
	
	char* month ;
	char *jour ;
	char *hours;
	char *session ;
	char* other ;
	int day;

}Log;


int main(){
	char *url = (char*)malloc(sizeof(char)*20);
	url = getenv("QUERY_STRING");
	char *recUser = NULL;
    int page=0;

	recUser= (char*)malloc(sizeof(char)*20);
	
	Log msg[100];
    char tabMonth[12][6]={"Jan","Feb","Mar","Apr","Mey","jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char days[7][20]={"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
	//char user[100][20];
	char *linerecover = (char*)malloc(sizeof(char)*256);
	
	printf("Content-type: text/html\n\n");
	printf("<head><meta charset=\"UTF-8\"><title>log2Auth</title>\n");
	printf("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">");
	printf("<link rel=\"stylesheet\" href=\"http://gasyzoo.mg/style/styles.css\" />");
	printf("</head>\n");
	printf("<html><body><header>");
	/*---------------------------------------------------------------------------------------------*/
	for(int i=0;i<100;i++){
		msg[i].month = (char*)malloc(sizeof(char)*20);
		msg[i].jour = (char*)malloc(sizeof(char)*25);
		msg[i].hours = (char*)malloc(sizeof(char)*20);
		msg[i].session = (char*)malloc(sizeof(char)*40);
		msg[i].other = (char*)malloc(sizeof(char)*155);
		msg[i].day;
	}
	
	int compt=0;
	int lineBeginRecover = nblinerecover();
    int dayEndMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sevenFirstDaysYear[7] = {0,1,2,3,4,5,6};
	int k=page*10;
	int l=(page*10)+10;
	sscanf(url,"user=%[^&\n]",recUser,&page);

	char *p=strstr(url, "page=");
	if(p!=NULL ){
		printf("<p>Mandeha</p>");
		sscanf(p, "page=%d", &page);
		printf("<p>page=%d</p>", page);
	}

/*-----------------------------------------------------------------------------------------------------------------------*/	
	
	
	printf("<section>"); 
	for(int i=0;i<10;i++){
        printf("<a href=\"http://gasyzoo.mg/cgi-bin/log2.cgi?user=%s&page=%d\"><button>%d</button></a>",msg[i].other,i,i+1);
	}
	printf("</section>");
	printf("<form action=\"/cgi-bin/log2.cgi\" method=\"get\"><input type=\"text\" name=\"user\"><input type=\"submit\" value=\"search\"><input type=\"submit\" value=\"Retour\"></form>");
	printf("</header>");
	printf("<h2>Les 100 dernieres Authentification réussites \nLes page=%d</h2>", page);
	printf("<center><table border = \"1\">"); 
	printf("<tr><thead><th>Temps</th>");
	printf("<th>Session d'Ouverture/Fermeture</th>"); 
	printf("<th>Utilisateur</th></thead></tr>");
 
/* -------------------------------------------------------------------------------------------------------------------- */
	
	FILE *file = fopen("/var/log/auth.log" , "r");
	while(!feof(file)){
		int i=0;
		
		fgets(linerecover,255,file);
		compt++;
		
		if(strstr(linerecover,"opened")!=NULL || strstr(linerecover,"closed")!=NULL){
			sscanf(linerecover,"%[^ ] %d %[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %[^ ] %*[^ ] %*[^ ] %[^ ] ",msg[i].month,&msg[i].day,msg[i].hours,msg[i].session,msg[i].other);
		}
		if(compt>lineBeginRecover){
			
			if(strcmp(recUser,msg[i].other)==0 || *recUser==0 ){
				
				printf("<tbody>");
				//if(strstr(msg[i].session,"opened")!=NULL){
					dayGenerate(tabMonth,msg[i].month,days,msg[i].day,msg[i].jour,dayEndMonths,sevenFirstDaysYear);
					translateMonthMalagasy(msg[i].month,tabMonth);
					printf("<tr><td>%d Miditra</td><td>%d Miditra</td><td>%d Miditra</td></tr>",l,k,i);
					if(k<l){
						/* printf("<tr><td>Miditra</td><td>Miditra</td><td>Miditra</td></tr>"); */
						printf("<tr style=\"background:teal;\">");
                    	printf("<td>%s, %d %s %s</td>",msg[i].jour,msg[i].day,msg[i].month,msg[i].hours);
						printf("<td>%s</td>",msg[i].session);
						printf("<td><a href=\"/cgi-bin/log2.cgi?user=%s\">%s </a></td></tr>",msg[i].other,msg[i].other);	
					}
					k++;
				//}
/* 
				if(strstr(msg[i].session,"closed")!=NULL){
					dayGenerate(tabMonth,msg[i].month,days,msg[i].day,msg[i].jour,dayEndMonths,sevenFirstDaysYear);
					translateMonthMalagasy(msg[i].month,tabMonth);
				if(i<=page*10 +10 && i>=page*10){	
					printf("<tr style=\"background:green;\" id=\"ligne%d\"><td>%s, %d %s %s</td>",l,msg[i].jour,msg[i].day,msg[i].month,msg[i].hours);
					printf("<td>%s</td>",msg[i].session);
					printf("<td><a href=\"/cgi-bin/log2.cgi?user=%s\">%s k=%d</a></td></tr>",msg[i].other,msg[i].other,k+1);
				}
					i++;
				} */
			}
			printf("</tbody>");	
		}i++;
	}
	printf("</table></center></body></html>\n"); 
	fclose(file);
	for(int i=0;i<100;i++){
		free(msg[i].month);free(msg[i].jour);free(msg[i].other);free(msg[i].hours);free(msg[i].session);
	}
	free(linerecover);
	return 0;
}
