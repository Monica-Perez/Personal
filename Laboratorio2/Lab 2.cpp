#include <iostream>

using namespace std;

int main(){
    double zona=0, examen=0, nfinal=0;
    int curso=0;
    //evalue los cursos y las notas de cada curso
    //mensajes: no llego a zona, excelente, muy bueno, bueno, malo

    cout << "Seleccione el Curso que Desee: \n" << endl;
    cout << "1. Administracion" << endl;
    cout << "2. Derecho" << endl;
    cout << "3. Fisica" << endl;
    cout << "4. Programacion" << endl;
    cout << "5. Calculo\n" << endl;
    cin >> curso;

    cout << "\nIngrese Nota de Zona: ";
    cin >> zona;
    cout << "Ingrese Nota de Examen: ";
    cin >> examen;

    if (zona<25){
        cout << "\n No llego a zona minima.\n";
    }else{
        cout << "\n Si llego a zona minima.\n";
    }

    nfinal = zona+examen;
    cout << "\nNota Final: " << nfinal;
    if (nfinal <=59){
        cout << "\n Reprobado, Insuficiente\n";
    }else if (nfinal >= 60 && nfinal <= 75){
        cout << "\n Aprobado, Bueno\n";
    }else if (nfinal >= 76 && nfinal <= 85){
        cout << "\n Aprobado, Muy Bueno\n";
    }else if (nfinal >= 86 && nfinal <= 95){
        cout << "\n Aprobado, Distinguido\n";
    }else if (nfinal >= 96 && nfinal <= 100){
        cout << "\n Aprobado, Excelente\n";
    }

    return 0;
}



