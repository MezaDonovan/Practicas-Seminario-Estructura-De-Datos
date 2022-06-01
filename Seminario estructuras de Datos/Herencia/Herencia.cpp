#include <iostream>
#include "CAuto.h"
#include "CPatrulla.h"
#include "CToreto.h"
#include "CPatrullaBlindada.h"
#include "CMotor.h"
#include "CTaxi.h"

using namespace std;

//Funciones CMotor

void CMotor::CMotor_Imprimir()
{
        printf("\nCilindros : %d",Cilindros);
        printf("\nCilindrada : %d",Cilindrada);
        printf(" CC");
}

CMotor::CMotor()
{
    printf("\nCosntruyendo Motor...\n");
    printf("\nDe Cuantos Cilindros Desea El Motor\n");
    scanf("%d",&Cilindros);
    printf("\nDeme la Cilindrada de su Motor\n");
    scanf("%d",&Cilindrada);
    printf("\n");
}

CMotor::~CMotor()
{
    printf("\nDestruyendo Motor...\n");
}

//Funciones CAuto
void CAuto::CAuto_Imprimir()
{
    printf("\nVelocidad Actual: %d",Velocidad);
    printf(" Km/hr\n");

}
int CAuto::CAuto_Acelerar()
{
    printf("\nAcelerando...\n");
    Velocidad = Velocidad +1;
}

CAuto::CAuto()
{
    printf("\nCosntruyendo Auto...\n");
}

CAuto::~CAuto()
{
    printf("\nDestruyendo Auto...\n");
}


//Funciones Patrulla

void CPatrulla::CPatrulla_Imprimir()
{
    printf("\nVelocidad Actual: %d",Velocidad);
    printf(" Km/hr\n");

}
int CPatrulla::CPatrulla_Acelerar()
{
    printf("\nAcelerando...\n");
    Velocidad = Velocidad +2;
}

CPatrulla::CPatrulla()
{
    printf("\nCosntruyendo Patrulla...\n");
}

CPatrulla::~CPatrulla()
{
    printf("\nDestruyendo Patrulla...\n");
}

//Funciones Patrulla Artillada

void CPatrullaArtillada::CPatrullaArtillada_Imprimir()
{
    printf("\nBlindaje : %d",Blindaje);
    printf("\nVelocidad Actual: %.2f",Velocidad);
    printf(" Km/hr\n");

}

float CPatrullaArtillada::CPatrullaArtillada_Acelerar()
{
    printf("\nAcelerando...\n");
    Velocidad = Velocidad + 1.5;
}

CPatrullaArtillada::CPatrullaArtillada()
{
    printf("\nCosntruyendo Patrulla Artillada...\n");
}

CPatrullaArtillada::~CPatrullaArtillada()
{
    printf("\nDestruyendo Patrulla Artillada...\n");
}

//Funciones Toreto

void CToreto::CToreto_Imprimir()
{
    printf("\nVelocidad Actual: %d",Velocidad);
    printf(" Km/hr\n");
}

int CToreto::CToreto_Acelerar()
{
    printf("\nAcelerando...\n");
    Velocidad = Velocidad + 3;
}

int CToreto::CToreto_Turbo()
{
    printf("\nAplicando Turbo...\n");
    Velocidad = Velocidad + 10;
}

CToreto::CToreto()
{
    printf("\nCosntruyendo Auto Toreto...\n");
}

CToreto::~CToreto()
{
    printf("\nDestruyendo Auto Toreto...\n");
}

//Funciones Taxi

void CTaxi::CTaxi_Imprimir()
{
    printf("\nVelocidad Actual: %d",Velocidad);
    printf(" Km/hr\n");

}
int CTaxi::CTaxi_Acelerar()
{
    printf("\nAcelerando...\n");
    Velocidad = Velocidad +5;
}

CTaxi::CTaxi()
{
    printf("\nCosntruyendo Taxi...\n");
}

CTaxi::~CTaxi()
{
    printf("\nDestruyendo Taxi...\n");
}

