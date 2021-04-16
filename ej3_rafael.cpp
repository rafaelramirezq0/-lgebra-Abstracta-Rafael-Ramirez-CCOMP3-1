#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;
 
int main() {
 int str_en_int;
 string numeros_en_str;
 cout<<"Ingrese un numero: "; cin>>str_en_int;cout<<endl;
 
 stringstream estringstrim;
 estringstrim << str_en_int; 
 estringstrim >> numeros_en_str;
 
 cout<<"Verificación:"<<endl;
 cout<<"HOLA "+numeros_en_str<<endl;
 cout<<"Sí concatena con un string";

