
typedef struct MitSt{
        char name[50];
        char fName[100];
        char birth[100];
        char eMail[100];
        char urlGit[200];
        char mention[100];
}MitSt;

void fscanst(MitSt *ms,FILE *pt,const int NB_ST);
void strecover(MitSt *ms,FILE *fp,const int NB_ST);
void insortst(MitSt *ms,const int NB_ST);
void fmovest(MitSt *ms,FILE *file,const int NB_ST);

