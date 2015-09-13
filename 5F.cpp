#include <bits/stdc++.h>
using namespace std;
 
int n;
double val;
double tot;
double bed;
double cost;
 
int main (){
 
    freopen ("flat.in", "r", stdin);
    freopen ("flat.out", "w", stdout);
    cin >> n >> val;
    for (int i = 1; i <= n; i++){
        double v;
        string act;
        cin >> v >> act;
        tot += v;
        if (act == "bedroom")
            bed += v;
        if (act == "balcony")
            cost += (v / 2);
        else cost += (v);
    }
    printf ("%.0lf\n%.0lf\n%.6lf\n", tot, bed, cost * val);
    return 0;
}
