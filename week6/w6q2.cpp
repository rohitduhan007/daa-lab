#include<iostream>
#include<queue>
using namespace std;
bool bipartite(int **AdjM,int V) {
    queue<int> Q;
    int *color=new int[V]();
    int curr=1;
    color[0]=curr;
    Q.push(0);
    while (!Q.empty()) {
        int u=Q.front();
        Q.pop();
        if (AdjM[u][u])
            return false;
        curr *=-1;
        for (int v=0;v<V;v++) {
            if (AdjM[u][v] && color[v]==0) {
                color[v]=curr;
                Q.push(v);
            }
            else if(AdjM[u][v] && color[u]==color[v]) 
                return false;    
        }
    }
    return true;
}
int main(){
    int n,s,d;
    cin>>n; 
    int **AdjM; 
    AdjM=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
        AdjM[i]=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>AdjM[i][j];
        }
    }
    if(bipartite(AdjM,n))
        cout<<"Yes Bipartite";
    else
        cout<<"Not Bipartite";
    return 0;
}