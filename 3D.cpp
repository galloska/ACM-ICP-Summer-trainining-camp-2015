#include <bits/stdc++.h>
using namespace std;
 
struct datos{
    int val, id;
};
int n;
int num[100002];
datos arr[100002];
int islas = 1;
int res = 0;
int vis[100002];
 
bool doble (datos a, datos b){
    return a.val < b.val;
}
 
int main (){
 
    freopen ("islands.in", "r", stdin);
    freopen ("islands.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i<= n; i++){
        scanf ("%d", &num[i]);
        arr[i].val = num[i];
        arr[i].id = i;
    }
    sort (arr + 1, arr + 1 + n, doble);
    for (int i = 1; i <= n; i++){
        if (vis[arr[i].id] == 0){
            int izq = arr[i].id, der = arr[i].id;
            while (num[izq] == arr[i].val){
                vis[izq] = 1;
                izq--;
            }
            while (num[der] == arr[i].val){
                vis[der] = 1;
                der++;
            }
            if (num[izq] < arr[i].val && num[der] < arr[i].val)
                islas--;
            else
                if (num[izq] > arr[i].val && num[der] > arr[i].val)
                    islas++;
            res = max (res, islas);
        }
    }
    printf ("%d\n", res);
    return 0;
}
