// graph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<vector>
#include<stack>
const int INF = 1e9;
using namespace std;

// fix this

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void Dijkstra(int s, vector<int> &p,vector<int>& d, vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> u(n, false);
    
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == INF) {
            break;
        }

        u[v] = true;
        for (auto &edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p) {
    int result = 0;
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
        result += 1;
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
int n; // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}
void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

// dynamic programming

int trap(vector<int>& height) {
    stack<int>leftWalls;
    stack<int>localMaxHeight;
    // find the first wall
    int index = 0;
    for (auto& i : height) {
        if (i > 0) {
            leftWalls.push(i);
            index++;
            break;
        }
        index++;
    }
    int totalWater = 0;
    int currentMaxWall = 0;
    for (int i = index; i < height.size(); ++i) {
        // push back the previous wall
        if (leftWalls.empty())
            leftWalls.push(height[i - 1]);
        if (height[i]<leftWalls.top()) {
            leftWalls.push(height[i]);
            if (height[i] > currentMaxWall) 
                currentMaxWall = height[i];
        }
        else if (leftWalls.top() < height[i]) {
            while (!leftWalls.empty()) {
                totalWater += height[i] - leftWalls.top() >= 0 ? height[i] - leftWalls.top() : 0;
                leftWalls.pop();
            }
            break;
        }
    }
    return totalWater;
}
int main()
{
    vector<int>height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    height = { 4,2,0,3,2,5 };
    cout << trap(height);
    //vector<vector<pair<int, int>>> adj(5);

    //addEdge(adj, 0, 1, 10);
    //addEdge(adj, 0, 4, 20);
    //addEdge(adj, 1, 2, 30);
    //addEdge(adj, 1, 3, 40);
    //addEdge(adj, 1, 4, 50);
    //addEdge(adj, 2, 3, 60);
    //addEdge(adj, 3, 4, 70);
    // dijstra algorithm
    //int source = 0;
    vector<int> d;
    vector<int> p;
    //cout << "Distances: \n";
    //for (auto &i : d){ 
    //    cout << i << ' ';
    //}
    //cout << endl;
    //int n, m;
    //cin >> n >> m;
    //vector<vector<pair<int, int>>> adj(n);
    //int from, to,weight;
    //for (int i = 0; i < m; ++i) {
    //    cin >> from >> to >> weight;
    //    addEdge(adj, from - 1, to - 1, weight);
    //}
    //Dijkstra(0,p,d,adj);
    //
    //for (auto& i : restore_path(0, n-1, p)) {
    //    cout << i +1<< ' ';
    //}


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
