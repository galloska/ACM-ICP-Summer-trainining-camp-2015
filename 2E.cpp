#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <string.h>
#define pii pair<int,int>
 
using namespace std;
 
const int MAXN = 1000005;
 
int cabeza = -1;
int vis[MAXN];
vector<int> lista[MAXN];
queue<int> q;
 
int in[MAXN];
 
void bfs(){
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<lista[v].size();i++){
            int u = lista[v][i];
            --in[u];
            if(!in[u]){
                vis[u] = v;
                q.push(u);
            }
        }
    }
}
 
void bfs2(){
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<lista[v].size();i++){
            int u = lista[v][i];
            if(vis[u]==1<<30){
                vis[u] = v;
                q.push(u);
            }
            else{
                cabeza = v;
                return;
            }
        }
    }
}
 
int main(){
    freopen( "cycle.in","r",stdin );
    freopen( "cycle.out","w",stdout );
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        a--,b--;
        lista[a].push_back(b);
        in[b]++;
        //lista[b].push_back(a);
    }
    fill( vis, vis + n, 1<<30);
 
    for(int i=0;i<n;i++)
        if(!in[i]){
            vis[i] = i;
            q.push(i);
        }
 
    bfs();
 
    for(int i=0;i<n;i++)
        if(vis[i]==1<<30){
            vis[i] = i;
            q.push(i);
            bfs2();
            break;
        }
 
    if(cabeza!=-1){
        printf("YES\n");
        int v = cabeza;
        vector<int> ord;
        while(v != vis[v]){
            ord.push_back(v+1);
            v = vis[v];
        }
        ord.push_back(v+1);
        for(int i=ord.size()-1;i>=0;i--){
            if(i!=ord.size()-1) printf(" ");
            printf("%d",ord[i]);
        }
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}
