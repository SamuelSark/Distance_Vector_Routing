//Average Time Complexity is O(n^2) & Worst Case: O(n^3)
#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge {
    int source;
    int destination;
    int cost;
};

struct Graph {
    int vertex;
    int edge;
    struct Edge* edge_array;
};

struct Graph* Graph_Maker(int vertex, int edge) {
    struct Graph* graph = new Graph;
    graph->vertex = vertex;
    graph->edge = edge;
    graph->edge_array = new Edge[edge];
    return graph;
}

void Bellman_Ford_Algorithm(int source, struct Graph* graph) {
    int vertex = graph->vertex;
    int edge = graph->edge;
    vector<int> distance_array(vertex);
    for (int i = 0; i < vertex; i++){
        distance_array[i] = INT_MAX;
    }
    distance_array[source] = 0;
    for (int i = 1; i < vertex; i++) {
        for (int j = 0; j < edge; j++) {
            if (distance_array[graph->edge_array[j].source] + graph->edge_array[j].cost < distance_array[graph->edge_array[j].destination] && distance_array[graph->edge_array[j].source] != INT_MAX){
            distance_array[graph->edge_array[j].destination] = distance_array[graph->edge_array[j].source] + graph->edge_array[j].cost;
            }
        }
    }
    for (int i = 0; i < edge; i++) {
        if (distance_array[graph->edge_array[i].source] + graph->edge_array[i].cost < distance_array[graph->edge_array[i].destination] && distance_array[graph->edge_array[i].source] != INT_MAX) {
            cout << "Graph involves negative cost cycle" << endl;
            return;
        }
    }
    printf("vertex = ");
    for (int i = 0; i < vertex; i++){
        cout << " " << i << " ";
    }
    cout << "\nThe distance from source = ";
    for (int i = 0; i < vertex; i++){
        cout << " " << distance_array[i] << " ";
    }
    cout << endl;
    return;
}

int main() {
    // Determine manually how many vertixes and edges are goinng to be invovled in the graph
    int vertex = 4;
    int edge = 5;
    //manually we can build the graph by providing the source, destination,and its cost
    struct Graph* graph = Graph_Maker(vertex, edge);
    graph->edge_array[0].source = 0;
    graph->edge_array[0].destination = 1;
    graph->edge_array[0].cost = 1;

    graph->edge_array[1].source = 0;
    graph->edge_array[1].destination = 3;
    graph->edge_array[1].cost = 3;

    graph->edge_array[2].source = 1;
    graph->edge_array[2].destination = 3;
    graph->edge_array[2].cost = 6;

    graph->edge_array[3].source = 3;
    graph->edge_array[3].destination = 2;
    graph->edge_array[3].cost = 2;

    graph->edge_array[4].source = 2;
    graph->edge_array[4].destination = 1;
    graph->edge_array[4].cost = -12;

    //calls the Bellman ford algorithm function
    Bellman_Ford_Algorithm(0,graph);
    return 0;
}