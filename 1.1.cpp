#include<iostream>
#include<stack>
#define max 25
using namespace std;

void depthFirstSearch(int arr[][max], int n){
    stack<int> stack;
    int curr, visited[n] = {0};
    cout<<"Enter start node: ";
    cin>>curr;
    stack.push(curr-1);
    visited[curr-1] = 1;
    while(!stack.empty()){
        curr = stack.top();
        cout<<(curr+1)<<">>";
        stack.pop();
        for(int i = 0; i<n; i++) if(visited[i]==0 && arr[curr][i]!=0){
            stack.push(i);
            visited[i] = 1;
        }
    }
    return;
}

int main(){
    cout<<"Depth first search on undirected, adjacency matrix graph.\n";
    cout<<"Enter the number of vertices in the graph: ";
    int n;
    cin>>n;
    int arr[n][max];
    cout<<"Enter the adjacency matrix:"<<endl;
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) cin>>arr[i][j];
    depthFirstSearch(arr, n);
    return 1;
}