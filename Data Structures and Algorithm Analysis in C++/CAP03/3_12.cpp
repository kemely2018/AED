#include <iostream>
#include "lista_enlazada.h"
using namespace std;

int main()
{
    Lista_enlazada<int> M;
    M.insertar_orde(5);
    M.insertar_orde(7);
    M.insertar_orde(6);
    M.insertar_orde(1);
    M.insertar_orde(4);
    M.insertar_orde(3);
    M.mostrar();
    return 0;
}
