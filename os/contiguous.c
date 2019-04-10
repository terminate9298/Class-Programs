#include<stdio.h>
int main()
{
int f[50],i,st,j,len,c,k;
for(i=0;i<50;i++)
f[i]=0;
do{
printf("\n Enter the starting block & length of file");
scanf("%d%d",&st,&len);
for(j=st;j<(st+len);j++)
{
if(f[j]==0)
{
f[j]=1;
printf("\t%d->%d",j,f[j]);
}
else
{
printf("\nBlock already allocated");
break;
}
}
if(j==(st+len))
printf("\n the file is allocated to disk");
printf("\n if u want to enter more files?(y-1/n-0)");
scanf("%d",&c);
}while(c!=0);
printf("\nAllocated blocks are:\n");
for(i=0;i<=j;i++)
{
if(f[i]==1)
printf("%d ", i);}
printf("\n");
return 0;
}
