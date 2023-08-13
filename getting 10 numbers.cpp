#include <stdio.h>
int main() 
{
int num[10];
for (int i = 0; i < 10; i++) {
printf("Enter number %d: ", i + 1);
scanf("%d", &num[i]);
}
printf("You entered: ");
for (int i = 0; i < 10; i++) {
printf("%d ", num[i]);
}
return 0;
}

