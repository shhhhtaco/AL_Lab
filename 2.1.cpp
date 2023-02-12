#include<iostream>
#include<list>
#define max 25

using namespace std;

int findPath(list<int> graph[], int n, int src, int dest, int visited[], int path[], int count){
    if(src==dest) return 1;
    list<int>::iterator iter;
    for(iter = graph[src-1].begin(); iter!=graph[src-1].end(); ++iter){
        if(visited[*iter-1]!=1){
            path[count++] = *iter;
            visited[*iter-1] = 1;
            if(findPath(graph, n, *iter, dest, visited, path, count)) return 1;
            else --count;
        }
    }
    return 0;
}

int main(){
    cout<<"Find path between two vertices in directed graph."<<endl;
    cout<<"Enter number of vertices in graph: ";
    int n, a, src, dest;
    cin>>n;
    cout<<"Enter the adjacency list: "<<endl;
    list<int> graph[n];
    for(int i = 0; i<n; i++){
        while(1){
            cin>>a;
            if(a!=0) graph[i].push_back(a);
            else break;
        }
    }
    cout<<"Enter the source and destination: ";
    cin>>src>>dest;
    int visited[n] = {0}, path[n] = {0}, count = 1;
    visited[src-1] = 1;
    path[0] = src;
    a = findPath(graph, n, src, dest, visited, path, count);
    if(a==1) for(int i = 0; i<n; i++){
        if(path[i]==0) break;
        cout<<path[i]<<">>";
    }
    else cout<<"Path not found.";
    return 1;
}