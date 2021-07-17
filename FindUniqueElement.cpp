/*
 * Given an array where every element occurs three times, except one element which occurs only once. Find the element
 * that occurs once. Expected time complexity is O(n) and O(1) extra space.
 */
#include <iostream>
#include <set>
#include <numeric>

long getElementWithFrequencyOne(int pInt[10], size_t i);

long getUniqueElementAuxillarySpace(int pInt[10], size_t i);

using namespace std;

int main() {
    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    cout<<"Element with frequency 1 is: "<<getElementWithFrequencyOne(arr, sizeof(arr)/ sizeof(int));
    cout<<"\nElement with frequency 1 using auxillary space is: "<<getUniqueElementAuxillarySpace(arr,
            sizeof(arr)/ sizeof(int));
    return 0;
}

/*
 * Add each number once and multiply the sum by 3, we will get thrice the sum of each element of the array. Store it as
 * thrice_sum. Subtract the sum of the whole array from the thrice_sum and divide the result by 2. The number we get is
 * the required number (which appears once in the array).
   Array [] : [a, a, a, b, b, b, c, c, c, d]
   Mathematical Equation = ( 3*(a+b+c+d) – (a + a + a + b + b + b + c + c + c + d) ) / 2
   In more simple words: ( 3*(sum_of_array_without_duplicates) – (sum_of_array) ) / 2
 */
long getUniqueElementAuxillarySpace(int arr[], size_t n) {
    set<int> uniqueElements(arr, arr + n);
    long arr_sum = accumulate(arr, arr + n, 0);
    long set_sum = 3 * accumulate(uniqueElements.begin(), uniqueElements.end(), 0);

    return (set_sum - arr_sum)/2;
}

/*
 * Following is an O(n) time complexity and O(1) extra space method suggested by aj. We can sum the bits in same
 * positions for all the numbers and take modulo with 3. The bits for which sum is not multiple of 3, are the bits of
 * number with single occurrence.
    Let us consider the example array {5, 5, 5, 8}. The 101, 101, 101, 1000
    Sum of first bits%3 = (1 + 1 + 1 + 0)%3 = 0;
    Sum of second bits%3 = (0 + 0 + 0 + 0)%3 = 0;
    Sum of third bits%3 = (1 + 1 + 1 + 0)%3 = 0;
    Sum of fourth bits%3 = (1)%3 = 1;
    Hence number which appears once is 1000. Note that this approach works only for array with positive integers.
 */
long getElementWithFrequencyOne(int arr[], size_t n) {
    long result = 0;
    int sum, currentBitPosition;

    // Iterate upto 32 bit positions
    for(int i = 0; i < 32; i++) {
        sum = 0;
        currentBitPosition = (i << i);
        for(int j = 0; j < n; j++) {
            if (currentBitPosition & arr[j]) {
                sum++;
            }
        }
        if (sum % 3) {
            result = result | currentBitPosition;
        }
    }
    return result;
}
