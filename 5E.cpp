#include <bits/stdc++.h>
 
using namespace std;
 
int res;
int num[15];
 
int main(){
    freopen( "explicit.in" , "r" , stdin );
    freopen( "explicit.out" , "w" , stdout );
    for(int i=0;i<10;i++)
        scanf("%d",&num[i]);
 
    for(int i=0;i<10;i++)
        for(int j=i+1;j<10;j++)
            res ^= ( num[i] | num[j] );
 
    for(int i=0;i<10;i++)
        for(int j=i+1;j<10;j++)
            for(int h=j+1;h<10;h++)
            res ^= ( num[i] | num[j] || num[h] );
    printf("%d\n",res);
    return 0;
}
