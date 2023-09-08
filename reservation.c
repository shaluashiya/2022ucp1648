#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define constants
#define MAX_SEATS 100
#define MAX_NAME_LENGTH 50

// Struct to represent a passenger
struct Passenger {
    char name[MAX_NAME_LENGTH];
    int age;
    char gender;
    int seat_number;
};

// Function to check seat availability
int isSeatAvailable(int seats[], int seat_number) {
    return seats[seat_number] == 0;
}

// Function to reserve a seat
void reserveSeat(struct Passenger passengers[], int seats[], int seat_number) {
    if (isSeatAvailable(seats, seat_number)) {
        struct Passenger passenger;
        
        printf("Enter passenger name: ");
        scanf("%s", passenger.name);
        printf("Enter passenger age: ");
        scanf("%d", &passenger.age);
        printf("Enter passenger gender (M/F): ");
        scanf(" %c", &passenger.gender);
        
        passenger.seat_number = seat_number;
        
        passengers[seat_number] = passenger;
        seats[seat_number] = 1;
        
        printf("Seat reserved successfully! PNR: %d\n", seat_number);
    } else {
        printf("Seat %d is already reserved.\n", seat_number);
    }
}

// Function to cancel a reservation
void cancelReservation(struct Passenger passengers[], int seats[], int seat_number) {
    if (seats[seat_number] == 1) {
        printf("Cancelled reservation for seat %d\n", seat_number);
        seats[seat_number] = 0;
    } else {
        printf("Seat %d is not reserved.\n", seat_number);
    }
}

// Function to display the passenger list
void displayPassengerList(struct Passenger passengers[], int seats[]) {
    printf("Passenger List:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (seats[i] == 1) {
            printf("Seat %d: %s (Age: %d, Gender: %c)\n", i, passengers[i].name, passengers[i].age, passengers[i].gender);
        }
    }
}

int main() {
    int seats[MAX_SEATS] = {0}; // 0 indicates available, 1 indicates reserved
    struct Passenger passengers[MAX_SEATS];
    
    while (1) {
        printf("\nRailway Reservation System\n");
        printf("1. Reserve a seat\n");
        printf("2. Cancel reservation\n");
        printf("3. Display passenger list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int seat_number;
                printf("Enter seat number: ");
                scanf("%d", &seat_number);
                if (seat_number >= 0 && seat_number < MAX_SEATS) {
                    reserveSeat(passengers, seats, seat_number);
                } else {
                    printf("Invalid seat number. Please enter a valid seat number.\n");
                }
                break;
            }
            case 2: {
                int seat_number;
                printf("Enter seat number: ");
                scanf("%d", &seat_number);
                if (seat_number >= 0 && seat_number < MAX_SEATS) {
                    cancelReservation(passengers, seats, seat_number);
                } else {
                    printf("Invalid seat number. Please enter a valid seat number.\n");
                }
                break;
            }
            case 3:
                displayPassengerList(passengers, seats);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }
    
    return 0;
}
