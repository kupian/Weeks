#include <stdio.h>
#include <time.h>

/*
A program to calculate the number of whole weeks between two dates
*/

void convertDate(char* str, struct tm *date);
int weeksFromSeconds(double seconds);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: weeks DD/MM/YY DD/MM/YY\n");
        return 1;
    }

    struct tm startDate = {0};
    struct tm endDate = {0};

    convertDate(argv[1], &startDate);
    convertDate(argv[2], &endDate);

    time_t startTime = mktime(&startDate);
    time_t endTime = mktime(&endDate);

    if (startTime == -1 || endTime == -1) {
        printf("Error reading date\n");
        return 2;
    }

    double difference = difftime(endTime, startTime);
    int weeks = weeksFromSeconds(difference);

    printf("%d\n", weeks);

    return 0;
}

/*
Convert a dd/mm/yy or dd/mm/yyyy string into a tm struct
*/
void convertDate(char* str, struct tm *date) {
    int year;
    int month;
    int day;

    sscanf(str, "%d/%d/%d", &day, &month, &year);

    if (year < 100) {
        // handle YYYY input
        year += 2000;
    }

    date->tm_year = (year+2000)-1900;
    date->tm_mon = month-1;
    date->tm_mday = day;
}

int weeksFromSeconds(double seconds) {
    int weeks = seconds / 60 / 60 / 24 / 7;
    return weeks;
}