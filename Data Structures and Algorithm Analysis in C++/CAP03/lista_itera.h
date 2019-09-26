#include <iostream>

using namespace std;

template< class T> 
class Nodo{
    private:
        T dato;
        Nodo* anterior;
        Nodo* siguiente;
        
    public:
        Nodo(T _dato){
            siguiente=NULL;
            anterior=NULL;
            dato=_dato;
        }
        void setSiguiente(Nodo<T>* _siguiente){
            siguiente= _siguiente;
        }
        void setAnterior(Nodo<T>* _anterior){
            anterior=_anterior;
        }
        void setDato(T _dato){
            dato=_dato;
        }
        Nodo<T>* getSiguiente(){
            return siguiente;
        }
        Nodo<T>* getAnterior(){
            return anterior;
        }
        T getDato()
        {
            return dato;
        }
};

template <class T>
class ListaDoble
{
    private:
        Nodo<T>* head;
        Nodo<T>* cola;
        int tam;
    public:
        ListaDoble(){
            head=NULL;
            cola=NULL;
            tam=0;
        }
        ~ListaDoble(){
            for(int i =0 ; i<tam ; i++)
            {
                Nodo<T>* lista = head;
                head = head->getSiguiente();
                delete lista;
            }
        }
        void mostrar(){
            Nodo<T>* aux=head;
            while(aux!=NULL){
                cout<<aux->getDato()<<" ";
                aux=aux->getSiguiente();
            }
            cout<<endl;
        }
        void push(T dato){
            Nodo<T> *aux =  new Nodo<T>(dato);
            if(tam==0){
                aux->setAnterior(NULL);
                aux->setSiguiente(head);
                cola=aux;
                head = aux;
                tam++;
            }
            else if(tam>0){
                aux->setAnterior(NULL);
                aux->setSiguiente(head);
                head->setAnterior(aux);
                head = aux;
                tam++;
            }
        }
        
        void inyectar(T dato){//para añadir al final de la lista
            Nodo<T> *aux =  new Nodo<T>(dato);
            if(tam==0){
                push(aux->getDato());
            }
            else if(tam>0){
                aux->setAnterior(cola);
                aux->setSiguiente(NULL);
                cola->setSiguiente(aux);
                cola=aux;
                tam++;
            }
        }
        
        T pop(){//para eliminar el elemento frontal de la lista
                T dato;
                if(tam==0){
                       return 0;
                }
                else if(tam>0){
                        Nodo<T> *eliminar = head;
                        head=head->getSiguiente();
                         dato=eliminar->getDato();
                         delete eliminar;
                        tam--;
                        return dato;
               }
        }
        T expulsar(){//para eliminar el ultimo elemento de la lista
            T dato;
            if(tam==0){
                return 0;
            }
            else if(tam>0){
                Nodo<T> *eliminar = cola;
                cola=cola->getAnterior();
                cola->setSiguiente(NULL);
                dato=eliminar->getDato();
                delete eliminar;
                tam--;
                return dato;
                
            }
        }
        Nodo<T>* begin()
        {
            return head->getAnterior();
        }
        Nodo<T>* end()
        {
            return cola;
        }
        
        Nodo<T>* rbegin()
        {
            return cola;
        }
        Nodo<T>* rend()
        {
            return head->getAnterior();
        }
        
};

template <class T>
class Iterator
{
    public:
        virtual bool hasNext()=0;
        virtual bool hasAnt()=0;
};

template <class T>
class IteratorLista : public Iterator<T>
{
    private:
        Nodo<T>* iterador;
    public:
        IteratorLista();

        virtual bool hasAnt();
        virtual bool hasNext();

        Nodo<T>* operator++();
        Nodo<T>* operator--();
        
        IteratorLista<T> operator++(int k) const{
            Nodo<T>* iterador1=iterador;
            for(int i=0;i<k;i++)
                iterador1 = iterador1->getSiguiente();
            IteratorLista<T> itlist(iterador1);
            return itlist;
        }

        void operator=(Nodo<T>* ptro);
        bool operator!=(Nodo<T>* ptro);
        T operator*();

};

template<class T>
IteratorLista<T>::IteratorLista()
{
    iterador=NULL;
}

template<class T>
bool IteratorLista<T>::hasNext()
{
    return (iterador !=NULL);
}

template<class T>
bool IteratorLista<T>::hasAnt()
{
    return (iterador !=NULL);
}


template<class T>
Nodo<T>* IteratorLista<T>::operator++()
{
    iterador = iterador->getSiguiente();
    return iterador;
}

template<class T>
Nodo<T>* IteratorLista<T>::operator--()
{
    iterador = iterador->getAnterior();
    return iterador;
}


template<class T>
void IteratorLista<T>::operator=(Nodo<T>* ptro)
{
    iterador = ptro;
}

template<class T>
bool IteratorLista<T>::operator!=(Nodo<T> *ptro)
{
    return iterador!=ptro;
}

template<class T>
T IteratorLista<T>::operator*()
{
    return iterador->getDato();
}



