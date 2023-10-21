#ifndef _DATE_H
#define _DATE_H
int nblinerecover();
void dayGenerate(char month[12][6],char *monthEnter,char days[7][20],int dayEnter,char *day,int finMois[12],int sevenFirstDaysYear[7] );
//int endMonthDay(char *monthEnter,char month[12][6],int dayEnter,char days[7][20],char *day);
void translateMonthMalagasy(char *month,char tabMonth[12][6]);
//int recoverUserPasswd(char user[100][20]);

#endif