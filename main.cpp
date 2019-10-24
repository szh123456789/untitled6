#include <iostream>
#include <cstring>
using namespace std;

typedef int (*oo)(int,int);

int map(oo o,int *p,int j)
{
  int *q=(int *)malloc(sizeof(*p));
    for( int i=0;i<j;i++,p++){
        q[i]=o(*p,1);

        }
  return *q;
}
int add(int i,int j){
    return i+j;
}
int sub(int i,int j){
    return  i-j;
}

int reduce(oo o,int *p,int j){
    int x=0;
   for(int i=0;i<j;i++,p++){
       x=o(*p,x);
   }
   return x;
}

int main() {
    int i;
    cout<<"请输入数组元素个数"<<endl;
    cin>>i;
    int a[i];
    int *p=a;

    cout<<"请输入数组元素值"<<endl;
    for(int j=0;j<i;j++){
        cin>>a[j];
    }
    cout<<endl;
    for(int j=0;j<i;j++){
        cout<<map(add,a,i)+j<<" ";
    }
    cout<<endl;

     cout<<reduce(add,a,i);
    return 0;
}