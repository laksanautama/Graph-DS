#include <iostream>

using namespace std;

const int MAX_VERTICES = 10;

void printGraph(int graph[][MAX_VERTICES], int vertices) {
    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {
            cout<<graph[i][j]<<" ";

        }
        cout << "\n";
    }
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int vertices = 5;

    // Initialize the graph
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Add edges to the graph
    graph[0][1] = 1;
    graph[0][4] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    cout << "Graph:\n";
    printGraph(graph, vertices);

    return 0;
}
