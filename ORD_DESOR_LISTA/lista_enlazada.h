#pragma once
#include <iostream>

using namespace std;

// Definici�n del nodo
template <class Type>
class nodeType{
	public:
		Type info;
	    nodeType<Type> *link;
};

/* -------------- CLASE ITERADOR -------------------*/

/* class linkedListIterator:
Esta clase especifica los miembros 
para implementar un iterador
a una lista vinculada.*/

template <class Type>
class linkedListIterator{
	
	public:
		linkedListIterator();
		//Constructor predeterminado
		//Poscondition:actual = NULL;current ->actual
		
        linkedListIterator(nodeType<Type> *ptr);
        //Constructor con parametros
        //Postcondition: actual = ptr;
        Type operator*();
        //Funci�n para sobrecargar el operador de desreferenciaci�n *.
        //Postcondition: Devuelve la informaci�n contenida en el nodo.
        linkedListIterator<Type> operator++();    
        //Sobrecargar el operador de preincremento.
        //Postcondition: El iterador avanza al siguiente nodo.
        bool operator==(const linkedListIterator<Type>& right) const;
        //Sobrecargar el operador de igualdad.
        //Postcondition: Devuelve verdadero si este iterador es igual a 
        //el iterador especificado por la derecha, de lo contrario, 
        //devuelve falso.
        bool operator!=(const linkedListIterator<Type>& right) const;
        //Sobrecargar el operador de desigualdad.
        //Postcondition: Devuelve verdadero si este iterador no es igual  
        //a el iterador especificado por la derecha, de lo contrario, 
        //devuelve falso.
    private:
    	nodeType<Type> *current;
    	//puntero para apuntar al nodo actual en la lista enlazada

};



/* -------------- CLASE LISTA_ENLAZADA_SIMPLE -------------------*/

/* class linkedListType:
Esta clase especifica los miembros para implementar las propiedades 
b�sicas de una lista vinculada. Esta es una clase abstracta.
 No podemos instanciar un objeto de esta clase.*/

template <class Type>
class linkedListType{
	public:
		const linkedListType<Type>& operator=(const linkedListType<Type>&);
        //Sobrecargar el operador de asignaci�n.
        
        void initializeList(); 
        //Inicializar la lista a un estado vac�o.
        //Postcondition: first = NULL, last = NULL, count = 0;
        
        bool isEmptyList() const;
        //Funci�n para determinar si la lista est� vac�a. 
        //Postcondition: Devuelve verdadero si la lista est� vac�a; 
		//               de lo contrario, devuelve falso.
		
		void print() const;
        //Funci�n para generar los datos contenidos en cada nodo.
        //Postcondition: ninguno
        
        int length() const;
        //Funci�n para devolver el n�mero de nodos en la lista.
        //Postcondition: Se devuelve el valor de cuenta.

        void destroyList();
        //Funci�n para eliminar todos los nodos de la lista.
        //Postcondition: first = NULL, last = NULL, count = 0;
		
		Type front() const; 
        //Funci�n para devolver el primer elemento de la lista.
        //Precondition: la lista debe existir y no debe estar vac�a.
        //Postcondition: Si la lista est� vac�a, el programa termina;
        //               de lo contrario, se devuelve el primer 
		//               elemento de la lista.
		
		Type back() const; 
        //Funci�n para devolver el �ltimo elemento de la lista.
        //Precondition: La lista debe existir y no debe estar vac�a.
        //Postcondition: Si la lista est� vac�a, el programa
        //               termina; de lo contrario, el �ltimo
        //               se devuelve el elemento de la lista.

        virtual bool search(const Type& searchItem) const = 0;
        //Funci�n para determinar si searchItem est� en la lista.
        //Postcondition: Devuelve verdadero si searchItem est� en la lista,
        //               de lo contrario, se devuelve el valor falso.
		
		virtual void insertFirst(const Type& newItem) = 0;
        //Funci�n para insertar newItem al comienzo de la lista.
        //Postcondition: primeros puntos a la nueva lista, newItem es
        // insertado al principio de la lista, los �ltimos puntos a
        // el �ltimo nodo de la lista, y el recuento se incrementa en
        // 1.
		
		virtual void insertLast(const Type& newItem) = 0;
        //Funci�n para insertar newItem al final de la lista.
        //Postcondition: primeros puntos a la nueva lista, newItem es
        // insertado al final de la lista, los �ltimos puntos al
        // �ltimo nodo de la lista, y el recuento se incrementa en 1.
		
		virtual void deleteNode(const Type& deleteItem) = 0;
        //Funci�n para eliminar deleteItem de la lista.
        //Postcondition: Si se encuentra, el nodo que contiene deleteItem es
        // eliminado de la lista. primeros puntos al primer nodo,
        // �ltimos puntos al �ltimo nodo de la lista actualizada, y
        // el recuento se reduce en 1.
		
