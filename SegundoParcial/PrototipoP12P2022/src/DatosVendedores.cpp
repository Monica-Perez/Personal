#include "DatosVendedores.h"
#include "Vendedores.h"
#include <cstring>
#include <iostream>

using std::string;

DatosVendedores::DatosVendedores(int valorCodigo, string valorNombre, string valorDireccion, int valorTelefono,  string valorNit, string valorEstatus )
{
    establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerDireccion( valorDireccion );
    establecerTelefono( valorTelefono );
    establecerNit( valorNit );
    establecerEstatus( valorEstatus );
}
int DatosVendedores::obtenerCodigo() const
{
   return codigo;
}
void DatosVendedores::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
/*---------------------------------------------------------------*/
string DatosVendedores::obtenerNombre() const
{
   return nombre;
}
void DatosVendedores::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
string DatosVendedores::obtenerDireccion() const
{
   return direccion;
}
void DatosVendedores::establecerDireccion( string direString )
{
    const char *valorDireccion = direString.data();
    int longitud = strlen( valorDireccion );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( direccion, valorDireccion, longitud );

    direccion[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
string DatosVendedores::obtenerNit() const
{
   return nit;
}
void DatosVendedores::establecerNit( string nitstring )
{
    const char *valorNit = nitstring.data();
    int longitud = strlen( valorNit );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nit, valorNit, longitud );

    nit[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
int DatosVendedores::obtenerTelefono() const
{
   return telefono;
}
void DatosVendedores::establecerTelefono( int valorTelefono )
{
   telefono = valorTelefono;
}
/*---------------------------------------------------------------*/
string DatosVendedores::obtenerEstatus() const
{
   return estatus;
}
void DatosVendedores::establecerEstatus( string estatusstring )
{
    const char *valorEstatus = estatusstring.data();
    int longitud = strlen( valorEstatus );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( estatus, valorEstatus, longitud );

    estatus[ longitud ] = '\0';
}

DatosVendedores::~DatosVendedores()
{
    //dtor
}
