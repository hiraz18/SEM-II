#include <stdio.h>

// Define the structure for complex numbers
typedef struct {
    float real;
    float imag;
} complex;

// Function prototype using pointers for efficiency
void addComplex(complex *n1, complex *n2, complex *result);

int main() {
    complex num1, num2, result;

    // Input for the first number
    printf("Enter real and imaginary parts for 1st number: ");
    if (scanf("%f %f", &num1.real, &num1.imag) != 2) return 1;

    // Input for the second number
    printf("Enter real and imaginary parts for 2nd number: ");
    if (scanf("%f %f", &num2.real, &num2.imag) != 2) return 1;

    // Pass addresses using the '&' operator
    addComplex(&num1, &num2, &result);

    // Logic to print the sign correctly
    if (result.imag >= 0) {
        printf("\nSum = %.1f + %.1fi\n", result.real, result.imag);
    } else {
        // Use -result.imag to turn the negative number positive for display
        printf("\nSum = %.1f - %.1fi\n", result.real, -result.imag);
    }

    return 0;
}

// Function using pointers to access memory addresses directly
void addComplex(complex *n1, complex *n2, complex *result) {
    // We use the '->' operator to access structure members via pointers
    result->real = n1->real + n2->real;
    result->imag = n1->imag + n2->imag;
}
