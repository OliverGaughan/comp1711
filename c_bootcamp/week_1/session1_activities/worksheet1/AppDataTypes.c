#include <stdio.h>

int main() {
    int numOfDays;
    float speedOfLight = 186282;
    float secondsInADay = 86400;
    float distanceTravelled;

    printf("Enter the number of days: ");
    scanf("%d", &numOfDays);

    distanceTravelled = (speedOfLight*secondsInADay) * numOfDays;

    printf("In %d days, light travels %f miles per second!\n", numOfDays, distanceTravelled);

    return 0;
}