#include <stdio.h>
#include <time.h>

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double looping_fact(int n) {
    double result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    int number;
    clock_t start, end;
    double time_used;

    printf("Enter the number you want to find its factorial: ");
    scanf("%d", &number);

    // Measure time for recursive factorial multiple times and loop for more measurements
    start = clock();

    for (int i = 0; i < 10000; i++) {
        double x = factorial(number);
    }
    end = clock();
    time_used = ((double)(end - start));

    printf("The time taken in seconds (recursive) for multiple calculations is %f\n", time_used);

    // Measure time for looping factorial multiple times and loop for more
    start = clock();
    for (int i = 0; i < 10000; i++) {
        double x1 = looping_fact(number);
    }
    end = clock();
    time_used = ((double)(end - start));

    printf("The time taken in seconds (looping) for multiple calculations is %f\n", time_used);

    return 0;
}
