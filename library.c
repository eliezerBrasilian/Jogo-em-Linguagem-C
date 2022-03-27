#include<stdio.h>
#include<stdlib.h>
#include <TIME.H>
#include <windows.h>

typedef struct sFila
{
	int comandoFila;
	int numVezesFila;
	
}Dfila;

typedef struct sNo_fila
{
	Dfila info;
	struct sNo_fila *prox;
	
}NoFila;

typedef struct sfila
{
	NoFila *inicio;
	NoFila *fim;
}Fila;


typedef struct sPilha
 { 
    int comando;
    int numVezes;
 	
 }Pilha;

typedef struct sNo
{
	Pilha  info;
	struct sNo *prox;
	
}NO;

void inicializarFila(Fila *ptr)
{
	ptr->inicio = NULL;
	ptr->fim = NULL;
	
}

NO* inicializar(NO** lista)
{
	*lista=NULL;
}

NoFila* alocarFila()
{
   return (NoFila*) malloc(sizeof(NoFila)) ;	
}

NO* alocar()
{
  return (NO*) malloc(sizeof(NO)) ;
}

NoFila desalocar_fila(NoFila* q)
{
	free(q);
}

NO* desalocar(NO* q)
{
    free(q);
}


int fila_vazia(Fila *ptr)
{
	if(ptr->inicio==NULL)
	return 1;
	
	 return 0;
}

int pilha_vazia(NO *lista)
{
    if(lista==NULL)
        return 1;

        return 0;
}



void enfilheirar (Fila *ptr,Dfila elem)
{
	 NoFila *novo;
	 novo = alocarFila();
	 
	   if(novo!=NULL)
	   {
	   	novo->info = elem;
	   	novo->prox = NULL;
	   	
	   	 if(fila_vazia(ptr)==1)
	   	 {
	   	 	ptr->inicio = novo;
	   	 	ptr->fim = novo;
		 }
		 
		 else
		 {
		 	(ptr->fim)->prox = novo;
		 	ptr->fim = novo;
		 }
	   }
	   
	   else{
	   	printf("\nErro na alocacao do no!\n");
	   }
}

void empilhar(NO **topo,Pilha elem)
{
	NO *novo;
	novo= alocar();
	
	 if(novo!=NULL)
	 {
	 	novo->info = elem;
	 	novo->prox=*topo;
	 	*topo=novo; 	
	 }
	 
	 else
	 {
	 	printf("\nErro na alocacao do no\n");
	 }
}



void desenfileirar(Fila *fila)
{
	NoFila *q;
	q = fila->inicio;
	
	if(!fila_vazia(fila))
	{
		fila->inicio = q->prox;
		desalocar_fila(q);
	}
}
void desempilhar(NO** topo)
{
    NO* q;
    q = *topo;

    if(!pilha_vazia(*topo))
    {
        *topo=q->prox;
		desalocar(q);
	  
    }
}




void impresaoNaoConvencional_fila(Fila *ptr)
{
	
	NoFila *aux;
	aux = ptr->inicio;
	
    printf("\n\n\t\t\t\t\t\t\t\t\t            Fila: ");
	if(!fila_vazia(ptr))
	{
	   while(aux!=NULL)
	   {
	   	 printf("%d-%d  ",aux->info.comandoFila,aux->info.numVezesFila);
	   	  aux = aux->prox;
	   }
    }

    else
	{
		printf("Vazia\n");
	}
}
void impresaoNaoCovencional_pilha(NO *topo)
{
	NO* aux;
	aux = topo;
	
    printf("\n\n\t\t\t\t\t\t\t\t\t            Pilha: ");
	
	if(!pilha_vazia(topo))
	{
		
		while(aux != NULL)
		{   
		printf("%d-%d  ",aux->info.comando,aux->info.numVezes);	
		    aux = aux->prox;	
    	}	
	
	}
	else
	{
		printf("Vazia\n");
	}
}




void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 550 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
  
void meuDelay(){
	int i=0;
	for(i; i<3;i++)delay(1); // pausa de 1 segundo // Wait a second;
	
}



void tabuleiroInicial_Fase1(char letra[8][8]){
	  letra[0][0] = 'P',letra[0][1] = ' ',letra[0][2] = ' ',letra[0][3] = ' ',letra[0][4] = 'X',letra[0][5] = ' ',letra[0][6] = 'X',letra[0][7] = 'X';
	  letra[1][0] = 'X',letra[1][1] = 'X',letra[1][2] = 'X',letra[1][3] = ' ',letra[1][4] = 'X',letra[1][5] = ' ',letra[1][6] = ' ',letra[1][7] = ' ';
	  letra[2][0] = ' ',letra[2][1] = ' ',letra[2][2] = ' ',letra[2][3] = ' ',letra[2][4] = ' ',letra[2][5] = ' ',letra[2][6] = ' ',letra[2][7] = ' ';
	  letra[3][0] = 'X',letra[3][1] = ' ',letra[3][2] = ' ',letra[3][3] = ' ',letra[3][4] = 'X',letra[3][5] = ' ',letra[3][6] = 'X',letra[3][7] = 'X';
	  letra[4][0] = 'X',letra[4][1] = ' ',letra[4][2] = ' ',letra[4][3] = ' ',letra[4][4] = 'X',letra[4][5] = ' ',letra[4][6] = ' ',letra[4][7] = ' ';
	  letra[5][0] = ' ',letra[5][1] = ' ',letra[5][2] = ' ',letra[5][3] = ' ',letra[5][4] = ' ',letra[5][5] = ' ',letra[5][6] = 'X',letra[5][7] = ' ';
	  letra[6][0] = 'X',letra[6][1] = 'X',letra[6][2] = 'X',letra[6][3] = ' ',letra[6][4] = ' ',letra[6][5] = ' ',letra[6][6] = 'X',letra[6][7] = ' ';
	  letra[7][0] = ' ',letra[7][1] = ' ',letra[7][2] = ' ',letra[7][3] = ' ',letra[7][4] = ' ',letra[7][5] = ' ',letra[7][6] = ' ',letra[7][7] = 'O';
	
	}

