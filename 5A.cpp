#include <bits/stdc++.h>
 
using namespace std;
 
int cubeta[10005];
char cad[10005];
 
int main(){
    freopen( "arrange.in" , "r" , stdin );
    freopen( "arrange.out" , "w" , stdout );
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("\n%s",cad);
        cubeta[cad[0]]++;
    }
    int cont = 0;
    for(int i='A';i<='Z';i++){
        if(!cubeta[i]) break;
        cont++;
    }
    printf("%d\n",cont);
    return 0;
}
