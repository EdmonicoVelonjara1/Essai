#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char tmp[256];
    char tmp1[60];
    char tmp2[60];
    char *nomLoginFile = (char*)malloc(sizeof(char)*30);
    nomLoginFile = "/var/www/html/cgi-bin/logina.txt";
    char *inscription = NULL;
    char *connection = NULL;
    char *pseudo_inscription = NULL;
    char *password_inscription = NULL;
    inscription = (char*)malloc(sizeof(char)*200);
    pseudo_inscription = (char*)malloc(sizeof(char)*60);
    password_inscription = (char*)malloc(sizeof(char)*60);
    char *connect_pseudo = NULL;
    char *connect_password = NULL;
    connection = (char*)malloc(sizeof(char)*200);
    connect_pseudo = (char*)malloc(sizeof(char)*60);
    connect_password = (char*)malloc(sizeof(char)*60);
    inscription = getenv("QUERY_STRING");
    sscanf(inscription,"identifiant=%[^&]&motdepasse=%[^&]&%*[^\n]\n",pseudo_inscription,password_inscription);
    connection = getenv("QUERY_STRING");
    sscanf(connection,"nom=%[^&]&password=%[^&]&%*[^\n]\n",connect_pseudo,connect_password);

    FILE *pt1 = NULL;
    pt1 = fopen(nomLoginFile,"a+");

    if(inscription!=NULL){// && strcmp(pseudo_inscription,"\0")!=0 && pseudo_inscription!=NULL && connection==NULL){
        fprintf(pt1,"%s:%s\n",pseudo_inscription,password_inscription);
        printf("Location: http://gasyzoo.mg/cgi-bin/message.cgi\n\n");
    }

    rewind(pt1);

if(connection!=NULL)
    while(!feof(pt1)){
        fgets(tmp,255,pt1);
        sscanf(tmp,"%[^:]:%[^\n]\n",tmp1,tmp2);
        if(strcmp(tmp1,connect_pseudo)==0 && strcmp(tmp2,connect_password)==0){
             printf("Location: http://gasyzoo.mg/cgi-bin/message.cgi\n\n");
             break;
        }
        else if(strcmp(tmp1,connect_pseudo)!=0 && strcmp(tmp2,connect_password)==0){
             printf("Location: http://gasyzoo.mg/iderror.html\n\n");
        }
        else if(strcmp(tmp1,connect_pseudo)==0 && strcmp(tmp2,connect_password)!=0){
             printf("Location: http://gasyzoo.mg/passwd.html\n\n");
        }
        else if(strcmp(tmp1,connect_pseudo)!=0 && strcmp(tmp2,connect_password)!=0){
            printf("Location: http://gasyzoo.mg/verify.html\n\n");
            break;
        }
    }
    fclose(pt1);
    return 0;
}