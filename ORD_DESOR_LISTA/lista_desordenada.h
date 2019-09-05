#pragma once
#include <iostream>
#include "lista_enlazada.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>{
public:
    bool search(const Type& searchItem) const;
      //Funci�n para determinar si searchItem est� en la lista.
      //Postcondition:Devuelve verdadero si searchItem est� en la lista,
      // de lo contrario, se devuelve el valor falso.

    void insertFirst(const Type& newItem);
      //Funci�n para insertar newItem al comienzo de la lista.
      //Postcondition: primeros puntos a la nueva lista, newItem es
      // insertado al principio de la lista, los �ltimos puntos a
      // el �ltimo nodo, y el recuento se incrementa en 1.

    void insertLast(const Type& newItem);
      //Funci�n para insertar newItem al final de la lista.
      //Postcondition:primeros puntos a la nueva lista, newItem es
      // insertado al final de la lista, los �ltimos puntos al
      // �ltimo nodo, y el recuento se incrementa en 1.

    void deleteNode(const Type& deleteItem);
      //Funci�n para eliminar deleteItem de la lista.
      //Postcondition: Si se encuentra, el nodo que contiene deleteItem
      // se elimina de la lista. primeros puntos al primero
      // nodo, �ltimos puntos al �ltimo nodo de la actualizaci�n
      // lista, y el recuento se reduce en 1.
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const{
    nodeType<Type> *current; //puntero para recorrer la lista
    bool found = false;

    current = linkedListType<Type>::first;  //establecer actual para apuntar a la primera
                     //nodo en la lista

    while (current != NULL && !found)    //busca en la lista
        if (current->info == searchItem) //searchItem se encuentra
            found = true;
        else
            current = current->link; //hacer punto actual para
                                     //el siguiente nodo
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //puntero para crear el nuevo nodo

    newNode = new nodeType<Type>; //crear el nuevo nodo

    newNode->info = newItem;    //almacenar el nuevo elemento en el nodo
    newNode->link = linkedListType<Type>::first;      //inserte newNode antes del primero
    linkedListType<Type>::first = newNode;            //hacer el primer punto al primer nodo real
    linkedListType<Type>::count++;                    //recuento incremental

    if (linkedListType<Type>::last == NULL)   //si la lista estaba vac�a, newNode tambi�n es el �ltimo nodo de la lista
        linkedListType<Type>::last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //puntero para crear el nuevo nodo

    newNode = new nodeType<Type>; //crear el nuevo nodo

    newNode->info = newItem;  //almacenar el nuevo elemento en el nodo
    newNode->link = NULL;     //establecer el campo de enlace de newNode
                               // a NULL

    if (linkedListType<Type>::first == NULL)  //si la lista est� vac�a, newNode es
                         // tanto el primer como el �ltimo nodo
    {
        linkedListType<Type>::first = newNode;
        linkedListType<Type>::last = newNode;
        linkedListType<Type>::count++;        //recuento incremental
    }
    else    //la lista no est� vac�a, inserte newNode despu�s del �ltimo
    {
        linkedListType<Type>::last->link = newNode; //inserte newNode despu�s del �ltimo
        linkedListType<Type>::last = newNode; //hacer el �ltimo punto a lo real
                        //�ltimo nodo en la lista
        linkedListType<Type>::count++;        //recuento incremental
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //puntero para recorrer la lista
    nodeType<Type> *trailCurrent; //puntero justo antes de el aacyual
    bool found;

    if (linkedListType<Type>::first == NULL)    //Caso 1; La lista est� vac�a.
        cout << "No se puede eliminar de una lista vac�a."
             << endl;
    else
    {
        if (linkedListType<Type>::first->info == deleteItem) //Caso 2
        {
            current = linkedListType<Type>::first;
            linkedListType<Type>::first = linkedListType<Type>::first->link;
            linkedListType<Type>::count--;
            if (linkedListType<Type>::first == NULL)    //la lista tiene solo un nodo
                linkedListType<Type>::last = NULL;
            delete current;
        }
        else //busca en la lista el nodo con la informaci�n dada
        {
            found = false;
            trailCurrent = linkedListType<Type>::first;  //establecer trailCurrent para apuntar
                                    // al primer nodo
            current = linkedListType<Type>::first->link; //establecer actual para apuntar a
                                    // el segundo nodo

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Caso 3; si se encuentra, elimine el nodo
            {
                trailCurrent->link = current->link;
                linkedListType<Type>::count--;

                if (linkedListType<Type>::last == current)   //nodo a eliminar
                                        // fue el �ltimo nodo
                    linkedListType<Type>::last = trailCurrent; //actualizar el valor
                                          // de �ltimo
                delete current;  //eliminar el nodo de la lista
            }
            else
                cout << "El elemento a eliminar no est� en "
                     << "la lista." << endl;
        }//end else
    }//end else
}//end deleteNode




