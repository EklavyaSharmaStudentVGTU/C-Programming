#include <stdio.h>

/**
 * Structure representing a Linear Feedback Shift Register (LFSR) Counter generator.
 */
typedef struct {
    unsigned int state;  // Current state of the LFSR.
    unsigned int tap;    // Tap position for feedback.
} LFSRCounter;

/**
 * Initializes a new LFSRCounter object with the specified initial state and tap position
 */
LFSRCounter createLFSRCounter(unsigned int initialState, unsigned int tapPosition) {
    LFSRCounter counter;
    counter.state = initialState;
    counter.tap = tapPosition;
    return counter;
}

/**
 * Generates the next value of the LFSRCounter.
 */
unsigned int generateNextValue(LFSRCounter* counter) {
    unsigned int feedbackBit = (counter->state >> (counter->tap - 1)) & 1;  // Extracting the feedback bit.
    unsigned int newBit = (counter->state & 1) ^ feedbackBit;  // XORing the least significant bit with the feedback bit.
    counter->state = (counter->state >> 1) | (newBit << 31);  // Shifting the state to the right and inserting the new bit.
    return counter->state;
}

// Usage example for LFSRCounter

int main() {
    LFSRCounter counter = createLFSRCounter(0b10101010, 8);  // Creating an LFSRCounter with initial state 0b10101010 and tap position 8.
    printf("Initial state: 0x%X\n", counter.state);

    for (int i = 0; i < 10; i++) {
        unsigned int nextValue = generateNextValue(&counter);
        printf("Next value: 0x%X\n", nextValue);
    }

    return 0;
}