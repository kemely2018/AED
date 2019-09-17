/*
  3.Implemente la rutina de búsqueda de STL que devuelve el iterador que contiene la primera aparición de x en el rango que comienza 
  en el inicio y se extiende hasta el final, pero sin incluirlo. Si no se encuentra x, se devuelve el final. 
  Esta es una no clase (función global) con firma.
*/

#include <iostream>
#include <list>
using namespace std;

template <typename Iterator, typename Object>
Iterator find(Iterator inicio, Iterator final,const Object & x ){
	for(inicio;inicio !=final; inicio++){
		if(*inicio == x)
			return inicio;
	}
	return final; 
}

int main(){
	list<int> lista = {1,6,4,7,8};
	list<int>::iterator ini= lista.begin();
	list<int>::iterator fin= lista.end();
	int a = 4;
	auto resp= find(ini, fin, a);
	if(resp==fin){
		cout << "NO ENCONTRADO!" << endl;
	} else {
		cout << "ENCONTRADO: " << *resp << endl;
	}

	return 0;
}
