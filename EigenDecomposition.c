#include<stdio.h>
#include<math.h>
main()
{
    int siz,i,j,k,l;
    int res=0,res1=0;
    printf("Enter the size of matrix\n");
    scanf("%d",&siz);
    int mat[siz][siz];
    printf("\nEnter the matrix\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int eigval[siz];
    int eigvec[siz][siz];
    int a=0,b=0,c=0;
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){

        }
    }
    //finding coeefecient of lambda square
    for(i=0;i<siz;i++){
        a=a+mat[i][i];
    }
    printf("\na= %d\n",a);
    //finding the determinant

int finddet(){
    int smallmat[4];
    int count;
    for(i=0;i<siz;i++){
            count=0;
            for(j=1;j<siz;j++){
                    for(k=0;k<siz;k++){
                        if( k==i){
                            continue;
                        }
                        else{
                            smallmat[count]=mat[j][k];
                            count=count+1;

                        }
                    }




            }
            if(i==1){

        res=(smallmat[1]*smallmat[2])-smallmat[0]*smallmat[3];
            }

        else{
                    res=(smallmat[0]*smallmat[3])-smallmat[1]*smallmat[2];

        }
        res=res*mat[0][i];
        c=c+res;

    }
    return c;
}
c=finddet();
    /*
    for(i=0;i<4;i++){
        printf("%d",smallmat[i]);
    }
    printf("\n%d",b);
    */
printf("\nc=% d\n",c);//determinant is stored in c
//finding coeffecient of lambda in characterisitc equation
int smallmat[4];
    int count1;
    for(i=0;i<siz;i++){
            count1=0;



            for(j=0;j<siz;j++){
                    for(k=0;k<siz;k++){
                        if(j==i || k==i){
                            continue;
                        }
                        else{
                            smallmat[count1]=mat[j][k];
                            count1=count1+1;

                        }
                    }




            }

                    res1=(smallmat[0]*smallmat[3])-smallmat[1]*smallmat[2];



        b=b+res1;

    }

    printf("\nb= %d\n",b);
    //finding eigen values
     int calc=1,calc1=1,count2,count3;
    count2=0;
    count3=0;

    for(i=0;i>=0;i++){
        calc=pow(i,3)-a*pow(i,2)+b*i-c;
        if(i!=0){
        calc1=pow((-i),3)-a*pow(-i,2)+b*(-i)-c;
        }
        if(calc==0){
            eigval[count2+count3]=i;
            count2=count2+1;
        }
        if(calc1==0){
            eigval[count2+count3]=-i;
            count3=count3+1;
        }
        if((count2+count3)==siz){
            break;
        }
    }
    for(i=0;i<siz;i++){
        printf("Eigen value %d = %d\n",i,eigval[i]);
    }
    //Creating A-Lambda(I) matrices for each eigen value and finding the eigen vectors
    int mat1[siz][siz],mat2[siz][siz],mat3[siz][siz];
    int smallmat1[4];
    for(k=0;k<siz;k++){

   //creating matrix for a particular eigen value
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            mat1[i][j]=mat[i][j];
            if(i==j){
                mat1[i][j]=mat1[i][j]-eigval[k];
            }
        }
    }
    //creating vectors for a particular matrix of a particular eigen value
    int count;
    for(l=0;l<siz;l++){
            count=0;
    for(i=0;i<siz-1;i++){
        for(j=0;j<siz;j++){

            if(j==l){
                continue;
            }
            smallmat1[count]=mat1[i][j];
            count=count+1;
        }

    }
    if(l!=1){
    eigvec[l][k]=(smallmat1[0]*smallmat1[3])-(smallmat1[1]*smallmat1[2]);
    }else{
    eigvec[l][k]=(smallmat1[1]*smallmat1[2])-(smallmat1[0]*smallmat1[3]);

    }

     }
    }
    printf("\nPrinting matrix containing all eigen vectors....\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%d ",eigvec[i][j]);
        }
        printf("\n");
    }
    //simplifying the eigen vectors  by dividing with hcf of each eigen vector
    int oldest,older,current,hcfval,max;

    for(j=0;j<siz;j++){

            //printf("\nEigen vectors of %dth eigen value are: \n",j);
        for(i=0;i<siz;i++){
            current=eigvec[i][j];
            if(i>0){
                older=eigvec[i-1][j];
            }
            if(i>1){
                oldest=eigvec[i-2][j];
            }
        }
   // printf("%d %d %d",oldest,older,current);
    if(current>=oldest && current>=older){
        max=current;
    }else if(older>=oldest && older>=current){
    max=older;
    }else{
    max=oldest;
    }
    hcfval=1;

        for(i=1;i<=max;i++){
            if(current%i==0 && (older%i==0 && oldest%i==0)){
                hcfval=i;


            }
        }

        for(i=0;i<siz;i++){
            eigvec[i][j]=eigvec[i][j]/hcfval;

        }
    }
    printf("\n Given matrix A = PDP(Inverse)\n");
    printf("\nModal Matrix P is .....\n");
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            printf("%d ",eigvec[i][j]);
        }
        printf("\n");
    }
    printf("\nDiagonal matrix D is .......\n");
    int dig[siz][siz];
    for(i=0;i<siz;i++){
        for(j=0;j<siz;j++){
            dig[i][j]=0;
            if(i==j){
                dig[i][j]=eigval[i];
            }
            printf("%d ",dig[i][j]);
        }
        printf("\n");
    }
    printf("\nP(Inverse) is ........\n");
    //Finding inverse
    double inv[siz][2*siz];
    int arr[siz];
    for(i=0;i<siz;i++){
        for(int j=0;j<siz;j++){

            inv[i][j]=eigvec[i][j];
            if(i==j){
                inv[i][j+siz]=1;
            }
            else{
                inv[i][j+siz]=0;
            }

        }

    }
    for(int i=0;i<siz;i++){

        for(j=0;j<siz;j++){
            if(i!=j){
                double ratio=inv[j][i]/inv[i][i];
                for(k=0;k<2*siz;k++){
                    inv[j][k]=inv[j][k]-ratio*inv[i][k];
                }
            }
        }


    }
    for(int i=0;i<siz;i++){
        for(int j=siz;j<2*siz;j++){
            inv[i][j]=inv[i][j]/inv[i][i];
        }
    }
    for(int i=0;i<siz;i++){
        for(int j=siz;j<2*siz;j++){
            printf("%f ",inv[i][j]);
        }
        printf("\n");
    }


}

