#include <stdio.h>
#include <string.h>
int main(){
    char pszCadena[10]=" Hola Mundo";
    int x=Tamanio(pszCadena);
    printf("Tamanio de la cadena: %d\n",x);
    int y=ImprimeReves(pszCadena);
    for (y=x-1;y>=0;y--){
            printf("%c",pszCadena[y]);
    }
    Reves(pszCadena);
}

int Tamanio(char*pszCadena)
{
    *pszCadena=&pszCadena;

    int i= 0;
    while(pszCadena[i] != '\0')
        i++;
    return i;
    }

void ImprimeReves(char* pszCadena)
{
    *pszCadena=&pszCadena;
    int i = 0;
    while(pszCadena[i] != 'h'){
        i++;
    return i;
    }
}

void Reves(char* pszCadena)
{
    *pszCadena=&pszCadena;
    int longitud = strlen(pszCadena);
    int i;
    for (i = 0; i < strlen(pszCadena) / 2; i++)
    {
        char temp = pszCadena[i];
        pszCadena[i] = pszCadena[longitud - i - 1];
        pszCadena[longitud - i - 1] = temp;
    }
}
