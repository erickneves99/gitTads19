#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	
	//variaveis menu
	int opcao, continuar, dificuldade, menu, mapa = 0, liberado = 0;
	char jogador[20]; 
		
do {
	
	printf("\n =============Menu=============");
	printf("\n ==============================");
	printf("\n = (1)Configuracao:           =");
	printf("\n = (2)Iniciar jogo:           =");
	printf("\n = (3)Pontuacao:              =");
	printf("\n ==============================");
		if(liberado == 1) {
			printf("\n = Inicie o jogo %s", jogador);
		}
	
	printf("\n = ");
	scanf("%i", &opcao);
		if(opcao != 0 && opcao <= 3){
			system	("cls");
			menu = 0; //desliga menu
		}
	
	//config
	if (opcao == 1){
		printf("\n ==============================");
		printf("\n = Tamanho do mapa:           =");
		printf("\n = (1)Facil: (5)x(5)          =");
		printf("\n = (2)Medio: (10)x(10)        =");
		printf("\n = (3)Dificil: (25)x(40)      =");
		printf("\n ==============================");
		printf("\n = ");
		scanf("%i", &dificuldade);
		
		if(dificuldade != 0 && dificuldade <= 3) {
			printf("\n ==============================");
			printf("\n = Digite o nome do jogador:  =");
			printf("\n ==============================");
			printf("\n = ");
			fflush(stdin);
			gets(jogador);
			liberado = 1;
			menu = 1; //liga menu
			system ("cls");
		}
	}
		//mapa escolhido
		if (opcao == 2 && (dificuldade != 0 && dificuldade <= 3)) {
			if (dificuldade == 1) {
				mapa = 1;
			}
				else if (dificuldade == 2) {
					mapa = 2;
				}
					else if (dificuldade == 3){
					mapa = 3;
					}
		menu = 0; // desliga menu
		}
		
		if (opcao == 3) {
			//sistema de pontua��o
		}
		
		else if (opcao == 0 || opcao > 3){
			system ("cls");
			printf("\n =  Escolha uma opcao valida  =");
			menu = 1; //liga menu
		}

	
	/*
	inicio
	la�o
	Mapa:
		1
	*/
	
		if (mapa == 1) {
				
			int mapafim = 0;
			int lin = 5, col = 5;
			int y, x, HP = 100, vida = 4;
			int spawn, inimigo, chave = '!', jogada;
			int px = 2, py = 0, cx = 0, cy = 0, ix = 0, iy = 0;
			char pegar = 0;
			
			srand (time(NULL));
			
				do {
				
					char lab[5][5] = {
					{'#','#','#','#','#'},
					{'#',' ',' ',' ','#'},
					{' ',' ','#',' ','#'},
					{'#',' ',' ',' ','I'},
					{'#','#','#','#','#'}
					};
					
					spawn = '@';
					lab[px][py] = spawn;
					
						if(pegar == 0){
												
							while(lab[cx][cy] == '#' || lab[cx][cy] == 'I'){
								cx = rand()%lin;
								cy = rand()%col;
							}
							lab[cx][cy] = chave;
													
						}
							if(pegar == 1) {
								if(cx == px && cy == py){
									chave = '@';
								}
									else {
										chave = ' ';
									}
							}
										
																	
						if(cx == px && cy == py) {
							if(pegar == 0){
							printf("\n ======= Pegou a chave! =======\n");
							}
							pegar = 1;																			
						}
															
					inimigo = '<';					
								
					if(ix == 0) {
							while(lab[ix][iy] == '#' || lab[ix][iy] == 'I'){
								ix = rand()%lin;
								iy = rand()%col;
							}							
					}
					lab[ix][iy] = inimigo;
				
					//matriz e est�tico					
					
					printf("\n ========== Labirinto =========\n");
					for(x=0; x < lin; x++){		  
		        		for(y=0; y < col; y++){
			        		printf(" %c", lab[x][y]);
						}
						printf("\n");
			        }
						
						printf(" HP: %i", HP);
						//Encontro inimigo - personagem
						
							if( (ix == px && iy == py) ){
								HP = HP -25;
								printf("\n Voce perdeu uma vida :( ");
								vida = vida - 1;
							}
								if(vida == 4){
									printf("\n Vida: @ @ @ @\n");
								}
									else if(vida == 3){
									printf("\n Vida: @ @ @ \n");
									}
										else if(vida == 2){
											printf("\n Vida: @ @\n");
										}
											else if(vida == 1){
												printf("\n Vida: @\n");
											}
																			
								if(HP <= 0){
									mapafim = 3;
								}
						//mov personagem
						if (spawn != lab[3][4]) {
							fflush(stdin);
							jogada = getchar();
								if(jogada == 'w') {
									if(lab[px-1][py] != '#'){
										px = px - 1;
									}
						
								}
								
								if(jogada == 's') {
									if(lab[px+1][py] != '#'){
										px = px + 1;
									}
						
								}
								
								if(jogada == 'd') {
									if(lab[px][py+1] != '#'){
										py = py+1;
									}
								}
								
								if(jogada == 'a') {
									if(lab[px][py-1] != '#'){
									py = py-1;
									}
								}
					
					 	}// fim
						
						//mov ' < '
						if(jogada =='w'){
							if(lab[ix-1][iy] != '#' && lab[ix-1][iy] != 'I'){
								ix--;
							}
						}
						if(jogada =='s'){
							if(lab[ix+1][iy] != '#' && lab[ix+1][iy] != 'I'){
								ix++;
							}
						}
						if(jogada =='d'){
							if(lab[ix][iy+1] != '#' && lab[ix][iy+1] != 'I'){
								iy++;
							}
						}
						if(jogada =='a'){
							if(lab[ix][iy-1] != '#' && lab[ix][iy-1] != 'I'){
								iy--;
							}
						}
						
						else if(spawn == lab [3][4] && chave == '!'){
									mapafim = 2;
								}
						
						else if(spawn == lab[3][4] && chave == ' ') {
									mapafim = mapafim + 1;
								}																		
						
						system ("cls");
				
				}while (mapafim == 0 );
				//la�o mapa
				
			if(mapafim == 1) {
				printf("\n ======== Voce venceu! ========\n");
			}
			
				else if(mapafim == 2) {
					printf("\n === Voce nao pegou a chave ===\n");
				}
					else if(mapafim == 3){					
						printf("\n ======== Voce morreu =========\n");	
					}
				
					
			printf("\n = Voltar ao menu (1) ou (0)? =\n");			
			scanf("%i", &continuar);
			if(continuar == 1) {
				dificuldade = 0;	
				liberado = 0;
				mapa = 0;
				menu = 1;
			}
				else { system ("cls");
				printf("\n ======== Fim de jogo. ======== ");
				}
				
					
				
		}	//fim do mapa 1
		
	/*
	inicio
	la�o
	Mapa:
		2
	*/	
	
	if (mapa == 2) {
				
			int mapafim = 0;
			int lin = 10, col = 10;
			int y, x, HP = 100, vida = 5;
			int spawn, inimigo, inimigo2, chave = '!', jogada;
			int px = 8, py = 0, cx = 0, cy = 0, ix = 0, iy = 0, i2x = 0, i2y = 0;
			char pegar = 0;
			
			srand (time(NULL));
			
				do {
				
					char lab[10][10] = {
					{'#','#','#','#','#','#','#','#','I','#'},
					{'#',' ',' ',' ',' ',' ','#',' ',' ','#'},
					{'#',' ','#','#','#',' ',' ',' ','#','#'},
					{'#',' ',' ',' ',' ','#','#','#',' ','#'},
					{'#','#',' ','#',' ',' ',' ',' ',' ','#'},
					{'#',' ','#',' ','#','#',' ','#','#','#'},
					{'#',' ',' ',' ',' ','#',' ',' ',' ','#'},
					{'#','#',' ','#',' ','#','#','#',' ','#'},
					{' ',' ',' ','#',' ',' ',' ',' ',' ','#'},					
					{'#','#','#','#','#','#','#','#','#','#'}
					};
					
					spawn = '@';
					lab[px][py] = spawn;
					
						if(pegar == 0){
												
							while(lab[cx][cy] == '#' || lab[cx][cy] == 'I'){
								cx = rand()%lin;
								cy = rand()%col;
							}
							lab[cx][cy] = chave;
													
						}
							if(pegar == 1) {
								if(cx == px && cy == py){
									chave = '@';
								}
									else {
										chave = ' ';
									}
							}
										
																	
						if(cx == px && cy == py) {
							if(pegar == 0){
							printf("\n ======= Pegou a chave! =======\n");
							}
							pegar = 1;																			
						}
					
					inimigo = '<';
					inimigo2 = '<';
								
					if(ix == 0) {
							while(lab[ix][iy] == '#' || lab[ix][iy] == 'I'){
								ix = rand()%lin;
								iy = rand()%col;
							}
							while(lab[i2x][i2y] == '#' || lab[i2x][i2y] == 'I'){
								i2x = rand()%lin;
								i2y = rand()%col;
							}
					}
					lab[ix][iy] = inimigo;													
					lab[i2x][i2y] = inimigo2;														
												
					//matriz lab e est�tica
						   
					printf("\n ========== Labirinto =========\n");
					
					for(x=0; x < lin; x++){		  
		        		for(y=0; y < col; y++){
			        		printf(" %c", lab[x][y]);
						}
						printf("\n");
			        }
						printf(" HP: %i", HP);
						//Encontro inimigo - personagem
						
							if( (ix == px && iy == py) || (i2x == px && i2y == py) ){
								HP = HP -20;
								printf("\n Voce perdeu uma vida :( ");
								vida = vida -1;
							}
								if(vida == 5){
									printf("\n Vida: @ @ @ @ @\n");
								}
									else if(vida == 4){
									printf("\n Vida: @ @ @ @ \n");
									}
										else if(vida == 3){
											printf("\n Vida: @ @ @\n");
										}
											else if(vida == 2){
												printf("\n Vida: @ @\n");
											}
												else if(vida == 1){
													printf("\n Vida: @\n");
												}
													if(HP <= 0){
														mapafim = 3;
													}
						//mov personagem
						if (spawn != lab[0][8]) {
							fflush(stdin);
							jogada = getchar();
								if(jogada == 'w') {
									if(lab[px-1][py] != '#'){
										px = px - 1;
									}
						
								}
								
								if(jogada == 's') {
									if(lab[px+1][py] != '#'){
										px = px + 1;
									}
						
								}
								
								if(jogada == 'd') {
									if(lab[px][py+1] != '#'){
										py = py+1;
									}
								}
								
								if(jogada == 'a') {
									if(lab[px][py-1] != '#'){
									py = py-1;
									}
								}
					
					 	}// fim
						
					//mov ' < '
						if(jogada =='w'){
							if(lab[ix-1][iy] != '#' && lab[ix-1][iy] != 'I'){
								ix--;
							}
						}
						if(jogada =='s'){
							if(lab[ix+1][iy] != '#' && lab[ix+1][iy] != 'I'){
								ix++;
							}
						}
						if(jogada =='d'){
							if(lab[ix][iy+1] != '#' && lab[ix][iy+1] != 'I'){
								iy++;
							}
						}
						if(jogada =='a'){
							if(lab[ix][iy-1] != '#' && lab[ix][iy-1] != 'I'){
								iy--;
							}
						}
						
					//mov ' < '	2
							if(jogada =='w'){
								if(lab[i2x-2][i2y] == ' ' || lab[i2x-2][i2y] == '@' || lab[i2x-2][i2y] == '!' || lab[i2x-2][i2y] == '<'){
									i2x = i2x -2;
								}
									else if(lab[i2x-2][i2y] == '#' && lab[i2x-1][i2y] != '#' && lab[i2x-1][i2y] != 'I'){
										i2x = i2x -1;
									}
							}
							if(jogada =='s'){
								if(lab[i2x+2][i2y] == ' ' || lab[i2x+2][i2y] == '@' || lab[i2x+2][i2y] == '!' || lab[i2x+2][i2y] == '<'){
									i2x = i2x +2;
								}
									else if(lab[i2x+2][i2y] == '#' && lab[i2x+1][i2y] != '#' && lab[i2x+1][i2y] != 'I'){
										i2x = i2x +1;
									}
							}
							if(jogada =='d'){
								if(lab[i2x][i2y+2] == ' ' || lab[i2x][i2y+2] == '@' || lab[i2x][i2y+2] == '!' || lab[i2x][i2y+2] == '<'){
									i2y = i2y + 2;
								}
									else if(lab[i2x][i2y+2] == '#' && lab[i2x][i2y+1] != '#' && lab[i2x][i2y+1] != 'I'){
										i2y = i2y + 1;
									}
							}
							if(jogada =='a'){
								if(lab[i2x][i2y-2] == ' ' || lab[i2x][i2y-2] == '@' || lab[i2x][i2y-2] == '!' || lab[i2x][i2y-2] == '<'){
									i2y = i2y - 2;
								}
									else if(lab[i2x][i2y-2] == '#' && lab[i2x][i2y-1] != '#' && lab[i2x][i2y-1] != 'I'){
										i2y = i2y - 1;
									}
							}
					
						
						
						else if(spawn == lab [0][8] && chave == '!'){
									mapafim = 2;
								}
						
						else if(spawn == lab[0][8] && chave == ' ') {
									mapafim = mapafim + 1;
								}																		
						
						system ("cls");
				
				}while (mapafim == 0 );
				//la�o mapa
				
			if(mapafim == 1) {
				printf("\n ======== Voce venceu! ========\n");
			}
			
				else if(mapafim == 2) {
					printf("\n === Voce nao pegou a chave ===\n");
				}
					else if(mapafim == 3){					
						printf("\n ======== Voce morreu =========\n");	
					}	
		
			printf("\n = Voltar ao menu (1) ou (0)? =\n");			
			scanf("%i", &continuar);
			if(continuar == 1) {
				dificuldade = 0;	
				liberado = 0;
				mapa = 0;
				menu = 1;
			}
				else { system ("cls");
				printf("\n ======== Fim de jogo. ======== ");
				}
		
	}	//fim do mapa 2

	/*
	inicio
	la�o
	Mapa:
		3
	*/	
	
	if (mapa == 3) {
				
			int mapafim = 0;
			int lin = 25, col = 40;
			int y, x, HP = 100, vida = 6;
			int spawn, inimigo, inimigo2, inimigo3, inimigo4, inimigo5, inimigo6, chave = '!', jogada;
			int px = 1, py = 0, cx = 0, cy = 0, ix = 0, iy = 0, i2x = 0, i2y = 0, i3x = 0, i3y = 0, i4x = 0, i4y = 0, i5x = 0, i5y = 0, i6x = 0, i6y = 0;
			char pegar = 0;
			
			srand (time(NULL));
			
				do {
				
					char lab[25][40] = {
				    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
				    {' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ','#','#',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ','#'},
				    {'#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#','#',' ','#'},
				    {'#',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ','#'},
				    {'#',' ','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#'},
				    {'#',' ','#',' ',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#','#',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ',' ','#'},
				    {'#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ',' ',' ',' ',' ','#',' ','#','#','#',' ','#','#','#','#','#','#','#','#','#',' ','#',' ','#','#',' ','#'},
				    {'#',' ','#',' ','#',' ',' ','#',' ','#','#','#','#',' ','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','#'},
				    {'#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ','#',' ',' ',' ','#','#','#','#','#',' ','#',' ','#',' ','#',' ','#','#',' ','#','#',' ','#',' ','#','#'},
				    {'#',' ','#',' ',' ',' ',' ','#',' ','#','#','#','#',' ','#','#','#','#','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#','#',' ',' ','#',' ','#',' ',' ','#'},
				    {'#',' ','#','#','#','#',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ','#',' ','#','#','#','#','#',' ','#'},
				    {'#',' ',' ',' ',' ','#',' ','#',' ','#','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ','#','#','#','#',' ',' ',' ','#',' ','#',' ','#'},
				    {'#',' ','#','#',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#'},
				    {'#',' ','#',' ',' ','#',' ','#',' ','#','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#','#','#','#',' ','#',' ','#',' ','#','#','#','#','#'},
				    {'#',' ','#',' ','#','#',' ','#',' ','#',' ',' ',' ',' ','#',' ','#',' ',' ','#',' ',' ',' ',' ','#',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#'},
				    {'#',' ','#',' ','#',' ',' ','#',' ','#','#','#','#','#','#',' ','#',' ','#','#',' ','#','#','#','#','#','#','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#'},
				    {'#',' ','#',' ','#',' ','#','#',' ','#',' ',' ',' ',' ',' ',' ','#',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#'},
				    {'#',' ','#',' ','#',' ',' ','#',' ','#',' ','#','#','#','#','#','#','#',' ','#',' ','#','#','#','#','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ',' ',' ','#'},
				    {'#',' ','#','#','#','#','#','#',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#'},
				    {'#',' ',' ',' ',' ','#',' ',' ',' ','#',' ','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#'},
				    {'#',' ','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#','#','#',' ',' ',' ','#',' ','#','#','#',' ','#'},
				    {'#',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#',' ','#',' ',' ',' ',' ',' ','#','#','#',' ','#',' ','#',' ','#',' ','#'},
				    {'#',' ','#','#',' ','#',' ','#','#','#',' ','#','#','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','#','#',' ','#',' ',' ',' ','#',' ','#',' ','#',' ','#'},
				    {'#',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ',' ',' ','#',' ',' ',' ',' ',' ','#',' ','#',' ',' ',' ',' ',' ','#',' ','I'},
				    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}
				    };
					
					spawn = '@';
					lab[px][py] = spawn;
					
						if(pegar == 0){
												
							while(lab[cx][cy] == '#' || lab[cx][cy] == 'I'){
								cx = rand()%lin;
								cy = rand()%col;
							}
							lab[cx][cy] = chave;
													
						}
							if(pegar == 1) {
								if(cx == px && cy == py){
									chave = '@';
								}
									else {
										chave = ' ';
									}
							}
										
																	
						if(cx == px && cy == py) {
							if(pegar == 0){							
							printf("\n ======= Pegou a chave! =======\n");
							}
							pegar = 1;																			
						}
						
						inimigo = '<';
						inimigo2 = '<';
						inimigo3 = '<';	
						inimigo4 = '<';
						inimigo5 = '<';
						inimigo6 = '<';
						
						if(ix == 0) {
								while(lab[ix][iy] == '#' || lab[ix][iy] == 'I'){
									ix = rand()%lin;
									iy = rand()%col;
								}
								while(lab[i2x][i2y] == '#' || lab[i2x][i2y] == 'I'){
									i2x = rand()%lin;
									i2y = rand()%col;
								}
								while(lab[i3x][i3y] == '#' || lab[i3x][i3y] == 'I'){
									i3x = rand()%lin;
									i3y = rand()%col;
								}
								while(lab[i4x][i4y] == '#' || lab[i4x][i4y] == 'I'){
									i4x = rand()%lin;
									i4y = rand()%col;
								}
								while(lab[i5x][i5y] == '#' || lab[i5x][i5y] == 'I'){
									i5x = rand()%lin;
									i5y = rand()%col;
								}
								while(lab[i6x][i6y] == '#' || lab[i6x][i6y] == 'I'){
									i6x = rand()%lin;
									i6y = rand()%col;
								}
						}
						lab[ix][iy] = inimigo;						
						lab[i2x][i2y] = inimigo2;
						lab[i3x][i3y] = inimigo3;
						lab[i4x][i4y] = inimigo4;
						lab[i5x][i5y] = inimigo5;
						lab[i6x][i6y] = inimigo6;
						
					//matriz lab e est�tica
						   
					printf("\n ========== Labirinto =========\n");
					
					for(x=0; x < lin; x++){		  
		        		for(y=0; y < col; y++){
			        		printf("%c", lab[x][y]);
						}
						printf("\n");
			        }
					
					printf(" HP: %i", HP);
					
						//Encontro inimigo - personagem
						
							if( (ix == px && iy == py) || (i2x == px && i2y == py) || (i3x == px && i3y == py) || (i4x == px && i4y == py) || (i5x == px && i5y == py) || (i6x == px && i6y == py) ){
								HP = HP -19;
								printf("\n Voce perdeu uma vida :( ");
								vida = vida -1;
							}
								if(vida == 6){
									printf("\n Vida: @ @ @ @ @ @\n");									
								}
									else if(vida == 5){
									printf("\n Vida: @ @ @ @ @ \n");
									}
										else if(vida == 4){
											printf("\n Vida: @ @ @ @\n");
										}
											else if(vida == 3){
												printf("\n Vida: @ @ @\n");
											}
												else if(vida == 2){
													printf("\n Vida: @ @\n");
												}
													else if(vida == 1){
														printf("\n Vida: @\n");
													}
														if(HP <= 0){
															mapafim = 3;
														}
						//mov personagem
						if (spawn != lab[23][39]) {
							fflush(stdin);
							jogada = getchar();
								if(jogada == 'w') {
									if(lab[px-1][py] != '#'){
										px = px - 1;
									}
						
								}
								
								if(jogada == 's') {
									if(lab[px+1][py] != '#'){
										px = px + 1;
									}
						
								}
								
								if(jogada == 'd') {
									if(lab[px][py+1] != '#'){
										py = py+1;
									}
								}
								
								if(jogada == 'a') {
									if(lab[px][py-1] != '#'){
									py = py-1;
									}
								}
					
					 	}// fim
						
						//mov ' < '
						if(jogada =='w'){
							if(lab[ix-1][iy] != '#' && lab[ix-1][iy] != 'I'){
								ix--;
							}
						}
						if(jogada =='s'){
							if(lab[ix+1][iy] != '#' && lab[ix+1][iy] != 'I'){
								ix++;
							}
						}
						if(jogada =='d'){
							if(lab[ix][iy+1] != '#' && lab[ix][iy+1] != 'I'){
								iy++;
							}
						}
						if(jogada =='a'){
							if(lab[ix][iy-1] != '#' && lab[ix][iy-1] != 'I'){
								iy--;
							}
						}
						
						//mov ' < ' 4
						if(jogada =='w'){
							if(lab[i4x+1][i4y] != '#' && lab[i4x+1][i4y] != 'I'){
								i4x++;
							}
						}
						if(jogada =='s'){
							if(lab[i4x-1][i4y] != '#' && lab[i4x-1][i4y] != 'I'){
								i4x--;
							}
						}
						if(jogada =='d'){
							if(lab[i4x][i4y-1] != '#' && lab[i4x][i4y-1] != 'I'){
								i4y--;
							}
						}
						if(jogada =='a'){
							if(lab[i4x][i4y+1] != '#' && lab[i4x][i4y+1] != 'I'){
								i4y++;
							}
						}
						
						//mov ' < '	2
							if(jogada =='w'){
								if(lab[i2x-2][i2y] == ' ' || lab[i2x-2][i2y] == '@' || lab[i2x-2][i2y] == '!' || lab[i2x-2][i2y] == '<'){
									i2x = i2x -2;
								}
									else if(lab[i2x-2][i2y] == '#' && lab[i2x-1][i2y] != '#' && lab[i2x-1][i2y] != 'I'){
										i2x = i2x -1;
									}
							}
							if(jogada =='s'){
								if(lab[i2x+2][i2y] == ' ' || lab[i2x+2][i2y] == '@' || lab[i2x+2][i2y] == '!' || lab[i2x+2][i2y] == '<'){
									i2x = i2x +2;
								}
									else if(lab[i2x+2][i2y] == '#' && lab[i2x+1][i2y] != '#' && lab[i2x+1][i2y] != 'I'){
										i2x = i2x +1;
									}
							}
							if(jogada =='d'){
								if(lab[i2x][i2y+2] == ' ' || lab[i2x][i2y+2] == '@' || lab[i2x][i2y+2] == '!' || lab[i2x][i2y+2] == '<'){
									i2y = i2y + 2;
								}
									else if(lab[i2x][i2y+2] == '#' && lab[i2x][i2y+1] != '#' && lab[i2x][i2y+1] != 'I'){
										i2y = i2y + 1;
									}
							}
							if(jogada =='a'){
								if(lab[i2x][i2y-2] == ' ' || lab[i2x][i2y-2] == '@' || lab[i2x][i2y-2] == '!' || lab[i2x][i2y-2] == '<'){
									i2y = i2y - 2;
								}
									else if(lab[i2x][i2y-2] == '#' && lab[i2x][i2y-1] != '#' && lab[i2x][i2y-1] != 'I'){
										i2y = i2y - 1;
									}
							}
								
								//mov ' < ' 3
									if(jogada =='w'){
										if(lab[i3x+2][i3y] == ' ' || lab[i3x+2][i3y] == '@' || lab[i3x+2][i3y] == '!' || lab[i3x+2][i3y] == '<'){
											i3x = i3x +2;
										}
										else if(lab[i3x+2][i3y] == '#' && lab[i3x+1][i3y] != '#' && lab[i3x+1][i3y] != 'I'){
											i3x = i3x +1;
										}
									}
									if(jogada =='s'){
										if(lab[i3x-2][i3y] == ' ' || lab[i3x-2][i3y] == '@' || lab[i3x-2][i3y] == '!' || lab[i3x-2][i3y] == '<'){
											i3x = i3x -2;
										}
											else if(lab[i3x-2][i3y] == '#' && lab[i3x-1][i3y] != '#' && lab[i3x-1][i3y] != 'I'){
												i3x = i3x -1;
											}
									}
									if(jogada =='d'){
										if(lab[i3x][i3y-2] == ' ' || lab[i3x][i3y-2] == '@' || lab[i3x][i3y-2] == '!' || lab[i3x][i3y-2] == '<'){
											i3y = i3y - 2;
										}
											else if(lab[i3x][i3y-2] == '#' && lab[i3x][i3y-1] != '#' && lab[i3x][i3y-1] != 'I'){
												i3y = i3y -1;
											}
									}
									if(jogada =='a'){
										if(lab[i3x][i3y+2] == ' ' || lab[i3x][i3y+2] == '@' || lab[i3x][i3y+2] == '!' || lab[i3x][i3y+2] == '<'){
											i3y = i3y +2;
										}
											else if(lab[i3x][i3y+2] == '#' && lab[i3x][i3y+1] != '#' && lab[i3x][i3y+1] != 'I'){
												i3y = i3y + 1;
											}
									}
										//mov ' < '	5
										if(jogada =='w'){
											if(lab[i5x-2][i5y] == ' ' || lab[i5x-2][i5y] == '@' || lab[i5x-2][i5y] == '!' || lab[i5x-2][i5y] == '<'){
												i5x = i5x -2;
											}
												else if(lab[i5x-2][i5y] == '#' && lab[i5x-1][i5y] != '#' && lab[i5x-1][i5y] != 'I'){
													i5x = i5x -1;
												}
										}
										if(jogada =='s'){
											if(lab[i5x+2][i5y] == ' ' || lab[i5x+2][i5y] == '@' || lab[i5x+2][i5y] == '!' || lab[i5x+2][i5y] == '<'){
												i5x = i5x +2;
											}
												else if(lab[i5x+2][i5y] == '#' && lab[i5x+1][i5y] != '#' && lab[i5x+1][i5y] != 'I'){
													i5x = i5x +1;
												}
										}
										if(jogada =='d'){
											if(lab[i5x][i5y+2] == ' ' || lab[i5x][i5y+2] == '@' || lab[i5x][i5y+2] == '!' || lab[i5x][i5y+2] == '<'){
												i5y = i5y + 2;
											}
												else if(lab[i5x][i5y+2] == '#' && lab[i5x][i5y+1] != '#' && lab[i5x][i5y+1] != 'I'){
													i5y = i5y + 1;
												}
										}
										if(jogada =='a'){
											if(lab[i5x][i5y-2] == ' ' || lab[i5x][i5y-2] == '@' || lab[i5x][i5y-2] == '!' || lab[i5x][i5y-2] == '<'){
												i5y = i5y - 2;
											}
												else if(lab[i5x][i5y-2] == '#' && lab[i5x][i5y-1] != '#' && lab[i5x][i5y-1] != 'I'){
													i5y = i5y - 1;
												}
										}
								//mov ' < ' 6
											if(jogada =='w'){
												if(lab[i6x+1][i6y] != '#' && lab[i6x+1][i6y] != 'I'){
													i6x++;
												}
											}
											if(jogada =='s'){
												if(lab[i6x-1][i6y] != '#' && lab[i6x-1][i6y] != 'I'){
													i6x--;
												}
											}
											if(jogada =='d'){
												if(lab[i6x][i6y-1] != '#' && lab[i6x][i6y-1] != 'I'){
													i6y--;
												}
											}
											if(jogada =='a'){
												if(lab[i6x][i6y+1] != '#' && lab[i6x][i6y+1] != 'I'){
													i6y++;
												}
											}
									
						else if(spawn == lab [23][39] && chave == '!'){
									mapafim = 2;
								}
						
						else if(spawn == lab[23][39] && chave == ' ') {
									mapafim = mapafim + 1;
								}																		
						
						system ("cls");
				
				}while (mapafim == 0 );
				//la�o mapa
				
			if(mapafim == 1) {
				printf("\n ======== Voce venceu! ========\n");
			}
			
				else if(mapafim == 2) {
					printf("\n === Voce nao pegou a chave ===\n");
				}
					else if(mapafim == 3){					
						printf("\n ======== Voce morreu =========\n");	
					}
			printf("\n = Voltar ao menu (1) ou (0)? =\n");			
			scanf("%i", &continuar);
			if(continuar == 1) {
				dificuldade = 0;	
				liberado = 0;
				mapa = 0;
				menu = 1;
			}
				else { system ("cls");
				printf("\n ======== Fim de jogo. ======== ");
				}				
		
	}	//fim do mapa 3
	
	printf("\n ");
		
}while(menu != 0);	
	

	
	return 0;
}
