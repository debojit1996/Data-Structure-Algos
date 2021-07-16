
// Created by 320028052 on 7/16/2021.
//
#include <iostream>

using namespace std;

// Find the maximum subarray sub using Kadane's algo. This is a basic 1D DP problem
int main() {
    int arr[] = {5, -5, 3, 1, 7, 8};
    int n = 6, current = 0, maxTillNow = INT32_MIN;
    for( int i = 0; i < n; i++) {
        current+=arr[i];
        maxTillNow = max(current, maxTillNow);

        if(current < 0) {
            current = 0;
        }
    }
    cout<<"Maximum subarray sum: "<<maxTillNow;
    return 0;
}
