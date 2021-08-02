#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    cout<<"Root function-------- Root of "<<x<<" is: ";
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    cout<<x<<"\n";
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    cout<<"Root of x: "<<p<<"  Root of y: "<<q<<"\n";
    id[p] = id[q];
    for(int i = 1; i <=5; i++) {
        cout<<id[i]<<" ";
    }
    cout<<"\n";
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << "Minimum cost is: "<< minimumCost << endl;
    return 0;
}