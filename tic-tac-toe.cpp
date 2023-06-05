#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char velha[3][3];
int line, column;

void initMatrix() {
	
    for (line = 0; line < 3; line++) {
    	
        for (column = 0; column < 3; column++) {
        	
        	velha[line][column] = ' ';
        	
		}
		
    }
    
}

void gridOfGame(){
	
    for (line = 0; line < 3; line++) {
    	
        for (column = 0; column < 3; column++){
			
            printf(" %c ", velha[line][column]);
            
            if (column < 2) {
            	
            	printf("|");
            	
			}
                
        }
        
        printf("\n");
        
        if (line < 2) {
        	
        	printf("-----------\n");
        	
		}
            
    }
    
}

int validInput(int line, int column) {
	
    if (line >= 0 && line < 3 && column >= 0 && column < 3 && velha[line][column] == ' ') {
    	
    	return 1;
    	
	} else {
		
		return 0;
		
	}
        
}

void scanPos(char g) {
	
    int line, column;

    printf("\n(Jogador) Linha: ");
    scanf(" %d", &line);
    
    printf("(Jogador) Coluna: ");
    scanf(" %d", &column);

    while (validInput(line, column) == 0) {
    	
        printf("\n - Coordenadas Inexistentes! Tente Novamente...");
        
        printf("\n(Jogador) Linha: ");
	    scanf(" %d", &line);
	    
	    printf("(Jogador) Coluna: ");
	    scanf(" %d", &column);
        
    }
    
    velha[line][column] = g;
    
}

int closeLines(int line, char column) {
	
    if (velha[line][0] == column && velha[line][1] == column && velha[line][2] == column) {
    	
    	return 1;
    	
	} else {
		
		return 0;
		
	}
          
}

int closeColumn(int column, char g) {
	
    if (velha[0][column] == g && velha[1][column] == g && velha[2][column] == g) {
    	
    	return 1;
    	
	} else {
		
		return 0;
		
	}
	
}

int winnerLines (char column) {
	
    int winner = 0;
    
    for (line = 0; line < 3; line++){
    	
        winner += closeLines(line, column);
        
    }
    
    return winner;
    
}

int winnerColumn(char g) {
	
    int winner = 0;
    
    for (column = 0; column < 3; column++) {
    	
        winner += closeColumn(column, g);
        
    }
    
    return winner;
    
}

int winnerDiagonalFirst(char column) {
	
    if (velha[0][0] == column && velha[1][1] == column && velha[2][2] == column) {
    	
    	return 1;
    	
	} else {
		
		return 0;
		
	} 
	
}

int winnerDiagonalSecond(char column) {
	
    if (velha[0][2] == column && velha[1][1] == column && velha[2][0] == column) {
    	
    	return 1;
    	
	} else {
		
		return 0;
		
	}
	
}

int drawGame() {
	
    int voidQuantity = 0;

    for (line = 0; line < 3; line++) {
    	
        for (column = 0; column < 3; column++) {
        	
        	if (velha[line][column] == ' ') {
        		
        		voidQuantity++;
        		
		 }
        	
		}   
                
    }
    
    return voidQuantity;
}

void play() {
	
    int player = 1, victoryX = 0, victory0 = 0;
    char player1 = 'X', player2 = '0';

    do {
    	
        gridOfGame();
        
        if (player == 1) {
        	
            scanPos(player1);
            player++;
            victoryX += winnerLines(player1);
            victoryX += winnerColumn(player1);
            victoryX += winnerDiagonalFirst(player1);
            victoryX += winnerDiagonalSecond(player1);
            system("cls");
            
        } else {
        	
            scanPos(player2);
            player = 1;
            victory0 += winnerLines(player2);
            victory0 += winnerColumn(player2);
            victory0 += winnerDiagonalFirst(player2);
            victory0 += winnerDiagonalSecond(player2);
            system("cls");
            
        }
        
    } while(victoryX == 0 && victory0 == 0 && drawGame() > 0);

    gridOfGame();

    if (victory0 == 1) {
    	
    	printf("\nVencedor | PLAYER (O)\n");
    	
	} else if (victoryX == 1) {
		
		printf("\nVencedor | PLAYER (X)\n");
		
	} else {
		
		printf("\nVELHA\n");
		
	}   
        
}

int main(){
	
    char opt;

    do {
    	
        initMatrix();
        play();

        printf("\nDeseja jogar novamente? (S/N): ");
        scanf(" %c", &opt);
        system("cls");
        
    } while (toupper(opt) == 'S');

    return 0;
    
}
