#include<stdio.h>
main()
{
    int row,col,i,j,num;
    printf("Enter the matrix dimensions\n");
    scanf("%d",&row);
    scanf("%d",&col);
    int mat[row][col];
    printf("\nEnter the matrix\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int check=0;
    int tot=0;
    printf("Enter the no. you wish to search in the matrix\n");
    scanf("%d",&num);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(mat[i][j]==num){
                printf("The same number found in the matrix in row %d and column %d\n",i,j);
                check=1;
                tot=tot+1;
            }
        }
    }
    if(check==0){
        printf("The given number is not present in the matrix");
    }
    else{
        printf("A total of %d similar numbers were found in the matrix\n",tot);
    }
}
