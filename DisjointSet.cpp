#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define maxSize 1001
using namespace std;

/*
 * Check question and tutorial from here. its a practice question for this tutorial
 * https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/
 */
ll arr[maxSize], size[maxSize];

ll root(ll Arr[], ll i) {
    while(Arr[i] != i) {
        Arr[i] = Arr[Arr[i]];
        i = Arr[i];
    }
    return i;
}

void weightedUnion(ll A, ll B, ll Arr[], ll size[]) {
    ll root_A = root(Arr, A);
    ll root_B = root(Arr, B);
    if(root_A == root_B)
        return;
    if(size[root_A] > size[root_B]) {
        Arr[root_B] = Arr[root_A];
        size[root_A] += size[root_B];
        size[root_B] = 0;
    } else {
        Arr[root_A] = Arr[root_B];
        size[root_B] += size[root_A];
        size[root_A] = 0;
    }
}

void printResult(ll size[], ll N) {
    ll result[N];
    copy(size, size + N, result);
    sort(result, result + N);
    for(ll i = 1; i < N; i++) {
        if(result[i] > 0) {
            cout<<result[i]<<" ";
        }
    }
    cout<<"\n";
}

int main() {
    ll N, M, x , y;
    cin>>N>>M;
    for(ll i = 1; i <= N; i++) {
        arr[i] = i;
        size[i] = 1;
    }
    for(ll i = 0; i < M; i++) {
        cin>>x>>y;
        weightedUnion(x, y, arr, size);
        printResult(size, N+1);
    }
    return 0;
}