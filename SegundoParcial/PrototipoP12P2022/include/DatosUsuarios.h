#ifndef DATOSUSUARIOS_H
#define DATOSUSUARIOS_H

#include <iostream>
using std::string;

class DatosUsuarios
{
    public:
        virtual ~DatosUsuarios();
        DatosUsuarios( int = 0, int = 0 );

        void establecerUsuario( int );
        int obtenerUsuario() const;

        void establecerContra( int );
        int obtenerContra() const;

    protected:

    private:
        int usuario;
        int contra;
};

#endif // DATOSUSUARIOS_H