void tabuleiroFase1(char letra[8][8],char *PonteiroPraSeta){
	system("cls");
	printf(" \n\n                                                             FASE 1\n\n\n");
	printf("                                                       Sentido do Player:\n");
	printf(" _______________________________________\n");         
	printf("|    |    |    |    |    |    |    |    |                  | P %c |                            COMANDOS:\n",*PonteiroPraSeta);
    printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                     _________ \n",letra[0][0],letra[0][1],letra[0][2],letra[0][3],letra[0][4],letra[0][5],letra[0][6],letra[0][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |    |    | \n");
	printf("|    |    |    |    |    |    |    |    |                                                 1) |  F |  F |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |____|____|\n",letra[1][0],letra[1][1],letra[1][2],letra[1][3],letra[1][4],letra[1][5],letra[1][6],letra[1][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |                                                     _________ \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |    |    |\n",letra[2][0],letra[2][1],letra[2][2],letra[2][3],letra[2][4],letra[2][5],letra[2][6],letra[2][7]);
	printf("|____|____|____|____|____|____|____|____|                                                 2) |  F |  D |\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |____|____|\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[3][0],letra[3][1],letra[3][2],letra[3][3],letra[3][4],letra[3][5],letra[3][6],letra[3][7]);
	printf("|____|____|____|____|____|____|____|____|                                                     _________\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |    |    | \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                 3) |  F |  E |\n",letra[4][0],letra[4][1],letra[4][2],letra[4][3],letra[4][4],letra[4][5],letra[4][6],letra[4][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[5][0],letra[5][1],letra[5][2],letra[5][3],letra[5][4],letra[5][5],letra[5][6],letra[5][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[6][0],letra[6][1],letra[6][2],letra[6][3],letra[6][4],letra[6][5],letra[6][6],letra[6][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[7][0],letra[7][1],letra[7][2],letra[7][3],letra[7][4],letra[7][5],letra[7][6],letra[7][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	
}

void movimentarPlayerFase1(char letra[8][8],char *PonteiroPraSeta,Fila *inicio){
	
	int i,j;
	int anda=0;	
	int indiceJ;
	int indiceI;
	int indiceJmaisUmaPosicao = 0;
	int indiceImaisUmaPosicao = 0;
	int obstaculo=0;
	int colunaInicialUmaPosicaoAfrente = -1;
	int colunaFinalUmaPosicaoAfrente = 8;
	int linhaTopoUmaPosicaoAfrente = -1;
	int linhaChaoUmaPosicaoAfrente = 8;
	

	NoFila* aux;
	aux = inicio->inicio;
	
	
	
    //movimentacao FF frente frente
		if(aux->info.comandoFila== 1){//primeira coisa, pego o comando que o usuario digitou
		
			if(*PonteiroPraSeta == '<'){//avancar para coluna a esquerda
				//a ideia eh repetir as verificacoes com base no numero de vezes que o usuario informou
				while(anda < aux->info.numVezesFila){
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
								}	
							}
						}
					}
					
				anda++;
					}
				}
		
			if(*PonteiroPraSeta == '>'){//avancar para coluna a direita
				//a ideia eh repetir as verificacoes com base no numero de vezes que o usuario informou
				while(anda < aux->info.numVezesFila){
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
						}
					}
					
				anda++;
					}
				}
				
			//movimentacao para cima
			if(*PonteiroPraSeta == '^'){
	 		//a ideia eh repetir as verificacoes com base no numero de vezes que o usuario informou
				while(anda < aux->info.numVezesFila){
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
						}
					}
					
				anda++;
				}
			}
				
			//movimentacao para baixo
			if(*PonteiroPraSeta == 'v'){
		
			while(anda < aux->info.numVezesFila){
				for(i=0;i<8;i++){
					for(j=0;j<8;j++){
						indiceI = i;indiceI++;
						//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
						if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
							indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
							
							//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
							if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei uma casa
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								i++;
								letra[i][j] = 'P';//avancei mais uma casa
							}
							//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
							else{
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei so uma casa
							}
							
						}
					}
				}
				
			anda++;
			}
		  }
				
		}
	
	//movimentacao FD frente direita e FE (avancar uma vez e mudar seta ou so mudar seta senao der pra avancar)
	
		do{
			if(aux->info.comandoFila == 2)
			
			{
				
				switch(*PonteiroPraSeta)
				{
					case '>':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ++;
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';
									
								}
									*PonteiroPraSeta = 'v';//avanco uma orientacao da seta pra baixo
										
							}
						}
					break;
					
					case 'v':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
							indiceI = i;indiceI++;
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';
									
								}
							*PonteiroPraSeta = '<';//avanco uma orientacao da seta pra traz
							}
						}
						break;
					
					case '<':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ--;
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';
									
									}
								*PonteiroPraSeta = '^';//volto uma orientacao da seta pra cima
								}
							}
							break;
				
					case '^':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceI = i;indiceI--;
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';
									
								}
							*PonteiroPraSeta = '>';//avanco uma orientacao da seta pra frente
							}
						}
						break;
				
				//fim do switch
				}
	
			anda++;
		}
		
		//comando 3
		
			if(aux->info.comandoFila == 3)
			{
				
				switch(*PonteiroPraSeta)
				{
					case '>':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ++;
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';
								
								}
									//avancando ou nao eu vou mudar a orientacao da seta		
								*PonteiroPraSeta = '^';//avanco uma orientacao da seta pra cima
									}
								}
							break;
					
					case 'v':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceI = i;indiceI++;
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';
							
								}
								//avancando ou nao eu vou mudar a orientacao da seta
								*PonteiroPraSeta = '>';//avanco uma orientacao da seta pra frente
									}
								}
							break;
					
					case '<':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ--;
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';
									
								}
								//avancando ou nao eu vou mudar a orientacao da seta
								*PonteiroPraSeta = 'v';//volto uma orientacao da seta pra traz
									}
								}
							break;
				
					case '^':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceI = i;indiceI--;
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente)
								{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';
									
								}
							//avancando ou nao eu vou mudar a orientacao da seta
											*PonteiroPraSeta = '<';//avanco uma orientacao da seta pra frente
								}
							}
						break;
				
				//fim do switch
				}
	
			anda++;
		}
		
	}while(anda < aux->info.numVezesFila);
}
    
int execucaoFase1(Dfila acessoEmFila,Fila *ponteiroFila, char letra[8][8], char *PonteiroPraSeta)
{
    int verificaComando;
  	int numeroDeRepeticoes;
  	
  	int opcao,escolha;
  	int i=0,contRepeticao=3;
  	char enter;
  	int opcaoDeInserir = 1;
  	int opcaodeCompilar = 2;
  	int copiaDeopcaoDeInserir = opcaoDeInserir;
  	   
  	
  		do{
 	
			  while(copiaDeopcaoDeInserir==1)
 	    	  { 
				tabuleiroInicial_Fase1(letra);
				
			   do{
		       tabuleiroFase1(letra,PonteiroPraSeta);
		       impresaoNaoConvencional_fila(ponteiroFila);
		       printf("\n\n\t\t\t\t\t\t\t\t\t\t  -> Digite o comando: "); scanf("%d",&verificaComando);  
		       printf("\n\t\t\t\t\t\t\t\t\t\t  -> Numero de repeticoes: "); scanf("%d",&numeroDeRepeticoes); 
		      
	    	   }while(verificaComando <1 || verificaComando>3);
	    	
		    	acessoEmFila.comandoFila = verificaComando;
		       	acessoEmFila.numVezesFila = numeroDeRepeticoes;
				enfilheirar(ponteiroFila,acessoEmFila);
					
				   tabuleiroFase1(letra,PonteiroPraSeta);
			       impresaoNaoConvencional_fila(ponteiroFila);
			       
			       do{
			       	system("cls");
			       	tabuleiroFase1(letra,PonteiroPraSeta);
		       		impresaoNaoConvencional_fila(ponteiroFila);
			       printf("\n\n \t\t\t\t\t\t\t\t\t\tTecle 1(inserir) ou 2(executar jogo): ");
			       scanf("%d",&escolha);
			      
	               
	           		}while(escolha!=1 && escolha != 2);
	               
	               
	               
				   copiaDeopcaoDeInserir = opcaoDeInserir;
    	
        	 
        	 
	      if(escolha == opcaodeCompilar)
	      {
	    
		        do{
		             tabuleiroFase1(letra,PonteiroPraSeta);
		             impresaoNaoConvencional_fila(ponteiroFila);
		             movimentarPlayerFase1(letra,PonteiroPraSeta,ponteiroFila);
		             
		             meuDelay();           //mostrar P se movimentando mais lentamante 
		             desenfileirar(ponteiroFila);
		         
			      }while(fila_vazia(ponteiroFila)!=1);
		  
				
				meuDelay();			 
				system("cls");
				tabuleiroFase1(letra,PonteiroPraSeta);
			    impresaoNaoConvencional_fila(ponteiroFila);
					  
			        
						if(letra[7][7]=='P')
			            { 
						Beep(567,500);   
	    	         	 
						  *PonteiroPraSeta = '>';// fazendo a seta voltar pra posicao inicial na proxima fase
						  	                
			                    return 1; //venceu
						}
	              
				           
						   //o usuario ainda nao venceu
					        else
							{
								contRepeticao--; 
			                	if(contRepeticao>0){
								printf("\n\n\t\t\t\t\t\t\t\t\t            %d tentativas restantes!!",contRepeticao); 
								
							  
							    //Se o usuario ainda tiver chance de jogar
							
							
									printf("\n\n\n\t\t\t\t\t\t\t\t\t            Tecle Qualquer Tecla Para Tentar Novamente: ");
									getch();
						  
								}
					                      
					            
								system("cls");
								*PonteiroPraSeta = '>';
								copiaDeopcaoDeInserir= 1;
								
								 if(contRepeticao==0)
	                            {
	                           	copiaDeopcaoDeInserir= 3;   //o Ususario ja ultrapassou o limite de tentativas, passo um valor qualquer para sair do while
					         	}		
					        }
					        
		    }
		     
		     if(copiaDeopcaoDeInserir== 3)
		     {
		   	 system("cls");
			 tabuleiroFase1(letra,PonteiroPraSeta);
			 impresaoNaoConvencional_fila(ponteiroFila);
		     meuDelay();
		   	 meuDelay();
		   	 meuDelay();
			 }
		  }
		    
	
   }while(contRepeticao>0);
   
	        	system("cls");
	        	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGAME OVER\n");
	        	//exit(1);
	 	
}

    	
    	

