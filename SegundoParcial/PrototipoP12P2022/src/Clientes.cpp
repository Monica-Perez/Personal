#include "Clientes.h"
#include "DatosClientes.h"
#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>
using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>
using std::setw;
using std::setprecision;
#include <cstdlib>

int opcionCli();
void imprimirRegistroCli( fstream& );
/*void crearArchivoCreditoCli();
void mostrarLineaCli( ostream&, const DatosEmpleado & );
void nuevoRegistroCli( fstream& );
int obtenernCodigoCli( const char * const );
void modificarRegistroCli( fstream& );
void eliminarRegistroCli( fstream& );
void consultarRegistroCli( fstream& );
void mostrarLineaPantallaCli( const DatosEmpleado &);*/

using namespace std;

Clientes::Clientes()
{
    /*fstream creditoEntradaSalida( "Clientes.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoEmp();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }*/
    /*enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionCli() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroCli( creditoEntradaSalida );
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
            break;*/
            /*default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE*/
}
int opcionCli(){
    cout<<"\n\t\t\t------------------------------------------------"<<endl;
    cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\t\t\t |   CLIENTES - MONICA PEREZ, 9959-21-1840   |"<<endl;
	cout<<"\t\t\t------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar Cliente" << endl
        << "\t\t\t 3. Modificar Cliente" << endl
        << "\t\t\t 4. Eliminar Cliente" << endl
        << "\t\t\t 5. Mostrar Lista de Clientes" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t------------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu;
    cin >> opcionMenu;

   return opcionMenu;
}
/*void imprimirRegistroCli( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirCliente.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Nombre" << setw( 16 ) << "Dirección" << setw( 16 ) << "NIT"<< right
       << setw( 10 ) << "Telefono" << setw( 10 ) << "CodigoVendedor" << setw( 16 ) << "Estatus" << endl;
    leerDeArchivo.seekg( 0 );

    DatosClientes clientes;
    leerDeArchivo.read( reinterpret_cast< char * >( &clientes ), sizeof( DatosClientes ) );

    while ( !leerDeArchivo.eof() ) {
        if ( clientes.obtenerCodigo() != 0 )
        mostrarLineaEmp( archivoImprimirSalida, clientes );
        leerDeArchivo.read( reinterpret_cast< char * >( &clientes ), sizeof( DatosClientes ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
*/

Clientes::~Clientes()
{
    //dtor
}
