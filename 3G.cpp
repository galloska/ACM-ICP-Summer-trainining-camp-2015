#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
 
int n, q;
vector <int> aris[MAXN];
int lca[MAXN][22];
int nivel[MAXN];
int tiempo;
int inicios[MAXN];
int finales[MAXN];
int ft[MAXN * 2];
 
void dfs (int nodo, int pad, int niv){
    nivel[nodo] = niv;
    lca[nodo][0] = pad;
    tiempo++;
    inicios[nodo] = tiempo;
    for (int i = 0; i < aris[nodo].size(); i++)
        if (aris[nodo][i] != pad)
            dfs (aris[nodo][i], nodo, niv + 1);
    tiempo++;
    finales[nodo] = tiempo;
}
 
void f_lca (){
    for (int pot = 1; pot <= 18; pot++)
        for (int i = 1; i <= n; i++)
            lca[i][pot] = lca[lca[i][pot - 1]][pot - 1];
}
 
int sube (int nodo, int h){
    for (int i = 18; i >= 0; i--)
        if (nivel[lca[nodo][i]] >=h)
            nodo = lca[nodo][i];
    return nodo;
}
 
int get_lca (int u, int v){
    int h_u = nivel[u];
    int h_v = nivel[v];
    if (h_u > h_v) u = sube (u, h_v);
    else if (h_v > h_u) v = sube (v, h_u);
    if (u == v)
        return u;
    for (int i = 18; i >= 0; i--){
        if (lca[u][i] != lca[v][i]){
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}
 
void update (int pos, int val){
    while (pos <= n * 2){
        ft[pos] += val;
        pos += (pos & -pos);
    }
}
 
int query (int pos){
    int suma = 0;
    while (pos){
        suma += ft[pos];
        pos -= (pos & -pos);
    }
    return suma;
}
 
int main (){
 
    freopen ("grassplant.in", "r", stdin);
    freopen ("grassplant.out", "w", stdout);
    scanf ("%d %d",&n, &q);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf ("%d %d", &a, &b);
        aris[a].push_back(b);
        aris[b].push_back(a);
    }
    dfs (1, 1, 0);
    /*for (int i = 1; i <= n; i++)
        cout << lca[i][0] << " ";
    cout << endl;*/
    f_lca ();
    /*for (int i = 1; i <= n; i++)
        cout << nivel[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++){
        for (int pot = 0; pot <= 18; pot++)
            cout << lca[i][pot] << " ";
        cout << endl;
    }*/
    /*for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <=n; j++)
            cout << i << " " << j << " : " << get_lca (i, j) << endl;
    }*/
    for (int i = 1; i <= q; i++){
        char aux;
        int a, b;
        scanf (" %c %d %d", &aux, &a, &b);
        if (aux == 'P'){
            update (inicios[a], 1);
            update (inicios[b], 1);
            update (inicios[get_lca (a, b)], -2);
        }else{
            int act;
            if (nivel[a] > nivel[b])
                act = a;
            else act = b;
            printf ("%d\n", query (finales[act]) - query (inicios[act] - 1));
        }
    }
    return 0;
}
