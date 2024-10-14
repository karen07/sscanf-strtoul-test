#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    int test_vals_size = 10000000;

    uint64_t *test_vals = (uint64_t *)malloc(test_vals_size * sizeof(uint64_t));
    char *hex_test_vals = (char *)malloc(test_vals_size * (sizeof(uint64_t) * 2 + 1));

    uint64_t *res_vals = (uint64_t *)malloc(test_vals_size * sizeof(uint64_t));

    for (int i = 0; i < test_vals_size; i++) {
        char *test_vals_p = (char *)&(test_vals[i]);
        for (int j = 0; j < (int)sizeof(uint64_t); j++) {
            test_vals_p[j] = rand();
        }

        sprintf(&(hex_test_vals[i * (sizeof(uint64_t) * 2 + 1)]), "%.16lx", test_vals[i]);
    }

    //sscanf
    struct timeval now_timeval_start;
    gettimeofday(&now_timeval_start, NULL);

    for (int i = 0; i < test_vals_size; i++) {
        sscanf(&(hex_test_vals[i * (sizeof(uint64_t) * 2 + 1)]), "%lx", &(res_vals[i]));
    }

    struct timeval now_timeval_end;
    gettimeofday(&now_timeval_end, NULL);

    uint64_t now_us_start = now_timeval_start.tv_sec * 1000000 + now_timeval_start.tv_usec;
    uint64_t now_us_end = now_timeval_end.tv_sec * 1000000 + now_timeval_end.tv_usec;

    printf("spend time 1  sscanf: %ld μs\n", now_us_end - now_us_start);

    for (int i = 0; i < test_vals_size; i++) {
        if (res_vals[i] != test_vals[i]) {
            printf("FUUCKKK sscanf %d\n", i);
        }
        res_vals[i] = 0;
    }

    //strtoul
    gettimeofday(&now_timeval_start, NULL);

    for (int i = 0; i < test_vals_size; i++) {
        res_vals[i] = strtoul(&(hex_test_vals[i * (sizeof(uint64_t) * 2 + 1)]), NULL, 16);
    }

    gettimeofday(&now_timeval_end, NULL);

    now_us_start = now_timeval_start.tv_sec * 1000000 + now_timeval_start.tv_usec;
    now_us_end = now_timeval_end.tv_sec * 1000000 + now_timeval_end.tv_usec;

    printf("spend time 1 strtoul: %ld μs\n", now_us_end - now_us_start);

    for (int i = 0; i < test_vals_size; i++) {
        if (res_vals[i] != test_vals[i]) {
            printf("FUUCKKK strtoul %d\n", i);
        }
        res_vals[i] = 0;
    }

    //sscanf
    gettimeofday(&now_timeval_start, NULL);

    for (int i = 0; i < test_vals_size; i++) {
        sscanf(&(hex_test_vals[i * (sizeof(uint64_t) * 2 + 1)]), "%lx", &(res_vals[i]));
    }

    gettimeofday(&now_timeval_end, NULL);

    now_us_start = now_timeval_start.tv_sec * 1000000 + now_timeval_start.tv_usec;
    now_us_end = now_timeval_end.tv_sec * 1000000 + now_timeval_end.tv_usec;

    printf("spend time 2  sscanf: %ld μs\n", now_us_end - now_us_start);

    for (int i = 0; i < test_vals_size; i++) {
        if (res_vals[i] != test_vals[i]) {
            printf("FUUCKKK sscanf %d\n", i);
        }
        res_vals[i] = 0;
    }

    //strtoul
    gettimeofday(&now_timeval_start, NULL);

    for (int i = 0; i < test_vals_size; i++) {
        res_vals[i] = strtoul(&(hex_test_vals[i * (sizeof(uint64_t) * 2 + 1)]), NULL, 16);
    }

    gettimeofday(&now_timeval_end, NULL);

    now_us_start = now_timeval_start.tv_sec * 1000000 + now_timeval_start.tv_usec;
    now_us_end = now_timeval_end.tv_sec * 1000000 + now_timeval_end.tv_usec;

    printf("spend time 2 strtoul: %ld μs\n", now_us_end - now_us_start);

    for (int i = 0; i < test_vals_size; i++) {
        if (res_vals[i] != test_vals[i]) {
            printf("FUUCKKK strtoul %d\n", i);
        }
        res_vals[i] = 0;
    }

    return 0;
}
