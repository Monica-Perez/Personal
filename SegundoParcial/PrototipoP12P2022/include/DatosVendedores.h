#ifndef DATOSVENDEDORES_H
#define DATOSVENDEDORES_H

#include <iostream>
using std::string;

class DatosVendedores
{
    public:
        virtual ~DatosVendedores();
        DatosVendedores( int = 0, string = "", string = "", int = 0, string = "", string = "" );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerDireccion( string );
        string obtenerDireccion() const;

        void establecerTelefono( int );
        int obtenerTelefono() const;

        void establecerNit( string );
        string obtenerNit() const;

        void establecerEstatus( string );
        string obtenerEstatus() const;

    protected:

    private:
        int codigo;
        char nombre[ 15 ];
        char direccion[ 15 ];
        int telefono;
        char nit[ 15 ];
        char estatus[ 15 ];
};

#endif // DATOSVENDEDORES_H
