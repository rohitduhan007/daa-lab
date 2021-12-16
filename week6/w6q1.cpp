#include<iostream>
#include<stack>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n][n];
    //a = (int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    int s,d;
    cin>>s>>d;
    s--;
    d--;

    // ALGO STARTS HERE
    bool z = false;
    stack<int> sp;
    bool visited[n];
    sp.push(s);         // push source node
    visited[s] = true;     // hence we have visited the source node
    while(!sp.empty()){
        int upper = sp.top();
        sp.pop();
        for(int v=0;v<n;v++){
            if(a[upper][v] && v == d){   // reached destination
                z = true;
                break;
            }
            if(a[upper][v] && !visited[v]){  // if not visited the edge, then push in stack
                sp.push(v);
                visited[v] = true;
            }
        }
    }

    cout<<"OUTPUT:\n";
    if(z == true)
        cout<<"Yes Path Exists";
    else 
        cout<<"No Such Path Exists";
    return 0;
}