#include <stdio.h>

// Declare the assembly functions
extern int factorial(int n);
extern int fibonacci(int n);

// Helper function for testing
void test(const char* name, int (*func)(int), int input, int expected) {
    int result = func(input);
    if (result == expected) {
        printf("[PASS] %s(%d) = %d\n", name, input, result);
    } else {
        printf("[FAIL] %s(%d) = %d (expected %d)\n", name, input, result, expected);
    }
}

int main() {
    printf("Running unit tests...\n");

    // Test factorial
    test("factorial", factorial, 5, 120);  // 5! = 120
    test("factorial", factorial, 0, 1);    // 0! = 1

    // Test Fibonacci
    test("fibonacci", fibonacci, 10, 55); // Fib(10) = 55
    test("fibonacci", fibonacci, 0, 0);   // Fib(0) = 0

    return 0;
}
