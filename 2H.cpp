#include <bits/stdc++.h>
using namespace std;
 
int n;
string cad[12];
int mapa[12][12];
int vis[12];
bool ban = true;
int val = 9;
int valor[12];
int cubeta[12];
 
void dfs (int nodo){
    if (vis[nodo] == 1){
        ban = false;
        return;
    }
    if (vis[nodo] == 0){
        vis[nodo] = 1;
        for (int i = 1; i <= 10; i++)
            if (mapa[nodo][i])
                dfs (i);
        vis[nodo] = 2;
        if (val == 0 && cubeta[nodo])
            ban = false;
        valor[nodo] = val;
        val--;
    }
}
 
int main (){
 
    freopen ("tiv.in", "r", stdin);
    freopen ("tiv.out", "w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cad[i];
    if (cad[1].size() > 1)
        cubeta[cad[1][0] - 'a' + 1] = 1;
    for (int i = 2; i <= n; i++){
        if (cad[i].size() > 1)
            cubeta[cad[i][0] - 'a' + 1] = 1;
        if (cad[i].size() == cad[i - 1].size()){
            int pos = 0;
            while (cad[i][pos] == cad[i - 1][pos] && pos < cad[i].size())
                pos++;
            if (pos < cad[i].size())
                mapa[cad[i - 1][pos] - 'a' + 1][cad[i][pos] - 'a' + 1] = 1;
            else
                ban = false;
        }else{
            if(cad[i].size() < cad[i - 1].size())
                ban = false;
        }
    }
    for (int i = 1; i <= 10; i++){
        if (cubeta[i] && vis[i] == 0)
            dfs (i);
    }
    for (int i = 1; i <= 10; i++){
        if (vis[i] == 0)
            dfs (i);
    }
    if (ban){
        cout << "Yes" << endl;
        for (int i = 1; i <= 10; i++)
            cout << valor[i] << " ";
        cout << endl;
    }else
        cout << "No" << endl;
    return 0;
}
