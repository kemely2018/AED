#include<iostream>
#include "lista_desordenada.h"
#include "lista_ordenada.h"
using namespace std;
int main(){
	
	//unorderedLinkedList<int> lis;
	orderedLinkedList<int> lis;
	linkedListIterator<int> it;
	lis.insertFirst(8);
	lis.insertFirst(3);
	lis.insertFirst(2);
	lis.print();
	cout<<lis.length()<<endl;
	lis.insertLast(4);
	lis.insertLast(1);
	lis.print();
	cout<<lis.length()<<endl;
       
	lis.deleteNode(2); 
    for(it = lis.begin(); it != lis.end(); ++it)                  
        cout << *it << " ";                         
    cout << endl; 
	return 0;
}


