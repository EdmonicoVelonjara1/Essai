
typedef struct Pc{
	char marque[200];
	char etiq[200];
	char mac[200];
}Pc;

Pc *saisir(Pc *pc,FILE *file);
Pc *triage(Pc *pc);