void tabuleiroInicial_Fase2(char letra[8][8]){
	
	  letra[0][0] = 'P',letra[0][1] = 'X',letra[0][2] = ' ',letra[0][3] = ' ',letra[0][4] = 'X',letra[0][5] = ' ',letra[0][6] = ' ',letra[0][7] = ' ';
	  letra[1][0] = ' ',letra[1][1] = 'X',letra[1][2] = ' ',letra[1][3] = ' ',letra[1][4] = 'X',letra[1][5] = ' ',letra[1][6] = ' ',letra[1][7] = ' ';
	  letra[2][0] = ' ',letra[2][1] = ' ',letra[2][2] = ' ',letra[2][3] = ' ',letra[2][4] = ' ',letra[2][5] = ' ',letra[2][6] = 'X',letra[2][7] = ' ';
	  letra[3][0] = 'X',letra[3][1] = ' ',letra[3][2] = ' ',letra[3][3] = 'X',letra[3][4] = 'X',letra[3][5] = ' ',letra[3][6] = 'X',letra[3][7] = ' ';
	  letra[4][0] = 'X',letra[4][1] = ' ',letra[4][2] = 'X',letra[4][3] = ' ',letra[4][4] = ' ',letra[4][5] = ' ',letra[4][6] = ' ',letra[4][7] = ' ';
	  letra[5][0] = 'X',letra[5][1] = ' ',letra[5][2] = 'X',letra[5][3] = ' ',letra[5][4] = 'X',letra[5][5] = 'X',letra[5][6] = 'X',letra[5][7] = ' ';
	  letra[6][0] = ' ',letra[6][1] = ' ',letra[6][2] = ' ',letra[6][3] = ' ',letra[6][4] = ' ',letra[6][5] = ' ',letra[6][6] = ' ',letra[6][7] = ' ';
	  letra[7][0] = ' ',letra[7][1] = ' ',letra[7][2] = ' ',letra[7][3] = ' ',letra[7][4] = ' ',letra[7][5] = 'X',letra[7][6] = 'X',letra[7][7] = 'O';
	
}

void tabuleiroFase2(char letra[8][8],char *PonteiroPraSeta){
	
	system("cls");
	printf(" \n\n                                                             FASE 2\n\n\n");
	printf("                                                       Sentido do Player:\n");
	printf(" _______________________________________\n");         
	printf("|    |    |    |    |    |    |    |    |                  | P %c |                            COMANDOS:\n",*PonteiroPraSeta);
    printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                     ___________________ \n",letra[0][0],letra[0][1],letra[0][2],letra[0][3],letra[0][4],letra[0][5],letra[0][6],letra[0][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |    |    |    |    | \n");
	printf("|    |    |    |    |    |    |    |    |                                                 1) |  D |  F |  F |  E | \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |____|____|____|____|\n",letra[1][0],letra[1][1],letra[1][2],letra[1][3],letra[1][4],letra[1][5],letra[1][6],letra[1][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |                                                     ___________________ \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |    |    |    |    |\n",letra[2][0],letra[2][1],letra[2][2],letra[2][3],letra[2][4],letra[2][5],letra[2][6],letra[2][7]);
	printf("|____|____|____|____|____|____|____|____|                                                 2) |  F |  F |  F |  D |\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |____|____|____|____|\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[3][0],letra[3][1],letra[3][2],letra[3][3],letra[3][4],letra[3][5],letra[3][6],letra[3][7]);
	printf("|____|____|____|____|____|____|____|____|                                                     ______________\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |    |    |    | \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                 3) |  E |  F |  F |\n",letra[4][0],letra[4][1],letra[4][2],letra[4][3],letra[4][4],letra[4][5],letra[4][6],letra[4][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[5][0],letra[5][1],letra[5][2],letra[5][3],letra[5][4],letra[5][5],letra[5][6],letra[5][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[6][0],letra[6][1],letra[6][2],letra[6][3],letra[6][4],letra[6][5],letra[6][6],letra[6][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[7][0],letra[7][1],letra[7][2],letra[7][3],letra[7][4],letra[7][5],letra[7][6],letra[7][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	
}

void movimentarPlayerFase2(char letra[8][8],char *PonteiroPraSeta,NO *topo){
	
	int i,j;
	int anda=0;	
	int indiceJ;
	int indiceI;
	int indiceJmaisUmaPosicao = 0;
	int indiceImaisUmaPosicao = 0;
	int indiceJterceira = 0;
	int indiceIterceira = 0;
	int obstaculo=0;
	int colunaInicialUmaPosicaoAfrente = -1;
	int colunaFinalUmaPosicaoAfrente = 8;
	int linhaTopoUmaPosicaoAfrente = -1;
	int linhaChaoUmaPosicaoAfrente = 8;
	
		
	do{
		//dffe
		if(topo->info.comando == 1){
			switch(*PonteiroPraSeta){
				case '>':
					
					//alterando a orientacao da seta
					*PonteiroPraSeta = 'v';
					
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI++;
						//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
						if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
							indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
							
							//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
							if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei uma casa
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								i++;
								letra[i][j] = 'P';//avancei mais uma casa
							}
							//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
							else{
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei so uma casa
							  }
							
						  }
						}
					}
					//avancando ou nao eu vou alterar a orientacao
						*PonteiroPraSeta = '>';
						break;
			
		
			case 'v':
			
			*PonteiroPraSeta = '<';
			
				for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
								}	
							}
						}
					}
						*PonteiroPraSeta = 'v';
						break;
			
			case '<':
				
			*PonteiroPraSeta = '^';
			for(i=0;i<8;i++){
				for(j=0;j<8;j++){
							indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
						}
					}
							*PonteiroPraSeta = '<';
							break;
							
				case '^':
					
				*PonteiroPraSeta = '>';
				
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
						}
					}
						*PonteiroPraSeta = '^';
						break;
			}//fim do switch
			anda++;	
		}
		
		//fffd
		
		if(topo->info.comando == 2){
			switch(*PonteiroPraSeta){
				case '>':
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
									
									//tentativa de avancar mais uma coluna
									indiceJterceira = indiceJmaisUmaPosicao; indiceJterceira++;
									
									if(letra[i][j] == 'P' && letra[i][indiceJterceira] != 'X' && indiceJterceira != colunaFinalUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei uma casa
									}
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
						}
					}
					
					*PonteiroPraSeta = 'v';
					break;
					
					case 'v':
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i++;
									letra[i][j] = 'P';//avancei mais uma casa
									
									//tentativa de avancar mais um indice
									indiceIterceira = indiceImaisUmaPosicao; indiceIterceira++;
									
									if(letra[i][j] == 'P' && letra[indiceIterceira][j] != 'X' && indiceIterceira != linhaChaoUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei uma casa
									}
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei so uma casa
								}
								
							}
						}
					}
						*PonteiroPraSeta = '<';
						break;
						
					case '<':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ--;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
										indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
										
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
										j--;
										letra[i][j] = 'P';//avancei mais uma casa
										
										//tentativa de avancar mais uma coluna
									indiceJterceira = indiceJmaisUmaPosicao; indiceJterceira--;
									
									if(letra[i][j] == 'P' && letra[i][indiceJterceira] != 'X' && indiceJterceira != colunaFinalUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
									}
										
									}
									//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
									else{
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei so uma casa
									}	
								}
							}
						}
						
						*PonteiroPraSeta = '^';
						break;
						
						case '^':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceI = i;indiceI--;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
									indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
										i--;
										letra[i][j] = 'P';//avancei mais uma casa
										
										//tentativa de avancar mais uma linha
									indiceIterceira = indiceImaisUmaPosicao; indiceIterceira++;
									
										if(letra[i][j] == 'P' && letra[indiceIterceira][j] != 'X' && indiceIterceira != linhaTopoUmaPosicaoAfrente){
											letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
											i--;
											letra[i][j] = 'P';//avancei uma casa
										}
									}
									//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
									else{
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei so uma casa
									}
										
								}
							}
						}
							
							*PonteiroPraSeta = '>';
							break;
				
			}//fim do switch
			anda++;
		}
		
		//eff
		if(topo->info.comando == 3){
			switch(*PonteiroPraSeta){
				case '>':
					*PonteiroPraSeta = '^';
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
						}
					}
					break;
					
					case '^':
						*PonteiroPraSeta = '<';
						
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
									}	
								}
							}
						}
					break;
					
					case '<':
						*PonteiroPraSeta = 'v';
						
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei so uma casa
								}
								
							}
						}
					}
				break;
						
					
					case 'v':
						*PonteiroPraSeta = '>';
						
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ++;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei uma casa
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
										j++;
										letra[i][j] = 'P';//avancei mais uma casa
									}
									//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
									else{
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei so uma casa
									}
								}
							}
						}
			}//fim do switch
			anda++;
		}
		
	}	while(anda < topo->info.numVezes);
	
	
}

