#include<stdio.h>
#define max 20
#define min 20
void input(int mat[max][min],int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
}
void create(int mat[max][min],int sparse[max][3],int row,int column)
{
    int k=1;
    sparse[0][0]=row;
    sparse[0][1]=column;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(mat[i][j]!=0)
            {
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2]=k-1;
}
void print(int sparse[max][3])
{
    int i;
    printf("row   column   values\n");
    printf("-----------------------\n");
    
    for(i=0;i<=sparse[0][2];i++)
    {
        if(i==1)
         printf("-----------------------\n");
         for(int j=0;j<3  ;j++){
             printf("%d\t",sparse[i][j]);
         }
         printf("\n");

    }
}

int main()
{
    int row,column;
    printf("enter the number of rows of matrix\n");
    scanf("%d",&row);
    printf("enter the number of columns of matrix\n");
    scanf("%d",&column);
    int mat[max][min],sparse[max][3];
    printf("enter the elements of matrix\n");
     input(mat,row,column);
    create(mat,sparse,row,column);
    print(sparse);
    return 0;
}
