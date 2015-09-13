#include <bits/stdc++.h>
 
using namespace std;
 
map<int,int> check;
int a;
char cad[100005];
int homo , hetero;
int dif , igual;
 
int main(){
    freopen( "homo.in" , "r" , stdin );
    freopen( "homo.out" , "w" , stdout );
    int n,a;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("\n%s %d",cad,&a);
        if(cad[0]=='i'){
            if(check[a]==1) igual++;
            else if(check[a]==0) dif++;
            check[a]++;
        }
        else{
            if(check[a]==1) dif--;
            else if(check[a]==2) igual--;
            if(check[a]>0) check[a]--;
        }
        if(dif>=2 && igual>=1) printf("both\n");
        else if(dif>=2) printf("hetero\n");
        else if(igual>=1) printf("homo\n");
        else printf("neither\n");
    }
    return 0;
}
