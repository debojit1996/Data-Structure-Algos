//
// Created by 320028052 on 7/16/2021.
//
#include <iostream>

using namespace std;

int main() {
//    int arr[] = {0, 0, 1, 0, 1, 1, 0, 1, 1, 1 ,1, 0, 1, 1, 0};
//    int arr[] = {0, 0, 0};
//    int arr[] = {1, 0, 0};
//    int arr[] = {0, 1, 0};
    int arr[] = {1, 1, 1, 1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(int);
    int maxConsecutive = 0, currentCount = 0;
    for (int i = 0; i < n; i++) {
        if (!arr[i]) {
            currentCount = 0;
        } else {
            currentCount++;
            maxConsecutive = max(maxConsecutive, currentCount);
        }
    }
    cout<<"Maximum consecutive ones in array: "<<maxConsecutive;
    return 0;
}
