#include <stdio.h>
#include <math.h>

int calculateDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

int isArmstrong(int number) {
    int originalNumber = number;
    int digits = calculateDigits(number);
    int sum = 0;

    while (number != 0) {
        int remainder = number % 10;
        sum += pow(remainder, digits);
        number /= 10;
    }

    return (sum == originalNumber);
}

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number)) {
        printf("%d is an Armstrong number.\n", number);
    } else {
        printf("%d is not an Armstrong number.\n", number);
    }

    return 0;
}

