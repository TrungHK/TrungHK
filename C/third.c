#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int mid, int right){
    int start1 = left, end1 = mid;
    int start2 = mid+1, end2 = right;
    int index = left;
    int i = 0;
    int* temp = (int*)malloc(sizeof(int) * (right - left + 1));
    for (; start1 <= end1 && start2<= end2; i++){
        if(arr[start1] <= arr[start2]) {
            temp[i] = arr[start1];
            start1++;
        }else{
            temp[i] = arr[start2];
            start2++;
        }
    }
    for (; start1<=end1; start1++){
        temp[i] = arr[start1];
        i++;
    }
    for (; start2<=end2; start2++){
        temp[i] = arr[start2];
        i++;
    }
    for (int i = 0; i < (right - left + 1); i++){
        arr[index] = temp[i];
        index++;
    }
}

void mergeSort(int* arr, int left, int right){
    if (left>=right) return;
    else{
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}


int main(){
    int arr[100];
    int n; 
    scanf ("%d", &n);
    for (int i = 0; i < n; i++){
        scanf ("%d", &arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++){
        printf ("%d ", arr[i]);
    }
}