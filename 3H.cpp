#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> pii;
 
const int MAXN = 1000005;
const int MOD = 1000000007;
 
vector<pii> p[MAXN];
 
struct DisjointSet{
      int sets;
      int* parent;
      int* members;
 
      void init(int n){ // O(v)
            sets = n;
            parent = new int[n];
            members = new int[n];
            for(int i = 0; i < n; i++)
                  parent[i] = i, members[i] = 1;
      }
 
      int get(int a){ // O(1)
            if(a == parent[a]) return a;
            return parent[a] = get(parent[a]);
      }
 
      int setsize(int a){ // O(1)
            return members[get(a)];
      }
 
      bool joined(int a, int b){ // O(1)
            return get(a) == get(b);
      }
 
      void join(int a, int b){ // O(1)
            if(joined(a, b)) return;
            members[get(b)] += members[get(a)];
            parent[get(a)] = get(b);
            sets--;
      }
};
 
DisjointSet graph;
long long res = 1 , costo;
set<int> padres;
 
void Uno(int a,int b){
    if(!graph.joined(a,b))
        graph.join(a,b);
}
 
void Dos(int a,int b,int c,int d){
    if(graph.joined(a,b) && graph.joined(c,d)) return;
    if(!graph.joined(a,b) && graph.joined(c,d))
        Uno(a,b);
    else if(graph.joined(a,b) && !graph.joined(c,d))
        Uno(c,d);
    else{
        padres.clear();
        padres.insert(graph.get(a));
        padres.insert(graph.get(b));
        padres.insert(graph.get(c));
        padres.insert(graph.get(d));
        if(padres.size()==2){
            res = (res * 2LL)%MOD;
            graph.join(a,b);
        }
        else{
            graph.join(a,b);
            graph.join(c,d);
        }
    }
}
 
bool proceso(int a,int b,int c,int d,int e,int f){
    padres.insert(graph.get(a));
    padres.insert(graph.get(b));
    padres.insert(graph.get(c));
    padres.insert(graph.get(d));
    padres.insert(graph.get(e));
    padres.insert(graph.get(f));
    int tam = padres.size();
 
    padres.clear();
    padres.insert(graph.get(a));
    padres.insert(graph.get(b));
    padres.insert(graph.get(c));
    padres.insert(graph.get(d));
    if(padres.size()==2)
        return false;
 
    padres.clear();
    padres.insert(graph.get(a));
    padres.insert(graph.get(b));
    padres.insert(graph.get(e));
    padres.insert(graph.get(f));
    if(padres.size()==2)
        return false;
 
    padres.clear();
    padres.insert(graph.get(e));
    padres.insert(graph.get(f));
    padres.insert(graph.get(c));
    padres.insert(graph.get(d));
    if(padres.size()==2)
        return false;
    if(tam!=3) return false;
    graph.join(a,b);
    graph.join(c,d);
    return true;
}
 
void Tres(int a,int b,int c,int d,int e,int f){
    if(graph.joined(a,b) && graph.joined(c,d) && graph.joined(e,f)) return;
    else if(!graph.joined(a,b) && graph.joined(c,d) && graph.joined(e,f))
        Uno(a,b);
    else if(graph.joined(a,b) && !graph.joined(c,d) && graph.joined(e,f))
        Uno(c,d);
    else if(graph.joined(a,b) && graph.joined(c,d) && !graph.joined(e,f))
        Uno(e,f);
    else if(!graph.joined(a,b) && !graph.joined(c,d) && graph.joined(e,f))
        Dos(a,b,c,d);
    else if(!graph.joined(a,b) && graph.joined(c,d) && !graph.joined(e,f))
        Dos(a,b,e,f);
    else if(graph.joined(a,b) && !graph.joined(c,d) && !graph.joined(e,f))
        Dos(c,d,e,f);
    else{        
        padres.clear();
        padres.insert(graph.get(a));
        padres.insert(graph.get(b));
        padres.insert(graph.get(c));
        padres.insert(graph.get(d));
        padres.insert(graph.get(e));
        padres.insert(graph.get(f));
        if(padres.size()==2){
            graph.join(a,b);
            res = (res*3LL)%MOD;
        }
        else{
            padres.clear();
            if(proceso(a,b,c,d,e,f)){
                res = (res*3LL)%MOD;
                return;
            }
 
            padres.clear();
            padres.insert(graph.get(a));
            padres.insert(graph.get(b));
            padres.insert(graph.get(c));
            padres.insert(graph.get(d));
            if(padres.size()==2){
                res = (res*2LL)%MOD;
                graph.join(a,b);
                graph.join(e,f);
                return;
            }
 
            padres.clear();
            padres.insert(graph.get(a));
            padres.insert(graph.get(b));
            padres.insert(graph.get(e));
            padres.insert(graph.get(f));
            if(padres.size()==2){
                res = (res*2LL)%MOD;
                graph.join(a,b);
                graph.join(c,d);
                return;
            }
 
            padres.clear();
            padres.insert(graph.get(e));
            padres.insert(graph.get(f));
            padres.insert(graph.get(c));
            padres.insert(graph.get(d));
            if(padres.size()==2){
                res = (res*2LL)%MOD;
                graph.join(e,f);
                graph.join(a,b);
                return;
            }
 
            graph.join(a,b);
            graph.join(c,d);
            graph.join(e,f);
        }
    }
}
 
int main(){
    freopen( "simplify.in" , "r" , stdin );
    freopen( "simplify.out" , "w" , stdout );
    int n,m,a,b,c,d,e,f;
    scanf("%d %d",&n,&m);
 
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        a--,b--;
        p[c].push_back( pii( a , b ) );
    }
 
    graph.init(n);
 
    for(int i=1;i<MAXN;i++)
        for(int j=0;j<p[i].size();j++){
            a = p[i][j].first;
            b = p[i][j].second;
            if(!graph.joined(a,b)){
                graph.join(a,b);
                costo += (long long) i;
            }
        }
 
    graph.init(n);
 
    for(int i=1;i<MAXN;i++){
        if(p[i].size()==0) continue;
        if(p[i].size()==1){
            a = p[i][0].first;
            b = p[i][0].second;
            Uno(a,b);
        }
        else if(p[i].size()==2){
            a = p[i][0].first;
            b = p[i][0].second;
            c = p[i][1].first;
            d = p[i][1].second;
            Dos( a , b , c , d );
        }
        else if(p[i].size()==3){
            a = p[i][0].first;
            b = p[i][0].second;
            c = p[i][1].first;
            d = p[i][1].second;
            e = p[i][2].first;
            f = p[i][2].second;
            Tres(a,b,c,d,e,f);
        }
    }
 
    printf("%lld %lld\n",costo,res);
    return 0;
}
