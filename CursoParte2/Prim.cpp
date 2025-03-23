#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int INF=1e9;

void primMST(int V, vector<vector<pair <int, int>>> &adj) {
  vector<int> key(V,INF);
  vector<int> parent(V,-1); //nodo padre
  vector<int> inMST(V,false);//si ya esta incluido

  //min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    key[0] = 0;//nodo 0 para empezar
    pq.push({0,0});//nodo 0, peso 0

    while (!pq.empty()) {
      int u = pq.top().second; pq.pop();

      if(inMST[u]) continue;
      inMST[u] = true;

      for(auto &[v,weight] : adj[u]) {
        if(!inMST[v] && weight < key[v]) {
          key[v] = weight;
          parent[v] = u;
          pq.push({key[v], v});
        }
      }
    }
  cout << "Aristas del MST:\n";
  for (int i = 1; i < V; ++i) {
    cout << parent[i] << " - " << i << " con peso " << key[i] << "\n";
  }

}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Grafo: (nodo1, nodo2, peso)
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    primMST(V, adj);

    return 0;
}