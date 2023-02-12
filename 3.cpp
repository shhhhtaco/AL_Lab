#include<iostream>
#include<list>

using namespace std;

void findInDegree(list<int> graph[], int n, int inDegree[]){
    for(int i = 0; i<n; i++){
        list<int>::iterator iter;
        for(iter = graph[i].begin(); iter!=graph[i].end(); ++iter){
            inDegree[*iter-1] += 1;
        }
    }
    return;
}

void topologicalTraverse(list<int> graph[], int n, int inDegree[], int curr, int visited[]){
    list<int>::iterator iter;
    for(iter = graph[curr].begin(); iter!=graph[curr].end(); ++iter){
        visited[*iter-1] +=1;
        if(visited[*iter-1]==inDegree[*iter-1]) cout<<*iter<<">>";
        topologicalTraverse(graph, n, inDegree, *iter-1, visited);
    }
    return;
}

void findTopologicalSort(list<int> graph[], int n){
    int i, inDegree[n] = {0}, visited[n] = {0};
    findInDegree(graph, n, inDegree);
    for(i = 0; i<n; i++){
        if(inDegree[i]==0){
            cout<<i+1<<">>";
            topologicalTraverse(graph, n, inDegree, i, visited);
        }
    }
    return;
}

int main(){
    int n, a;
    cout<<"Program for topological sorting."<<endl;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    list<int> graph[n];
    cout<<"Enter the graph: "<<endl;
    for(int i = 0; i<n; i++){
        while(1){
            cin>>a;
            if(a!=0) graph[i].push_back(a);
            else break;
        }
    }
    findTopologicalSort(graph, n);
    return 1;
}