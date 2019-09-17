/*4.Dadas dos listas ordenadas, L1 y L2, escriba un procedimiento para calcular L1 interseccion L2 
usando solo la lista de operaciones básicas.*/

#include <iostream>
#include "list"
using namespace std;

list<int> intersection(list<int> &L1, list<int> &L2){
	list<int> L3;
	list<int>::iterator it;
	list<int>::iterator it2;
	for(it = L1.begin(); it != L1.end(); it++){
		for( it2 = L2.begin(); it2 != L2.end(); it2++){
			if(*it == *it2){
				L3.push_back(*it);
			}
		}
	}
	return L3;
}

void imprimir(list<int> L){
	list<int>::iterator it;
	cout <<"[";
	for(it = L.begin(); it != L.end(); it++){
		cout << *it << ", ";
	}
	cout <<"]"<< "\n" << endl;
}
int main(){
	list<int> a={1,2,3,4,5,6,7,8,9,10};
	list<int> b={2,4,6,8,10,18};
	list<int> c;
	c=intersection(a, b);
	cout << "LISTA A = " ;
	imprimir(a);
	cout << "LISTA B = " ;
	imprimir(b);
	cout<<"A n B"<<endl;
	cout << "LISTA C = " ;
	imprimir(c);
	
	return 0;
}
