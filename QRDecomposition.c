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
    double copmat[siz][siz];
    for(i=0;i<siz;i++){
            for(j=0;j<siz;j++){
        copmat[i][j]=mat[i][j];

            }
    }
    //function for the dot product of 2 vectors
    double vectdot(double arr1[][siz],double arr2[][siz],int n,int m){
        int res=0;
        int x;

        for(x=0;x<siz;x++){
            res=res+arr1[x][n]*arr2[x][m];
        }
        return res;

    }
    //finding the orthogonal vectors and storing them in copmat
    double stor[siz];
    for(j=1;j<siz;j++){
            for(k=j;k>0;k--){


            stor[j-1]=vectdot(copmat,copmat,j,k-1);//mat->copmat
            stor[j]=vectdot(copmat,copmat,k-1,k-1);//mat->copmat
            stor[j+1]=stor[j-1]/stor[j];

        for(i=0;i<siz;i++){
                copmat[i][j]= copmat[i][j]-stor[j+1]*copmat[i][k-1];

        }
        }
    }
    //turning copmat into orthonormal matrix by divifing each vector y its norm. copmat becomes Q
    printf("\nORTHOGONAL bases matrix is ......\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",copmat[i][j]);
        }
        printf("\n");
    }
    double resi;
    for(j=0;j<siz;j++){
            resi=0;
        for(i=0;i<siz;i++){
            resi=resi+(copmat[i][j]*copmat[i][j]);
        }
        resi=sqrt(resi);
        for(i=0;i<siz;i++){
            copmat[i][j]=copmat[i][j]/resi;
        }
    }
    //Finding R. R=Transpose of Q into A
    double r[siz][siz];
    double qt[siz][siz];
    double matmul(double arr1[][siz],int arr2[][siz],int n,int m){
        double result=0;
        int x;

        for(x=0;x<siz;x++){
            result=result+arr1[n][x]*arr2[x][m];
        }
        return result;

    }
    //finding Q transpose
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            qt[i][j]=copmat[j][i];
        }
    }
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            r[i][j]=matmul(qt,mat,i,j);
        }
    }
    printf("\na=QXR\n");
    printf("\nQ matrix is .....\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",copmat[i][j]);
        }
        printf("\n");
    }
    printf("\nQT matrix is ......\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",qt[i][j]);
        }
        printf("\n");
    }
    printf("\nR matrix is ......\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%f ",r[i][j]);
        }
        printf("\n");
    }
    /*
    int v1[siz],v2[siz],v3[siz];
    for(i=0;i<siz;i++){
        v1[i]=mat[i][0];
        v2[i]=mat[i][1];
        v3[i]=mat[i][2];
    }
    int y1[siz],y2[siz],y3[siz];
    */


}
