#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Ccadena{
private:
    char szBuffer[128];
public:
    void setleer();//leer caracter por caracter y guardarlo en buffer
    void setimprimir();// imprimir caracter por caracter buffer
    int setTamanio();// imprime el tamanio de la cadena
    void setImprimeReves();// imprime al reves la cadena
    void setReves();// no imprime la cadena pero la invierte

};

int main(int argc, char **argv) {//main y prototipos de funciones
    Ccadena buffer;
    buffer.setleer();
    buffer.setimprimir();
    buffer.setTamanio();
    buffer.setImprimeReves();
    buffer.setReves();
    return 0;
}

void Ccadena::setleer()//Funcion Leer
{
            printf("Dame la cadena a trabajar\n");
            fgets(szBuffer,129, stdin);
            //gets(szBuffer);
}

void Ccadena::setimprimir()//Funcion Imprimir
{
            printf("\n");
            for (int i = 0;i<szBuffer[i];i++)
            {
                printf("%c",szBuffer[i]);
                printf("\n");
            }
}

int Ccadena::setTamanio()//Funcion Tamanio
{
           int i= 0;
           while(szBuffer[i] != '\0')
           i++;
           printf("\n");
           printf("Tamanio de la cadena : %d",i);
           printf(" Caracteres");
           printf("\n");
}

void Ccadena::setImprimeReves()//Funcion imprimir Al reves
{
            printf("\n");
            int i = 0;
            while(szBuffer[i] != '\0'){
                    i++;
            }
            for (int y=i-1;y>=0;y--){
            printf("%c",szBuffer[y]);
            printf("\n");
    }
}

void Ccadena::setReves()//Funcion reves
{
    int longitud = strlen(szBuffer);
    int i;
    for (i = 0; i < strlen(szBuffer) / 2; i++)
    {
        char temp = szBuffer[i];
        szBuffer[i] = szBuffer[longitud - i - 1];
        szBuffer[longitud - i - 1] = temp;
    }
    printf("\n\n");
    printf("Reves: ");
    printf(szBuffer);
}
