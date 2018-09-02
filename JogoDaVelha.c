#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

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
	int opcao;
	
	do{
		tabuleiro(casas);
		
		printf("Digite 1 para jogar com um amigo\n");
		printf("Digite 2 para jogar com o computador\n");
		scanf("%i", &opcao);
	}while(opcao < 1 || opcao > 2);
	
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
				scanf("%i", &jogada);
			}else{
				if(opcao == 1){
					printf("\nJOGADOR O: ");
					scanf("%i", &jogada);
				}else{
					//aqui o Pc tenta vencer
					//verificando o Jogador O
					//verificando as linhas da letra O
					if(casas[0] == 'O' && casas[1] == 'O' && casas[2] == ' '){jogada = 3;}
					else if(casas[3] == 'O' && casas[4] == 'O' && casas[5] == ' '){jogada = 6;}
					else if(casas[6] == 'O' && casas[7] == 'O' && casas[8] == ' '){jogada = 9;}
					else if(casas[0] == 'O' && casas[1] == ' ' && casas[2] == 'O'){jogada = 2;}
					else if(casas[3] == 'O' && casas[4] == ' ' && casas[5] == 'O'){jogada = 5;}
					else if(casas[6] == 'O' && casas[7] == ' ' && casas[8] == 'O'){jogada = 8;}
					else if(casas[0] == ' ' && casas[1] == 'O' && casas[2] == 'O'){jogada = 1;}
					else if(casas[3] == ' ' && casas[4] == 'O' && casas[5] == 'O'){jogada = 4;}
					else if(casas[6] == ' ' && casas[7] == 'O' && casas[8] == 'O'){jogada = 7;}
					//verificando as colunas da letra O
					else if(casas[0] == 'O' && casas[3] == 'O' && casas[6] == ' '){jogada = 7;}
					else if(casas[1] == 'O' && casas[4] == 'O' && casas[7] == ' '){jogada = 8;}
					else if(casas[2] == 'O' && casas[5] == 'O' && casas[8] == ' '){jogada = 9;}
					else if(casas[0] == 'O' && casas[3] == ' ' && casas[6] == 'O'){jogada = 4;}
					else if(casas[1] == 'O' && casas[4] == ' ' && casas[7] == 'O'){jogada = 5;}
					else if(casas[2] == 'O' && casas[5] == ' ' && casas[8] == 'O'){jogada = 6;}
					else if(casas[0] == ' ' && casas[3] == 'O' && casas[6] == 'O'){jogada = 1;}
					else if(casas[1] == ' ' && casas[4] == 'O' && casas[7] == 'O'){jogada = 2;}
					else if(casas[2] == ' ' && casas[5] == 'O' && casas[8] == 'O'){jogada = 3;}
					//verificando a diagonal principal da letra O
					else if(casas[0] == 'O' && casas[4] == 'O' && casas[8] == ' '){jogada = 9;}
					else if(casas[0] == 'O' && casas[4] == ' ' && casas[8] == 'O'){jogada = 5;}
					else if(casas[0] == ' ' && casas[4] == 'O' && casas[8] == 'O'){jogada = 1;}
					//verificando a diagonal secundária da letra O
					else if(casas[2] == 'O' && casas[4] == 'O' && casas[6] == ' '){jogada = 7;}
					else if(casas[2] == 'O' && casas[4] == ' ' && casas[6] == 'O'){jogada = 5;}
					else if(casas[2] == ' ' && casas[4] == 'O' && casas[6] == 'O'){jogada = 3;}
					
					//aqui o Pc tenta anular a vitória do desafiante
					//verificando o Jogador X
					//verificando as linhas da letra X
					else if(casas[0] == 'X' && casas[1] == 'X' && casas[2] == ' '){jogada = 3;}
					else if(casas[3] == 'X' && casas[4] == 'X' && casas[5] == ' '){jogada = 6;}
					else if(casas[6] == 'X' && casas[7] == 'X' && casas[8] == ' '){jogada = 9;}
					else if(casas[0] == 'X' && casas[1] == ' ' && casas[2] == 'X'){jogada = 2;}
					else if(casas[3] == 'X' && casas[4] == ' ' && casas[5] == 'X'){jogada = 5;}
					else if(casas[6] == 'X' && casas[7] == ' ' && casas[8] == 'X'){jogada = 8;}
					else if(casas[0] == ' ' && casas[1] == 'X' && casas[2] == 'X'){jogada = 1;}
					else if(casas[3] == ' ' && casas[4] == 'X' && casas[5] == 'X'){jogada = 4;}
					else if(casas[6] == ' ' && casas[7] == 'X' && casas[8] == 'X'){jogada = 7;}
					//verificando as colunas da letra O
					else if(casas[0] == 'X' && casas[3] == 'X' && casas[6] == ' '){jogada = 7;}
					else if(casas[1] == 'X' && casas[4] == 'X' && casas[7] == ' '){jogada = 8;}
					else if(casas[2] == 'X' && casas[5] == 'X' && casas[8] == ' '){jogada = 9;}
					else if(casas[0] == 'X' && casas[3] == ' ' && casas[6] == 'X'){jogada = 4;}
					else if(casas[1] == 'X' && casas[4] == ' ' && casas[7] == 'X'){jogada = 5;}
					else if(casas[2] == 'X' && casas[5] == ' ' && casas[8] == 'X'){jogada = 6;}
					else if(casas[0] == ' ' && casas[3] == 'X' && casas[6] == 'X'){jogada = 1;}
					else if(casas[1] == ' ' && casas[4] == 'X' && casas[7] == 'X'){jogada = 2;}
					else if(casas[2] == ' ' && casas[5] == 'X' && casas[8] == 'X'){jogada = 3;}
					//verificando a diagonal principal da letra O
					else if(casas[0] == 'X' && casas[4] == 'X' && casas[8] == ' '){jogada = 9;}
					else if(casas[0] == 'X' && casas[4] == ' ' && casas[8] == 'X'){jogada = 5;}
					else if(casas[0] == ' ' && casas[4] == 'X' && casas[8] == 'X'){jogada = 1;}
					//verificando a diagonal secundária da letra O
					else if(casas[2] == 'X' && casas[4] == 'X' && casas[6] == ' '){jogada = 7;}
					else if(casas[2] == 'X' && casas[4] == ' ' && casas[6] == 'X'){jogada = 5;}
					else if(casas[2] == ' ' && casas[4] == 'X' && casas[6] == 'X'){jogada = 3;}
					//se não escolher nenhuma das jogadas acima é feita uma jogada aleatória
					else{
						do{
							srand((unsigned)time(NULL));
							jogada = 1 + rand() % 9;
						}while(casas[jogada - 1] != ' ');	
					}
				}
				
			}
				
			
			
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
