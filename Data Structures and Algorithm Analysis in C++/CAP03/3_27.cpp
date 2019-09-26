/* Si se ejecuta la rutina recursiva en la Secci�n 2.4 para calcular los n�meros de Fibonacci
para N = 50, �es probable que se agote el espacio de la pila? �Por qu� o por qu� no?*/

/* El espacio de apilamiento no se agotar� porque solo se apilar�n 49 llamadas. 
Sin embargo, el tiempo de ejecuci�n es exponencial, como se muestra en el Cap�tulo 2, 
y por lo tanto la rutina no terminar� en un per�odo de tiempo razonable.*/

#include<iostream>
using namespace std;

unsigned long Fib(int N)
{
  
  if (N <= 1)
    return 1;
  else
    return Fib(N-1) + Fib(N-2);
}

int main()
{
  unsigned long i, c, d;
  int numRepeat = 51;
  for(i = 10; i < numRepeat; i+=10)
  {
    d = Fib(i);
    cout<<i<<"    ES    "<<d<<endl;
  }
  return 0;
}
