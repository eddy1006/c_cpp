#include <stdio.h>
#include <time.h>
#include <stdbool.h>
int main()
{
    time_t start_t, end_t;
    double diff_t;

    printf("Starting of the program...\n");
    time(&start_t);
    while (true)
    {
        printf("Sleeping for 6 seconds...\n");
        sleep(6);
        break;
    }
    time(&end_t);
    diff_t = difftime(end_t, start_t);

    printf("Execution time = %f\n", diff_t);
    printf("Exiting of the program...\n");

    return (0);
}