int execucaoFase2(Pilha acessoEmPilha, NO *ponteiroNoPilha,char letra[8][8],char *PonteiroPraSeta){
	int verificaComando;
  	int numeroDeRepeticoes;
  	
  	int opcao,escolha;
  	int i=0,contRepeticao=3;
  	char enter;
  	
  	int opcaoDeInserir = 1;
  	int opcaodeCompilar = 2;
  	int copiaDeopcaoDeInserir = opcaoDeInserir;

  	
  	do{
  		 while(copiaDeopcaoDeInserir==1)
 	     { 
 		   tabuleiroInicial_Fase2(letra);
	   	
	
			do{
		       tabuleiroFase2(letra,PonteiroPraSeta);
		       impresaoNaoCovencional_pilha(ponteiroNoPilha);
		       printf("\n\n\t\t\t\t\t\t\t\t\t\t  -> Digite o comando: "); scanf("%d",&verificaComando);  
		       printf("\n\t\t\t\t\t\t\t\t\t\t  -> Numero de repeticoes: "); scanf("%d",&numeroDeRepeticoes); 
		      
	    	}while(verificaComando <1 || verificaComando>3);
	    	
			acessoEmPilha.comando = verificaComando;
	       	acessoEmPilha.numVezes = numeroDeRepeticoes;
			empilhar(&ponteiroNoPilha,acessoEmPilha);
		
	
		   tabuleiroFase2(letra,PonteiroPraSeta);
	       impresaoNaoCovencional_pilha(ponteiroNoPilha);
	       
	       do{
	       tabuleiroFase2(letra,PonteiroPraSeta);
		   impresaoNaoCovencional_pilha(ponteiroNoPilha);
		   printf("\n\n \t\t\t\t\t\t\t\t\t\tTecle 1(inserir) ou 2(executar jogo): ");
	       scanf("%d",&escolha);
	       system("cls");
		   }while(escolha!=1 && escolha != 2);
		 	
			copiaDeopcaoDeInserir = opcaoDeInserir; 
			 
			    
	       
	      if(escolha == opcaodeCompilar)
	      {
	    
	        do{
	            tabuleiroFase2(letra,PonteiroPraSeta);
	            impresaoNaoCovencional_pilha(ponteiroNoPilha);
	            movimentarPlayerFase2(letra,PonteiroPraSeta,ponteiroNoPilha);
	            meuDelay();
	            desempilhar(&ponteiroNoPilha);
	          
			} while(pilha_vazia(ponteiroNoPilha)!=1);
	  
				
			meuDelay();			 //mostrar P se movimentando mais lentamante 
			system("cls");
			tabuleiroFase2(letra,PonteiroPraSeta);
		    impresaoNaoCovencional_pilha(ponteiroNoPilha);
					  
	        	if(letra[7][7]=='P')
	            {
	            	    Beep(567,500);  
	                    *PonteiroPraSeta = '>';
	                    return 1; //venceu
				}
	                //o usuario ainda nao venceu
		        else
				{
					contRepeticao--; 
                   if(contRepeticao>0){
                   	
				     	printf("\n\n\t\t\t\t\t\t\t\t\t            %d tentativas restantes!!",contRepeticao); 
						printf("\n\n\n\t\t\t\t\t\t\t\t\t            Tecle Qualquer Tecla Para Tentar Novamente: ");
						getch();
					}
		                      
		            
					system("cls");
					*PonteiroPraSeta = '>';
					copiaDeopcaoDeInserir= 1;
					
					if(contRepeticao==0)
                   {
                   	copiaDeopcaoDeInserir=3;
                   }
							
		        }
		    }
		    
		     if(copiaDeopcaoDeInserir== 3)
		     {
		   	 system("cls");
			 tabuleiroFase1(letra,PonteiroPraSeta);
		   	 impresaoNaoCovencional_pilha(ponteiroNoPilha);
		   	 meuDelay();
		   	 meuDelay();
		   	 meuDelay();
		     
			 }
		}
	
   }while(contRepeticao>0);
   
        	system("cls");
        	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGAME OVER\n");
	        exit(1);
   	
}




void tabuleiroInicialFase3_ida(char letra[8][8]){
	
	  letra[0][0] = 'P',letra[0][1] = ' ',letra[0][2] = ' ',letra[0][3] = ' ',letra[0][4] = ' ',letra[0][5] = ' ',letra[0][6] = ' ',letra[0][7] = 'X';
	  letra[1][0] = ' ',letra[1][1] = 'X',letra[1][2] = 'X',letra[1][3] = 'X',letra[1][4] = ' ',letra[1][5] = ' ',letra[1][6] = ' ',letra[1][7] = 'X';
	  letra[2][0] = ' ',letra[2][1] = ' ',letra[2][2] = ' ',letra[2][3] = ' ',letra[2][4] = ' ',letra[2][5] = ' ',letra[2][6] = ' ',letra[2][7] = ' ';
	  letra[3][0] = ' ',letra[3][1] = ' ',letra[3][2] = ' ',letra[3][3] = ' ',letra[3][4] = ' ',letra[3][5] = 'X',letra[3][6] = 'X',letra[3][7] = ' ';
	  letra[4][0] = 'X',letra[4][1] = 'X',letra[4][2] = ' ',letra[4][3] = 'X',letra[4][4] = ' ',letra[4][5] = ' ',letra[4][6] = ' ',letra[4][7] = ' ';
	  letra[5][0] = ' ',letra[5][1] = ' ',letra[5][2] = ' ',letra[5][3] = 'X',letra[5][4] = ' ',letra[5][5] = ' ',letra[5][6] = ' ',letra[5][7] = 'X';
	  letra[6][0] = ' ',letra[6][1] = 'X',letra[6][2] = ' ',letra[6][3] = ' ',letra[6][4] = ' ',letra[6][5] = ' ',letra[6][6] = ' ',letra[6][7] = 'X';
	  letra[7][0] = ' ',letra[7][1] = 'X',letra[7][2] = ' ',letra[7][3] = ' ',letra[7][4] = ' ',letra[7][5] = ' ',letra[7][6] = ' ',letra[7][7] = 'O';
}

