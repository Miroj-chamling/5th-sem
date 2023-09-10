#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STATES 2 // Number of possible states (e.g., sunny and rainy)

// Transition matrix defines the probabilities of moving from one state to another
double transitionMatrix[NUM_STATES][NUM_STATES] = {
    {0.7, 0.3}, // Transition probabilities from state 0 to 0 and 0 to 1
    {0.4, 0.6}  // Transition probabilities from state 1 to 0 and 1 to 1
};

// Function to simulate the Markov chain
int simulateMarkovChain(int initialState, int numSteps) {
    int currentState = initialState;
    printf("Initial state: %d\n", currentState);

    for (int step = 1; step <= numSteps; ++step) {
        double randomValue = (double)rand() / RAND_MAX; // Generate a random value between 0 and 1
        double cumulativeProbability = 0.0;

        // Determine the next state based on the transition probabilities
        for (int nextState = 0; nextState < NUM_STATES; ++nextState) {
            cumulativeProbability += transitionMatrix[currentState][nextState];
            if (randomValue < cumulativeProbability) {
                currentState = nextState;
                break;
            }
        }

        printf("Step %d: State %d\n", step, currentState);
    }

    return currentState;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int initialState = 0; // Initial state (0 or 1)
    int numSteps = 10;    // Number of steps to simulate

    int finalState = simulateMarkovChain(initialState, numSteps);

    printf("Final state: %d\n", finalState);

    return 0;
}
