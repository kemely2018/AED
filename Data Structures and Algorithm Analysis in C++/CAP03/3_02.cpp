/*2.	Cambie dos elementos adyacentes ajustando solo los enlaces 
(y no los datos) usando:
a. singly linked lists */

#include<iostream>
#include "lista_enlazada.h"
using namespace std;

int main(){
    Lista_enlazada<int> l_int;
    l_int.insertar(2);
    l_int.insertar(1);
    l_int.insertar(3);
    l_int.insertar(8);
    l_int.insertar(5);
    l_int.mostrar();
    l_int.swap_adyacente(2);
    l_int.mostrar();
    l_int.swap_adyacente(4);
    l_int.mostrar();
}

