#include<iostream>
using namespace std;

template <class L>
class Nodo{
	private:
	   L dato;
	   Nodo<L> *siguiente;
	public:
		//Constructor de Nodo
		Nodo(L n){
			dato=n;
			siguiente=NULL;
		}
		void siguiente_nodo(Nodo<L> *next){
			siguiente=next;
		}
		L getdato(){
			return dato;
		}
		Nodo<L> *getsiguiente(){
			return siguiente;
		}
		
};

template <class L>
class Lista_enlazada{
	Nodo<L> *inicio;
	int tam;
	public:
	// Inicializar la Lista
	Lista_enlazada(){
		this->inicio=NULL;
		tam=0;
	}
	/*void insertar(L dat){//Te lo insertar al inicio
		Nodo<L> *nuevo;
		nuevo = new Nodo<L>(dat);
		nuevo->siguiente_nodo(inicio);
		inicio=nuevo;	
	}*/
	int getSize()//para obtener el tamanio
    {
        return tam;
    }
	//Este metodo va a cambiar el atributo *siguiente de un Nodo para que ya no apunte a NULL
    void insertar(L dat)
    {
        Nodo<L> *nuevo;
        //Creamos un objeto de tipo nodo
        nuevo=new Nodo<L>(dat);
        Nodo<L> *auxiliar;
        //Si lista esta vacia INICIO  guarde el valor de NUEVO
        if(inicio==NULL)
        {
            inicio=nuevo;
        }
        //Cuando no sea el primer nodo , hacemos que *suiguiente apunte a la direccion de nuevo
        else{
                auxiliar=inicio;
                while((auxiliar->getsiguiente())!=NULL)
                {
                    auxiliar=auxiliar->getsiguiente();
                }
            auxiliar->siguiente_nodo(nuevo);
        }
        tam++;
    }
    void mostrar()
    {
    	//Creamos un metodo nodo que guarde la direccion del primer nodo y asi acceder a 
		// los atributos  Valor y *siguiente
        Nodo<L> *temp;
        temp=inicio;
        //Recorremos el Nodo 
        while(temp)
        {
        	//Imprimir Valor de mi nodo
            cout<<temp->getdato()<<" -> ";
            //guardo en temp la direccion del siguiente nodo
            temp=temp->getsiguiente();
        }
        cout<<"NULL"<<endl;

    }
    
    int buscar_pos(int p){
    	Nodo<L> *temp;
    	temp=inicio;
    	//Iterar p veces el atributo *siguiente
    	for(int i=0;i<p;i++){
    		//guardo en temp la direccion del siguiente nodo
    		temp=temp->getsiguiente();
		}
		// Retorna el atributo Valor de mi Nodo
		return temp->getdato();
	}
    int buscar_valor(L v)
    {
        Nodo<L> *temp=inicio;
        int p=0;
        while(temp)
        {
        	//compara v con el dato
            if(v==temp->getdato())
            {
               //Retorna la posicion en la que se encuentra
			    return p;
            }
              p++;
            temp=temp->getsiguiente();
        }
        return -1;

    }
    void eliminar_pos(int p)
    {
        Nodo<L>*temp;
        temp=inicio;
        Nodo<L>*temp1;
        if(p==0)
        {
            temp=temp->getsiguiente();
        }
        else
        {
            for(int j=0;j<p-1;j++)
            {
                temp=temp->getsiguiente();
            }
            temp1=temp->getsiguiente();
            temp->siguiente_nodo(temp1->getsiguiente());
        }
    }
    
    void swap_adyacente(int pos) {
    	Nodo<L> *ini;
    	Nodo<L> *temp;
    	
    	if(pos <0 || pos > tam-1){
    		cout<<"error"<<endl;
		}
		else if(pos==0){
			temp = inicio->getsiguiente();
			inicio->siguiente_nodo(temp->getsiguiente());
			temp->siguiente_nodo(inicio);
			inicio=temp;	
		}else{
			ini=inicio;
			temp=inicio;
    	    for(int i=0;i<pos-2;i++){
				ini=ini->getsiguiente();
			}
			for(int i=0;i<pos-1;i++){
				temp=temp->getsiguiente();
			}
			ini->siguiente_nodo(temp->getsiguiente());
			temp->siguiente_nodo(ini->getsiguiente()->getsiguiente());
			ini->getsiguiente()->siguiente_nodo(temp);
			ini=temp;
				
		}
		
	}

    ~Lista_enlazada()
    {

       while(inicio!=NULL)
       {
           inicio=inicio->getsiguiente();
           delete inicio;
       }
    }
    
};



