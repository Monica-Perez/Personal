#include "DatosProductos.h"
#include "Productos.h"
#include <cstring>
#include <iostream>

using std::string;

DatosProductos::DatosProductos( int valorCodigo, string valorNombre, int valorCodLinea, int valorCodMarca, string valorExistencia, string valorEstatus )
{
    establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerCodLinea( valorCodLinea );
    establecerCodMarca( valorCodMarca );
    establecerExistencia( valorExistencia );
    establecerEstatus( valorEstatus );
}
int DatosProductos::obtenerCodigo() const
{
   return codigo;
}
void DatosProductos::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
/*---------------------------------------------------------------*/
string DatosProductos::obtenerNombre() const
{
   return nombre;
}
void DatosProductos::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
int DatosProductos::obtenerCodLinea() const
{
   return codLinea;
}
void DatosProductos::establecerCodLinea( int valorCodLinea )
{
   codLinea = valorCodLinea;
}
/*---------------------------------------------------------------*/
int DatosProductos::obtenerCodMarca() const
{
   return codMarca;
}
void DatosProductos::establecerCodMarca( int valorCodMarca )
{
   codMarca = valorCodMarca;
}
/*---------------------------------------------------------------*/
string DatosProductos::obtenerExistencia() const
{
   return existencia;
}
void DatosProductos::establecerExistencia( string existenciastring )
{
    const char *valorExistencia = existenciastring.data();
    int longitud = strlen( valorExistencia );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( existencia, valorExistencia, longitud );

    existencia[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
string DatosProductos::obtenerEstatus() const
{
   return estatus;
}
void DatosProductos::establecerEstatus( string estatusstring )
{
    const char *valorEstatus = estatusstring.data();
    int longitud = strlen( valorEstatus );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( estatus, valorEstatus, longitud );

    estatus[ longitud ] = '\0';
}

DatosProductos::~DatosProductos()
{
    //dtor
}
