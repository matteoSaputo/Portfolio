#include<iostream>
#include <cstdlib>
#include<vector>
using namespace std;

void makeMove(int &n, int &candidate, int &to, int &from);
vector<int> t[3];

int main(){
    int n, candidate, to, from;
    cout<<"Enter How Many Rings: ";
    cin>>n;
    cout<<endl;
          
	for(int i = n+1; i >= 1; i--)
    	t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);
                
    if(n%2==0){
        from=0;
        to=2;
        candidate=1;          
    }else{
        from=0;
        to=1;
        candidate=1;
    }
    
    makeMove(n, candidate, to, from);
    return 0;
}

void makeMove(int &n, int &candidate, int &to, int &from){
	while(t[1].size()<n+1){              
    	cout<<"Move ring "<<candidate<<" from tower "<<  char(from+65)<<" to tower "<<char(to+65)<<endl;
                      
        t[from].pop_back();
        t[to].push_back(candidate);
        int A1, A2, x[5]={2,0,1,2,0}; 
        for(int i=1;i<4;i++){  
			if(to==x[i]){  
				A1= x[i-1];
                A2= x[i+1];        
            }
        }
                      
        if(t[A1].back() < t[A2].back()) from=A1;
        else from=A2;
                    
        for(int i=1;i<4;i++){
            if(n%2!=0){
                if(from==x[i]){
				   	if(t[from].back() < t[x[i+1]].back()) to = x[i+1];
                    else to = x[i-1];
                }
            }else{
                if(from==x[i]){
                    if(t[from].back() < t[x[i-1]].back()) to = x[i-1];
                    else to = x[i+1];
                }     
            }
        }
        candidate= t[from].back();
    }
}