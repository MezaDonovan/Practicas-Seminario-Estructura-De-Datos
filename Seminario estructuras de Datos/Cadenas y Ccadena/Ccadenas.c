#include <stdio.h>

class Ccadena{
private:
    char szBuffer[128];

void setleer();//leer caracter por caracter y guardarlo en buffer
void setimprimir();// imprimir caracter por caracter buffer
int setTamanio();
void setImprimeReves();
void setReves();

};

int main() {

    printf("Hello world");

    return 0;
}

void ccadena::leer()
{
    fgets(szBuffer,128,stdin)
}
