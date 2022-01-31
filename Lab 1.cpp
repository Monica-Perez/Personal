#include <iostream>

using namespace std;

int main()
{
    int n1 = 0, n2 = 0, s=0, r=0,m=0,d=0;
    cout << "Ingrese Numero 1: ";
    cin >> n1;
    cout << "Ingrese Numero 2: ";
    cin >> n2;
    s=n1+n2;
    r=n1-n2;
    m=n1*n2;
    d=n1/n2;
    cout << " La Suma es: " << s <<endl;
    cout << " La Resta es: " << r <<endl;
    cout << " La Multiplicacion es: " << m <<endl;
    cout << " La Division es: " << d <<endl;
    return 0;
}
