#include "DatosClientes.h"
#include "Clientes.h"
#include <cstring>
#include <iostream>

using std::string;

DatosClientes::DatosClientes(/*int valorCodigo, string valorNombre, string valorDireccion,  string valorNit, int valorTelefono, int valorCodVendedor, string valorEstatus */)
{
    /*establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerDireccion( valorDireccion );
    establecerNit( valorNit );
    establecerTelefono( valorTelefono );
    establecerCodVendedor( valorCodVendedor );
    establecerEstatus( valorEstatus );*/
}/*
int DatosClientes::obtenerCodigo() const
{
   return codigo;
}
void DatosClientes::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
/*---------------------------------------------------------------*/
/*string DatosClientes::obtenerNombre() const
{
   return nombre;
}
void DatosClientes::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
/*string DatosClientes::obtenerDireccion() const
{
   return direccion;
}
void DatosClientes::establecerDireccion( string direString )
{
    const char *valorDireccion = direString.data();
    int longitud = strlen( valorDireccion );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( direccion, valorDireccion, longitud );

    direccion[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
/*string DatosClientes::obtenerNit() const
{
   return nit;
}
void DatosClientes::establecerNit( string nitstring )
{
    const char *valorNit = nitstring.data();
    int longitud = strlen( valorNit );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nit, valorNit, longitud );

    nit[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
/*int DatosClientes::obtenerTelefono() const
{
   return telefono;
}
void DatosClientes::establecerTelefono( int valorTelefono )
{
   telefono = valorTelefono;
}
/*---------------------------------------------------------------*/
/*int DatosClientes::obtenerCodVendedor() const
{
   return codVendedor;
}
void DatosClientes::establecerCodVendedor( int valorCodVendedor )
{
   codVendedor = valorCodVendedor;
}
/*---------------------------------------------------------------*/
/*string DatosClientes::obtenerEstatus() const
{
   return estatus;
}
void DatosClientes::establecerEstatus( string estatusstring )
{
    const char *valorEstatus = estatusstring.data();
    int longitud = strlen( valorEstatus );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( estatus, valorEstatus, longitud );

    estatus[ longitud ] = '\0';
}
*/
DatosClientes::~DatosClientes()
{
    //dtor
}
