#include <iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

Node *addNode(Node *node, int data){
    return node->next = new Node{data, nullptr};
}

void printList(Node *first){
    Node *p = first;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void destroy(Node *first){
    Node *p = first;
    while (p->next != nullptr)
    {
        Node *current = p;
        p = p->next;
        delete current;
    }
}


void deleteNode(Node *node){
    if (node->next)
    {
        node->data = node->next->data;  
        Node *p = node->next;
        node->next = node->next->next;  
        delete p;
    }
    else    
    {
        node->next = nullptr;
    }
}
int main(){
    Node *head = new Node{0, nullptr};
    Node *p = head;
    Node *itr = nullptr;
    for (int i = 1; i < 10; ++i){
        p = addNode(p, i);
        if(i == 5)
            itr = p;
    }
    printList(head);
    deleteNode(itr);
    printList(head);
    destroy(head);
    return 0;
}
