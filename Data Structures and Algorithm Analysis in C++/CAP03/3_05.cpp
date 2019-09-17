/*4.Dadas dos listas ordenadas, L1 y L2, escriba un procedimiento para calcular L1 union L2 
usando solo la lista de operaciones básicas.*/

#include <iostream>
#include "list"
using namespace std;

list<int> un(list<int> &L1, list<int> &L2){
	list<int> L3;
	list<int>::iterator it;
	for(it = L1.begin(); it != L1.end(); it++){
		L3.push_back(*it);
	}
	for(it = L2.begin(); it != L2.end(); it++){
		L3.push_back(*it);
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
	list<int> a={1,3,5,7,9,15};
	list<int> b={2,4,6,8,10,18,20};
	list<int> c;
	c=un(a, b);
	cout << "LISTA A = " ;
	imprimir(a);
	cout << "LISTA B = " ;
	imprimir(b);
	cout<<"A U B"<<endl;
	cout << "LISTA C = " ;
	imprimir(c);
	
	return 0;
}
