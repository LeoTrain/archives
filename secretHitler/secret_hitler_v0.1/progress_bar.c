#include "lib.h"

void	progress_bar(int duration)
{
    int steps = 25;
    float step_duration = (float)duration / steps;
    int percent_step = 4;

    printf("\033[1;34m[");
    fflush(stdout);

    for (int i = 1; i <= steps; i++) {
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        int percent = i * percent_step;
        printf("]\033[1;34m %d%%\033[0m", percent);
        fflush(stdout);

        usleep(step_duration * 1000000);

        printf("\r\033[1;34m[");
        fflush(stdout);
    }
    printf("\033[0m\n");
}