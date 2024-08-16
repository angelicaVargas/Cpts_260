/* Name: Angelica Vargas
 * Class: CPTS 260
 * Assignment: Homework 3 - testing CPU speed
*/

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
//#define cache_size (8 * 1024 * 1024)

double test_speed(int cache_size) {

    double five_tries[5];         // initializing array with # of tries
    struct timeval start_time;    // initializing start_time of search
    struct timeval end_time;      // initializing end_time of search
    int i, j;  // variables used for loops
    double avg = 0.0, total = 0.0;  // variables used to collect time (microsec)

    for(i = 0; i < 5; i++) {                // loop to record time
        gettimeofday(&start_time, NULL);    // start timer
	// allocate memory, where you are writing to
	char *space = (char*)malloc(cache_size);    // dynamically allocate size of cache 
	
	    for(j = 0; j < cache_size; j++) {    //
            space[j] = 'a';    // writing char 'a' to memory
            }

        gettimeofday(&end_time, NULL);      // ending the timei
	free(space);    // releasing memory in space

        five_tries[i] = ((cache_size)/(end_time.tv_usec - start_time.tv_usec));  //start and end to microseconds
        total += five_tries[i];  // finding total - adding up time after each iteration
        }
    
    avg = total/5;           // finding average

    return avg;
}

int main() {
    // 1KB to bit = 1 * 1024
    // 1MB to bit = 1 * 1024 * 1024

    // testing L1 which is 1KB
    printf("L1 average speed: %.3f GHz. \n", test_speed(1 * 1024));
    
    // testing L2 which is 3KB
    printf("L1 average speed: %.3f GHz. \n", test_speed(3 * 1024));
    
    // testing L3 which is 8MB
    printf("L1 average speed: %.3f GHz. \n", test_speed(8 * 1024 * 1024));
    
    return 0;
}
