#include <iostream>
using namespace std;

template<class V>
class Vector{
	public:
		typedef V* iterator;
		Vector(int initialSize = 0):sizeV(initialSize), capacityV(initialSize+DEFAULT_CAPACITY){
			head = new V[capacityV];
			tail = head + initialSize;
		}
		
		~Vector(){
			delete [] head;
		}
		
		V & operator[](int indicador){
			if(indicador>=0 && indicador<size()){
				return head[indicador];
			}
			else{
				cout<<"Indice fuera de los limites";
				return head[0];
			}
		}
		
		void push_back(const V & obj){
			if(sizeV == capacityV){
				resize(capacityV *= 2);
			}
			head[sizeV++] = obj;
			++tail;
		}
		
		void pop_back(){
			--sizeV;
		}	
		
		void resize(int new_capacity){
			V * original = head;
			if(new_capacity>=capacityV){
				head = new V[new_capacity];
			}
			tail = head + sizeV;		
			for(int i=0; i<sizeV; ++i){
				head[i] = original[i];
			}
			delete [] original;
		}
		
		int size() const{
			return sizeV;
		}
		
		int capacity() const{
			return capacityV;
		}
		
		iterator begin(){
			return head;
		}
		
		iterator end(){
			return tail;
		}
		
		iterator insert(const V & obj, iterator itr){
			if(sizeV == capacityV)
			    resize(capacityV *= 2);
			for(iterator mod_itr = end(); mod_itr != itr; --mod_itr)
			    *mod_itr = *(mod_itr-1);
		    *itr = obj;
		    ++sizeV;
		    ++tail;
		    return itr+1;
		}
		
		iterator erase(iterator itr){
			for(iterator mod_itr = itr; mod_itr+1 != end(); ++mod_itr)
			    *mod_itr = *(mod_itr+1);
		    --sizeV;
		    --tail;
			return itr;
		}
		
		enum {DEFAULT_CAPACITY = 16};
		
    private:
    	int sizeV;
		int capacityV;
		V * head;
		V * tail;

	
};
