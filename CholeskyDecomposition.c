#include <stdio.h>
#include <math.h>

main()
{
    printf("Enter the size: \n");
    int siz;
    scanf("%d",&siz);
    int mat[siz][siz];
    printf("Enter the values: \n");
    int i,j,k;
    for(i=0;i<siz;i++){
            for(j=0;j<siz;j++){
        scanf("%d",&mat[i][j]);

            }
    }
    for(i=0;i<siz;i++){
            for(j=0;j<siz;j++){
        if(mat[i][j]!=mat[j][i]){
            printf("Not a symmetric matrix. CHELOSKY DECOMPOSITION CANT BE APPLIED");
            break;
        }

            }
    }

    int trans[siz*siz];
    int l[siz][siz];
    int lt[siz][siz];
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            lt[i][j]=0;
            l[i][j]=0;
        }
    }
    int matmul(int arr1[][siz],int arr2[][siz],int n,int m){
        int res=0;
        int x;

            for(x=0;x<siz;x++){
                res=res+arr1[n][x]*arr2[x][m];
            }
            return res;

}
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            //going by the template of L transpose for the order in which we get the solutions
            if(i==j){
            lt[i][j]=sqrt(mat[i][j]-(matmul(l,lt,i,j)));

            }
            else if(j>i){
                lt[i][j]=(mat[i][j]-matmul(l,lt,i,j))/lt[i][j-(j-i)];
               // printf("%d \n",lt[i][j-1]);
            }
            else{
                //lt[i][j]=lt[j][i];
                 lt[i][j]=0;
            }
           // printf("%d ",lt[i][j]);
           l[j][i]=lt[i][j];

        }
        //printf("\n");
    }
    printf("Given matrix mat = LXL(transpose)\n");
    printf("L transpose matrix is : \n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%d ",lt[i][j]);
        }
        printf("\n");
    }
    //printf("%d",matmul(l,lt,1,1));
    printf("L matrix is : \n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%d ",l[i][j]);
        }
        printf("\n");
    }

}
