#include<stdio.h>
int main()
{
int s;
int a[50];
int min,max;
printf("Enter number of elements: ");
scanf("%d",&s);
for(int i=0;i<s;i++)
{
	printf("\nenter %d number:",i);
	scanf("%d",&a[i]);
}

for(int i=0;i<s;i++)
{
	min=a[0];
	if(min>a[i])
	{ 
	min=a[i];
	}
}
printf("\nmin value is %d",min);
for(int i=0;i<s;i++)
{
	max=a[0];
	if(max<a[i])
	{ 
	max=a[i];
	}
}
printf("\nmax value is %d",max);
}

