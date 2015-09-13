#include <stdio.h>
#include <vector>
 
using namespace std;
 
const int MAXN = 1005;
 
int cont;
bool vis[MAXN];
vector<int> lista[MAXN];
 
void dfs(int v){
    vis[v] = true;
    cont++;
    for(int i=0;i<lista[v].size();i++){
        if(!vis[lista[v][i]])
            dfs(lista[v][i]);
    }
}
 
int main(){
    freopen( "tree.in","r",stdin );
    freopen( "tree.out","w",stdout );
    int n,m,a,b;
    bool flag;
    scanf("%d %d",&n,&m);
    if(m+1==n) flag = true;
    else flag = false;
    while(m--){
        scanf("%d %d",&a,&b);
        a--,b--;
        lista[a].push_back(b);
        lista[b].push_back(a);
    }
    dfs(0);
    if(cont==n && flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}
