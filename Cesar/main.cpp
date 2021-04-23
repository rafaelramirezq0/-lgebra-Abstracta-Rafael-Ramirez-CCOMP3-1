#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class cesar {
	int clave;
	public:
		string abc_mayus = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		string abc_minus = "abcdefghijklmnopqrstuvwxyz";
    	cesar(){
        int clave_0 = getsetPrivate();
        }


    int getsetPrivate(){
    	int entrada;
    	cout<<"Ingresar clave: "; cin >> entrada;
      clave=entrada;
      return clave;
    }


    int modulo(int a,int b){
      int q = a/b;
      int r = a-(q*b);

      if (r<0){
          q--;
          r = a-(q*b);
      }
      return r;
	  }


    string encrypt(string msg){
    	string encriptado(msg.length(), ' ');
    	int index;

    	for(int i = 0; i<msg.length(); i++){

        for(int j = 0; j<abc_minus.length(); j++){

          if(msg[i] == abc_minus[j]){

            index=modulo(j + clave, abc_minus.length());
            encriptado[i] = abc_minus[index];
          }

        }

			for(int j = 0; j<abc_mayus.length(); j++){

				if(msg[i] == abc_mayus[j]){
					index = modulo(j + clave, abc_mayus.length());
					encriptado[i] = abc_mayus[index];
				  }
			  }
		  }
	    return encriptado;
	}


  
	string descifrar(string msg){
    	string decrypt(msg.length(),' ');
    	int index;

    	for(int i = 0; i<msg.length(); i++){

        for(int j = 0; j<abc_minus.length(); j++){

          if(msg[i] == abc_minus[j]){
            index = modulo(j-clave,abc_minus.length());
            decrypt[i] = abc_minus[index];
          }
			  }

        for(int j = 0; j<abc_mayus.length(); j++){

          if(msg[i] == abc_mayus[j]){

            index=modulo(j-clave, abc_mayus.length());
            decrypt[i] = abc_mayus[index];
            }
          }
      }
      return decrypt;
  }

};


int main(){
	cesar emisor;
	string msj = "hola amigitos de youtube";
	
  string msg_encriptado = emisor.encrypt(msj);
	cout<<msg_encriptado<<endl;

	
  cesar receptor;

	string msg_decriptado = receptor.descifrar(msg_encriptado);
	cout<<msg_decriptado<<endl;

  return 0;
}