		linkedListIterator<Type> begin();
        //Funci�n para devolver un iterador al comienzo de la lista enlazada.
        //Postcondition: Devuelve un iterador tal que el inicio se establece en primer lugar.
		
		linkedListIterator<Type> end();
        //Funci�n para devolver a un iterador un elemento m�s all� del �ltimo
		// elemento de la lista vinculada. 
        //Postcondition: Devuelve un iterador tal que el actual se env�e a NULL.
		
		linkedListType(); 
        //Constructor predeterminado
        //Inicializa la lista a un estado vac�o.
        //Postcondition: first = NULL, last = NULL, count = 0; 
		
		linkedListType(const linkedListType<Type>& otherList); 
        //constructor de copia
		
		~linkedListType();   
        //destructor
        //Elimina todos los nodos de la lista.
        //Postcondition: El objeto de la lista se destruye.
    protected:
    	int count;  //variable para almacenar el n�mero de elementos de la lista
    	nodeType<Type> *first; //puntero al primer nodo de la lista
    	nodeType<Type> *last; //puntero al �ltimo nodo de la lista
    
    private:
    	void copyList(const linkedListType<Type>& otherList); 
        //Funci�n para hacer una copia de otherList.
        //Postcondition: Se crea y asigna una copia de otherList
        // a esta lista.

};

/* -------------- CLASE ITERADOR -------------------*/

template <class Type>
linkedListIterator<Type>::linkedListIterator(){
    current = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr){
    current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*(){
    return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(){
    current = current->link;
    return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const{
    return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const{
    return (current != right.current);
}

/* -------------- CLASE LISTA_ENLAZADA_SIMPLE -------------------*/

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == NULL);
}

template <class Type>
linkedListType<Type>::linkedListType() //Constructor predeterminado
{
    first = NULL;
    last = NULL;
    count = 0;
}

template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;   //puntero para desasignar la memoria ocupada por el nodo
    while (first != NULL)   //mientras hay nodos en la lista
    {
        temp = first;        //establecer temp al nodo actual
        first = first->link; //avanzar primero al siguiente nodo
        delete temp;   //desasignar la memoria ocupada por temp
    }

    last = NULL; //inicializar �ltimo a NULL; primero ya
                 //establecido en NULL por el ciclo while
    count = 0;
}

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //si la lista tiene nodos, elim�nelos
}

template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; //puntero para recorrer la lista

    current = first;    //establecer actual para que apunte al primer nodo
    cout<<"[ ";
    while (current != NULL) //mientras m�s datos para imprimir
    {
        cout <<current->info << ", ";
        current = current->link;
    }
    cout<<"]"<<endl;
}//final de impresi�n

template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}  //longitud final

template <class Type>
Type linkedListType<Type>::front() const
{   
    assert(first != NULL);

    return first->info; //devolver la informaci�n del primer nodo
}//end front

template <class Type>
Type linkedListType<Type>::back() const
{   
    assert(last != NULL);

    return last->info; //devolver la informaci�n del �ltimo nodo	
}//end back

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);

    return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(NULL);

    return temp;
}

template <class Type>
void linkedListType<Type>::copyList
                   (const linkedListType<Type>& otherList) 
{
    nodeType<Type> *newNode; //puntero para crear un nodo
    nodeType<Type> *current; //puntero para recorrer la lista

    if (first != NULL) //si la lista no est� vac�a, vac�ela
       destroyList();

    if (otherList.first == NULL) //otherList est� vac�o
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    else
    {
        current = otherList.first; //puntos actuales a la lista para ser copiados
        count = otherList.count;

            //copia el primer nodo
        first = new nodeType<Type>;  //crear un nodo

        first->info = current->info; //copia la info
        first->link = NULL;        //establecer el campo de enlace del nodo en NULL
        last = first;              //hacer el �ltimo punto al primer nodo
        current = current->link;     //hacer punto actual al siguiente nodo

           //copia la lista restante
        while (current != NULL)
        {
            newNode = new nodeType<Type>;  //crear un nodo
            newNode->info = current->info; //copia la info
            newNode->link = NULL;       //establecer el enlace de newNode a NULL
            last->link = newNode;  //adjuntar newNode despu�s del �ltimo
            last = newNode;        //hacer el �ltimo punto al �ltimo nodo actual
            current = current->link;   //hacer punto actual al siguiente nodo
        }//final while
    }//end else
}//end copyList

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
   destroyList();
}//end destructor

template <class Type>
linkedListType<Type>::linkedListType
                      (const linkedListType<Type>& otherList)
{
   	first = NULL;
    copyList(otherList);
}//end copy constructor


//sobrecargar el operador de asignaci�n
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
                      (const linkedListType<Type>& otherList)
{ 
    if (this != &otherList) //evitar la auto-copia
    {
        copyList(otherList);
    }//end else

     return *this; 
}























