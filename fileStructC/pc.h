typedef struct{
        char marque[200];
        char etiq[100];
        char mac[200];

}Pc;

void saisir(Pc *pc,FILE *file,const int NB_PC);
void triage(Pc *pc,const int NB_PC);
