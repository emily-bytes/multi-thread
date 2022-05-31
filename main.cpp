/**
 * This is a multi-threaded program using C++ that calculates various statistical
 * values for a list of numbers.
 */
#include <pthread.h>
#include <cstdio>

/* Global variables shared by worker threads */
float avg;
int min, max;
int size = 0;
int i;

/* Worker thread functions */
void* calcAvg(void *arg);
void* findMin(void *arg);
void* findMax(void *arg);

/**
 * This program takes a series of numbers on the command line and creates three separate
 * worker threads which calculate the average value and finds the minimum/maximum value.
 */
int main() {
    /* Determine number of elements (size of array) */
    printf("How many numbers would you like to process? ");
    scanf("%d", &size);

    /* Array to hold numbers */
    int nums[size];

    /* Read command line arguments into array */
    printf("Enter numbers: ");
    for(i = 0; i < size; i++){
        scanf("%d", &nums[i]);
    }

    /* Thread identifiers */
    pthread_t t1, t2, t3;

    /* Call threads */
    pthread_create(&t1, NULL, calcAvg, (void *) nums);
    pthread_create(&t2, NULL, findMin, (void *) nums);
    pthread_create(&t3, NULL, findMax, (void *) nums);

    /* Wait for worker threads to complete */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    /* Parent thread prints values */
    printf("The average value is %.0f\n", avg);
    printf("The minimum value is %d\n", min);
    printf("The maximum value is %d\n", max);

    return 0;
}

/* This function calculates the average value */
void* calcAvg(void *arg) {
    int *val = (int *) arg;
    int sum = 0;

    for(i = 0; i < size; i++)
    {
        sum += val[i];
        avg =  static_cast<float>(sum)/size;
    }
    pthread_exit(NULL);
}

/* This function finds the minimum value */
void* findMin(void *arg) {
    int *val = (int *) arg;
    int temp = val[0];
    for(i = 0; i < size; i++) {
        if (temp > val[i])
            temp = val[i];
    }
    min = temp;
    pthread_exit(NULL);
}

/* This function finds the maximum value */
void* findMax(void *arg) {
    int *val = (int *) arg;
    int temp = val[0];
    for(i = 0; i < size; i++) {
        if(temp < val[i])
            temp = val[i];
    }
    max = temp;
    pthread_exit(NULL);
}
