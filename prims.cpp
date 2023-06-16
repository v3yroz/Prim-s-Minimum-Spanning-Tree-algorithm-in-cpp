#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();


class Edge{
public:
    int weight;
    int vertex;

    Edge(int weight, int vertex) : weight(weight), vertex(vertex) {}
};


int primMST(const vector<vector<Edge>>& graph, int startVertex){

    int n = graph.size();

    vector<int> key(n, INF);
    vector<bool> mstSet(n, false);
    vector<int> parent(n, -1);

    key[startVertex] = 0;

    for(int i = 0; i < n - 1; ++i){
        int minKeyVertex = -1;
        for(int v = 0; v < n; ++v){
            if(!mstSet[v] && (minKeyVertex == -1 || key[v] < key[minKeyVertex])){
                minKeyVertex = v;
            }
        }

        mstSet[minKeyVertex] = true;

        for(int j = 0; j < graph[minKeyVertex].size(); ++j){

            int weight = graph[minKeyVertex][j].weight;
            int vertex = graph[minKeyVertex][j].vertex;

            if(!mstSet[vertex] && weight < key[vertex]){
                key[vertex] = weight;
                parent[vertex] = minKeyVertex;
            }
        }
    }

    int totalWeight = 0;
    for(int i = 0; i < n; ++i){
        if(parent[i] != -1){
            totalWeight += key[i];
        }
    }

    return totalWeight;
}
