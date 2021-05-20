#include <iostream>
#include <string>
#include <cstring>
#include "mate.cpp"
using namespace std;

class RSA {
    /*
    int p = 17;
    int q = 43;
    int n = p*q;
    int fi_n = (p-1)*(q-1)
    int e_cpublica = modulo(crear_random_primo(71,300),fi_n)*/
private: 
    int p = crear_random_primo(9,30);
    int q = crear_random_primo(31,70);
    int fi_n = (p-1)*(q-1);
    int x0, y0;
    


public:
    RSA(){}
    string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,. ";
    int N = p*q;
    int e_cpublica = modulo(crear_random_primo(71,300),fi_n);

    int d_cprivada = inversa(fi_n, e_cpublica, &x0, &y0);
    
    void get_p_q(){
        cout<<p<<"        "<<q<<endl;
    }

    int mod(int a, int b){
        return modulo(a,b);
    }
    int return_index(string abc, char caracter){
        for(int i=0; abc.length(); i++){
            if(abc[i] == caracter){return (i+1);}
        }
    }

    int* ENCRYPT(string mensaje, RSA& RECEPTOR){
        //cout<<"RECEPTOR:"<<RECEPTOR.p<<"      "<<RECEPTOR.q<<endl;
        //cout<<"EMISOR:"<<p<<"      "<<q<<endl;
        int index_abc, index_cifrado;
        int* encript_array{new int[mensaje.length()]{} };
        for(int i=0; i<mensaje.length(); i++){
            index_abc = return_index(abecedario, mensaje[i]);
            index_cifrado = mod(potencia_mod(index_abc, e_cpublica, N),N);
            encript_array[i] = index_cifrado;
            cout<<"index original de la letra: "<<index_abc<<'\t'<<'\t'<<"encript_array["<<i<<"]: "<<encript_array[i]<<endl;
        }
        return encript_array;
    }

    int* DECRYPT(int* array_encriptado, string mensaje_original){
        int index_descifrado;
        int* decripted_array{new int[sizeof(array_encriptado)]{} };

        for(int i=0; i<mensaje_original.length(); i++){
            index_descifrado = mod(potencia_mod(array_encriptado[i],d_cprivada,N),N);
            decripted_array[i] = index_descifrado;
            cout<<"decripted_array["<<i<<"]: "<<decripted_array[i]<<'\t'<<'\t'<<'\t'<<"Numero cuando estaba cifrado:"<<array_encriptado[i]<<endl;
        }
        return decripted_array;
    }
};


int main(){
    RSA Bernardo;   // emisor
    RSA Alicia;     // receptor
    
    string mensaje = "TI";

    "ENCRIPTAR";
    int* msg_encriptado = Bernardo.ENCRYPT(mensaje, Alicia);

    cout<<endl;

    int* msg_descifrado = Alicia.DECRYPT(msg_encriptado, mensaje);
}
