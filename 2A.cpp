#include <stdio.h>
 
using namespace std;
 
int mat[105][105];
 
int main(){
    freopen( "adjacency.in","r",stdin );
    freopen( "adjacency.out","w",stdout );
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&a,&b);
        a--,b--;
        mat[a][b] = mat[b][a] = 1;
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j!=0) printf(" ");
            printf("%d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
