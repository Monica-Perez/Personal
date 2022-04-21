#include "Vendedores.h"
#include "DatosVendedores.h"
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

int opcionV();
void imprimirRegistroV( fstream& );
void crearArchivoCreditoV();
void mostrarLineaV( ostream&, const DatosVendedores & );
void nuevoRegistroV( fstream& );
int obtenerCodigoV( const char * const );
void modificarRegistroV( fstream& );
void eliminarRegistroV( fstream& );
void consultarRegistroV( fstream& );
void mostrarLineaPantallaV( const DatosVendedores &);

using namespace std;

Vendedores::Vendedores()
{
    fstream creditoEntradaSalida( "Vendedores.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoV();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionV() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroV( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroV( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroV( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroV( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroV( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
}
int opcionV()
{
    cout<<"\n\t\t\t------------------------------------------------"<<endl;
    cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\t\t\t |  VENDEDORES - MONICA PEREZ, 9959-21-1840   |"<<endl;
	cout<<"\t\t\t------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar" << endl
        << "\t\t\t 3. Modificar" << endl
        << "\t\t\t 4. Eliminar" << endl
        << "\t\t\t 5. Mostrar Lista de Vendedores" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t------------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu;
    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroV( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirVendedor.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Nombre" << setw( 16 ) << "Dirección" << setw( 16 ) << "Telefono" << setw( 16 ) << "Nit" << setw( 16 ) <<right<< "Estatus" << endl;
    leerDeArchivo.seekg( 0 );

    DatosVendedores vendedores;
    leerDeArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

    while ( !leerDeArchivo.eof() ) {
        if ( vendedores.obtenerCodigo() != 0 )
        mostrarLineaV( archivoImprimirSalida, vendedores );
        leerDeArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaV( ostream &salida, const DatosVendedores &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerDireccion().data()
          << setw( 16 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerNit().data()
          << setw( 16 ) << setprecision( 2 ) << right << fixed<< registro.obtenerEstatus().data() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoV()
{
    ofstream creditoSalida( "Vendedores.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosVendedores vendedoresEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &vendedoresEnBlanco ), sizeof( DatosVendedores ) );
}
void nuevoRegistroV( fstream &insertarEnArchivo )
{
    int codigo = obtenerCodigoV( "\nEscriba el Codigo del Vendedor " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosVendedores ) );
    DatosVendedores vendedores;
    insertarEnArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

    if ( vendedores.obtenerCodigo() == 0 ) {
        char nombre[ 15 ];
        char direccion[ 15 ];
        int telefono;
        char nit[ 15 ];
        char estatus[ 15 ];
        cout<<"Escriba el Nombre del Vendedor: ";
        cin>> setw( 15 ) >> nombre;
        cout<<"Escriba la Direccion del Vendedor: ";
        cin>> setw( 15 ) >> direccion;
        cout<<"Escriba el Telefono del Vendedor: ";
        cin>> telefono;
        cout<<"Escriba el Nit del Vendedor: ";
        cin>> setw( 15 ) >> nit;
        cout<<"Escriba el Estatus del Vendedor: ";
        cin>> setw( 15 ) >> estatus;
        vendedores.establecerNombre( nombre );
        vendedores.establecerDireccion( direccion );
        vendedores.establecerTelefono( telefono );
        vendedores.establecerNit( nit );
        vendedores.establecerEstatus( estatus );
        vendedores.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosVendedores ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &vendedores ), sizeof( DatosVendedores ) );
        cout<<"\n Vendedor agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Vendedor con codigo #" << codigo << " ya contiene informacion.\n" << endl;

} //FIN REGISTRO
int obtenerCodigoV( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroV( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Direccion\n 3. Nit \n 4. Telefono\n 5. Estatus\n R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenerCodigoV( "\nEscriba el codigo del Vendedor que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosVendedores ));

        DatosVendedores vendedores;
        actualizarArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

        //ACTUALIZAR EL REGISTRO
        if (vendedores.obtenerCodigo() != 0 ) {
            mostrarLineaV( cout, vendedores );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = vendedores.obtenerNombre();
            vendedores.establecerNombre( nombre );
            mostrarLineaV( cout, vendedores );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosVendedores ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &vendedores ), sizeof( DatosVendedores ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenerCodigoV( "\nEscriba el codigo del Vendedor que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosVendedores ));

        DatosVendedores vendedores;
        actualizarArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

        //ACTUALIZAR EL REGISTRO
        if (vendedores.obtenerCodigo() != 0 ) {
            mostrarLineaV( cout, vendedores );
            cout << "\nEscriba la nueva Direccion: ";
            string direccion;
            cin >> direccion;

            string direccionAnterior = vendedores.obtenerDireccion();
            vendedores.establecerDireccion( direccion );
            mostrarLineaV( cout, vendedores );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosVendedores ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &vendedores ), sizeof( DatosVendedores ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenerCodigoV( "\nEscriba el codigo del Vendedor que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosVendedores ));

        DatosVendedores vendedores;
        actualizarArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

        if (vendedores.obtenerCodigo() != 0 ) {
                mostrarLineaV( cout, vendedores );
                cout << "\nEscriba el nuevo NIT: ";
                string nit;
                cin >> nit;

                string nitAnterior = vendedores.obtenerNit();
                vendedores.establecerNit( nit );
                mostrarLineaV( cout, vendedores );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosVendedores ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &vendedores ), sizeof( DatosVendedores ) );
        }
    }else if(opcionAc == 4){
        int codigo = obtenerCodigoV( "\nEscriba el codigo del Vendedor que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosVendedores ));

        DatosVendedores vendedores;
        actualizarArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

        if (vendedores.obtenerCodigo() != 0 ) {
                mostrarLineaV( cout, vendedores );
                cout << "\nEscriba el nuevo Telefono: ";
                int telefono;
                cin >> telefono;

                int telefAnterior = vendedores.obtenerTelefono();
                vendedores.establecerTelefono( telefono );
                mostrarLineaV( cout, vendedores );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosVendedores ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &vendedores ), sizeof( DatosVendedores ) );
        }
    }else if(opcionAc == 5){
        int codigo = obtenerCodigoV( "\nEscriba el codigo del Vendedor que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosVendedores ));

        DatosVendedores vendedores;
        actualizarArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

        if (vendedores.obtenerCodigo() != 0 ) {
                mostrarLineaV( cout, vendedores );
                cout << "\nEscriba el nuevo Estatus: ";
                string estatus;
                cin >> estatus;

                string estatusAnterior = vendedores.obtenerEstatus();
                vendedores.establecerEstatus( estatus );
                mostrarLineaV( cout, vendedores );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosVendedores ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &vendedores ), sizeof( DatosVendedores ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroV( fstream &eliminarDeArchivo )
{
    int codigo = obtenerCodigoV( "\nEscriba el codigo del Vendedor a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosVendedores ) );
    DatosVendedores vendedores;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

    if ( vendedores.obtenerCodigo() != 0 ) {
        DatosVendedores vendedoresEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosVendedores ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &vendedoresEnBlanco ), sizeof( DatosVendedores ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-
void consultarRegistroV( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Nombre" << setw( 14 ) << " Direccion" << setw( 14 ) << " Telefono" << setw( 15 ) << " NIT" << setw( 15 ) << right << " Estatus"  << endl;
    leerDeArchivo.seekg( 0 );
    DatosVendedores vendedores;
    leerDeArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );
    while ( !leerDeArchivo.eof() ) {
        if ( vendedores.obtenerCodigo() != 0 )
            mostrarLineaPantallaV( vendedores );
            leerDeArchivo.read( reinterpret_cast< char * >( &vendedores ), sizeof( DatosVendedores ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaV( const DatosVendedores &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 14 ) << registro.obtenerDireccion().data()
          << setw( 14 ) << registro.obtenerTelefono()
          << setw( 16 ) << registro.obtenerNit().data()
          << setw( 14 ) << setprecision( 2 ) << right <<  registro.obtenerEstatus() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-


Vendedores::~Vendedores()
{
    //dtor
}
