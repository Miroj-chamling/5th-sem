//using lcg

#include <stdio.h>
#include <stdlib.h>

// LCG parameters
unsigned long long int seed = 123456789; // Initial seed
unsigned long long int a = 6364136223846793005ULL; // Multiplier
unsigned long long int c = 1ULL; // Increment
unsigned long long int m = 18446744073709551615ULL; // Modulus (2^64 - 1)

// Function to generate a random number using LCG
unsigned long long int generateRandomLCG() {
    seed = (a * seed + c) % m;
    return seed;
}

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        unsigned long long int random = generateRandomLCG();
        printf("%llu\n", random);
    }

    return 0;
}

//using mid square method


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number using the Mid-Square Method
unsigned int generateRandomMidSquare(unsigned int seed) {
    seed *= seed;
    seed /= 100;
    return seed % 10000;
}

int main() {
    unsigned int seed = time(NULL) % 10000; // Use current time as the initial seed
    int i;
    for (i = 0; i < 10; i++) {
        seed = generateRandomMidSquare(seed);
        printf("%u\n", seed);
    }

    return 0;
}
