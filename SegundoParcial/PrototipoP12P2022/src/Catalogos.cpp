#include "Catalogos.h"
#include "Clientes.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int opcionCat();
Catalogos::Catalogos()
{
    enum Opciones { clientes = 1, proveedores, productos, FIN };
    int opcion;
    while ( ( opcion = opcionCat() ) != FIN ) {
        switch ( opcion ) {
            case clientes:
                Clientes claseclientes;
            break;
            /*case nuevo:
                nuevoRegistroEmp( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroEmp( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroEmp( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroEmp( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;*/

      } //FIN SWITCH

   } //FIN WHILE
}
int opcionCat(){
    cout<<"\n\t\t\t------------------------------------------------"<<endl;
    cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\t\t\t |   CATALOGOS - MONICA PEREZ, 9959-21-1840   |"<<endl;
	cout<<"\t\t\t------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t  1. Clientes" << endl
        << "\t\t\t  2. Vendedores" << endl
        << "\t\t\t  3. Productos" << endl
        << "\t\t\t  4. Marcas" << endl
        << "\t\t\t  5. Lineas" << endl
        << "\t\t\t  6. Regresar a Menu Principal" << endl
        <<"\n\t\t\t------------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;
}
Catalogos::~Catalogos()
{
    //dtor
}
