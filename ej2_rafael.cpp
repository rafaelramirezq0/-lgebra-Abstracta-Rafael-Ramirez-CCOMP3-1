#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main() {
  string numeros_en_str;
  int str_en_int;
  cout<<"Ingrese una cadena de numeros: "; cin>>numeros_en_str;cout<<endl;

  stringstream estringstrim;
  estringstrim << numeros_en_str;  
  estringstrim >> str_en_int;

  cout<<"Verificación:"<<endl;
  cout<<10+str_en_int<<endl;
  cout<<"Sí suma con otro int";

}
