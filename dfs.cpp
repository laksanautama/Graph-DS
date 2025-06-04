#include<iostream>
#include<stack>
#include<queue>
using namespace std;

const int MAX_SIZE = 15;
int adjmatrix[MAX_SIZE][MAX_SIZE];
int ukuran[MAX_SIZE];
bool visited[MAX_SIZE];


void addEdge(int u, int v, bool isDirected){
    adjmatrix[u][ukuran[u]++] = v;
if(!isDirected){
    adjmatrix[v][ukuran[v]++] = u;
}
}

void DFS(int start){
stack<int>s;

s.push(start);

while(!s.empty()){
    int node = s.top();
    s.pop();

    if(!visited[node]){
        visited[node] = true;
        cout<<node<<" ";

        for(int i = ukuran[node]-1; i >= 0; i--){
            int next = adjmatrix[node][i];
            if(!visited[next]){
                s.push(next);
            }
        }
    }
}
}


void displayGraph(int nodes){
for(int i = 0; i < nodes; ++i){

    cout<<i<<": ";
    for(int j = 0; j < ukuran[i]; ++j){
        cout<<adjmatrix[i][j]<<" ";
    }
    cout<<endl;
}
}

int main(){


int nodes, edges;
cout<<"Masukan jumlah node: ";
cin>>nodes;

cout<<"Masukan jumlah edge: ";
cin>>edges;

cout<<"Apakah Directed atau Undirected Graph? (pilih 1 atau 0): ";
bool isDirected;
cin>>isDirected;

cout<<"Tambahkan edge (u v): "<<endl;
for(int i = 0; i < edges; ++i){
    int u, v;
    cin>>u>>v;
    addEdge(u, v, isDirected);
}

cout<<endl;

displayGraph(nodes);

int startNode;
cout<<"Masukan node awal: ";
cin>>startNode;
cout<<endl;
cout<<"Tampilan node dengan DFS searching: "<<endl;
DFS(startNode);
}
