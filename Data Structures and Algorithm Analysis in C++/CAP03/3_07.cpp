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
	for(int i=-2;i<9;i++){
		cout<<l[i]<<endl;
	}
}

