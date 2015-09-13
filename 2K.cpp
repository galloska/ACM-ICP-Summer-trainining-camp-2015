#include <stdio.h>
#include <vector>
 
using namespace std;
 
int memo[15][(1<<11)][(1<<5)];
int dist[(1<<11)][(1<<11)];
char cad[15][15];
int mascara[15];
vector<int> pos;
 
int grilla(int i,int j){
    if(i>=0 && i<3 && j<=0 && j<3) return 1;
    if(i>=0 && i<3 && j>=3 && j<6) return 2;
    if(i>=0 && i<3 && j>=6 && j<9) return 3;
 
    if(i>=3 && i<6 && j<=0 && j<3) return 4;
    if(i>=3 && i<6 && j>=3 && j<6) return 5;
    if(i>=3 && i<6 && j>=6 && j<9) return 6;
 
    if(j<=0 && j<3) return 7;
    if(j>=3 && j<6) return 8;
    if(j>=6 && j<9) return 9;
}
 
int Obtener(int i){
    return mascara[i];
}
 
int DP(int fila,int mask_col,int mask_grill){
    //if(fila==9) printf("%d %d\n",mask_col,mask_grill);
    if(fila==9 && mask_col==0 && mask_grill==0){
        //printf("SI\n");
        return 0;
    }
    if(fila==9) return 1<<30;
 
    if(fila==3 && mask_grill==0)
        mask_grill = 0;//estados[1];
    else if(fila==3) return 1<<30;
    else if(fila==6 && mask_grill==0)
        mask_grill = 0;//estados[2];
    else if(fila==6) return 1<<30;
    if(memo[fila][mask_col][mask_grill]!=-1) return memo[fila][mask_col][mask_grill];
    //printf("%d\n",fila);
    //getchar();
 
    int res = 1<<30,a=0,b=0,c=0;
 
    for(int i=0;i<pos.size();i++){
        for(int j=0,h=8;j<9;j++,h--){
            if(j<3){
                if(j==0) a = (pos[i]&(1<<h)) ? 1 : 0;
                else a ^= (pos[i]&(1<<h)) ? 1 : 0;
            }
            else if(j<6){
                if(j==3) b = (pos[i]&(1<<h)) ? 1 : 0;
                else b ^= (pos[i]&(1<<h)) ? 1 : 0;
            }
            else{
                if(j==6) c = (pos[i]&(1<<h)) ? 1 : 0;
                else c ^= (pos[i]&(1<<h)) ? 1 : 0;
            }
        }
        //printf("%d %d %d\n",fila + 1 , mask_col^pos[i] , );
        int num = (a<<2)+(b<<1)+c;
        res = min( res , DP( fila + 1 , mask_col^pos[i] , mask_grill^(num) ) + dist[Obtener(fila)][pos[i]] );
    }
    //printf("Paso\n");
 
    return memo[fila][mask_col][mask_grill] = res;
}
 
int main(){
    freopen( "bsudoku.in","r",stdin );
    freopen( "bsudoku.out","w",stdout );
    for(int i=0;i<9;i++)
        scanf("\n%s",cad[i]);
 
    for(int i=0;i<(1<<9);i++){
        int cont = 0;
        for(int j=0;j<9;j++)
            if(i&(1<<j))
                cont++;
        if(cont&1) continue;
        pos.push_back(i);
    }
    //printf("%d\n",(int)pos.size());
 
    for(int i=0;i<9;i++){
        int mask = 0;
        for(int j=0,h=8;j<9;j++,h--)
            if(cad[i][j]=='1')
                mask += 1<<h;
        mascara[i] = mask;
    }
 
    for(int i=0;i<(1<<9);i++){
        for(int j=i+1;j<(1<<9);j++){
            int cont = 0;
            for(int h=0;h<9;h++){
                int a = (i&(1<<h)) ? 1 : 0;
                int b = (j&(1<<h)) ? 1 : 0;
                if(a!=b) cont++;
            }
            dist[i][j] = dist[j][i] = cont;
        }
    }
 
    for(int i=0;i<=9;i++)
        for(int j=0;j<=(1<<9);j++)
            for(int h=0;h<=(1<<3);h++)
                memo[i][j][h] = -1;
 
    printf("%d\n",DP( 0 , 0 , 0));//estados[0] ));
    return 0;
}
