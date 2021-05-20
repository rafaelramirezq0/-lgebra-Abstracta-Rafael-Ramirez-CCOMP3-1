#include <iostream>
#include <ctime>
//#include <time.h>
using namespace std;

void swap(int *a, int *b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

int modulo(int a, int n){
    int r = a-n * (a/n);
    
    if(r<0){
      r += n;
    };
    
    return r;
}

int euclides(int a, int b){

  if (modulo(a,b) != 0){
    int x = b;
    b = modulo(a, b);
    a = x;
    return euclides(a,b);
  }
  
  else{
  return b;
  }

}

int inversa(int a, int b, int* x, int* y){

    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1;     // x1= y en el algoritmo        y1= x en el algoritmo
    int mcd = inversa(b%a, a, &x1, &y1);

    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return x1;  // retornar x1 si es que a>b como 391,29     ||     retornar y1 si es que a<b para hallar euclides
}

int factores(int num){
    int a = 1;
    int b = num;

    while(a != num){
        while(b != 0){
            if(a*b == num){
                cout<<"a: "<<a<<"             "<<"b: "<<b<<endl;
                a += 1;
                continue;
            }
            else{
                b -= 1;
            }
        }
        a += 1;
        b = num;
    }
}

bool confirm_prime(int num){
    for(int i=2; i<=num/2; i++){
        int j{num-1};
        if( modulo(num,i) == 0 || modulo(num,j) == 0 ){
            return false;     // returns 0 osea no es prim0
        }
        j -= 1;
    }
    return true;       // returns 1 osea es primo
}

int crear_random_primo(int min, int max){
    srand(time(0));
    int numero = modulo(rand(),max-min)+min;

    if(confirm_prime(numero) == true){
        return numero;
    }

    else{
        while(confirm_prime(numero) == false){
            srand(time(0));
            int numero = modulo(rand(),max-min)+min;

            if(confirm_prime(numero) == true){
                return numero;
            }
        }
    }
}

long potencia(int base, int m){
    if (m != 0)
        return (base*potencia(base, m-1));
    else
        return 1;
}

int potencia_mod(int x,int m, int N){
    int counter = 1, potenciar = 1;
    int eme = m, elevado = x, rpta = x;
    
    for(int i=2; i<m; i+=i){
        counter++;
    }
    
    for(int i=0; i<counter;i++){
        //cout<<"___________________________________________________________________________________________________________________"<<endl;
        //cout<<"x: "<<x<<'\t'<<"m: "<<m<<'\t'<<"m(mod2): "<<modulo(m,2)<<'\t';
        
        if(i==0){
            elevado = modulo(potencia(x,1),N); potenciar = 2;
            rpta = x;
            m = m/2;
        }

        else if(modulo(m,2) == 1){
            elevado = modulo(potencia(elevado,2),N); potenciar+= potenciar;
            rpta = modulo(elevado*rpta,N);
            m = m/2;
        }

        else if(modulo(m,2) == 0){
            elevado = modulo(potencia(elevado,2),N); potenciar+= potenciar;
            m = m/2;
        }

        if(m==0){
            
        }
        //cout<<"elevado: "<<elevado<<'\t'<<"rpta(mod N): "<<rpta<<'\t'<<"n/2: "<<(m)<<"               "<<potenciar<<endl;

    }
    return rpta;

}
