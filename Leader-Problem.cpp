//
// Created by 320028052 on 7/16/2021.
//

#include <iostream>

using namespace std;
// An element is called the leader of an array if there is no element greater than it on the right side.
int main() {
    int arr[] = {6, 10, 5, 2, 10, 4, 5, 2};
    int n = sizeof(arr)/ sizeof(int) , currentLeader = arr[n-1];
    cout<<currentLeader<<" ";
    // we traverse from right coz we always keep track of the current leader
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > currentLeader) {
            currentLeader = arr[i];
            cout<<currentLeader<<" ";
        }
    }
    return 0;
}


