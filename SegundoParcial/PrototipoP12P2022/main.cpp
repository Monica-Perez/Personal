#include <iostream>
#include "Usuarios.h"
#include "Catalogos.h"

using namespace std;

int escribirOpcion();
enum Opciones { catalogos = 1,/*proveedores, productos,*/ FIN };

int main()
{
    Usuarios claseusuarios;
    int opcion=0;
    while (( opcion = escribirOpcion() ) != FIN)
    {
        switch ( opcion ) {
            case catalogos:
                {
                    Catalogos clasecatalogos;
                }
            break;
            /*case proveedores:
                {
                    Puestos clasepuestos;
                }
            break;
            case productos:
                {
                    Departamento clasedepartamentos;
                }
            break;*/
        }
    }
    return 0;
}
int escribirOpcion(){
    system("cls");
    cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\t\t\t |  MENU GENERAL - MONICA PEREZ 9959-21-1840  |"<<endl;
	cout<<"\t\t\t------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. Catalogos" << endl
        << "\t\t\t  2. Procesos" << endl
        << "\t\t\t  3. Informes" << endl
        << "\t\t\t  4. Finalizar el Programa" << endl
        <<"\n\t\t\t------------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;
}
