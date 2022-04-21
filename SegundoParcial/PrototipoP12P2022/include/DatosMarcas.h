#ifndef DATOSMARCAS_H
#define DATOSMARCAS_H

#include <iostream>
using std::string;

class DatosMarcas
{
    public:
        virtual ~DatosMarcas();
        DatosMarcas( int = 0, string = "" , string = "" );

        void establecerCodigo( int );
        int obtenerCodigo() const;

        void establecerNombre( string );
        string obtenerNombre() const;

        void establecerEstatus( string );
        string obtenerEstatus() const;

    protected:

    private:
        int codigo;
        char nombre[ 15 ];
        char estatus[ 15 ];
};

#endif // DATOSMARCAS_H
