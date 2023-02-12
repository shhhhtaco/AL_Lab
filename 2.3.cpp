#include<iostream>
#include<list>
#include<stack>
#define max 25

using namespace std;

void depthFirstSearch(list<int> graph[], int n, int visited[], int curr){
    stack<int> stack;
    stack.push(curr-1);
    visited[curr-1] = 1;
    while(!stack.empty()){
        curr = stack.top();
        stack.pop();
        list<int>::iterator iter;
        for(iter = graph[curr].begin(); iter!=graph[curr].end(); ++iter) if(visited[*iter-1]==0){
            stack.push(*iter-1);
            visited[*iter-1] = 1;
        }
    }
    return;
}

int connectedGraph(list<int> graph[], int n){
    int last, visited[n] = {0};
    for(int i = 0; i<n; i++){
        if(visited[i]!=1){
            depthFirstSearch(graph, n, visited, (i+1));
            last = i;
        }
    }
    int revisited[n] = {0};
    depthFirstSearch(graph, n, revisited, (last+1));
    for(int i = 0; i<n; i++) if(revisited[i]==0) return 0;
    return 1;
}

int main(){
    cout<<"Find if graph is connected or not.\n";
    cout<<"Enter the number of vertices in graph: ";
    int n, a;
    cin>>n;
    list<int> graph[n];
    for(int i = 0; i<n; i++){
        while(1){
            cin>>a;
            if(a!=0) graph[i].push_back(a);
            else break;
        }
    }
    if(connectedGraph(graph, n)) cout<<"Connected graph.";
    else cout<<"Not connected graph.";
    return 1;
}