#include <bits/stdc++.h>
using namespace std;
 
int n, m, t;
vector <int> filas;
vector <int> columnas;
 
int main (){
 
    freopen ("defense.in", "r", stdin);
    freopen ("defense.out", "w", stdout);
    scanf ("%d %d %d",&n, &m, &t);
    for (int i = 1; i <= t; i++){
        int a, b;
        scanf ("%d %d", &a, &b);
        filas.push_back(a);
        columnas.push_back(b);
    }
    filas.push_back(0);
    filas.push_back(n + 1);
    columnas.push_back(0);
    columnas.push_back(m + 1);
    int mayor_fila = 0;
    sort(filas.begin(), filas.end());
    sort(columnas.begin(), columnas.end());
    for (int i = 1; i < filas.size(); i++){
        int act = filas[i] - filas[i - 1] - 1;
        mayor_fila = max (mayor_fila, act);
    }
    int mayor = 0;
    for (int i = 1; i < columnas.size(); i++){
        int act = columnas[i] - columnas[i - 1] - 1;
        mayor = max (mayor, mayor_fila * act);
    }
    printf ("%d\n", mayor);
    return 0;
}
