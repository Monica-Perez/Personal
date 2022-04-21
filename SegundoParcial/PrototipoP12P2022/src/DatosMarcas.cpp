#include "DatosMarcas.h"
#include "Marcas.h"
#include <cstring>
#include <iostream>

using std::string;

DatosMarcas::DatosMarcas( int valorCodigo, string valorNombre, string valorEstatus )
{
    establecerCodigo( valorCodigo );
    establecerNombre( valorNombre );
    establecerEstatus( valorEstatus );
}
int DatosMarcas::obtenerCodigo() const
{
   return codigo;
}
void DatosMarcas::establecerCodigo( int valorCodigo )
{
   codigo = valorCodigo;
}
/*---------------------------------------------------------------*/
string DatosMarcas::obtenerNombre() const
{
   return nombre;
}
void DatosMarcas::establecerNombre( string primerNombre )
{
    const char *valorNombre = primerNombre.data();
    int longitud = strlen( valorNombre );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( nombre, valorNombre, longitud );

    primerNombre[ longitud ] = '\0';
}
/*---------------------------------------------------------------*/
string DatosMarcas::obtenerEstatus() const
{
   return estatus;
}
void DatosMarcas::establecerEstatus( string estatusstring )
{
    const char *valorEstatus = estatusstring.data();
    int longitud = strlen( valorEstatus );
    longitud = ( longitud < 15 ? longitud : 14 );
    strncpy( estatus, valorEstatus, longitud );

    estatus[ longitud ] = '\0';
}

DatosMarcas::~DatosMarcas()
{
    //dtor
}
