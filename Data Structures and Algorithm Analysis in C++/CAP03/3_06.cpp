#include <iostream>
#include <list>
using namespace std;


int JosephusProblema(int n, int m)
{
    list<int> list;
    for (int i = 1; i <= n; ++i){
    	list.push_back(i);
	}
              
    auto iter = list.begin();
    while(list.size() > 1)
    { 
        int nIterations = m % list.size();
        for (int i = 0; i < nIterations; ++i)
        {
            if(iter == list.end())
                iter = list.begin(); 
			++iter;   
        }
        if(iter == list.end())         
                iter = list.begin();
        iter = list.erase(iter);        
        
    }
    if(iter == list.end())             
        iter = list.begin();
    return *iter;   
}

int main(){
	cout<<" N=5 || M= 1 -> GANADOR:"<<JosephusProblema(5,1)<<endl;
	cout<<" N=100 || M= 2 -> GANADOR:"<<JosephusProblema(100,2)<<endl;
	cout<<" N=1500 || M= 1 -> GANADOR:"<<JosephusProblema(1500,1)<<endl;
    return 0;
}
