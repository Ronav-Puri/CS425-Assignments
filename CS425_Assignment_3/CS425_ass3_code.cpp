/* CS425 - Computer Networks
    Homework-3 (Question 1) Submission
    
    Name: Ronav Puri
    Roll No: 230815
    Program: BT-CSE
    
    Due Date: 10/04/2026 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define matrix std::vector< std::vector<int> >
#define INF 1e5

const int V = 11;

// Dijkstra Algorithm
void dijkstra(matrix &graph, char src, char dest){
    int src_ = src-'A';
    int dest_ = dest-'A';
    vector<int> D(V, INF);   // Distance from source to each vertex
    vector<int> P(V, -1);  // Parent array to reconstruct the path
    vector<bool> visited(V, false); // Track visited vertices

    D[src_] = 0;

    for(int t=0; t<V-1; t++){
        int min=INF, u=-1;

        // Find the vertex with the minimum distance
        for(int v=0; v<V; v++){
            if(!visited[v] && D[v]<=min){
                min = D[v];
                u = v;
            }
        }

        if(u==-1) break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for(int v=0; v<V; v++){
            if(!visited[v] && graph[u][v]!=INF && D[u] + graph[u][v] < D[v]){
                D[v] = D[u] + graph[u][v];
                P[v] = u;
            }
        }
    }

    if(D[dest_]==INF){
        cout << "Dijkstra: No path exists.\n";
        return;
    }
    
    // Reconstruct the shortest path from destination to source
    string path = "";
    int curr = dest_;
    while(curr!=src_){
        path = " -> " + string(1, (char)(curr + 'A')) + path;
        curr = P[curr];
    }
    cout << "\n--- Dijkstra ---\n";
    cout << "Route: " << (char)(src_ + 'A') << path << "\nCost:  " << D[dest_] << '\n';
}

// Bellman-Ford Algorithm 
void bellmanford(matrix &graph, char src, char dest){
    int src_ = src-'A';
    int dest_ = dest-'A';
    vector<int> D(V, INF);  // Distance from source to each vertex
    vector<int> P(V, -1); // Parent array to reconstruct the path
    
    D[src_] = 0;

    for(int t=0; t<V-1; t++){
        for(int u=0; u<V; u++){
            for(int v=0; v<V; v++){
                if(graph[u][v]!=INF && D[u]!=INF && D[u] + graph[u][v] < D[v]){
                    D[v] = D[u] + graph[u][v];
                    P[v] = u;
                }
            }
        }
    }

    if(D[dest_]==INF){
        cout << "Bellman-Ford: No path exists.\n";
        return;
    }
    
    // Reconstruct the shortest path from destination to source
    string path = "";
    int curr = dest_;
    while(curr!=src_){
        path = " -> " + string(1, (char)(curr + 'A')) + path;
        curr = P[curr];
    }
    cout << "\n--- Bellman-Ford ---\n";
    cout << "Route: " << (char)(src_ + 'A') << path << "\nCost:  " << D[dest_] << '\n';
}

int main() {
    // Initialize a V x V matrix filled with INF
    matrix graph(V, vector<int>(V, INF));
    
    // Build the graph as per given figure in the assignment
    graph['A'-'A']['E'-'A'] = 1; graph['E'-'A']['A'-'A'] = 1;
    graph['A'-'A']['B'-'A'] = 1; graph['B'-'A']['A'-'A'] = 1;
    graph['B'-'A']['C'-'A'] = 1; graph['C'-'A']['B'-'A'] = 1;
    graph['C'-'A']['G'-'A'] = 1; graph['G'-'A']['C'-'A'] = 1;
    graph['C'-'A']['F'-'A'] = 3; graph['F'-'A']['C'-'A'] = 3;
    graph['C'-'A']['J'-'A'] = 4; graph['J'-'A']['C'-'A'] = 4;
    graph['D'-'A']['E'-'A'] = 5; graph['E'-'A']['D'-'A'] = 5;
    graph['D'-'A']['H'-'A'] = 1; graph['H'-'A']['D'-'A'] = 1;
    graph['D'-'A']['K'-'A'] = 1; graph['K'-'A']['D'-'A'] = 1;
    graph['D'-'A']['J'-'A'] = 2; graph['J'-'A']['D'-'A'] = 2;
    graph['E'-'A']['G'-'A'] = 1; graph['G'-'A']['E'-'A'] = 1;
    graph['F'-'A']['K'-'A'] = 1; graph['K'-'A']['F'-'A'] = 1;
    graph['G'-'A']['H'-'A'] = 1; graph['H'-'A']['G'-'A'] = 1;

    char src, dest;
    cout << "Enter Source (A-K): ";     
    cin >> src;
    cout << "Enter Destination (A-K): "; 
    cin >> dest;

    dijkstra(graph, src, dest);
    bellmanford(graph, src, dest);

    return 0;
}