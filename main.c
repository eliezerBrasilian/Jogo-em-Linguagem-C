/* 6317 Eliezer Assuncao de Paulo  
7570 Camille Custodio de Paiva


 GRUPO 4 */

#include"library.c"

int main()
{
	char opcaoEscolhidaPeloPlayer;
	
    do{
    	opcaoEscolhidaPeloPlayer = menuInicial();

		  if(opcaoEscolhidaPeloPlayer == 's')
		  {
		  	
			  comecarJogo();
		  	
		  }
		  
		  if(opcaoEscolhidaPeloPlayer == 'i')
		  {
		  	apresentacao();
		  	printf("\n\n\t Digite alguma tecla para retornar ao menu: ");
		  	//system("pause");
			getch();
		  	
		  }
		  
		  if(opcaoEscolhidaPeloPlayer == 'x'){
		  	exit(1);
		  }
	}while(opcaoEscolhidaPeloPlayer != 's');
   
  return 0;
  
}
