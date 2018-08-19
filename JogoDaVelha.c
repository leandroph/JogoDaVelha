#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void tabuleiro(char casas2[9]){//deseja o tabuleiro
	system("cls");
	printf("\t  %c  |  %c  |  %c  \n", casas2[0], casas2[1], casas2[2]);
	printf("\t------------------\n");
	printf("\t  %c  |  %c  |  %c  \n", casas2[3], casas2[4], casas2[5]);
	printf("\t------------------\n");
	printf("\t  %c  |  %c  |  %c  \n", casas2[6], casas2[7], casas2[8]);
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char casas[9] = {'1','2','3','4','5','6','7','8','9'};
	
	char resp;
	int cont_jogadas, jogada = 1, vez = 0, i, pontos_X = 0, pontos_O= 0, empate = 0;
	do{
		cont_jogadas = 1;
		for(i = 0; i < 9; i++ ){
			casas[i] = ' ';
		}
		
		do{
			tabuleiro(casas);//chama o método do tabuleiro passando a variavel casas como parametro
			
			if(jogada == 0){
				printf("\nJOGADA INVÁLIDA, TENTE NOVAMENTE ");
			}
			
			printf("\nDigite a casa a ser marcada [1-9] ");
			
			if(vez % 2 == 0){
				printf("\nJOGADOR X: ");
			}else{
				printf("\nJOGADOR O: ");
			}
				
			scanf("%i", &jogada);
			
			if(jogada < 1 || jogada > 9){
				jogada = 0;
			}else if(casas[jogada - 1] == 'X' || casas[jogada - 1] == 'O'){
				jogada = 0;
			}else{
				if(vez % 2 == 0){
					casas[jogada - 1] = 'X';
				}else{
					casas[jogada - 1] = 'O';
				}
				cont_jogadas++;
				vez++;
				
			}
			
			//verificando as posições de vitória
			if (casas[0] == 'X' && casas[1] == 'X' && casas[2] == 'X'){cont_jogadas = 11;}	
			if (casas[3] == 'X' && casas[4] == 'X' && casas[5] == 'X'){cont_jogadas = 11;}	
			if (casas[6] == 'X' && casas[7] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}		
			if (casas[0] == 'X' && casas[3] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}	
			if (casas[1] == 'X' && casas[4] == 'X' && casas[7] == 'X'){cont_jogadas = 11;}	
			if (casas[2] == 'X' && casas[5] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}	
			if (casas[0] == 'X' && casas[4] == 'X' && casas[8] == 'X'){cont_jogadas = 11;}	
			if (casas[3] == 'X' && casas[4] == 'X' && casas[6] == 'X'){cont_jogadas = 11;}	
			
			if (casas[0] == 'O' && casas[1] == 'O' && casas[2] == 'O'){cont_jogadas = 12;}	
			if (casas[3] == 'O' && casas[4] == 'O' && casas[5] == 'O'){cont_jogadas = 12;}	
			if (casas[6] == 'O' && casas[7] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}		
			if (casas[0] == 'O' && casas[3] == 'O' && casas[6] == 'O'){cont_jogadas = 12;}	
			if (casas[1] == 'O' && casas[4] == 'O' && casas[7] == 'O'){cont_jogadas = 12;}	
			if (casas[2] == 'O' && casas[5] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}	
			if (casas[0] == 'O' && casas[4] == 'O' && casas[8] == 'O'){cont_jogadas = 12;}	
			if (casas[3] == 'O' && casas[4] == 'O' && casas[6] == 'O'){cont_jogadas = 12;}	
				
		}while(cont_jogadas <= 9);
		
		tabuleiro(casas);
		
		if(cont_jogadas == 10){
			printf("JOGO EMPATADO\n");
			
			empate++;
		}
		if(cont_jogadas == 11){
			printf("VENCEDOR JOGADOR X\n");
			
			pontos_X++;	
		}
		if(cont_jogadas == 12){
			printf("VENCEDOR JOGADOR O\n");
			
			pontos_O++;
		}
		
		printf("\n##########################");
		printf("\n#        PLACAR          #");
		printf("\n# Pontos JOGADOR X: %i    #", pontos_X);
		printf("\n# Pontos JOGADOR O: %i    #", pontos_O);
		printf("\n# EMPATES: %i             #", empate);
		printf("\n##########################");
		
		printf("\n\nDeseja continuar [S/N]: ");
		scanf("%s", &resp);
		strupr(&resp);
	}while(resp == 'S');
	return 0;
}
