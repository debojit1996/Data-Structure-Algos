#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int n1 = m-l+1, n2 = r-m;
    int leftArray[n1];
    int rightArray[n2];

    for(int i = 0; i < n1; i++) {
        leftArray[i] = arr[l + i];
    }

    for(int i = 0; i < n2; i++) {
        rightArray[i] = arr[m + 1 + i];
    }
    int i=0, j=0;
    int mergedIndex = l;
    while(i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[mergedIndex] = leftArray[i];
            i++;
        } else {
            arr[mergedIndex] = rightArray[j];
            j++;
        }
        mergedIndex++;
    }

    while(i < n1) {
        arr[mergedIndex] = leftArray[i];
        i++;
        mergedIndex++;
    }
    while(j < n2) {
        arr[mergedIndex] = rightArray[j];
        j++;
        mergedIndex++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    //code here
    if (l < r) {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    
    int arr[] = {1, 4, 10, 2, 7};
    mergeSort(arr, 0, 4);
    for(int i = 0; i < 5; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}