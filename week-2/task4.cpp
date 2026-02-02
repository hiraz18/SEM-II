#include <stdio.h>

// Define the structure for time
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function prototype
void calculateDifference(struct Time t1, struct Time t2, struct Time *diff);

int main() {
    struct Time start, end, diff;

    printf("Enter start time (HH:MM:SS): ");
    scanf("%d:%d:%d", &start.hours, &start.minutes, &start.seconds);

    printf("Enter end time (HH:MM:SS): ");
    scanf("%d:%d:%d", &end.hours, &end.minutes, &end.seconds);

    // Calculate difference (assuming end time is later than start time)
    calculateDifference(start, end, &diff);

    printf("\nTime Difference: %02d:%02d:%02d\n", diff.hours, diff.minutes, diff.seconds);

    return 0;
}

// Function to subtract start time from end time
void calculateDifference(struct Time t1, struct Time t2, struct Time *diff) {
    // Borrow 60 seconds if end seconds < start seconds
    if (t2.seconds < t1.seconds) {
        t2.minutes--;
        t2.seconds += 60;
    }
    diff->seconds = t2.seconds - t1.seconds;

    // Borrow 60 minutes if end minutes < start minutes
    if (t2.minutes < t1.minutes) {
        t2.hours--;
        t2.minutes += 60;
    }
    diff->minutes = t2.minutes - t1.minutes;

    diff->hours = t2.hours - t1.hours;
}
