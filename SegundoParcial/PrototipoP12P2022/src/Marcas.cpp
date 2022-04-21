#include "Marcas.h"
#include "DatosMarcas.h"
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

int opcionM();
void imprimirRegistroM( fstream& );
void crearArchivoCreditoM();
void mostrarLineaM( ostream&, const DatosMarcas & );
void nuevoRegistroM( fstream& );
int obtenerCodigoM( const char * const );
void modificarRegistroM( fstream& );
void eliminarRegistroM( fstream& );
void consultarRegistroM( fstream& );
void mostrarLineaPantallaM( const DatosMarcas &);

using namespace std;


Marcas::Marcas()
{
    fstream creditoEntradaSalida( "Marcas.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoM();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionM() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroM( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroM( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroM( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroM( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroM( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   }
}
int opcionM()
{
    cout<<"\n\t\t\t------------------------------------------------"<<endl;
    cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\t\t\t |     MARCAS - MONICA PEREZ, 9959-21-1840    |"<<endl;
	cout<<"\t\t\t------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar" << endl
        << "\t\t\t 3. Modificar" << endl
        << "\t\t\t 4. Eliminar" << endl
        << "\t\t\t 5. Mostrar Lista de Marcas" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t------------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu;
    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroM( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirMarcas.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 14 )<< "Nombre" <<right<< "Estatus" << endl;
    leerDeArchivo.seekg( 0 );

    DatosMarcas marcas;
    leerDeArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );

    while ( !leerDeArchivo.eof() ) {
        if ( marcas.obtenerCodigo() != 0 )
        mostrarLineaM( archivoImprimirSalida, marcas );
        leerDeArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaM( ostream &salida, const DatosMarcas &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 16 ) << setprecision( 2 ) << right << fixed<< registro.obtenerEstatus().data() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoM()
{
    ofstream creditoSalida( "Marcas.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosMarcas marcasEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &marcasEnBlanco ), sizeof( DatosMarcas ) );
}
void nuevoRegistroM( fstream &insertarEnArchivo )
{
    int codigo = obtenerCodigoM( "\nEscriba el Codigo de la Marca " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosMarcas ) );
    DatosMarcas marcas;
    insertarEnArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );

    if ( marcas.obtenerCodigo() == 0 ) {
        char nombre[ 15 ];
        char estatus[ 15 ];
        cout<<"Escriba el Nombre de la Marca: ";
        cin>> setw( 28 ) >> nombre;
        cout<<"Escriba el Estatus de la Marca: ";
        cin>> setw( 16 ) >> estatus;
        marcas.establecerNombre( nombre );
        marcas.establecerEstatus( estatus );
        marcas.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosMarcas ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &marcas ), sizeof( DatosMarcas ) );
        cout<<"\n Marca agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Marca con codigo #" << codigo << " ya contiene informacion.\n" << endl;

} //FIN REGISTRO
int obtenerCodigoM( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroM( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Estatus\n R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenerCodigoM( "\nEscriba el codigo de la Marca que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosMarcas ));

        DatosMarcas marcas;
        actualizarArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );

        //ACTUALIZAR EL REGISTRO
        if (marcas.obtenerCodigo() != 0 ) {
            mostrarLineaM( cout, marcas );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = marcas.obtenerNombre();
            marcas.establecerNombre( nombre );
            mostrarLineaM( cout, marcas );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosMarcas ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &marcas ), sizeof( DatosMarcas ) );
        }

    }else if(opcionAc == 2){
        int codigo = obtenerCodigoM( "\nEscriba el codigo de la Marca que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosMarcas ));

        DatosMarcas marcas;
        actualizarArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );

        if (marcas.obtenerCodigo() != 0 ) {
                mostrarLineaM( cout, marcas );
                cout << "\nEscriba el nuevo Estatus: ";
                string estatus;
                cin >> estatus;

                string estatusAnterior = marcas.obtenerEstatus();
                marcas.establecerEstatus( estatus );
                mostrarLineaM( cout, marcas );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosMarcas ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &marcas ), sizeof( DatosMarcas ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroM( fstream &eliminarDeArchivo )
{
    int codigo = obtenerCodigoM( "\nEscriba el codigo de la Marca a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosMarcas ) );
    DatosMarcas marcas;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );

    if ( marcas.obtenerCodigo() != 0 ) {
        DatosMarcas marcasEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosMarcas ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &marcasEnBlanco ), sizeof( DatosMarcas ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-
void consultarRegistroM( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Nombre" << setw( 15 ) << right << " Estatus"  << endl;
    leerDeArchivo.seekg( 0 );
    DatosMarcas marcas;
    leerDeArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );
    while ( !leerDeArchivo.eof() ) {
        if ( marcas.obtenerCodigo() != 0 )
            mostrarLineaPantallaM( marcas );
            leerDeArchivo.read( reinterpret_cast< char * >( &marcas ), sizeof( DatosMarcas ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaM( const DatosMarcas &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 12 ) << setprecision( 2 ) << right <<  registro.obtenerEstatus() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Marcas::~Marcas()
{
    //dtor
}
