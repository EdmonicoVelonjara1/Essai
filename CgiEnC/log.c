#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date.h"

typedef struct Log{	
	char month[30] ;
	char jour[16] ;
	char hours[40];
	char session[26] ;
	char other[50] ;
	int day;
}Log;

int main(){
	char *url = (char*)malloc(sizeof(char)*60);
	url = getenv("QUERY_STRING");
	char *recUser = NULL;
	recUser= (char*)malloc(sizeof(char)*20);	
	Log* msg = malloc(100*sizeof(Log));
    char tabMonth[12][6]={"Jan","Feb","Mar","Apr","Mey","jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    char days[7][20]={"Sabotsy","Alahady","Alatsinainy","Talata","Alarobia","Alakamisy","Zoma"};
	char *linerecover = (char*)malloc(sizeof(char)*256);
	int compt=0;
    int dayEndMonths[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sevenFirstDaysYear[7] = {0,1,2,3,4,5,6};
	int tab[100];
	sscanf(url,"user=%s",recUser);
/*-----------------------------------------------------------------------------------------------------------------------*/	
	printf("Content-type: text/html\n\n"
			"<html>"
			"<head>"
				"<meta charset=\"UTF-8\">"
				"<title>LogAuth</title>"
			"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"
			"<link rel=\"stylesheet\" href=\"http://gasyzoo.mg/style/styles.css\" />"
			"</head>"
			"<body>"
			"<header>"
				"<a href=/cgi-bin/message.cgi style=\"color:blue;\">QUITTER</a>"
				"<form action=\"/cgi-bin/log.cgi\" method=\"get\">"
					"<input type=\"text\" name=\"user\">"
					"<input type=\"submit\" value=\"search\">"
					"<input type=\"submit\" value=\"Retour\">"
				"</form>"
			"</header>"
			"<h2>Les 100 dernieres Authentification réussites</h2>"
			"<center>"
				"<table border = \"1\">"
				"<tr>"
					"<thead>"
						"<th>Temps</th>"
						"<th>Session d'Ouverture/Fermeture</th>"
						"<th>Utilisateur</th>"
					"</thead>"
				"</tr>");

/* -------------------------------------------------------------------------------------------------------------------- */
	FILE *file = fopen("/var/log/auth.log.1" , "r");
	int i=0;
	while(!feof(file)){
		fgets(linerecover,255,file);
		compt++;
		
		if(strstr(linerecover,"opened")!=NULL || strstr(linerecover,"closed")!=NULL){
			sscanf(linerecover,"%[^ ] %d %[^ ] %*[^ ] %*[^ ] %*[^ ] %*[^ ] %[^ ] %*[^ ] %*[^ ] %[^ ] %*[^\n ]",msg[i].month,&msg[i].day,msg[i].hours,msg[i].session,msg[i].other);
		}
		if(strcmp(recUser,msg[i].other)==0 || *recUser==0 ){	
			if(strstr(msg[i].session,"opened")!=NULL || strstr(msg[i].session,"closed")!=NULL ){
			 	dayGenerate(tabMonth,msg[i].month,days,msg[i].day,msg[i].jour,dayEndMonths,sevenFirstDaysYear);
				translateMonthMalagasy(msg[i].month,tabMonth);
				printf("<tr style=\"background:teal;\"><td>%d %s, %d %s %s</td>",i,msg[i].jour,msg[i].day,msg[i].month,msg[i].hours);
				printf("<td>%s</td>",msg[i].session);
				printf("<td><a href=\"/cgi-bin/log.cgi?user=%s\">%s</a></td></tr>",msg[i].other,msg[i].other);	
				i++;
			}
		}		
	}
	printf("</table></center>"); 
	printf("</body></html>\n");
	fclose(file);
	for(int i=0;i<100;i++){
	 	free(msg[i].month);free(msg[i].jour);free(msg[i].other);free(msg[i].hours);free(msg[i].session);
	}
	free(linerecover); 		
	return 0;
}
