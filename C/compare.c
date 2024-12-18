#include <stdio.h>

int main(){
   
    int arr[2];
    for (int i = 0; i < 3; i++){
        scanf ("%d", &arr[i]);
    }
    for (int i = 0; i < 3; i++){
        printf ("%d", arr[i]);
    }
}