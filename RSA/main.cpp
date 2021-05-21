#include <iostream>
#include <string>
#include <cstring>
#include "mate.cpp"
using namespace std;

class RSA {

private: 
    //long p = 17;                                     // Usar esto para 'p' específico
    //long q = 43;                                     // Usar esto para 'q' específico
    int p = crear_random_primo(9,30);
    int q = crear_random_primo(31,70);
    long fi_N = (p-1)*(q-1);
    long x0, y0;
    long d_cprivada = inversa2(fi_N, e_cpublica, x0, y0);

public:
    RSA(){}

    string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,. ";
    long N = p*q;
    //long e_cpublica = 101;                                                       // Usar esta para clave 'e' específica
    long e_cpublica = modulo(crear_random_primo(71,300),fi_N);

    void get_DATA(){
        cout<<"VARIABLES:"<<'\n'<<
        "p: "<<p<<endl<<
        "q: "<<q<<endl<<
        "N: "<<N<<endl<<
        "fi_n: "<<fi_N<<endl<<
        "clave e publica: "<<e_cpublica<<endl<<
        "clave d privada: "<<d_cprivada<<endl;
        cout<<endl;
    }   

    long mod(long a, long b){
        return modulo(a,b);
    }
    int return_index(string abc, char caracter){
        for(int i=0; abc.length(); i++){
            if(abc[i] == caracter){return (i+1);}
        }
    }

    long* ENCRYPT(string mensaje, RSA& RECEPTOR){
        //cout<<"RECEPTOR-> p: "<<RECEPTOR.p<<"      q: "<<RECEPTOR.q<<"      N: "<<RECEPTOR.N<<"      fi_n: "<<RECEPTOR.fi_N<<endl;
        long index_abc, index_cifrado;
        long* encript_array{new long[mensaje.length()]{} };cout<<'\t'<<"Cifrado:"<<endl;
        for(int i=0; i<mensaje.length(); i++){
            index_abc = return_index(abecedario, mensaje[i]);
            index_cifrado = mod(potencia_mod(index_abc, RECEPTOR.e_cpublica, RECEPTOR.N),RECEPTOR.N);
            encript_array[i] = index_cifrado;
            cout<<'\t'<<'\t'<<"Letra NUM "<<i<<" -> ";
            cout<<'\t'<<'\t'<<"index original de la letra: "<<index_abc<<'\t'<<'\t'<<"encript_array["<<i<<"]: "<<encript_array[i]<<endl;
        }
        return encript_array;
    }

    long* DECRYPT(long* array_encriptado, string mensaje_original){
        long index_descifrado;
        long* decripted_array{new long[sizeof(array_encriptado)]{} };cout<<'\t'<<"Descifrado:"<<endl;

        for(int i=0; i<mensaje_original.length(); i++){
            index_descifrado = mod(potencia_mod(array_encriptado[i],d_cprivada,N),N);
            decripted_array[i] = index_descifrado;
            cout<<'\t'<<'\t'<<"Letra NUM "<<i<<" -> ";
            cout<<'\t'<<'\t'<<"decripted_array["<<i<<"]: "<<decripted_array[i]<<'\t'<<'\t'<<'\t'<<"Numero cuando estaba cifrado:"<<array_encriptado[i]<<endl;
        }
        // El valor de decripted_array[i] es representativo, no es el algoritmo comleto xq esta por verse :);
        return decripted_array;
    }
};


int main(){
    RSA Bernardo;   // emisor
    RSA Alicia;     // receptor

    string mensaje = "TI";

    cout<<"Bernardo "; Bernardo.get_DATA();
    cout<<"Alicia "; Alicia.get_DATA();
    "ENCRIPTAR";
    long* msg_encriptado = Bernardo.ENCRYPT(mensaje, Alicia);

    cout<<endl;

    long* msg_descifrado = Alicia.DECRYPT(msg_encriptado, mensaje);
}
