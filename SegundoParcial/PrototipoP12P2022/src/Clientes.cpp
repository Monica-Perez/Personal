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
void crearArchivoCreditoCli();
void mostrarLineaCli( ostream&, const DatosClientes & );
void nuevoRegistroCli( fstream& );
int obtenerCodigoCli( const char * const );
void modificarRegistroCli( fstream& );
void eliminarRegistroCli( fstream& );
void consultarRegistroCli( fstream& );
void mostrarLineaPantallaCli( const DatosClientes &);

using namespace std;

Clientes::Clientes()
{
    fstream creditoEntradaSalida( "Clientes.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoCli();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionCli() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroCli( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroCli( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroCli( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroCli( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroCli( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   } //FIN WHILE
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
void imprimirRegistroCli( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirCliente.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 16 )<< "Nombre" << setw( 16 ) << "Dirección" << setw( 16 ) << "NIT" << setw( 10 ) << "Telefono" << setw( 10 ) << "CodigoVendedor" << setw( 16 ) <<right<< "Estatus" << endl;
    leerDeArchivo.seekg( 0 );

    DatosClientes clientes;
    leerDeArchivo.read( reinterpret_cast< char * >( &clientes ), sizeof( DatosClientes ) );

    while ( !leerDeArchivo.eof() ) {
        if ( clientes.obtenerCodigo() != 0 )
        mostrarLineaCli( archivoImprimirSalida, clientes );
        leerDeArchivo.read( reinterpret_cast< char * >( &clientes ), sizeof( DatosClientes ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaCli( ostream &salida, const DatosClientes &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerDireccion().data()
          << setw( 16 ) << registro.obtenerNit().data()
          << setw( 10 ) << registro.obtenerTelefono()
          << setw( 10 ) << registro.obtenerCodVendedor()
          << setw( 16 ) << setprecision( 2 ) << right << fixed<< registro.obtenerEstatus().data() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoCli()
{
    ofstream creditoSalida( "Clientes.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosClientes clienteEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( DatosClientes ) );
}
void nuevoRegistroCli( fstream &insertarEnArchivo )
{
    int codigo = obtenerCodigoCli( "\nEscriba el Codigo del Cliente " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosClientes ) );
    DatosClientes clientes;
    insertarEnArchivo.read( reinterpret_cast< char * >( &clientes ), sizeof( DatosClientes ) );

    if ( clientes.obtenerCodigo() == 0 ) {
        char nombre[ 15 ];
        char direccion[ 15 ];
        char nit[ 15 ];
        int telefono;
        int codVendedor;
        char estatus[ 15 ];
        cout<<"Escriba el Nombre del Cliente: ";
        cin>> setw( 15 ) >> nombre;
        cout<<"Escriba la Direccion del Cliente: ";
        cin>> setw( 15 ) >> direccion;
        cout<<"Escriba el Nit del Cliente: ";
        cin>> setw( 15 ) >> nit;
        cout<<"Escriba el Telefono del Cliente: ";
        cin>> telefono;
        cout<<"Escriba el Codigo del Vendedor: ";
        cin>> codVendedor;
        cout<<"Escriba el Estatus del Cliente: ";
        cin>> setw( 15 ) >> estatus;
        clientes.establecerNombre( nombre );
        clientes.establecerDireccion( direccion );
        clientes.establecerNit( nit );
        clientes.establecerTelefono( telefono );
        clientes.establecerCodVendedor( codVendedor );
        clientes.establecerEstatus( estatus );
        clientes.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosClientes ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &clientes ), sizeof( DatosClientes ) );
        cout<<"\n Cliente agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Cliente con codigo #" << codigo << " ya contiene informacion.\n" << endl;

} //FIN REGISTRO
int obtenerCodigoCli( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroCli( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Direccion\n 3. Nit \n 4. Telefono\n 5. Estatus\n R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenerCodigoCli( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes clientes;
        actualizarArchivo.read( reinterpret_cast< char * >( &clientes ), sizeof( DatosClientes ) );

        //ACTUALIZAR EL REGISTRO
        if (clientes.obtenerCodigo() != 0 ) {
            mostrarLineaCli( cout, clientes );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = clientes.obtenerNombre();
            clientes.establecerNombre( nombre );
            mostrarLineaCli( cout, clientes );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &clientes ), sizeof( DatosClientes ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenerCodigoCli( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes cliente;
        actualizarArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );

        //ACTUALIZAR EL REGISTRO
        if (cliente.obtenerCodigo() != 0 ) {
            mostrarLineaCli( cout, cliente );
            cout << "\nEscriba la nueva Direccion: ";
            string direccion;
            cin >> direccion;

            string direccionAnterior = cliente.obtenerDireccion();
            cliente.establecerDireccion( direccion );
            mostrarLineaCli( cout, cliente );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &cliente ), sizeof( DatosClientes ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenerCodigoCli( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes cliente;
        actualizarArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );

        if (cliente.obtenerCodigo() != 0 ) {
                mostrarLineaCli( cout, cliente );
                cout << "\nEscriba el nuevo NIT: ";
                string nit;
                cin >> nit;

                string nitAnterior = cliente.obtenerNit();
                cliente.establecerNit( nit );
                mostrarLineaCli( cout, cliente );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &cliente ), sizeof( DatosClientes ) );
        }
    }else if(opcionAc == 4){
        int codigo = obtenerCodigoCli( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes cliente;
        actualizarArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );

        if (cliente.obtenerCodigo() != 0 ) {
                mostrarLineaCli( cout, cliente );
                cout << "\nEscriba el nuevo Telefono: ";
                int telefono;
                cin >> telefono;

                int telefonoAnterior = cliente.obtenerTelefono();
                cliente.establecerTelefono( telefono );
                mostrarLineaCli( cout, cliente );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &cliente ), sizeof( DatosClientes ) );
        }
    }else if(opcionAc == 5){
        int codigo = obtenerCodigoCli( "\nEscriba el codigo del Cliente que desea Modifcar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosClientes ));

        DatosClientes cliente;
        actualizarArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );

        if (cliente.obtenerCodigo() != 0 ) {
                mostrarLineaCli( cout, cliente );
                cout << "\nEscriba el nuevo Estatus: ";
                string estatus;
                cin >> estatus;

                string estatusAnterior = cliente.obtenerEstatus();
                cliente.establecerEstatus( estatus );
                mostrarLineaCli( cout, cliente );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosClientes ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &cliente ), sizeof( DatosClientes ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroCli( fstream &eliminarDeArchivo )
{
    int codigo = obtenerCodigoCli( "\nEscriba el codigo del Cliente a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosClientes ) );
    DatosClientes cliente;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );

    if ( cliente.obtenerCodigo() != 0 ) {
        DatosClientes clienteEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosClientes ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &clienteEnBlanco ), sizeof( DatosClientes ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-
void consultarRegistroCli( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Nombre" << setw( 14 ) << " Direccion" << setw( 16 ) << " NIT" << setw( 14 ) << " Telefono" << setw( 10 ) << " CodVendedor" << setw( 15 ) << right << " Estatus"  << endl;
    leerDeArchivo.seekg( 0 );
    DatosClientes cliente;
    leerDeArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );
    while ( !leerDeArchivo.eof() ) {
        if ( cliente.obtenerCodigo() != 0 )
            mostrarLineaPantallaCli(cliente);
            leerDeArchivo.read( reinterpret_cast< char * >( &cliente ), sizeof( DatosClientes ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaCli( const DatosClientes &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 16 ) << registro.obtenerDireccion().data()
          << setw( 16 ) << registro.obtenerNit().data()
          << setw( 14 ) << registro.obtenerTelefono()
          << setw( 10 ) << registro.obtenerCodVendedor()
          << setw( 16 ) << setprecision( 2 ) << right <<  registro.obtenerEstatus() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Clientes::~Clientes()
{
    //dtor
}
