#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100005;
 
vector<int> lista[MAXN];
int aux[MAXN];
int in[MAXN];
string cad;
int color[MAXN];
int nodo[MAXN];
queue<int> q;
bool valid[MAXN];
 
int dfs(int v){
    nodo[v] = 1;
    for(int i=0;i<lista[v].size();i++){
        int u = lista[v][i];
        nodo[v] &= dfs(u);
    }
    return 1 - nodo[v];
}
 
int main(){
    freopen( "bureau.in" , "r" , stdin );
    freopen( "bureau.out" , "w" , stdout );
    int n,a;
    cin>>n;
 
    for(int i=0;i<n;i++){
        cin>>cad;
        if(cad=="declare") continue;
        cin>>a;
        a--;
        lista[a].push_back(i);
        in[i]++;
    }
 
    vector<int> orden;
 
    for(int i=0;i<n;i++)
        if(!in[i])
            dfs( i );
 
    vector<int> res;
    for(int i=0;i<n;i++)
        if(nodo[i])
            res.push_back(i+1);
 
    sort( res.begin() , res.end() );
    printf("%d\n",(int)res.size());
    for(int i=0;i<res.size();i++){
        printf("%d",res[i]);
        if(i!=res.size()-1) printf(" ");
    }
    printf("\n");
    return 0;
}
