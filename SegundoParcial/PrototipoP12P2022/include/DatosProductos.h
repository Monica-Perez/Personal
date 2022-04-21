#ifndef DATOSPRODUCTOS_H
#define DATOSPRODUCTOS_H

#include <iostream>
using std::string;

class DatosProductos
{
    public:
        virtual ~DatosProductos();
        DatosProductos( int = 0, string = "", int = 0, int = 0, string = "" , string = "" );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerCodLinea( int );
        int obtenerCodLinea() const;

        void establecerCodMarca( int );
        int obtenerCodMarca() const;

        void establecerExistencia( string );
        string obtenerExistencia() const;

        void establecerEstatus( string );
        string obtenerEstatus() const;


    protected:

    private:
        int codigo;
        char nombre[ 15 ];
        int codLinea;
        int codMarca;
        char existencia[ 15 ];
        char estatus[ 15 ];
};

#endif // DATOSPRODUCTOS_H