void tabuleiroInicial_Fase3_volta(char letra[8][8]){
	
	  letra[0][0] = 'O',letra[0][1] = ' ',letra[0][2] = ' ',letra[0][3] = ' ',letra[0][4] = ' ',letra[0][5] = ' ',letra[0][6] = ' ',letra[0][7] = 'X';
	  letra[1][0] = ' ',letra[1][1] = 'X',letra[1][2] = 'X',letra[1][3] = 'X',letra[1][4] = ' ',letra[1][5] = ' ',letra[1][6] = ' ',letra[1][7] = 'X';
	  letra[2][0] = ' ',letra[2][1] = ' ',letra[2][2] = ' ',letra[2][3] = ' ',letra[2][4] = ' ',letra[2][5] = ' ',letra[2][6] = ' ',letra[2][7] = ' ';
	  letra[3][0] = ' ',letra[3][1] = ' ',letra[3][2] = ' ',letra[3][3] = ' ',letra[3][4] = ' ',letra[3][5] = 'X',letra[3][6] = 'X',letra[3][7] = ' ';
	  letra[4][0] = 'X',letra[4][1] = 'X',letra[4][2] = ' ',letra[4][3] = 'X',letra[4][4] = ' ',letra[4][5] = ' ',letra[4][6] = ' ',letra[4][7] = ' ';
	  letra[5][0] = ' ',letra[5][1] = ' ',letra[5][2] = ' ',letra[5][3] = 'X',letra[5][4] = ' ',letra[5][5] = ' ',letra[5][6] = ' ',letra[5][7] = 'X';
	  letra[6][0] = ' ',letra[6][1] = 'X',letra[6][2] = ' ',letra[6][3] = ' ',letra[6][4] = ' ',letra[6][5] = ' ',letra[6][6] = ' ',letra[6][7] = 'X';
	  letra[7][0] = ' ',letra[7][1] = 'X',letra[7][2] = ' ',letra[7][3] = ' ',letra[7][4] = ' ',letra[7][5] = ' ',letra[7][6] = ' ',letra[7][7] = 'P';
}

void tabuleiroFase3(char letra[8][8],char *PonteiroPraSeta){
	system("cls");
	printf(" \n\n                                                             FASE 3\n\n\n");
	printf("                                                       Sentido do Player:\n");
	printf(" _______________________________________\n");         
	printf("|    |    |    |    |    |    |    |    |                  | P %c |                            COMANDOS:\n",*PonteiroPraSeta);
    printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                     ___________________ \n",letra[0][0],letra[0][1],letra[0][2],letra[0][3],letra[0][4],letra[0][5],letra[0][6],letra[0][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |    |    |    |    | \n");
	printf("|    |    |    |    |    |    |    |    |                                                 1) |  D |  F |  F |  D | \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |____|____|____|____|\n",letra[1][0],letra[1][1],letra[1][2],letra[1][3],letra[1][4],letra[1][5],letra[1][6],letra[1][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |                                                     ___________________ \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |    |    |    |    |\n",letra[2][0],letra[2][1],letra[2][2],letra[2][3],letra[2][4],letra[2][5],letra[2][6],letra[2][7]);
	printf("|____|____|____|____|____|____|____|____|                                                 2) |  F |  E |  F |  F |\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |____|____|____|____|\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[3][0],letra[3][1],letra[3][2],letra[3][3],letra[3][4],letra[3][5],letra[3][6],letra[3][7]);
	printf("|____|____|____|____|____|____|____|____|                                                     ___________________\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |    |    |    |    | \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                 3) |  F |  F |  D |  F |\n",letra[4][0],letra[4][1],letra[4][2],letra[4][3],letra[4][4],letra[4][5],letra[4][6],letra[4][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[5][0],letra[5][1],letra[5][2],letra[5][3],letra[5][4],letra[5][5],letra[5][6],letra[5][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[6][0],letra[6][1],letra[6][2],letra[6][3],letra[6][4],letra[6][5],letra[6][6],letra[6][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[7][0],letra[7][1],letra[7][2],letra[7][3],letra[7][4],letra[7][5],letra[7][6],letra[7][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
 	
}

void tabuleiroFase3_volta(char letra[8][8],char *PonteiroPraSeta){
	system("cls");
	printf(" \n\n                                                             FASE 3\n\n\n");
	printf("                                                       Sentido do Player:\n");
	printf(" _______________________________________\n");         
	printf("|    |    |    |    |    |    |    |    |                  | P %c |                            COMANDOS:\n",*PonteiroPraSeta);
    printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                     ______________ \n",letra[0][0],letra[0][1],letra[0][2],letra[0][3],letra[0][4],letra[0][5],letra[0][6],letra[0][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |    |    |    | \n");
	printf("|    |    |    |    |    |    |    |    |                                                 1) |  F |  F |  E | \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |____|____|____|\n",letra[1][0],letra[1][1],letra[1][2],letra[1][3],letra[1][4],letra[1][5],letra[1][6],letra[1][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |                                                     ___________________ \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |    |    |    |    |\n",letra[2][0],letra[2][1],letra[2][2],letra[2][3],letra[2][4],letra[2][5],letra[2][6],letra[2][7]);
	printf("|____|____|____|____|____|____|____|____|                                                 2) |  D |  F |  F |  F |\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |____|____|____|____|\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[3][0],letra[3][1],letra[3][2],letra[3][3],letra[3][4],letra[3][5],letra[3][6],letra[3][7]);
	printf("|____|____|____|____|____|____|____|____|                                                     ______________\n");
	printf("|    |    |    |    |    |    |    |    |                                                    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                 3) |  F |  E |  F |\n",letra[4][0],letra[4][1],letra[4][2],letra[4][3],letra[4][4],letra[4][5],letra[4][6],letra[4][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |____|____|____|\n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                     ___________________\n",letra[5][0],letra[5][1],letra[5][2],letra[5][3],letra[5][4],letra[5][5],letra[5][6],letra[5][7]);
	printf("|____|____|____|____|____|____|____|____|                                                    |    |    |    |    |\n");
	printf("|    |    |    |    |    |    |    |    |                                                 4) |  F |  F |  F |  F |  \n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |                                                    |____|____|____|____|\n",letra[6][0],letra[6][1],letra[6][2],letra[6][3],letra[6][4],letra[6][5],letra[6][6],letra[6][7]);
	printf("|____|____|____|____|____|____|____|____|                                                     \n");
	printf("|    |    |    |    |    |    |    |    |\n");
	printf("|  %c |  %c |  %c |  %c |  %c |  %c |  %c |  %c |\n",letra[7][0],letra[7][1],letra[7][2],letra[7][3],letra[7][4],letra[7][5],letra[7][6],letra[7][7]);
	printf("|____|____|____|____|____|____|____|____|\n");
	
}

void movimentarPlayerFase3_ida(char letra[8][8],char *PonteiroPraSeta,Fila *inicio){
	
	int i,j;
	int anda=0;	
	int indiceJ;
	int indiceI;
	int indiceJmaisUmaPosicao = 0;
	int indiceImaisUmaPosicao = 0;
	int indiceJterceira = 0;
	int indiceIterceira = 0;
	int obstaculo=0;
	int colunaInicialUmaPosicaoAfrente = -1;
	int colunaFinalUmaPosicaoAfrente = 8;
	int linhaTopoUmaPosicaoAfrente = -1;
	int linhaChaoUmaPosicaoAfrente = 8;
	
	NoFila* aux;
	aux = inicio->inicio;
	
		
	do{
		//dffd
		if(aux->info.comandoFila == 1){
			switch(*PonteiroPraSeta){
				case '>':
					
					//alterando a orientacao da seta
					*PonteiroPraSeta = 'v';
					
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI++;
						//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
						if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
							indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
							
							//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
							if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei uma casa
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								i++;
								letra[i][j] = 'P';//avancei mais uma casa
							}
							//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
							else{
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei so uma casa
							  }
							
						  }
						}
					}
					//avancando ou nao eu vou alterar a orientacao
						*PonteiroPraSeta = '<';
						break;
			
		//dffd
			case 'v':
			
			*PonteiroPraSeta = '<';
			
				for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
								}	
							}
						}
					}
						*PonteiroPraSeta = '^';
						break;
			
			//dffd
			case '<':
				
			*PonteiroPraSeta = '^';
			
				for(j=0;j<8;j++){
							indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
						}
							*PonteiroPraSeta = '>';
							break;
							
				case '^':
					
				*PonteiroPraSeta = '>';
				
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
						}
					}
						*PonteiroPraSeta = 'v';
						break;
			}//fim do switch
			anda++;	
		}
		
		//feff
		
		if(aux->info.comandoFila == 2){
			switch(*PonteiroPraSeta){
				case '>':
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								j++;
								letra[i][j] = 'P';//avancei mais uma casa
								}
								
								//avancando ou nao eu altero a orientacao da seta
								*PonteiroPraSeta = '^';//alterando a orientacao
								
								indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
						}
							
								
					}//fim do for linha
					
					break;
					
					//feff
					case 'v':
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i++;
									letra[i][j] = 'P';//avancei mais uma casa
							
								}
								
								*PonteiroPraSeta = '>';
								
									indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
						}
					}
	
				break;
						
						//feff
					case '<':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceJ = j;indiceJ--;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
										
								}
								
								*PonteiroPraSeta = 'v';
								
									indiceI = i;indiceI++;
						//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
						if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
							indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
							
							//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
							if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei uma casa
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								i++;
								letra[i][j] = 'P';//avancei mais uma casa
							}
							//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
							else{
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei so uma casa
							  }
							
						  }
								
						}
					}
							
				break;
						
						case '^':
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
								indiceI = i;indiceI--;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
									
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa		
								}
								
								*PonteiroPraSeta = '<';
								
									indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
								}	
							}
						}
					}
									
				break;
				
			}//fim do switch
			anda++;
		}
		
		//ffdf
		if(aux->info.comandoFila == 3){
			switch(*PonteiroPraSeta){
				case '>':
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
							*PonteiroPraSeta = 'v';
							
							indiceI = i;indiceI++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i++;
									letra[i][j] = 'P';//avancei mais uma casa
							
								}
							}
						}
					break;
					
						//ffdf
					case '^':
						
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
							*PonteiroPraSeta = '>';
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								j++;
								letra[i][j] = 'P';//avancei mais uma casa
								}
							
							}
						}
					break;
					
						//ffdf
					case '<':
						
					for(i=0;i<8;i++){
						for(j=0;j<8;j++){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
								}	
							}
							
							*PonteiroPraSeta = '^';
							
							indiceI = i;indiceI--;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
									
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa		
								}
							}
						}
					break;
						
						//ffdf
					case 'v':
						
						for(i=0;i<8;i++){
							for(j=0;j<8;j++){
									indiceI = i;indiceI++;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
									indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei uma casa
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
										i++;
										letra[i][j] = 'P';//avancei mais uma casa
									}
									//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
									else{
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei so uma casa
									  }
								  }
								  
								  *PonteiroPraSeta = '<';
								  
								  	indiceJ = j;indiceJ--;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
										
								}
							}
						}
			}//fim do switch
			anda++;
		}
		
	}	while(anda < aux->info.numVezesFila);

	
}

