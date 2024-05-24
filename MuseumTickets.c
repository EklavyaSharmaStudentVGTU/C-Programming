#include <stdio.h>

int main() {
    int ticketPrice = 100;
    int numOfTickets;
    float totalAmount;

    printf("Welcome to the Museum Ticket Counter!\n");
    printf("Each ticket costs Rs %d.\n", ticketPrice);

    printf("How many tickets would you like to purchase? ");
    scanf("%d", &numOfTickets);

    totalAmount = ticketPrice * numOfTickets;

    printf("\n--- Receipt ---\n");
    printf("Number of Tickets: %d\n", numOfTickets);
    printf("Total Amount: Rs %.2f\n", totalAmount);

    float amountPaid;
    printf("\nEnter the total amount to be paid: Rs ");
    scanf("%f", &amountPaid);

    if (amountPaid < totalAmount) {
        printf("Insufficient amount paid. Please try again.\n");
    } else if (amountPaid == totalAmount) {
        printf("Thank you for your payment. Enjoy your visit!\n");
    } else {
        float change = amountPaid - totalAmount;
        printf("Thank you for your payment. Your change is Rs %.2f. Enjoy your visit!\n", change);
    }

    return 0;
}