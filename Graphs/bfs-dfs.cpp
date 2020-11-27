#include <iostream>
#include <array>
#include <queue>
#include <stack>
using namespace std;
void BFS(int vtx,array<array<int,8>,8> A){
    queue<int> q;
    int visited[8] {0};
    cout<<vtx<<" ";
    visited[vtx]=1;
    q.emplace(vtx);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=1;v<=A.size();v++){
            if(A[u][v]==1 && visited[v]==0){
                cout<<v<<" ";
                visited[v]=1;
                q.emplace(v);
            }
        }
    }
    cout<<endl;
}
void DFS(int vtx,array<array<int,8>,8>A){
    stack<int> stk;
    int visited[8]{0};
    //cout<<vtx<<" ";
    stk.push(vtx);
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        cout<<u<<" ";
        visited[u]=1;
        for(int v=1;v<=A.size();v++){
            if(A[u][v]==1 && visited[v]==0){
                stk.push(v);
                visited[v]=1;
            }
        }
    }
    cout<<endl;
}
void Rdfs(int vtx,array<array<int,8>,8>A){
    static int visited[8] {0};
    if(visited[vtx]==0){
        cout<<vtx<<" ";
        visited[vtx]=1;
        for(int v=1;v<=A.size();v++){
            if(A[vtx][v]==1 && visited[v]==0)
                Rdfs(v,A);
        }
    }
}
int main() {
    array<array<int,8>,8> A{};
    A= {{
                       {0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 0, 1, 1, 0, 0},
                       {0, 1, 0, 1, 0, 1, 0, 0},
                       {0, 0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 0}
               }};
    cout << "Vertex: 1 -> " << flush;
    DFS(1, A);

    //cout << "Vertex: 1 -> " << flush;
   // Rdfs(1, A);
    cout<<endl;
    cout << "Vertex: 4 -> " << flush;
    DFS(4, A);

    //cout << "Vertex: 4 -> " << flush;
    //Rdfs(4, A);
    return 0;
}
