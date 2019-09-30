/*
Escriba una implementación de la clase set, con iteradores asociados 
utilizando un árbol de búsqueda binario.
Agregue a cada nodo un enlace al nodo principal.
*/
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;
template <typename Comparable>
class Set{
	private:
		struct BinaryNode{
			Comparable element;
			BinaryNode *left;
			BinaryNode *right;
			BinaryNode *parent;
			BinaryNode(const Comparable &theElement, BinaryNode *lt = nullptr, 
			BinaryNode *rt = nullptr, BinaryNode *pa = nullptr)
            : element{theElement}, left{lt}, right{rt}, parent{pa}{}
		 };
	public:
		class iterator{
			public:
				iterator() : current{nullptr}{}
				const Comparable &operator*() const{
					return current->element;
				}
				iterator &operator++(){
					if (current->right){
						BinaryNode *t = current->right;
						while (t->left != nullptr)
                            t = t->left;
                        current = t;}
					else{
						BinaryNode *t = current->parent;
						while (t && t->element < current->element)
						    t = t->parent;
                        current = t;}
                    return *this;
				}
                bool operator==(const iterator &rhs) const
                {return current == rhs.current; }
                
                bool operator!=(const iterator &rhs) const
                {return !(*this == rhs);}
            protected:
            	BinaryNode *current;
            	iterator(BinaryNode *p): current{p}{}
            	friend class Set<Comparable>;
		};
		
    Set(): theSize{0},root{nullptr}{}

    ~Set(){clear();}

    int size() const{
        return theSize;
    }

    bool empty() const{
        return size() == 0;
    }

    void clear(){
        makeEmpty(root);
    }

    iterator begin(){
        return {findMin(root)};
    }


    iterator end(){
        return {nullptr};
    }

    iterator insert(const Comparable &x){
        return insert(x, root, nullptr);
    }

  private:
    int theSize;
    BinaryNode *root; 

    iterator insert(const Comparable &x,BinaryNode *&t,BinaryNode *parent)
    {
        if (t == nullptr)
        {
            theSize++; 
            return {t = new BinaryNode{x, nullptr, nullptr, parent}};
        }
        else if (x < t->element)
            return insert(x, t->left, t);
        else if (t->element < x)
            return insert(x, t->right, t);

        return {t}; 
    }


    void makeEmpty(BinaryNode *&t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
            --theSize;
        }
        t = nullptr;
    }

    BinaryNode *findMin(BinaryNode *t) const
    {
        if (t != nullptr)
            while (t->left != nullptr)
                t = t->left;
        return t;
    }

    BinaryNode *findMax(BinaryNode *t) const
    {
        if (t != nullptr)
            while (t->right != nullptr)
                t = t->right;
        return t;
    }


    
};

int main(){
    Set<int> arbol;
    for (int i = 0; i < 10; ++i)
        arbol.insert(i);
        
    for (Set<int>::iterator iter = arbol.begin(); iter != arbol.end(); ++iter)
        cout << *iter << " ";

    return 0;
}
