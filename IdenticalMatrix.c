#include<stdio.h>
main()
{
    int row,col,i,j;
    printf("Enter the first matrix dimensions\n");
    scanf("%d",&row);
    scanf("%d",&col);
    int mat1[row][col];
    printf("\nEnter the first matrix\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat1[i][j]);
        }
    }
    int row1,col1;
    int check=0;
    printf("Enter the Second matrix dimensions\n");
    scanf("%d",&row1);
    scanf("%d",&col1);
    int mat2[row1][col1];
    printf("\nEnter the second matrix\n");
    for(i=0;i<row1;i++){
        for(j=0;j<col1;j++){
            scanf("%d",&mat2[i][j]);
        }
    }
    if(row!=row1 || col!=col1){
        printf("\nMatrices are not identical\n");
    }
    else{
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(mat1[i][j]!=mat2[i][j]){
                        printf("\nMatrices are not identical\n");
                        check=1;
                    break;
                }

            }
        }
    }
    if(check==0){
        printf("Matrices are identical");
    }

}
