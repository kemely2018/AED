/*
3.1 Se le proporciona una lista, L, y otra lista, P, que contiene enteros 
ordenados en orden ascendente. La operación printLots (L, P) imprimirá los 
elementos en L que están en posiciones especificado por P. Por ejemplo, si 
P = 1, 3, 4, 6, los elementos en las posiciones 1, 3, 4 y 6 en L están 
impresos. Escriba el procedimiento printLots (L, P). Solo puede usar las 
operaciones públicas de contenedor STL. 
¿Cuál es el tiempo de ejecución de su procedimiento?
-Es de 1 milisegundo = 0.001 segundos
*/

#include <iostream>
#include <list>
#include<ctime>
using namespace std;

int getMilisegundos(clock_t c){
	int tiempo=0;
    tiempo = (int)((c/(double)CLOCKS_PER_SEC)*1000) ;
    return tiempo;
}

void printLots(list <int> L,list <int> P) 
{ 
    list<int>::iterator itP;
	list<int>::iterator itL; 
	int cont=0;
    for(itP = P.begin(); itP != P.end(); ++itP){
    	for(itL = L.begin(); itL != L.end(); ++itL) {
    		if(*itP==cont){
    			cout<<*itL<<endl;
			}
			cont++;
		}
		cont=0;
	}        
} 

int main(){
	list<int> L={1,2,3,4,5,6,7,8,9};
	list<int> P={1,3,4,6};
	int t1,t2,tiempo;
	t1 =clock();
	printLots(L,P);
	t2=clock();
	tiempo=getMilisegundos(t2-t1);
	cout<<"Tiempo de ejecucion:"<<tiempo;
	return 0;
}