void movimentarPlayerFase3_volta(char letra[8][8],char *PonteiroPraSeta,NO *topo){
	
	int i,j;
	int anda=0;	
	int indiceJ;
	int indiceI;
	int indiceJmaisUmaPosicao = 0;
	int indiceImaisUmaPosicao = 0;
	int indiceJterceira = 0;
	int indiceIterceira = 0;
	int obstaculo=0;
	int colunaInicialUmaPosicaoAfrente = -1;
	int colunaFinalUmaPosicaoAfrente = 8;
	int linhaTopoUmaPosicaoAfrente = -1;
	int linhaChaoUmaPosicaoAfrente = 8;
	

	
		
	do{
		//ffe
		if(topo->info.comando == 1){
			switch(*PonteiroPraSeta){
				case '>':
					
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							
							indiceJ = j;indiceJ++;
									//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
							
					//avancando ou nao eu vou alterar a orientacao
						*PonteiroPraSeta = '^';
						}
					}
					
				break;
			
		
			case 'v':
			
				for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
										indiceI = i;indiceI++;
						//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
						if(letra[i][j] == 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
							indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
							
							//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
							if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei uma casa
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
								i++;
								letra[i][j] = 'P';//avancei mais uma casa
							}
							//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
							else{
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
								i++;
								letra[i][j] = 'P';//avancei so uma casa
							  }
							
						  }
						  *PonteiroPraSeta = '>';  
						}
					}
						
						break;
			
			case '<':
				
				for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
								indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
									
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
								}	
							}
							
							*PonteiroPraSeta = 'v';
						}
					}
					break;		
							
				case '^':
					
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceI = i;indiceI--;
							
							//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao--;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaTopoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i--;
									letra[i][j] = 'P';//avancei mais uma casa
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
								}
									
							}
							*PonteiroPraSeta = '<';
						}
					}
						
						break;
			}//fim do switch
			anda++;	
		}
		
		//dfff
		
		if(topo->info.comando == 2){
			switch(*PonteiroPraSeta){
				case '>':
					
					*PonteiroPraSeta = 'v';
					
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							
								indiceI = i;indiceI++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
								indiceImaisUmaPosicao = indiceI;indiceImaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[indiceImaisUmaPosicao][j] != 'X' && indiceImaisUmaPosicao != linhaChaoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									i++;
									letra[i][j] = 'P';//avancei mais uma casa
									
									//tentativa de avancar mais um indice
									indiceIterceira = indiceImaisUmaPosicao; indiceIterceira++;
									
									if(letra[i][j] == 'P' && letra[indiceIterceira][j] != 'X' && indiceIterceira != linhaChaoUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei uma casa
									}
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei so uma casa
								}
								
							}
							
						}
					}
					
					break;
					
					case 'v':
						
						*PonteiroPraSeta = '<';
						
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
								indiceJ = j;indiceJ--;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
										indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao--;
										
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaInicialUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
										j--;
										letra[i][j] = 'P';//avancei mais uma casa
										
										//tentativa de avancar mais uma coluna
									indiceJterceira = indiceJmaisUmaPosicao; indiceJterceira--;
									
									if(letra[i][j] == 'P' && letra[i][indiceJterceira] != 'X' && indiceJterceira != colunaFinalUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
									}
										
									}
									//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
									else{
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei so uma casa
									}	
								}
						}
					}
						
						break;
						
					case '<':
						
						*PonteiroPraSeta = '^';
						for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
									indiceI = i;indiceI--;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' &&indiceI != linhaTopoUmaPosicaoAfrente){
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa
										
										indiceI = i;indiceI--;//segunda tentativa
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j] == 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
										
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
										i--;
										letra[i][j] = 'P';//avancei mais uma casa
										
											indiceI = i;indiceI--;//terceira tentativa
								
											if(letra[i][j] == 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
												letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
												i--;
												letra[i][j] = 'P';//avancei uma casa
											}
										}
									
										
								}
							}
						}
						
						
						break;
						
						case '^':
							
							*PonteiroPraSeta = '>';
							
						for(i=7;i>=0;i--){
							for(j=7;j>=0;j--){
								
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								indiceJmaisUmaPosicao = indiceJ;indiceJmaisUmaPosicao++;
								
								//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJmaisUmaPosicao] != 'X' && indiceJmaisUmaPosicao != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou 
									j++;
									letra[i][j] = 'P';//avancei mais uma casa
									
									//tentativa de avancar mais uma coluna
									indiceJterceira = indiceJmaisUmaPosicao; indiceJterceira++;
									
									if(letra[i][j] == 'P' && letra[i][indiceJterceira] != 'X' && indiceJterceira != colunaFinalUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei uma casa
									}
								}
								//nao foi fim de tabuleiro e nem teve obstaculo na primeira verificacao mas teve na segunda
								else{
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
								}
							}
							
						}
					}
								
				break;
				
			}//fim do switch
			anda++;
		}
		
		//FEF
		if(topo->info.comando == 3){
			switch(*PonteiroPraSeta){
				case '>':
					
					for(i=7;i>=0;i--){
							for(j=7;j>=0;j--){
						indiceJ = j;indiceJ++;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
									
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei uma casa
									}
									
										*PonteiroPraSeta = '^';
									
									indiceI = i;indiceI--;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
		
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa
								}
							
							}
						}
					break;
					
					case '^':
						
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
								indiceI = i;indiceI--;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
		
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa
								}
								
								*PonteiroPraSeta = '<';
								
								indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
								}
								
							}
						}
					break;
					
					
					case '<':
						
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
								}
								
								*PonteiroPraSeta = 'v';
								
								indiceI = i;indiceI++;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
		
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei uma casa
								}
								
						}
					}
				break;
						
					
					case 'v':
					
						for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceI = i;indiceI++;
								
								//verifico se tem obstaculo ou final de tabuleiro na posicao anterior
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
		
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei uma casa
								}
								
									*PonteiroPraSeta = '>';
									
									indiceJ = j;indiceJ++;
								//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
								
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
									
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei uma casa
									}
									
							}
						}
			}//fim do switch
			anda++;
		}
		
		
		//ffff
			if(topo->info.comando == 4){
				
			switch(*PonteiroPraSeta){
				case '>':
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceJ = j;indiceJ++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei so uma casa
									
									//tentativa de avancar sgunda vez
									
									indiceJ = j;indiceJ++;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j] == 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j++;
									letra[i][j] = 'P';//avancei uma casa
									
									//tentativa de avancar a terceira vez
									
									indiceJ = j;indiceJ++;
									
									if(letra[i][j] == 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j++;
										letra[i][j] = 'P';//avancei uma casa
										
										//tentativa de avancar quarta vez
											indiceJ = j;indiceJ++;
										
										if(letra[i][j] == 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaFinalUmaPosicaoAfrente){
											letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
											j++;
											letra[i][j] = 'P';//avancei uma casa
											
										}
									}
									
								}
							}
									
						}
					}
					
					break;
					
					case 'v':
				for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceI = i;indiceI++;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei so uma casa
									
									//tentativa de avancar sgunda vez
									
									indiceI = i;indiceI++;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i++;
									letra[i][j] = 'P';//avancei uma casa
									
									//tentativa de avancar a terceira vez
									
									indiceI = i;indiceI++;
									
									if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i++;
										letra[i][j] = 'P';//avancei uma casa
										
										//tentativa de avancar quarta vez
											indiceI = i;indiceI++;
										
										if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaChaoUmaPosicaoAfrente){
											letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
											i++;
											letra[i][j] = 'P';//avancei uma casa
											
										}
									}
									
								}
							}
									
						}
					}
					
					break;
						
					case '<':
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceJ = j;indiceJ--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei so uma casa
									
									//tentativa de avancar sgunda vez
									
									indiceJ = j;indiceJ--;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
								if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
									letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									j--;
									letra[i][j] = 'P';//avancei uma casa
									
									//tentativa de avancar a terceira vez
									
									indiceJ = j;indiceJ--;
									
									if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										j--;
										letra[i][j] = 'P';//avancei uma casa
										
										//tentativa de avancar quarta vez
											indiceJ = j;indiceJ--;
										
										if(letra[i][j]== 'P' && letra[i][indiceJ] != 'X' && indiceJ != colunaInicialUmaPosicaoAfrente){
											letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
											j--;
											letra[i][j] = 'P';//avancei uma casa
											
										}
									}
									
								}
							}
									
						}
					}
					
					break;
					
					
				case '^':
					for(i=7;i>=0;i--){
						for(j=7;j>=0;j--){
							indiceI = i;indiceI--;
							//verifico se tem obstaculo ou final de tabuleiro na proxima posicao
							
							if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
								
								letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
									i--;
									letra[i][j] = 'P';//avancei so uma casa
									
									//tentativa de avancar sgunda vez
									
									indiceI = i;indiceI--;
									
									//nao foi fim de tabuleiro e nem teve obstaculo entao vamos avancar duas posicoes
									if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
										letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
										i--;
										letra[i][j] = 'P';//avancei uma casa
										
										//tentativa de avancar a terceira vez
										
										indiceI = i;indiceI--;
										
										if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
											letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
											i--;
											letra[i][j] = 'P';//avancei uma casa
											
											//tentativa de avancar quarta vez
												indiceI = i;indiceI--;
											
											if(letra[i][j]== 'P' && letra[indiceI][j] != 'X' && indiceI != linhaTopoUmaPosicaoAfrente){
												letra[i][j] = '-';//entao essa posicao fica vazia,substitui P por - ou vazio
												i--;
												letra[i][j] = 'P';//avancei uma casa
												
											}
										}
										
									}
								}			
							}
						}
					
					break;
				
			}//fim do switch
			anda++;
		}
		
	}	while(anda < topo->info.numVezes);
	
}


