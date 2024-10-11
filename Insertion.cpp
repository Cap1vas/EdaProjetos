#include <iostream>
usig namespace std;


int main(){
    int arr[6] ={17,38,2,7,10,9};
    for(int i =0;;i<6;i++){
        int j=i;
        while(j>0&&arr[j]<arr[j-1]){
            int aux = arr[j];
            arr[j]= arr[j-1];
            arr[j-1]=aux;
            j-=1;
        }
    }
}