#include <stdio.h>
#define N 3
int main(){
    int m1[N][N] = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    int m2[N][N];
    int x, y;
    for(x=0; x < N; x++){
       for(y=0; y < N; y++){
            if (m1[x][y]%2 == 0){
                m2[x][y] = 0;
            }else{
                m2[x][y] = 1;
            }
       }
    }
    //printf("%d , %d , %d", m2[0][0], m2[1][1], m2[2][2]);
}