int execucaoFase3(Dfila acessoEmFila,Pilha acessoEmPilha,Fila *ponteiroFila,NO *ponteiroNoPilha,char letra[8][8],char *PonteiroPraSeta){
	
	int verificaComando;
  	int numeroDeRepeticoes;
  	
  	int opcao,escolha;
  	int i=0,contRepeticao=3;
  	char enter;
  	
  	int opcaoDeInserir = 1;
  	int opcaodeCompilar = 2;
  	int copiaDeopcaoDeInserir = opcaoDeInserir;
  	
  	do{
  		 while(copiaDeopcaoDeInserir==1)
 	     { 
 		   tabuleiroInicialFase3_ida(letra);
	   	
		      do{
			       tabuleiroFase3(letra,PonteiroPraSeta);
			       impresaoNaoConvencional_fila(ponteiroFila);
			       printf("\n\n\t\t\t\t\t\t\t\t\t\t  -> Digite o comando: "); scanf("%d",&verificaComando);  
			       printf("\n\t\t\t\t\t\t\t\t\t\t  -> Numero de repeticoes: "); scanf("%d",&numeroDeRepeticoes); 
			      
		        }while(verificaComando <1 || verificaComando>3);
	    	
			    	acessoEmFila.comandoFila = verificaComando;
			       	acessoEmFila.numVezesFila = numeroDeRepeticoes;
					enfilheirar(ponteiroFila,acessoEmFila);
					
				    tabuleiroFase3(letra,PonteiroPraSeta);
			        impresaoNaoConvencional_fila(ponteiroFila);
			       
			       do{
			       	system("cls");
			       	tabuleiroFase3(letra,PonteiroPraSeta);
		       		impresaoNaoConvencional_fila(ponteiroFila);
			        printf("\n\n \t\t\t\t\t\t\t\t\t\tTecle 1(inserir) ou 2(executar jogo): ");
			        scanf("%d",&escolha);
			
	           		}while(escolha!=1 && escolha != 2);
	               
				   
				   copiaDeopcaoDeInserir = opcaoDeInserir;
    	
        	 
	      if(escolha == opcaodeCompilar)
	      {
	    
		        do{
		             tabuleiroFase3(letra,PonteiroPraSeta);
		             impresaoNaoConvencional_fila(ponteiroFila);
		             movimentarPlayerFase3_ida(letra,PonteiroPraSeta,ponteiroFila);
		             
		             meuDelay();           //mostrar P se movimentando mais lentamante 
		             desenfileirar(ponteiroFila);
		         
			      }while(fila_vazia(ponteiroFila)!=1);
		  
				
				 meuDelay();			 
				 system("cls");
				 tabuleiroFase3(letra,PonteiroPraSeta);
			     impresaoNaoConvencional_fila(ponteiroFila);
					  
			        
						if(letra[7][7]=='P')// Completou a ida corretamente
			            {   
	    	              Beep(567,500);
	    	              printf("\n\n\t\tParabens!!! Voce alcancou o primeiro objetivo da fase 3 ");
	    	              getch();
  	    
	    	              opcaoDeInserir = 1;
  	                      opcaodeCompilar = 2;
  	                      copiaDeopcaoDeInserir = opcaoDeInserir;
  	                      *PonteiroPraSeta = '<';
						 	
						 	system("cls");
						 	
							  		 while(copiaDeopcaoDeInserir==1)
							 	     { 
							 		  
								   	  tabuleiroInicial_Fase3_volta(letra); 
								
										do{
								         tabuleiroFase3_volta(letra,PonteiroPraSeta);
								         impresaoNaoCovencional_pilha(ponteiroNoPilha);
								         printf("\n\n\t\t\t\t\t\t\t\t\t\t  -> Digite o comando: "); scanf("%d",&verificaComando);  
								         printf("\n\t\t\t\t\t\t\t\t\t\t  -> Numero de repeticoes: "); scanf("%d",&numeroDeRepeticoes); 
					      
				                     	}while(verificaComando <1 || verificaComando>4);
				    	
										 acessoEmPilha.comando = verificaComando;
								       	 acessoEmPilha.numVezes = numeroDeRepeticoes;
										 empilhar(&ponteiroNoPilha,acessoEmPilha);
					
				
					                    tabuleiroFase3_volta(letra,PonteiroPraSeta);
				                        impresaoNaoCovencional_pilha(ponteiroNoPilha);
				       
									       do{
									       tabuleiroFase3_volta(letra,PonteiroPraSeta);
										   impresaoNaoCovencional_pilha(ponteiroNoPilha);
										   printf("\n\n \t\t\t\t\t\t\t\t\t\tTecle 1(inserir) ou 2(executar jogo): ");
									       scanf("%d",&escolha);
									       system("cls");
										   }while(escolha!=1 && escolha != 2);
					 	
						                   copiaDeopcaoDeInserir = opcaoDeInserir; 
						 
						    
				       
				                           if(escolha == opcaodeCompilar)
				                           {
				    
				                              do{
										            tabuleiroFase3_volta(letra,PonteiroPraSeta);
										            impresaoNaoCovencional_pilha(ponteiroNoPilha);
										           
										           movimentarPlayerFase3_volta(letra,PonteiroPraSeta,ponteiroNoPilha);
										           
										           
										            meuDelay();
										            desempilhar(&ponteiroNoPilha);
										          
					                        	} while(pilha_vazia(ponteiroNoPilha)!=1);
				  
							
												meuDelay();			 //mostrar P se movimentando mais lentamante 
												system("cls");
												tabuleiroFase3_volta(letra,PonteiroPraSeta);
											    impresaoNaoCovencional_pilha(ponteiroNoPilha);
								 
												 if(letra[0][0]=='P') //verifica se o usuario concluiu o caminho de volta e ganhou o jogo
					                             {
					                                Beep(567,500); 
					                                return 1;
							                   	 }    
								   
								                else
				                                {
													contRepeticao--; 
										                if(contRepeticao>0){
										                   	
														     	printf("\n\n\t\t\t\t\t\t\t\t\t            %d tentativas restantes!!",contRepeticao); 
																printf("\n\n\n\t\t\t\t\t\t\t\t\t            Tecle Qualquer Tecla Para Tentar Novamente: ");
																getch();
															}
											                      
		            
															system("cls");
															*PonteiroPraSeta = '<';
															copiaDeopcaoDeInserir= 1;
															
															if(contRepeticao==0)
										                   {
										                   	copiaDeopcaoDeInserir=3;
										                   }
							
		                                         }
		                                    }
		
										}
	                                 	
						                     
					}
	              
				           
						   //o usuario ainda nao venceu a ida
					    else
						{
								contRepeticao--; 
			                	if(contRepeticao>0){
								printf("\n\n\t\t\t\t\t\t\t\t\t            %d tentativas restantes!!",contRepeticao); 
								
							  
							    //Se o usuario ainda tiver chance de jogar
							
							
									printf("\n\n\n\t\t\t\t\t\t\t\t\t            Tecle Qualquer Tecla Para Tentar Novamente: ");
									getch();
						  
								}
					                      
					            
								system("cls");
								*PonteiroPraSeta = '>';
								copiaDeopcaoDeInserir= 1;
								
								 if(contRepeticao==0)
	                            {
	                           	copiaDeopcaoDeInserir= 3;   //o Ususario ja ultrapassou o limite de tentativas, passo um valor qualquer para sair do while
					         	}		
					    }
					        
		    }
		 }
		     if(copiaDeopcaoDeInserir== 3)
		     {
		   	 system("cls");
			 tabuleiroFase1(letra,PonteiroPraSeta);
			 impresaoNaoConvencional_fila(ponteiroFila);
		     meuDelay();
		   	 meuDelay();
			 }
		  
		    
	
   }while(contRepeticao>0);
   
	        	system("cls");
	        	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tGAME OVER\n"); //ultrapassou as tentativas 
	        	exit(1);
}




