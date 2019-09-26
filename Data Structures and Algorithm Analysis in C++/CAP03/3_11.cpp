#include<iostream>
#include"lista_enlazada.h"
using namespace std;
int main(){
	Lista_enlazada<int> L;
	int tamano=6;
	int d=8;
	for(int i=1;i<tamano;i++){
		L.insertar_inicio(i);
	}
	cout<<"------Imprimir la lista--------"<<endl;
	L.mostrar();
	cout<<"------Tamaño de la lista--------"<<endl;
	cout << L.getSize()<<endl;
	cout<<"------Comprobamos si el dato ya esta en la lista --------"<<endl;
	L.insertar_inicio(3);
	cout<<"------Insertamos en la lista--------"<<endl;
	L.mostrar();
	cout<<"------Tamaño de la lista--------"<<endl;
	cout << L.getSize()<<endl;
	cout<<"------Buscamos un dato en la lista--------"<<endl;
	if(L.buscar(d)==false){
		cout<<"No se encontro "<<d <<endl;
	}
	else{
		cout<<"Se encontro"<<endl;
	}
	cout<<"------Eliminamos un dato (3) de la lista--------"<<endl;
	L.eliminar_dato(3);
	L.mostrar();
	return 0;
}
