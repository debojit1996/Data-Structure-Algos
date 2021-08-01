#include<bits/stdc++.h>

#define ll long long int
#define pb push_back
#define maxLimit 100001
using namespace std;

bool visited[maxLimit];
vector<ll> v[maxLimit];

void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < v[s].size();++i) {
        if(visited[v[s][i]] == false)
            dfs(v[s][i]);
    }
}

int main() {
    ll N,M,i,a,b,x, count = 0;
    cin>>N>>M;

    memset(visited, false, sizeof(bool) * (N+1));
    for(i = 0; i < M; i++) {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cin>>x;
    dfs(x);
    for(i = 1; i <= N; i++) {
        if (!visited[i]) {
            count++;
        }
    }
    cout<<count;
    return 0;
}

