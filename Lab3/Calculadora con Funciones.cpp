#include <iostream>

using namespace std;

int sumar(int n1, int n2)
{
    return n1+n2;
}
int restar(int n1, int n2)
{
    return n1-n2;
}
int mult(int n1, int n2)
{
    return n1*n2;
}

int main()
{
    int n1=0, n2=0;
    cout<< "Ingrese numero 1: ";
    cin >> n1;
    cout<< "\nIngrese numero 2: ";
    cin >> n2;

    cout<<"\nCalculadora: "<<endl;
    int suma = sumar(n1,n2);
    int resta = restar(n1,n2);
    int mu = mult(n1,n2);

    cout<<"\Suma: "<<suma;
    cout<<"\nResta: "<<resta;
    cout<<"\nMultiplicacion: "<<mu;
    cout<<"\n";

    return 0;
}


