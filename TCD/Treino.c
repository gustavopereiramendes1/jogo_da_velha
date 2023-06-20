#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

void Cor_texto(int cor_texto, int cor_fundo);
void Mover_Cursor(int linha, int coluna);

  //COR DA LETRA
  enum{BLACK,                 //0
       BLUE,                  //1
       GREEN,                 //2
       CYAN,                  //3
       RED,                   //4
       MAGENTA,               //5
       BROWN,                 //6
       LIGHTGRAY,             //7
       DARKGRAY,              //8
       LIGHTBLUE,             //9
       LIGHTGREEN,            //10
       LIGHTCYAN,             //11
       LIGHTRED,              //12
       LIGHTMAGENTA,          //13
       YELLOW,                //14
       WHITE                  //15
       
    };  
  //COR DO FUNDO
  enum{_BLACK=0,                 
       _BLUE=16,                  
       _GREEN=32,                 
       _CYAN=48,                  
       _RED=64,                   
       _MAGENTA=80,               
       _BROWN=96,                 
       _LIGHTGRAY=112,             
       _DARKGRAY=128,              
       _LIGHTBLUE=144,             
       _LIGHTGREEN=160,            
       _LIGHTCYAN=176,             
       _LIGHTRED=192,              
       _LIGHTMAGENTA=208,          
       _YELLOW=224,                
       _WHITE=240                        
    };

int main(){
    Cor_texto(LIGHTCYAN, _WHITE);
    printf("Hello World!\n");
    Cor_texto(WHITE, _BLACK);
    return 0;

}

void Cor_texto(int cor_texto, int cor_fundo){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor_texto + cor_fundo);
}