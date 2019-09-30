#include <iostream>

template <typename Comparable>
struct BinaryNode
{
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const Comparable &theElement, BinaryNode *lt, BinaryNode *rt)
        : element{theElement}, left{lt}, right{rt}
    {
    }

    BinaryNode(Comparable &&theElement, BinaryNode *lt, BinaryNode *rt)
        : element{std::move(theElement)}, left{lt}, right{rt}
    {
    }
};


template <typename Comparable>
BinaryNode<Comparable> *findMin(BinaryNode<Comparable> *t)
{
    if (t == nullptr)
        return nullptr;
    if (t->left == nullptr)
        return t;
    return findMin(t->left);
}


template <typename Comparable>
BinaryNode<Comparable> *findMax(BinaryNode<Comparable> *t)
{
    if (t != nullptr)
        while (t->right != nullptr)
            t = t->right;
    return t;
}


template <typename Comparable>
void remove1(const Comparable &x, BinaryNode<Comparable> *&t)
{
    if (t == nullptr)
        return; 
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) 
    {
        t->element = findMax(t->left)->element;
        remove(t->element, t->left);
    }
    else 
    {
        BinaryNode<Comparable> *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}

template <typename Comparable>
void remove2(const Comparable &x, BinaryNode<Comparable> *&t)
{
    static int removeCount = 0;
    if (t == nullptr)
        return; 
    if (x < t->element)
        remove(x, t->left);
    else if (t->element < x)
        remove(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) 
    {
        if ((removeCount++) % 2)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            t->element = findMax(t->left)->element;
            remove(t->element, t->left);
        }
    }
    else 
    {
        BinaryNode<Comparable> *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
}



