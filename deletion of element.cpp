#include<stdio.h>
int main()
{
int n,x,j;
int a[50];
int search;
int flag=0;
printf("Enter number of elements: ");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("enter %d number:",i);
scanf("%d",&a[i]);
}
printf("enter the number to deleted: ");
scanf("%d",&x);
for(int i=0;i<n;i++)
if (x==a[i])
for(j=i;j<n-1;j++)
{
	a[j]=a[j+1];
}
for(int i=0;i<n-1;i++)
{
printf("%d\n",a[i]);
}
}