int main (){
    int opc;
    int opc2;
    printf("-Herencia-\n");
    do{
    printf("\n-Elija una opcion-\n");
    printf("\n1-Auto\n2-Patrulla\n3-Patrulla Artillada\n4-Toreto\n5-Taxi\n6-Salir\n\n");
    scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            {
                CMotor Motor;
                CAuto Auto;
                do{
                printf("\n-Elija una opcion-\n");
                printf("\n1-Imprimir\n2-Acelerar\n3-Salir\n\n");
                scanf("%d",&opc2);
                switch(opc2)
                {
                case 1:
                    Motor.CMotor_Imprimir();
                    Auto.CAuto_Imprimir();
                    break;
                case 2:
                    Auto.CAuto_Acelerar();
                    break;
                }
                if (opc2 >3 || opc2 <1)
                printf("\nOpcion invalida, Elija una opcion del menu\n");
                }while (opc2 != 3 );
            }
            break;

        case 2:
            {
                CMotor Motor;
                CPatrulla Patrulla;
                do{
                printf("\n-Elija una opcion-\n");
                printf("\n1-Imprimir\n2-Acelerar\n3-Salir\n\n");
                scanf("%d",&opc2);
                switch(opc2)
                {
                case 1:
                    Motor.CMotor_Imprimir();
                    Patrulla.CPatrulla_Imprimir();
                    break;
                case 2:
                    Patrulla.CPatrulla_Acelerar();
                    break;
                }
                if (opc2 >3 || opc2 <1)
                printf("\nOpcion invalida, Elija una opcion del menu\n");
                }while (opc2 != 3 );
            }
            break;

        case 3:
            {
                CMotor Motor;
                CPatrullaArtillada PatrullaArtillada;
                do{
                printf("\n-Elija una opcion-\n");
                printf("\n1-Imprimir\n2-Acelerar\n3-Salir\n\n");
                scanf("%d",&opc2);
                switch(opc2)
                {
                case 1:
                    Motor.CMotor_Imprimir();
                    PatrullaArtillada.CPatrullaArtillada_Imprimir();
                    break;
                case 2:
                    PatrullaArtillada.CPatrullaArtillada_Acelerar();
                    break;
                }
                if (opc2 >3 || opc2 <1)
                printf("\nOpcion invalida, Elija una opcion del menu\n");
                }while (opc2 != 3 );
            }

            break;

        case 4:
            {
                CMotor Motor;
                CToreto Toreto;
                do{
                printf("\n-Elija una opcion-\n");
                printf("\n1-Imprimir\n2-Acelerar\n3-Turbo\n4-Salir\n\n");
                scanf("%d",&opc2);
                switch(opc2)
                {
                case 1:
                    Motor.CMotor_Imprimir();
                    Toreto.CToreto_Imprimir();
                    break;
                case 2:
                    Toreto.CToreto_Acelerar();
                    break;
                case 3:
                    Toreto.CToreto_Turbo();
                    break;
                }
                if (opc2 >4 || opc2 <1)
                printf("\nOpcion invalida, Elija una opcion del menu\n");
                }while (opc2 != 4 );
            }
            break;
        case 5:
            {
                CMotor Motor;
                CTaxi Taxi;
                do{
                printf("\n-Elija una opcion-\n");
                printf("\n1-Imprimir\n2-Acelerar\n3-Salir\n\n");
                scanf("%d",&opc2);
                switch(opc2)
                {
                case 1:
                    Motor.CMotor_Imprimir();
                    Taxi.CTaxi_Imprimir();
                    break;
                case 2:
                    Taxi.CTaxi_Acelerar();
                    break;
                }
                if (opc2 >3 || opc2 <1)
                printf("\nOpcion invalida, Elija una opcion del menu\n");
                }while (opc2 != 3 );
            }
            break;
        }
        if (opc >6 || opc <1)
            printf("\nOpcion invalida, Elija una opcion del menu\n");

    }while (opc != 6 );
    printf("\nSaliendo del programa...\n");
}
