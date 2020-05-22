#include <stdio.h>

int queen[6][6];
int check_queen(int x,int y){
    int k;
    for(k=-5;k<=5;k++){
        if(0<=x+k&&x+k<6)   if(queen[x+k][y]==1)   return 0;
        if(0<=y+k&&y+k<6)   if(queen[x][y+k]==1)   return 0;
        if(0<=x+k&&x+k<6&&0<=y+k&&y+k<6)    if(queen[x+k][y+k]==1)   return 0;
        if(0<=x+k&&x+k<6&&0<=y-k&&y-k<6)    if(queen[x+k][y-k]==1)   return 0;
    }
    return 1;
}

int main(void){
    int i,j,x,y;
    while(1){
        printf("%s %d %d %d %d %d %d\n"," ",1,2,3,4,5,6);
        for(i=0;i<6;i++){
            printf("%d ",i+1);
            for(j=0;j<6;j++){
                printf("%d ",queen[j][i]);
            }
            printf("\n");
        }
        printf("x=");
        scanf("%d",&x);
        if(x<1||6<x){
            printf("1<=x<=6の範囲で入力してください\n");
            continue;
        }
        printf("y=");
        scanf("%d",&y);
        if(y<1||6<y){
            printf("1<=y<=6の範囲で入力してください\n");
            continue;
        }
        if(check_queen(x-1,y-1)==0){
            printf("false\n");
        }else if(check_queen(x-1,y-1)==1){
            queen[x-1][y-1]=1;
            printf("success\n");
        }
    }
    return 0;
}
