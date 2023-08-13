#include<stdio.h>
int main()
{
	int s;
	int a[50];
	int search;
	int flag=0;
	printf("enter the number of elements:");
	scanf("%d",&s);
	for(int i=0;i<s;i++)
	{
		printf("\nenter %d elements:",i);
		scanf("%d",&a[i]);
	}
	printf("\nenter the number to be searched:");
	scanf("%d",&search);
	for(int i=0;i<s;i++)
	{
		if (search==a[i])
		{
			printf("\n%d is  %d element",search,i);
			flag=1;
		}
	}
	if(flag==0)
	printf("number is not available");
}



OUTPUT
enter the number of elements:5
enter 0 elements:12
enter 1 elements:34
enter 2 elements:56
enter 3 elements:23
enter 4 elements:2

enter the number to be searched:4
number is not available
--------------------------------
Process exited after 17.34 seconds with return value 0
Press any key to continue . . .
