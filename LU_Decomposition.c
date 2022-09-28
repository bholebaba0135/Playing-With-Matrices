#include<stdio.h>
#include<math.h>
main()
{
    //Getting a matrix
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
    //Creating L and U matrices
    double l[siz][siz];
    double u[siz][siz];
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            if(i==j){
                l[i][j]=1;
            }
            else{
                l[i][j]=0;
            }

            u[i][j]=0;
        }
    }
    //matrix multiplication function
    double matmul(double arr1[][siz],double arr2[][siz],int n,int m){
        double res=0;
        int x;

        for(x=0;x<siz;x++){
            res=res+arr1[n][x]*arr2[x][m];
        }
        return res;

    }
    //creating the solution matrix with values of variables of both L and U matrices
    double resi[siz][siz];
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
                if(l[i][j]!=0 && i<=j  ){ //l[i][j]!=1
                    resi[i][j]=(mat[i][j]-matmul(l,u,i,j))/l[i][j];

                }
                else if(u[i][j]==0 && i>j){
                    resi[i][j]=(mat[i][j]-matmul(l,u,i,j))/u[i-(i-j)][j];
                }
                else{
                    resi[i][j]=(mat[i][j]-matmul(l,u,i,j));
                }
               // printf("%f ",resi[i][j]);
               //printf("%f",matmul(l,u,i,j));
                if(i>j){
                    l[i][j]=resi[i][j];
                }
                else{
                    u[i][j]=resi[i][j];
                }



        }
       // printf("\n");
    }

    //printing result matrix
    /*
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",resi[i][j]);
        }
        printf("\n");
    }
    */
    printf("\nA=LXU\n");
    printf("Matrix L is ..........\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",l[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix U is ..........\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",u[i][j]);
        }
        printf("\n");
    }


}
