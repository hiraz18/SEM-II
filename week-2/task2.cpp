#include <stdio.h>

// Define the structure to hold distance
struct Distance {
    int feet;
    float inch;
};

int main() {
    struct Distance d1, d2, sum;

    // Input for first distance
    printf("Enter 1st distance:\n");
    printf("Feet: ");
    scanf("%d", &d1.feet);
    printf("Inches: ");
    scanf("%f", &d1.inch);

    // Input for second distance
    printf("\nEnter 2nd distance:\n");
    printf("Feet: ");
    scanf("%d", &d2.feet);
    printf("Inches: ");
    scanf("%f", &d2.inch);

    // Adding distances
    sum.feet = d1.feet + d2.feet;
    sum.inch = d1.inch + d2.inch;

    // Logic: Convert inches to feet if inches >= 12
    while (sum.inch >= 12.0) {
        sum.inch = sum.inch - 12.0;
        sum.feet++;
    }

    // Displaying the result
    printf("\n--- Resulting Distance ---\n");
    printf("Total Distance: %d' %.1f\"\n", sum.feet, sum.inch);

    return 0;
}
