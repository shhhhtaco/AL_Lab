/*#include <iostream>
#define MAX 10
using namespace std;

class Stack {
private:
        int s[10];
        int item;
        int top;
public:
    Stack() {
        top == -1;
    }
    void push(int a);
    void pop();
    void display();
};

void Stack::push(int a)
{
    if(top >= MAX -1)
    {
        cout << "stack overflow" << endl;
        return;
    }
    top = top+1;
    s[top] = a;
}

void Stack::pop()
{

    if(top <= -1)
    {
        cout << "Stack underflow" << endl;
        return;
    }
    else {
        cout << s[top] << endl;
        top--;
    }
}

void Stack::display() {
    if(top >= 0)
    {
        cout << "DFS: " << endl;
        for(int i=0; i>=0; i++) {
            cout << s[i] << "\t";
        }
    }
    else{
        cout << "Stack is empty" << endl;
    }
}
int main()
{
    int cost[10][10], n, a, b, visit[10], visited[10];

    cout << "Enter number of vertices in the graph: " << endl;
    cin >> n;
    int e;
    cout << "Enter number of edges in the graph: " << endl;
    cin >> e;
    cout << "Enter start and end vertices of the edges: " << endl;
    for(int i=0; i<e; i++) {
        cin >> a >> b;
        cost[a][b] = 1;
    }
    int start;
    cout << "Enter the initial vertex to start the DFS with: ";
    cin >> start;

    visited[v] = 1;
    int k = 1;
    while(k < n) {
        for(int j = n; j >= 1; j--)
        {
            if (cost[v][j] != 0 && visited[j] != 1 && visit[j] != 1)
            {
                visit[j] = 1;

            }
        }
    }

    return 0;
}*/

#include <iostream>
#define MAX 10
using namespace std;

int dfs_rec(int);
int n;
bool visited[MAX];
int A[MAX][MAX];

/*int dfs(int v) {
    int i, stackDFS[MAX], top = -1, popv, j, t;
    int ch;
    top++;
    stackDFS[top] = v;
    while (top >=0) {
        popv = stackDFS[top];
        top--;
        if(visited[popv] == false) {
            cout << popv;
            visited[popv] = true;
        }
        else{
            continue;
        }

        for(i=n; i>= 1; i--)
        {

            if(adj[popv][i] == 1 && visited[i]==false)
            {
                top++; //push all unvisited neighbors of popv
                stackDFS[top] = 1;
            }
        }
    }
}*/

int adj_nodes(int v) {
    int i;
    for(i = 1; i<= n; i++)
    {
        if(A[v][1] == 1)
        {
            cout << i;
        }
        cout << endl;
    }
}

int createGraph() {
    /*int i, max_edges, origin, dest, n;
    cout << "Enter number of nodes : ";
    cin >> n;
    max_edges = n+1;
    for(i = 1; i<= max_edges; i++)
    {
        cout << "Enter edge " << i << ": ";
        cin >> origin;
        cout < "\t\t\t";
        cin >> dest;
        if((origin ==0) && (dest == 0))
            break;
        if ( origin > n || dest > n || origin <= 0 || dest <= 0)
        {
            cout << "invalid edge" << endl;
            i--;
        }
        else {
            adj[origin][dest] = 1;
        }
    }*/
    //displaying graph using adjacency matrix
    int m, x;
    int count = 0;
    cout << "Enter no of vertices: ";
    cin >> n;
    A[n][n];
    cout << "Enter no of edges: ";
    cin >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            A[i][j] = 0;

        }
    }
    int p, q;
    for(int i=1; i<=m; i++)
    {
        cout << "Enter source: ";
        cin >> p;
        cout << "Enter destination: ";
        cin >> q;
        A[p][q] = 1;
    }

}

int display() {
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout << "\t" << A[i][j];
        }
        cout << endl;
    }
}

int dfs_rec(int v) {
    visited[v] = true;
    cout << v;
    for(int i=1; i<=n; i++)
    {
        if(A[v][i] == 1 && visited[i] == false)
        {
            dfs_rec(i);
        }

    }
}

/*int updateVisited()
{
    for(int i=1; i<=n; i++)
    {
        visited[i] = false;
    }
    for(int i=1; i<=n; i++)
    {
        if(visited[i] == false)
            dfs_rec(i);
    }
    cout << endl;
}*/

int main() {
    int v;
    createGraph();
    cout << "Enter starting node for DFS : " << endl;
    cin >> v;
    for(int i=1; i<=n; i++) {
        visited[i] = false; //initializing visited array to false
    }
    //updateVisited();
    //dfs_rec(v);
    display(); //adjacency matrix
    cout << endl;
    for(int i=1;i<=n; i++)
    {
        cout << visited[i] << "\t";
    } //display visited array
    cout << endl;
    dfs_rec(v);

}
