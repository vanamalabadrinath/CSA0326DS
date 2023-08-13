#include<stdio.h>
int main()
{
int sum;
int i,a[5];
for(i=0;i<5;i++)
{
printf("enter the %d value:",i);
scanf("%d",&a[i]);
}
for(i=0;i<5;i++)
{
sum=sum+a[i];	
}
printf("%d\n",sum);
return 0;
}

