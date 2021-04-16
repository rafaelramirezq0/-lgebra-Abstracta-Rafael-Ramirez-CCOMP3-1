#include <iostream>
#include <cstring>
using namespace std;
using std::strtok;


int modulo(int a, int n){
  int r;
  r = a-n * (a/n);
  return r;
}

int main(){
  int bloque;
  string cadena;
  cout<<"Ingrese una cadena de caracteres: "; cin>>cadena;cout<<endl;
  cout<<"Ingrese el número de caracteres en los que se separará el bloque: "; cin>>bloque;cout<<endl;
  
  
  int len = modulo(cadena.length(), 4);
  char *tokens;
  
  if (len == 0){
    string vector[cadena.length()/4];
  }
  else{
    string vector[(cadena.length()/4)+1];    
  }

  for (unsigned i = 0; i < cadena.length(); i += bloque) {
    cout << cadena.substr(i, 4) << endl;}

  return 0;
}