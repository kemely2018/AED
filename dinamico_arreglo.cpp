#include<iostream>
#include<ctime>
using namespace std;

class Lista{
	private:
		int tamano;
		int *data;
	public:
		Lista(int tam,int arr[]);
		void llenar();
		void insert(int pos, int dato);
		void remove(int pos);
		void ordenar();
		int buscar(int dato);
		int lineal_buscar(int dato);
		void mostrar();
};

Lista::Lista(int tam,int arr[]){
	this->tamano=tam;
	data= new int[tam];
	for(int i=0;i<tam;i++){
		data[i]=arr[i];
	}
}

void Lista::llenar( ){
	int dato;
	srand(time(NULL));
	for(int i=0;i<tamano;i++){
		dato=1+rand()%(10);
		data[i]=dato;
	}
}
void Lista::mostrar(){
	cout<<"[";
	for(int i=0;i<tamano;i++){
		cout<<data[i]<<" , ";
	}
	cout<<"]"<<endl;
}

void Lista::insert(int pos,int dato){
	int *tmp=new int[++tamano];
	for(int i=0;i<pos;i++){
		tmp[i]=data[i];
	}
	tmp[pos]=dato;
	for(int j=pos+1;j<tamano;j++){
		tmp[j]=data[j-1];
	}
	delete []data;
	data=tmp;
	
}

void Lista::remove(int pos){
	int *tmp=new int[--tamano];
	for(int i=0;i<pos;i++){
		tmp[i]=data[i];
	}
	for(int j=pos;j<tamano;j++){
		tmp[j]=data[j+1];
	}
	delete []data;
	data=tmp;
}

void Lista::ordenar(){
	int pos,aux;
	for(int i=0;i<tamano;i++){
		pos=i;
		aux=data[i];
		while((pos>0)&& (data[pos-1]>aux)){
			data[pos]=data[pos-1];
			pos--;
		}
		data[pos]=aux;
	}
}

int Lista::buscar(int dato){
	int inicio=0,fin=tamano-1,mitad=0;
	while(inicio <= fin){
		mitad=(inicio+fin)/2;
		if(dato == data[mitad]){
			return mitad;
		}
		else{
			if(dato>data[mitad]){
				inicio=mitad+1;
			}
			else{
				fin=mitad-1;
			}
		}		
	}
	return 0;
}

int Lista::lineal_buscar(int dato){
	for(int i=0;i<tamano;i++){
		if(data[i]== dato){
			return i;
			break;
		}
	}
	return 0;
}

int main(){
	int a=10;
	int A[a];
	Lista lista(a,A);
	lista.llenar();
	/*******/
	int menu =0;
	int opcion,pos,numero,valor,x;
	while(menu==0){
		cout<<"--------------------------------------------------------"<<endl;
		cout<<"\tARREGLO DINAMICO"<<endl;
		cout<<"1)INSERTAR "<<endl;
		cout<<"2)ELIMINAR "<<endl;
		cout<<"3)ORDENAR  "<<endl;
		cout<<"4)BUSQUEDA BINARIA   "<<endl;
		cout<<"5)BUSQUEDA LINEAL   "<<endl;
		cout<<"6)MOSTRAR  "<<endl;
		cout<<"7)SALIR"<<endl;
		cout<<"OPCION : ";cin>>opcion;
		switch(opcion){
			case 1:
				cout<<"Posicion: ";cin>>pos;
				cout<<"Numero: ";cin>>numero;
				lista.insert(pos,numero);
				break;
			case 2:
				cout<<"Posicion: ";cin>>pos;
				lista.remove(pos);
				break;
			case 3:
				lista.ordenar();
				break;
			case 4:
				cout<<"Valor a buscar:";cin>>valor;
				x=lista.buscar(valor);
				if(x==0){
					cout<<"EL VALOR NO SE ENCUENTRA"<<endl;
				}
				else{
					cout<<"EL VALOR "<<valor<<" esta en la posicion "<<x<<endl;
				}
				break;
			case 5:
				cout<<"Valor a buscar:";cin>>valor;
				x=lista.lineal_buscar(valor);
				if(x==0){
					cout<<"EL VALOR NO SE ENCUENTRA"<<endl;
				}
				else{
					cout<<"EL VALOR "<<valor<<" esta en la posicion "<<x<<endl;
				}
				break;
			case 6:
				lista.mostrar();
				break;
			case 7:
				menu=1;
				break;
			default:
				break;
		}
	}
	return 0;
}