char menuInicial(){
	
char opcao;
  
  do{
  	  system("cls");
  	  printf("\n\n\n\n\t ________________________________________________________________________________________________________\n");
	  printf("\t{                                                                                                        }\n");
	  printf("\t{***                                  _____________________________________                              }\n");
	  printf("\t{                                    |   S - START GAME                    |                             }\n");
	  printf("\t{                                    |   I - CONHECER OS DEVS DO PROJETO   |                             }\n");
	  printf("\t{                                    |   X - SAIR                          |                             }\n");
	  printf("\t{                                    |_____________________________________|                             }\n");
	  printf("\t{                                                                                                        }\n");
	  printf("\t{                                                                                                        }\n");
	  printf("\t{                                                                                                     ***}\n");
	  printf("\t{________________________________________________________________________________________________________}\n");
	  
	  printf("\t                                      Escolha uma opcao: ");
	  //fflush(stdin);
	  scanf("%c",&opcao);
	  
	  if(opcao == 's' )break;
	  if(opcao == 'i' )break;
	  if(opcao == 'x' )break;
	  
  }
  while(opcao != 's' && opcao != 'i' && opcao != 'x');
  
  	system("cls");
	return opcao;
	
}

void apresentacao(){
	printf("\n\n\n\n\t Criadores: Eliezer Assuncao de Paulo e Camille Custodio de Paiva\n");
	printf("\t Somos estudantes da UFV e amamos tecnologia ;)\n\n");
	getchar();
}

void comecarJogo(){
	Fila *ponteiroFila;
	ponteiroFila = (Fila*)malloc(sizeof(Fila));
			  
	NO *ponteiroNo;
	Pilha acessoEmPilha;
	Dfila acessoEmFila;
			  
	inicializarFila(ponteiroFila);
	inicializar(&ponteiroNo);
			  
	int opcao,escolha;
	char *PonteiroPraSeta;
	char seta = '>';
	PonteiroPraSeta = &seta;
			  
	char letra[8][8];  
			  
	int i=0,contRepeticao=0;
	char enter;
			  
	int verificaComando;
	int numeroDeRepeticoes;
			 
	int venceuOuNaoFase1;
	int sim = 1;
	int venceuOuNaoSegundaFase;
	int venceuOuNaoTerceiraFase;
		  	
		venceuOuNaoFase1 = execucaoFase1(acessoEmFila,ponteiroFila,letra,PonteiroPraSeta);
		
		
		if(venceuOuNaoFase1 == sim)
		{
			printf("\n\n\t\t\t\tParabens!!! - Voce passsou de fase!");
			fflush(stdin);
			scanf("%c",&enter);
			    
			    
			venceuOuNaoSegundaFase = execucaoFase2(acessoEmPilha,ponteiroNo,letra,PonteiroPraSeta);
			    
			    if(venceuOuNaoSegundaFase == sim){
					printf("\n\n\t\t\t\tParabens!!! - Voce passsou de fase!");
				    fflush(stdin);
			   		scanf("%c",&enter);
			   			
						       
			    	venceuOuNaoTerceiraFase = execucaoFase3(acessoEmFila,acessoEmPilha,ponteiroFila,ponteiroNo,letra,PonteiroPraSeta);
			    		
			    	if(venceuOuNaoTerceiraFase == sim)
			    	{
			    		
			    		printf("\n\n\t\t\tParabens voce venceu o jogo!");
			    		
					}
			}
			    
		}
			
}

