#include <stdio.h>
main(){
printf(" Enter the size of matrix");
int siz;
scanf("%d",&siz);
int mat[siz][siz+1];
printf("Enter the contents of the matrix\n");
int i,j,k;
for(i=0;i<siz;i++){
    for(j=0;j<=siz;j++){
            if(j==siz){
                printf("Enter the value on the RHS of equal to sign");
            }
        scanf("%d",&mat[i][j]);
    }
}

int trans[siz];

for(k=siz-1;k>=0;k--){
for(i=siz-1;i>=0;i--){
    trans[i]=mat[i][k];//k=0
}

for(i=(k-1);i>=0;i--){//i=0
    for(j=siz;j>=0;j--){
            //if((trans[i] >0 && mat[0][0]>0)|| (trans[i] <0 && mat[0][0]<0)){
                mat[i][j]=mat[i][j]*mat[k][k] - mat[k][j]*trans[i];
           // }
           // else{
            //    mat[i][j]=(mat[i][j])*mat[0][0] + mat[0][j]*trans[i];
           // }
            //printf("%d ",mat[i][j]);

    }
   // printf("\n");
}
/*
for(i=0;i<siz;i++){
trans[i]=mat[i][k];//k=1
}
for(i=2;i<siz;i++){
    for(j=0;j<=siz;j++){

            //if((trans[i] >0 && mat[1][1]>0)|| (trans[i] <0 && mat[1][1]<0)){
                mat[i][j]=mat[i][j]*mat[1][1] - mat[1][j]*trans[i];
            //}
           // else{
           //     mat[i][j]=(mat[i][j])*mat[1][1] + mat[1][j]*trans[i];
           // }
           // printf("%d ",mat[i][j]);

    }
  // printf("\n");
}
*/
}
printf("Lower Triangular matrix is........\n");
for(i=0;i<siz;i++){
    for(j=0;j<=siz;j++){
            if(j==siz){
                printf(" : ");
            }
        printf("%d ",mat[i][j]);
    }
    printf("\n");
}
for(i=0;i<siz;i++){
    trans[i]=0;
}
for(i=0;i<siz;i++){
        trans[i]=mat[i][siz];
    for(j=0;j<siz;j++){
        //if(j==size-1){
        if(i==j){
            continue;
        }
        else{
        trans[i]=trans[i]-(mat[i][j]*trans[j]);
        }
       // }
       // else{

       // }
    }

    trans[i]=trans[i]/mat[i][i];
}
printf("a=%d, b=%d, c=%d",trans[0],trans[1],trans[2]);
}
