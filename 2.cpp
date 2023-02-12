#include<iostream>

using namespace std;

void bubble(int arr[], int id[], int n){
    int temp;
    for(int i = 0; i<n-1; i++) for(int j = 0; j<n-1-i; j++) if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        temp = id[j];
        id[j] = id[j+1];
        id[j+1] = temp;
    }
    return;
}

void fbubble(float arr[], int id[], int n){
    int temp;
    float temp1;
    for(int i = 0; i<n-1; i++) for(int j = 0; j<n-1-i; j++) if(arr[j]>arr[j+1]){
        temp1 = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp1;
        temp = id[j];
        id[j] = id[j+1];
        id[j+1] = temp;
    }
    return;
}

int greedyOnWeight(int weight[], int profit[], int id[], int x[], int n, int c){
    int sum = 0, p = 0;
    bubble(weight, id, n);
    for(int i = 0; i<n; i++){
        sum += weight[i];
        if(sum<c){
            p += profit[id[i]];
            x[id[i]] = 1;
        }
        else break;
    }
    return p;
}

int greedyOnProfit(int weight[], int profit[], int id[], int x[], int n, int c){
    int sum = 0, p = 0;
    bubble(profit, id, n);
    for(int i = n-1; i>=0; --i){
        sum += weight[id[i]];
        if(sum<c){
            x[id[i]] = 1;
            p += profit[i];
        }
        else break;
    }
    return p;
}

int greedyOnProfitDensity(int weight[], int profit[], int id[], int x[], int n, int c){
    int sum = 0, p = 0;
    float pw[n] = {0};
    for(int i = 0; i<n; i++) pw[i] = (float)profit[i]/weight[i];
    fbubble(pw, id, n);
    for(int i = n-1; i>=0; --i){
        sum += weight[id[i]];
        if(sum<c){
            x[id[i]] = 1;
            p += profit[id[i]];
        }
        else break;
    }
    return p;
}

int main(){
    cout<<"0/1 knapsack problem.";
    cout<<"\nEnter the number of containers: ";
    int n, c, a;
    cin>>n;
    int weight[n], profit[n], id[n], x[n] = {0}, p;
    cout<<"Enter the capacity: ";
    cin>>c;
    cout<<"Enter the weights: ";
    for(int i = 0; i<n; i++) cin>>weight[i];
    cout<<"Enter the corresponding profit: ";
    for(int i = 0; i<n; i++) cin>>profit[i];
    for(int i = 0; i<n; i++) id[i] = i;
    p = greedyOnWeight(weight, profit, id, x, n, c);
    c = 0;
    for(int i = 0; i<n; i++){
        cout<<x[i]<<" ";
        c += x[i];
    }
    cout<<"Maximum containers using greedy on weight method: "<<c<<endl<<"Maximum profit on this method: "<<p<<endl;
    p = greedyOnProfit(weight, profit, id, x, n, c);
    c = 0;
    for(int i = 0; i<n; i++){
        cout<<x[i]<<" ";
        c += x[i];
    }
    cout<<"Maximum containers using greedy on profit method: "<<c<<endl<<"Maximum profit on this method: "<<p<<endl;
    p = greedyOnProfitDensity(weight, profit, id, x, n, c);
    c = 0;
    for(int i = 0; i<n; i++){
        cout<<x[i]<<" ";
        c += x[i];
    }
    cout<<"Maximum containers using greedy on profit density method: "<<c<<endl<<"Maximum profit on this method: "<<p<<endl;
    return 1;
}