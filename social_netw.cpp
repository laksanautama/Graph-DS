#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_USERS = 100;
int graph[MAX_USERS][MAX_USERS];  // Adjacency matrix
bool visited[MAX_USERS];
int numUsers;


void addFriendship(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}


void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "Daftar user yang berada pada jaringan pertemana yg sama dgn: " << start << ": ";

    while (!q.empty()) {
        int user = q.front();
        q.pop();
        cout << user << " ";

        for (int i = 0; i < numUsers; i++) {
            if (graph[user][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int countSocialCircles() {
    int count = 0;
    fill(visited, visited + MAX_USERS, false);

    for (int i = 0; i < numUsers; i++) {
        if (!visited[i]) {
            bfs(i);
            count++;
        }
    }
    return count;
}

int main() {
    numUsers = 6;

 
    addFriendship(0, 1);
    addFriendship(1, 2);
    addFriendship(3, 4);
   

    int circles = countSocialCircles();
    cout << "Total social circles pada jaringan: " << circles << endl;

    return 0;
}
