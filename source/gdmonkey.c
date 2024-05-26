#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <curl/curl.h>
#include <string.h>

#define LEVEL_COUNT 1508 // Length of the level in frames, the first part of SM is 1508 frames long
#define MAX_CLICKS 100
#define CHANCE 10 // Chance monkey clicks in a frame: 1/CHANCE (By default, 1/10)

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

// Gets a true random int from random.org
int truerand() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1);
    chunk.size = 0;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.random.org/integers/?num=1&min=1&max=1000000000&col=1&base=10&format=plain&rnd=new");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    int randomInt = atoi(chunk.memory);
    free(chunk.memory);
    printf("Setting new rseed: %d\n\n", randomInt);

    return randomInt;
}


int main() {
    printf("\n-- STARTING GDMONKEY --\n      by: GDNacho\n\n");
    srand(truerand()); // Seeds rand()

    long long unsigned int attempts = 0;
    long long unsigned int total_time = 0;
    // level_array stores each frame of Stereo Madness
    int level_array[LEVEL_COUNT] = {25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,25,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,33,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,-2,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,22,22,22,22,22,22,22,22,22,22,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,28,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,15,15,15,15,15,15,15,15,15,15,15,15,15,-2,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,15,15,15,15,15,15,15,15,15,15,15,-2,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,32,0,0,0,0,0,0,0,0,0,0,0,0,28,28,28,28,28,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,-1,-1,-1,-1,-1,-1,-1,-1,30,30,30,30,30,30,30,30,30,30,30,30,30,30,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,28,28,28,28,28,28,28,28,28,28,28,28,28,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,28,28,28,28,28,28,28,28,28,28,28,28,28,28,-2,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,22,-2,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    bool completed = false;
    unsigned int attempt_clicks[MAX_CLICKS]; // Stores where the monkey clicked during the attempt
    unsigned int attempt_clicks_size;
    unsigned int record = 0; // As in monkey's personal best
    sleep(1);

    while (!completed) {
        attempts++;
        int airborn = 0;
        attempt_clicks_size = 0;
        completed = true;

        for (int i = 0; i < LEVEL_COUNT; ++i) {
            bool click = (airborn < 1 && rand() % CHANCE == 0); // 1 in CHANCE chance of the monkey clicking
            if (click) {
                // Monkey clicked
                attempt_clicks[attempt_clicks_size++] = i;
                if (level_array[i] < 0) {
                    // Monkey got a new best (Printed in frames)
                    completed = false;
                    total_time = total_time + i + 1;
                    if (record < i) {
                        printf("NEW BEST: %d (Attempt %llu, %llu frames spent so far)\n", i, attempts+1, total_time);
                        record = i;
                        printf("%d", attempt_clicks[0]*4);
                        for (int i = 1; i < attempt_clicks_size; i++) {
                            printf(", %d", attempt_clicks[i]*4);
                        }
                        printf("\n\n");
                    }
                    break;
                }
                airborn = level_array[i];
            } else {
                // Monkey didn't click
                if (level_array[i] == -2 && airborn < 1) {
                    // Monkey should've clicked and died
                    completed = false;
                    total_time = total_time + i + 1;
                    if (record < i) {
                        // Monkey got a new best (Printed in frames)
                        printf("NEW BEST: %d (Attempt %llu, %llu frames spent so far)\n", i, attempts+1, total_time);
                        record = i;
                        printf("%d", attempt_clicks[0]*4);
                        for (int i = 1; i < attempt_clicks_size; i++) {
                            printf(", %d", attempt_clicks[i]*4);
                        }
                        printf("\n\n");
                    }
                    break;
                }
                airborn--;
            }
        }

        // Refreshes random seed after 100 million attempts
        if (attempts % 100000000 == 0) {
            printf("%llu Attempts spent\n", attempts);
            srand(truerand());
        }
    }

    // Monkey won
    printf("\n\n--- CONGRATULATIONS! ---\nMonkey got to the ship part after %llu attempts and %llu frames!\nSave the last winning rseed\n", attempts, total_time + (LEVEL_COUNT)/60);
    
    printf("%d", attempt_clicks[0]*4);
    for (int i = 1; i < attempt_clicks_size; i++) {
        printf(", %d", attempt_clicks[i]*4);
    }
    printf("\n\n");

    while (true) {} // Stops the program from terminating in case it won to prevent any accidents (Like closing the terminal)
}