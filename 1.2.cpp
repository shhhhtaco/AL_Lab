#include<iostream>
#include<list>
#include<queue>
using namespace std;

void breadthFirstSearch(list<int> graph[], int n){
    queue<int> queue;
    int curr, visited[n] = {0};
    cout<<"Enter start node: ";
    cin>>curr;
    queue.push(curr-1);
    visited[curr-1] = 1;
    while(!queue.empty()){
        curr = queue.front();
        cout<<(curr+1)<<">>";
        queue.pop();
        list<int>::iterator iter;
        for(iter = graph[curr].begin(); iter!=graph[curr].end(); ++iter) if(visited[*iter-1]==0){
            queue.push(*iter-1);
            visited[*iter-1] = 1;
        }
    }
    return;
}

int main(){
    cout<<"Breadth first search on undirected, adjacency list graph.\n";
    cout<<"Enter the number of vertices in graph: ";
    int n, a;
    cin>>n;
    cout<<"Enter the adjacency list:"<<endl;
    list<int> graph[n];
    for(int i = 0; i<n; i++){
        while(1){
            cin>>a;
            if(a!=0) graph[i].push_back(a);
            else break;
        }
    }
    breadthFirstSearch(graph, n);
    return 1;
}