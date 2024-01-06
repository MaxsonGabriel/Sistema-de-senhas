
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


/* Sistema de senhas Pronto atendimento de empresas:

RF001 - O sistema deve contar as pessoas atendidas.
RF002 - O sistema deve oferecer 3 três atendimentos: Retorno de férias, Atestado, Periódico.
RF003 - O sistema deve conter uma lista das pessosas atendidas.
*/

//Definições de parâmetro máximo
#define MAX_NOME 50
#define MAX_STR 100
#define MAX_CAD 200


//Pessoas atendidas
struct Pessoa{
	int numAtd;
	struct tm DateHora;
	char tipoAtendimento[MAX_STR];
	int senha;
};


//Quantidade de atendimentos
int qtdAtd = 0;
Pessoa pessoa[MAX_CAD];


void SistemAtd(Pessoa *p1, int *qtdAtd);
void Atender(int tipo, struct Pessoa *p1, int *qtdAtd);
void listar(Pessoa *p1, int *qtdAtd);
void QuantAtd(int *q);
void showData(Pessoa *p1);


//menu
int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int c = 0;
	
	
	do{
		system("cls");
		
		printf("Olá Administrador:\n\n");
		printf(	"1 - Iniciar Atendimentos\n"
				"2 - Listar atendimentos\n"
				"3 - Quantidade de atendimentos\n" "4 - Sair\n\n");
		scanf("%d", &c);
		fflush(stdin);
		
		switch(c){
			case 1: SistemAtd(pessoa, &qtdAtd);
				break;
			case 2: listar(pessoa, &qtdAtd);
				break;
			case 3: QuantAtd(&qtdAtd);
				break;
			case 4: printf("Saindo do sistema...\n\n");
				break;
			default: printf("Opção inválida!\n\n");
		}
		
		system("pause");
		
	}while(c != 4);

	
	return 0;	
	
	
}

void SistemAtd(Pessoa *p1, int *qtdAtd){
	
	system("cls");
	
	int a;
	
	int senhaAtual = 0;
	int i = 0;
	
	do{
		printf("Bem Vindo ao Pronto atendimento!\n\n");
	
		printf( "Como deseja ser atendido?\n\n"
				"1 - Retorno de férias\n"
				"2 - Atestado\n"
				"3 - Periódico\n"				
				"4 - Sair\n\n");
		scanf("%d", &a);
		fflush(stdin);
		
		
		printf("\n\n");
		
		system ("pause");
	
		printf("\n\n");
	
		Atender(a, &p1[i], qtdAtd);
		
		p1[i].senha = senhaAtual;
		
		qtdAtd++;
		senhaAtual++;
		i++;
	
		printf("\n\n");
		
		
		
		
		system("cls");
		
		
			
	}while(a != 4);
	
	
	
	
}


void Atender(int tipo, struct Pessoa *p1, int *qtdAtd) {
    system("cls");

    p1[*qtdAtd].numAtd = tipo;

    switch (tipo) {
        case 1:
            strcpy(p1[*qtdAtd].tipoAtendimento, "Retorno de férias\n");
            break;
        case 2:
            strcpy(p1[*qtdAtd].tipoAtendimento, "Atestado\n");
            break;
        case 3:
            strcpy(p1[*qtdAtd].tipoAtendimento, "Periódico\n");
            break;
        default:
            break;
    }

    printf("Seu atendimento é: %d\n%s", tipo, p1[*qtdAtd].tipoAtendimento);
    printf("Senha: %d\n", p1[*qtdAtd].senha);
    showData(p1);
    printf("\n\n");
    system("pause");
}


void listar(Pessoa *p1, int *qtdAtd){
	
	system("cls");
	
	
	printf("Atendimentos realizados:\n\n");
	
	for(int i = 0; i < *qtdAtd; i++){
		printf(	"Tipo de atendimento: %d - %s\n", 
				p1[i].numAtd, p1[i].tipoAtendimento);
		printf("Senha: %d\n", p1[i].senha);
		showData(&p1[i]);
		printf("-------------------------------------------\n");
		
	}
	
	system("pause");
}

void QuantAtd(int *q){
	
	printf("Quantia de pessoas atendidas até agora: %d\n", *q);
	system ("pause");
	
}


void showData(struct Pessoa *p1){
	
	struct tm *DateHora;
	time_t hora = time(NULL);
	DateHora = localtime(&hora);
	DateHora->tm_year = DateHora->tm_year + 1900;
	DateHora->tm_mon++;
	
	printf("Data: %02d/%02d/%04d\n", DateHora->tm_mday, DateHora->tm_mon, DateHora->tm_year);
	printf("Hora: %02d:%02d", DateHora->tm_hour, DateHora->tm_min);
	
}
