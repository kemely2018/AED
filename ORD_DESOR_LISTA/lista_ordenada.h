/* Esta clase especifica los miembros para implementar el básico
propiedades de una lista ordenada doblemente vinculada.*/

#include "lista_enlazada.h"

using namespace std;

template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Función para determinar si searchItem está en la lista.
      //Postcondition: Devuelve verdadero si searchItem está en la lista,
       // de lo contrario, se devuelve el valor falso.

    void insert(const Type& newItem);
      //Función para insertar newItem en la lista.
      //Postcondition: primeros puntos a la nueva lista, newItem
       // se inserta en el lugar adecuado de la lista, y
       // cuenta se incrementa en 1.

    void insertFirst(const Type& newItem);
      //Función para insertar newItem al comienzo de la lista.
      //Postcondition: primeros puntos a la nueva lista, newItem es
       // insertado al principio de la lista, los últimos puntos al
       // último nodo de la lista, y el recuento se incrementa en 1.

    void insertLast(const Type& newItem);
      //Función para insertar newItem al final de la lista.
      //Postcondition:primeros puntos a la nueva lista, newItem es
      // insertado al final de la lista, los últimos puntos al
      // último nodo de la lista, y el recuento se incrementa en 1.


    void deleteNode(const Type& deleteItem);
      //Función para eliminar deleteItem de la lista.
      //Postcondition: Si se encuentra, el nodo que contiene deleteItem es
      // eliminado de la lista; primeros puntos al primer nodo
      // de la nueva lista, y el recuento se reduce en 1. Si
      // deleteItem no está en la lista, un mensaje apropiado
      //    está impreso.
};

template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current; //puntero para recorrer la lista

    current = linkedListType<Type>::first;  //comenzar la búsqueda en el primer nodo

    while (current != NULL && !found)
        if (current->info >= searchItem)
            found = true;
        else
            current = current->link;

    if (found)
       found = (current->info == searchItem); //prueba de igualdad

    return found;
}//end search


template <class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current; //puntero para recorrer la lista
    nodeType<Type> *trailCurrent; //puntero justo antes del actual
    nodeType<Type> *newNode;  //puntero para crear un nodo

    bool  found;

    newNode = new nodeType<Type>; //crear el nodo
    newNode->info = newItem;   //almacenar newItem en el nodo
    newNode->link = NULL;      //establecer el campo de enlace del nodo
                                // a NULL

    if (linkedListType<Type>::first == NULL)  //Caso1
    {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;
    }
    else
    {
        current = linkedListType<Type>::first;
        found = false;

        while (current != NULL && !found) //busca en la lista
           if (current->info >= newItem)
               found = true;
           else
           {
               trailCurrent = current;
               current = current->link;
           }

        if (current == linkedListType<Type>::first)      //Caso 2
        {
            newNode->link = linkedListType<Type>::first;
            linkedListType<Type>::first = newNode;
            linkedListType<Type>::count++;
        }
        else                       //Caso 3
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if (current == NULL)
                linkedListType<Type>::last = newNode;

            linkedListType<Type>::count++;
        }
    }//end else
}//end insert

template<class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

template<class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

template<class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //puntero para recorrer la lista
    nodeType<Type> *trailCurrent; //puntero justo antes del actual
    bool found;

    if (linkedListType<Type>::first == NULL) //Case 1
        cout << "No se puede eliminar de una lista vacía." << endl;
    else
    {
        current = linkedListType<Type>::first;
        found = false;

        while (current != NULL && !found)  //busca en la lista
            if (current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }

        if (current == NULL)   //Case 4
            cout << "El elemento a eliminar no está en el"
                 << "lista." << endl;
        else
            if (current->info == deleteItem) //el item a ser
                                    // eliminado está en la lista
            {
                if (linkedListType<Type>::first == current)       //Caso 2
                {
                    linkedListType<Type>::first = linkedListType<Type>::first->link;

                    if (linkedListType<Type>::first == NULL)
                        linkedListType<Type>::last = NULL;

                    delete current;
                }
                else                         //Caso 3
                {
                    trailCurrent->link = current->link;

                    if (current == linkedListType<Type>::last)
                        linkedListType<Type>::last = trailCurrent;

                    delete current;
                }
                linkedListType<Type>::count--;
            }
            else                            //Caso 4
                cout << "El elemento a eliminar no está en el "
                     << "lista." << endl;
    }
}//end deleteNode

