#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// DFS函数用于查找图的连通分量
void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& size) {
    visited[node] = true;
    size++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, size);
        }
    }
}

int main() {
    int m, n;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;
    vector<bool> visited(n + 1, false);
    vector<int> component_sizes;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int size = 0;
            dfs(i, graph, visited, size);
            components++;
            component_sizes.push_back(size);
        }
    }


    if (components != 2) {
        cout << 0 << endl;
    } else {
        long long int total_ways = components - 1;
        for (int size : component_sizes) {
            total_ways *= size;
        }
        cout << total_ways << endl;
    }

    return 0;
}
