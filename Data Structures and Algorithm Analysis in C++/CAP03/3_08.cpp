#include<iostream>
#include"vector.h"
using namespace std;

int main(){
	Vector<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	
	for (auto it = l.begin(); it != l.end(); ++it) 
        cout << *it << " "; 
    cout<<endl;
	
	l.insert(7,l.end());
	for (auto it = l.begin(); it != l.end(); ++it) 
        cout << *it << " "; 
    cout<<endl;
    
    l.erase(l.begin());
    l.erase(l.begin());
    for (auto it = l.begin(); it != l.end(); ++it) 
        cout << *it << " "; 
}

