
#include <iostream>
#define n 6
using namespace std;
int main()
{
    int A[6]= {17,38,2,7,10,9};
    int i,j,menor,aux;
for (i = 0; i < n - 1; i++)
{
menor = i;
for (j = i + 1; j < n; j++)
{
if (A[menor] > A[j])
menor = j;
}
aux = A[i];
A[i] = A[menor];
A[menor] = aux;
}
for(int k=0;k<6;k++){
        cout<<"O valor eh "<<A[k] <<"\t";
    }

    return 0;
}