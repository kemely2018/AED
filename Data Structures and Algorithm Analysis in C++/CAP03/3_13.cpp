#include<iostream>
#include"lista_itera.h"
int main()
{
    ListaDoble<int> L;
    for(int i=1;i<=5;i++){
    	L.push(i);
	}
	L.mostrar();
    IteratorLista<int> it;
    for(it=L.end() ; it != L.begin() ; --it )
        cout << *it << " ";
    cout<<endl;
    return 0;
}
