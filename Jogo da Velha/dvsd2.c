#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
void jogada(int px, int py, char tabuleiro[][3]);
void imprimir_tabu(char tabuleiro[][3]);
void jogo(char tabuleiro[][3]);
int checar_vitoria(char tabuleiro[][3]);

int main(){
    char tabuleiro[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }

    imprimir_tabu(tabuleiro);
    
    
    verifica_vez(tabuleiro);
    printf("\nGame Over!");
    Sleep(100000);

    return 0;
}

void jogada(int px, int py, char tabuleiro[][3]){
    //função que escreve no tabuleiro de acordo com a posicao digitada
    int x, y;
    //variaveis que armazenaram as posições de acordo com a tela do console
    for(x = 1; px > 1; x+=4, px--);
    for(y = 0; py > 1; y+=2, py--);
    //progressão aritmetica usando "for" para atribuir a posição no console de acordo com o tabuleiro
    gotoxy(x, y);
    //chamando a função gotoxy, para mover o cursor no console
    
    
    //armazena a mudança na matriz

    //dorme
}

void imprimir_tabu(char tabuleiro[][3]){
    for(int linha = 0; linha < 3; linha++){
        for(int coluna = 0; coluna < 3; coluna++){

            switch (coluna)
            {
            case 0:
                printf(" %c ", tabuleiro[linha][coluna]);
                break;
            case 1:
                printf("| %c |" , tabuleiro[linha][coluna]);
                break;
            case 2:
                printf(" %c ", tabuleiro[linha][coluna]);
                printf("\n");
                printf((linha!=2)?"___|___|___\n": "   |   |   \n");
            default:
                break;
            }
        }
    }
}

void gotoxy(int x, int y)
{
    HANDLE stdOutput;
    COORD pos;

    stdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(stdOutput, pos);
}

void jogo(char tabuleiro[][3]){
    int px, py, i;
    for(i = 0; i< 9; i++){
        if (!(i % 2)){
                
            scanf("%d%d", &py, &px);
            jogada(px, py, tabuleiro);
            printf("X");
            //Sleep(2000);
            tabuleiro[py-1][px-1] = 'X';
                
                
            gotoxy(0, 7+i);
            if(checar_vitoria(tabuleiro)){
                printf("Vencedor!");
                break;
            }
        }else{
            scanf("%d%d", &py, &px);
            jogada(px, py, tabuleiro);
            printf("O");
            //Sleep(2000);
            tabuleiro[py-1][px-1] = 'O';
                
            gotoxy(0, 7+i);
            if(checar_vitoria(tabuleiro)){
                printf("Vencedor!");
                break;
            }
        }
    }
    
}

int checar_vitoria(char tabuleiro[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if((tabuleiro[i][j] != ' ') && (tabuleiro[i][j] == tabuleiro[i+1][j])){
                if(tabuleiro[i+1][j] == tabuleiro[i+2][j]){
                    return 1;
                }
            }
            if((tabuleiro[i][j] != ' ') && (tabuleiro[i][j] == tabuleiro[i][j+1])){
                if(tabuleiro[i][j+1] == tabuleiro[i][j+2]){
                    return 1;
                }
            }
            if((tabuleiro[i][j] != ' ') && (tabuleiro[i][j] == tabuleiro[i+1][j+1])){
                if(tabuleiro[i+1][j+1] == tabuleiro[i+2][j+2]){
                    return 1;
                }
            }
            if(i + j == 2){
                if((tabuleiro[i][j] != ' ') && (tabuleiro[i][j] == tabuleiro[i+1][j-1])){
                    if(tabuleiro[i+1][j-1] == tabuleiro[i+2][j-2]){
                        return 1;
                    }
                }
            }
            
        }
        
    }
    return 0;
}

