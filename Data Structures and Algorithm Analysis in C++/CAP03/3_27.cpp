/* Si se ejecuta la rutina recursiva en la Sección 2.4 para calcular los números de Fibonacci
para N = 50, ¿es probable que se agote el espacio de la pila? ¿Por qué o por qué no?*/

/* El espacio de apilamiento no se agotará porque solo se apilarán 49 llamadas. 
Sin embargo, el tiempo de ejecución es exponencial, como se muestra en el Capítulo 2, 
y por lo tanto la rutina no terminará en un período de tiempo razonable.*/

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
