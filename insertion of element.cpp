#include<stdio.h>
int main()
{
int n,ele,x,j;
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
printf("Enter the number to inserted: ");
scanf("%d",&ele);
printf("Enter the position to inserted: ");
scanf("%d",&x);
for(j=n-1;j>=x;j--)
{
	a[j+1]=a[j];
}
a[j+1]=ele;

for(int i=0;i<n+1;i++)
{
printf("%d\n",a[i]);
}
}


