#include <iostream>
#include <algorithm>

void printElementsGreaterThanNByK(int pInt[7], int n, int k);

using namespace std;

/*
 * Given an array arr[] of size N and an integer K, the task is to find all the array elements that appear more than
 * (N / K) times.
 * Example:
 * Input: arr[] = { 1, 2, 6, 6, 6, 6, 6, 10 }, K = 4
 * Output: 6
 * Explanation:
 * The frequency of 6 in the array is greater than N / K(= 2). Therefore, the required output is 6.
 * Input: arr[] = { 3, 4, 4, 5, 5, 5, 5 }, K = 4
 * Output: 4 5
 * Explanation:
 * The frequency of 4 in the array is greater than N / K(= 1).
 * The frequency of 5 in the array is greater than N / K(= 1).
 * Therefore, the required output is 4 5.
 */
int main() {
    int arr[] = { 3, 4, 4, 5, 5, 5, 5 }, K = 4;
    int n = sizeof(arr)/ sizeof(int);
    cout<<"Elements having frequency greater than "<<n/K<<" are: \n";
    printElementsGreaterThanNByK(arr, n, K);
    return 1;
}

// complexity O(nLogn)
void printElementsGreaterThanNByK(int arr[], int n, int k) {
    int freq = n/k;
    sort(arr, arr + n);
    for(int i  = 0; i < n;) {
        int count = 1;
        while((i+1) < n && arr[i] == arr[i+1]) {
            count++;
            i++;
        }
        if(count > freq) {
            cout<<arr[i]<<" ";
        }
        i++;
    }
}

