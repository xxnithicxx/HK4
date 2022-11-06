#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
static int avg, max, min;

struct data
{
    int *arr;
    int size;
} dt;

void *average(void *parm)
{
    struct data *my_data = (struct data *)parm;
    int sum = 0;
    for (int i = 0; i < my_data->size; i++)
    {
        sum += my_data->arr[i];
    }

    avg = sum / my_data->size - 1;

    return NULL;
}

void* maximum(void * parm)
{
    struct data *my_data = (struct data *)parm;
    max = my_data->arr[0];
    for (int i = 0; i < my_data->size; i++)
        if (my_data->arr[i] > max)
            max = my_data->arr[i];
    return NULL;
}

void* minimum(void * parm)
{
    struct data *my_data = (struct data *)parm;
    min = my_data->arr[0];
    for (int i = 0; i < my_data->size; i++)
        if (my_data->arr[i] < min)
            min = my_data->arr[i];
    return NULL;
}

int main(int argc, char **argv)
{
    int n = argc;
    if (n == 0)
    {
        return -1;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = atoi(argv[i]);
    }

    dt.arr = arr;
    dt.size = n;

    pthread_t avgT, maxT, minT;
    if (pthread_create(&avgT, NULL, average, (void *)&dt) != 0)
        printf("Error creating thread");
    
    if (pthread_create(&maxT, NULL, maximum, (void *)&dt) != 0)
        printf("Error creating thread");

    if (pthread_create(&minT, NULL, minimum, (void *)&dt) != 0)
        printf("Error creating thread");

    pthread_join(avgT, NULL);
    pthread_join(maxT, NULL);
    pthread_join(minT, NULL);

    printf("Average: %d\n", avg);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}