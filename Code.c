#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define max 9001

int adj_mat [max][max];
int main()
{
int i,j,n,degA,degB,edge=0,sum=0;
double total_time;
clock_t start,end;
printf("How many vertices?:\n");
scanf("%d",&n);
srand(2);
start=clock();
for(i=1;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        adj_mat[i][j]=rand()%2;
        if(adj_mat[i][j]==1&&i!=j)
        {
            adj_mat[j][i]=1;
        }
        else if(adj_mat[i][j]==0&&i!=j)
        {
            adj_mat[j][i]=0;
        }
        else if(i==j)
        {
            adj_mat[j][i]=0;
        }
    }
}
printf("\n\nMatrix:\n\n");
for(i=0;i<n;i++)
 {

 for(j=0;j<n;j++)
{
printf("%d  ",adj_mat[i][j]);
}
printf("\n");

}

for(i=0;i<n;i++)
{
    degA=0;
    degB=0;
    for(j=0;j<n;j++)
    {
        if(adj_mat[i][j]==1)
        {
            degA++;
        }
        if(i==j&&adj_mat[i][j]==1)
        {
            degB++;
        }
        if(adj_mat[i][j]==1&&i>=j)
        {
            edge++;
        }

    }
    sum+=degA+degB;
}
printf("\n\nThe Total Degres is: %d\n",sum);
printf("\n\nThe Total edge is: %d\n",edge);
printf("\n\nThe Number of edge is=(Sum of degree/2)=(%d/2)=%d" ,sum,sum/2);
printf("\n\nSo the handshaking theorem is proved\n\n");


end=clock();
    total_time=((double)(end-start)/CLOCKS_PER_SEC)*pow(10,9);

     printf("\nExecution time is : %1f ns \n",total_time);
     printf("\n");

}


