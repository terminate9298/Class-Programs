#include<stdio.h>
void main()
{
    int i, n, total=0;
    float avg=0;
    printf("\nEnter number of Processes:");
    scanf("%d", &n);
    int process[n],wtime[n],ptime[n];
    for(i=0;i<n;i++)
    {
        printf("\nEnter Process %d ID:",i+1);
        scanf("%d", &process[i]);
        printf("\nEnter Process %d Wait Time:",i+1);
        scanf("%d",&ptime[i]);
    }
    wtime[0]=0;
    for(i=1;i<n;i++)
    {
        wtime[i]=wtime[i-1]+ptime[i-1];
        total=total+wtime[i];
    }
    avg=(float)total/n;
    printf("\nP_ID\t P_TIME\t W_TIME\n");
    for(i=0;i<n;i++)
        printf("%d\t %d\t %d\n",process[i],ptime[i],wtime[i]);
    printf("\nTotal Waiting Time: %d \nAverage Waiting Time: %f \n", total, avg);
    
}
