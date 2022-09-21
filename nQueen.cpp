#include<iostream>
using namespace std;
#define N 20
int q[N];
int count=1;

void dispasolution(int n){
    cout<<"第"<<(count++)<<"个解：";
    for(int i=1;i<=n;i++)
        cout<<"（"<<i<<"，"<<q[i]<<"）";
    cout<<endl;   
}

bool place(int i,int j){
    if(i==1) return true;
    int k=1;
    while(k<i){
        if((q[k]==j)||(abs(q[k]-j)==abs(i-k)))
            return false;
        k++;
    }
    return true;
}

void queen(int i,int n){
    if(i>n)
        dispasolution(n);
    else{
        for(int j=1;j<=n;j++)
            if(place(i,j)){
                q[i]=j;
                queen(i+1,n);
            }    
    }
}

int main(){
    int n;
    cout<<"几个皇后？(<20)";
    cin>>n;
    queen(1,n);
    return 0;
}