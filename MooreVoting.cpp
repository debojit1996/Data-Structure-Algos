//
// Created by 320028052 on 7/16/2021.
//
#include <iostream>
// Find the majority element in an array. An element is called to be a majority element if it occurs more than n/2 times
// in an array where n = size of array
using namespace std;

int main() {
    int arr[] = {2, 6, 8, 8, 6, 8, 8, 8}, res = 0, count = 1;
    // First loop finds the candidate
    for(int i = 1; i < 8; i++) {
        if(arr[res] == arr[i]) {
            count++;
        } else {
            count--;
        }

        if(count == 0) {
            count = 1;
            res = i;
        }
    }
    int freq = 0;
    // Check if returned index res contains the majority element
    for(int item : arr) {
        if(item == arr[res]) {
            freq++;
        }
    }
    if(freq > 4) {
        cout<<"Majority element is: "<<arr[res];
    } else {
        cout<<"No majority element in the array";
    }

    return 0;
}

