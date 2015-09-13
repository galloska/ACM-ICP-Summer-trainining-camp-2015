#include <bits/stdc++.h>
#define pii pair<int,int>
 
using namespace std;
 
typedef pair<int,int> Arista;
 
const int INF = 1<<30;
const int MAXN = 50005;
 
vector<int> E[MAXN];
 
int padre[MAXN];
map<int,int> cap[MAXN];
map<int,int> flujo[MAXN];
 
int Actualiza(int u,int f){
    int p = padre[u];
    if(p==u) return f;
    f = Actualiza(  p , min( f , cap[p][u] - flujo[p][u] ) ); 
    flujo[p][u] += f;
    flujo[u][p] -= f;
    return f;
}
 
int Aumenta(int s,int t,int n){
    fill( padre , padre + n , -1 );
    queue<int> q;
    q.push( s );
    padre[s] = s;
 
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u==t) break;
        for(int i=0;i<E[u].size();i++){
            int v = E[u][i];
            if(flujo[u][v]==cap[u][v] || padre[v]!=-1) continue;
            padre[v] = u;
            q.push(v);
        }
    }
 
    if(padre[t]==-1) return 0;
    return Actualiza(t,INF);
}
 
int Edmonds(int s,int t,int n){
    int flujo = 0,f;
    while(f=Aumenta(s,t,n) && flujo<=3)
        flujo += f;
    return flujo;
}
 
map<int,int> x;
map<int,int> y;
 
int main(){
    freopen( "3lines.in" , "r" , stdin );
    freopen( "3lines.out" , "w" , stdout );
    int n,u=2,k=2,a,b;
    vector<pii> puntos;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        puntos.push_back( pii( a , b ) );
        if(x.find(a)==x.end()) x[a] = u++;
        if(y.find(b)==y.end()) y[b] = k++;
    }
 
    for(int i=0;i<n;i++){
        a = x[puntos[i].first];
        b = y[puntos[i].second] + x.size();
        E[0].push_back( a );
        E[a].push_back( 0 );
        cap[0][a] = 1;
        cap[a][0] = 1;
        flujo[a][0] = 1;
 
        E[a].push_back( b );
        E[b].push_back( a );
        cap[a][b] = 1;
        cap[b][a] = 1;
        flujo[b][a] = 1;
 
        E[b].push_back( 1 );
        E[1].push_back(b);
        cap[b][1] = 1;
        cap[1][b] = 1;
        flujo[1][b] = 1;
    }
 
    int res = Edmonds( 0 , 1 , x.size() + y.size() + 2 );
    //printf("%d\n",res);
 
    if(res<=3) printf("1\n");
    else printf("0\n");
    return 0;
}
