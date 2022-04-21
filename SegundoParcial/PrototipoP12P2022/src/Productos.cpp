#include "Productos.h"
#include "DatosProductos.h"
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

int opcionP();
void imprimirRegistroP( fstream& );
void crearArchivoCreditoP();
void mostrarLineaP( ostream&, const DatosProductos & );
void nuevoRegistroP( fstream& );
int obtenerCodigoP( const char * const );
void modificarRegistroP( fstream& );
void eliminarRegistroP( fstream& );
void consultarRegistroP( fstream& );
void mostrarLineaPantallaP( const DatosProductos &);

using namespace std;

Productos::Productos()
{
    fstream creditoEntradaSalida( "Productos.dat", ios::in | ios::out | ios::binary);
    if ( !creditoEntradaSalida ) {
        cerr << "No se pudo abrir el archivo." << endl;
        crearArchivoCreditoP();
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo\n";
        exit ( 1 );
    }
    enum Opciones { agregar = 1, nuevo, modificar, eliminar, mostrar, FIN };
    int opcion;
    while ( ( opcion = opcionP() ) != FIN ) {
        switch ( opcion ) {
            case agregar:
                imprimirRegistroP( creditoEntradaSalida );
            break;
            case nuevo:
                nuevoRegistroP( creditoEntradaSalida );
            break;
            case modificar:
                modificarRegistroP( creditoEntradaSalida );
            break;
            case eliminar:
                eliminarRegistroP( creditoEntradaSalida );
            break;
            case mostrar:
                consultarRegistroP( creditoEntradaSalida );
            break;
            default:
            cerr << "Opcion incorrecta" << endl;
            break;

      } //FIN SWITCH

       creditoEntradaSalida.clear();

   }
}
int opcionP()
{
    cout<<"\n\t\t\t------------------------------------------------"<<endl;
    cout<<"\t\t\t------------------------------------------------"<<endl;
	cout<<"\t\t\t |   PRODUCTOS - MONICA PEREZ, 9959-21-1840   |"<<endl;
	cout<<"\t\t\t------------------------------------------------"<<endl;

    cout<< "\n\n\t\t\t 1. Guardar archivo de texto para Imprimirlo" << endl
        << "\t\t\t 2. Agregar" << endl
        << "\t\t\t 3. Modificar" << endl
        << "\t\t\t 4. Eliminar" << endl
        << "\t\t\t 5. Mostrar Lista de Productos" << endl
        << "\t\t\t 6. Regresar al Menu Principal" << endl
        <<"\n\t\t\t------------------------------------------------"<<endl
        << "\n\t\t\tIngrese su opcion: ";
    int opcionMenu;
    cin >> opcionMenu;

   return opcionMenu;
}
void imprimirRegistroP( fstream &leerDeArchivo )
{
    ofstream archivoImprimirSalida( "ImprimirProducto.txt", ios::out );
    if ( !archivoImprimirSalida ) {
        cerr << "No se pudo crear el archivo." << endl;
        exit( 1 );

    } //FIN DE INSTRUCCION if

    archivoImprimirSalida << left << setw( 10 ) << "Codigo" << setw( 14 )<< "Nombre" << setw( 13 ) << "CodLinea" << setw( 13 ) << "CodMarca" << setw( 13 ) << "Existencia" << setw( 14 ) <<right<< "Estatus" << endl;
    leerDeArchivo.seekg( 0 );

    DatosProductos productos;
    leerDeArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

    while ( !leerDeArchivo.eof() ) {
        if ( productos.obtenerCodigo() != 0 )
        mostrarLineaP( archivoImprimirSalida, productos );
        leerDeArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );
    } //FIN DE WHILE

} //FIN DE LA FUNCION -IMPRIMIR REGISTRO-
void mostrarLineaP( ostream &salida, const DatosProductos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerCodigo()
          << setw( 16 ) << registro.obtenerNombre().data()
          << setw( 10 ) << registro.obtenerCodLinea()
          << setw( 10 ) << registro.obtenerCodMarca()
          << setw( 10 ) << registro.obtenerExistencia().data()
          << setw( 16 ) << setprecision( 2 ) << right << fixed<< registro.obtenerEstatus().data() << endl;

}//FIN -MOSTRARLINEA-
void crearArchivoCreditoP()
{
    ofstream creditoSalida( "Productos.dat", ios::out | ios::binary );
    if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );
    }
    DatosProductos productosEnBlanco;
    for ( int i = 0; i < 100; i++ )
        creditoSalida.write(reinterpret_cast< const char * >( &productosEnBlanco ), sizeof( DatosProductos ) );
}
void nuevoRegistroP( fstream &insertarEnArchivo )
{
    int codigo = obtenerCodigoP( "\nEscriba el Codigo del Producto " );
    insertarEnArchivo.seekg( ( codigo - 1 ) * sizeof( DatosProductos ) );
    DatosProductos productos;
    insertarEnArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

    if ( productos.obtenerCodigo() == 0 ) {
        char nombre[ 15 ];
        int codLinea;
        int codMarca;
        char existencia[ 10 ];
        char estatus[ 15 ];
        cout<<"Escriba el Nombre del Producto: ";
        cin>> setw( 28 ) >> nombre;
        cout<<"Escriba la Codigo de Linea: ";
        cin>> codLinea;
        cout<<"Escriba el Codigo de Marca: ";
        cin>> codMarca;
        cout<<"Escriba la Existencia del Producto: ";
        cin>> setw( 15 ) >> existencia;
        cout<<"Escriba el Estatus del Producto: ";
        cin>> setw( 16 ) >> estatus;
        productos.establecerNombre( nombre );
        productos.establecerCodLinea( codLinea );
        productos.establecerCodMarca( codMarca );
        productos.establecerExistencia( existencia );
        productos.establecerEstatus( estatus );
        productos.establecerCodigo( codigo );

        insertarEnArchivo.seekp( ( codigo - 1 ) * sizeof( DatosProductos ) );
        insertarEnArchivo.write( reinterpret_cast< const char * >( &productos ), sizeof( DatosProductos ) );
        cout<<"\n Producto agregado Exitosamente..."<<endl;

    } //FIN IF
    else
        cerr << "El Producto con codigo #" << codigo << " ya contiene informacion.\n" << endl;

} //FIN REGISTRO
int obtenerCodigoP( const char * const indicador )
{
   int codigo;
    do {
      cout << indicador << "(1 - 100): ";
      cin >> codigo;

    } while ( codigo < 1 || codigo > 100 );

   return codigo;

} //FIN -OBTENERCODIGO-
void modificarRegistroP( fstream &actualizarArchivo )
{
    int opcionAc=0;
    cout<<"\nEscoja opcion a Actualizar: \n 1. Nombre\n 2. Existencia\n 3. Estatus\n R - ";
    cin>>opcionAc;

    if (opcionAc == 1){
        int codigo = obtenerCodigoP( "\nEscriba el codigo del Producto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosProductos ));

        DatosProductos productos;
        actualizarArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

        //ACTUALIZAR EL REGISTRO
        if (productos.obtenerCodigo() != 0 ) {
            mostrarLineaP( cout, productos );
            cout << "\nEscriba el nuevo Nombre: ";
            string nombre;
            cin >> nombre;

            string nombreAnterior = productos.obtenerNombre();
            productos.establecerNombre( nombre );
            mostrarLineaP( cout, productos );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosProductos ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &productos ), sizeof( DatosProductos ) );
        }

    }else if (opcionAc== 2){
        int codigo = obtenerCodigoP( "\nEscriba el codigo del Producto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosProductos ));

        DatosProductos productos;
        actualizarArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

        //ACTUALIZAR EL REGISTRO
        if (productos.obtenerCodigo() != 0 ) {
            mostrarLineaP( cout, productos );
            cout << "\nEscriba la nueva Existencia: ";
            string existencia;
            cin >> existencia;

            string existenciaAnterior = productos.obtenerExistencia();
            productos.establecerExistencia( existencia );
            mostrarLineaP( cout, productos );

            actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosProductos ));
            actualizarArchivo.write(reinterpret_cast< const char * >( &productos ), sizeof( DatosProductos ) );
        }
    }else if(opcionAc == 3){
        int codigo = obtenerCodigoP( "\nEscriba el codigo del Producto que desea Modificar" );

        actualizarArchivo.seekg(( codigo - 1 ) * sizeof( DatosProductos ));

        DatosProductos productos;
        actualizarArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

        if (productos.obtenerCodigo() != 0 ) {
                mostrarLineaP( cout, productos );
                cout << "\nEscriba el nuevo Estatus: ";
                string estatus;
                cin >> estatus;

                string estatusAnterior = productos.obtenerEstatus();
                productos.establecerEstatus( estatus );
                mostrarLineaP( cout, productos );

                actualizarArchivo.seekp(( codigo - 1 ) * sizeof( DatosProductos ));

                actualizarArchivo.write(reinterpret_cast< const char * >( &productos ), sizeof( DatosProductos ) );
        }
    }

} //FIN DE -ACTUALIZAR REGISTRO-
void eliminarRegistroP( fstream &eliminarDeArchivo )
{
    int codigo = obtenerCodigoP( "\nEscriba el codigo del Producto a Eliminar" );
    eliminarDeArchivo.seekg( ( codigo - 1 ) * sizeof( DatosProductos ) );
    DatosProductos productos;
    eliminarDeArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

    if ( productos.obtenerCodigo() != 0 ) {
        DatosProductos productosesEnBlanco;
        eliminarDeArchivo.seekp( ( codigo - 1 ) * sizeof( DatosProductos ) );
        eliminarDeArchivo.write( reinterpret_cast< const char * >( &productosesEnBlanco ), sizeof( DatosProductos ) );

      cout << " Cuenta #" << codigo << " eliminada Exitosamente.\n";

   } //FIN IF

   //ERROR SI NO EXISTE
   else
      cerr << "La cuenta #" << codigo << " esta vacia.\n";

} //FIN -ELIMINARREGISTRO-
void consultarRegistroP( fstream &leerDeArchivo )
{
    cout << left << setw( 10 ) << "\nCodigo" << setw( 16 ) << " Nombre" << setw( 11 ) << " CodLinea" << setw( 11 ) << " CodMarca" << setw( 11 ) << " Existencia" << setw( 15 ) << right << " Estatus"  << endl;
    leerDeArchivo.seekg( 0 );
    DatosProductos productos;
    leerDeArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );
    while ( !leerDeArchivo.eof() ) {
        if ( productos.obtenerCodigo() != 0 )
            mostrarLineaPantallaP( productos );
            leerDeArchivo.read( reinterpret_cast< char * >( &productos ), sizeof( DatosProductos ) );

   } //FIN WHILE

} //FIN CONSULTAR REGISTRO
void mostrarLineaPantallaP( const DatosProductos &registro )
{
   cout << left <<" "<< setw( 10 ) << registro.obtenerCodigo()
          << setw( 14 ) << registro.obtenerNombre().data()
          << setw( 12 ) << registro.obtenerCodLinea()
          << setw( 12 ) << registro.obtenerCodMarca()
          << setw( 12 ) << registro.obtenerExistencia().data()
          << setw( 14 ) << setprecision( 2 ) << right <<  registro.obtenerEstatus() << endl;

} //FIN -MOSTRARLINEAENOANTALLA-

Productos::~Productos()
{
    //dtor
}
