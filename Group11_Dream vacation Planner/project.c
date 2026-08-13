#define _DEFAULT_SOURCE
#include <stdio.h>
#include <unistd.h>
#define SIZE 4

void animation(void);
void display(char destination[SIZE][30], int price[], int seats[]);
void recommend(char destination[SIZE][30], int price[], int seats[]);
void book(char destination[SIZE][30], int price[], int seats[], int *revenue);

int main()
{
    char destination[SIZE][30] =
    {
        "Cox's Bazar",
        "Sajek",
        "Sylhet",
        "Saint Martin"
    };

    int price[SIZE] = {5000, 7000, 4500, 8000};
    int seats[SIZE] = {20, 15, 10, 8};

    int revenue = 0;
    int choice;

    do
    {
        printf("\n=================================\n");
        printf("       DREAM VACATION PLANNER\n");
        printf("=================================\n");
        printf("1. View Vacation Packages\n");
        printf("2. Find My Dream Destination\n");
        printf("3. Book Trip\n");
        printf("4. Exit\n");
        printf("=================================\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            display(destination, price, seats);

        }
        else if (choice == 2)
        {
            recommend(destination, price, seats);

        }
        else if (choice == 3)
        {
            book(destination, price, seats, &revenue);

        }
        else if (choice == 4)
        {
            printf("\n===== BOOKING SUMMARY =====\n");
            printf("Total Revenue: %d Taka\n", revenue);
            printf("===========================\n");
            printf("\nTHANK YOU FOR CHOOSING DREAM VACATION PLANNER!\n");
            printf("HAVE A WONDERFUL JOURNEY!\n");
            break;
        }
        else
        {
            printf("\nInvalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}


void animation(void)
{
    int j, k;

    printf("\n");

    for (j = 0; j <= 50; j++)
    {
        printf("\r\033[2K");

        for (k = 0; k < j; k++)
        {
            printf(" ");
        }

        printf("TRIP READYYY!!✈️✈️");

        fflush(stdout);

        usleep(50000);
    }

    printf("\n");
}



void display(char destination[SIZE][30], int price[], int seats[])
{
    int i;

    printf("\n===== VACATION PACKAGES =====\n");

    for (i = 0; i < SIZE; i++)
    {
        printf("\nPackage ID: %d\n", i + 1);
        printf("Destination: %s\n", destination[i]);
        printf("Price: %d Taka/person\n", price[i]);
        printf("Available Seats: %d\n", seats[i]);
        printf("-----------------------------\n");
    }
}


void recommend(char destination[SIZE][30], int price[], int seats[])
{
    int interest;


    printf("\n===== FIND YOUR DREAM DESTINATION =====\n");

    printf("\nWhat type of vacation do you like?\n");
    printf("1. Beach\n");
    printf("2. Mountain\n");
    printf("3. Nature\n");
    printf("4. Adventure\n");

    printf("Enter your choice: ");
    scanf("%d", &interest);

    if (interest < 1 || interest > 4)
    {
        printf("\nInvalid vacation type!\n");
        return;
    }

    if (interest == 1 )
    {
        printf("\nYour Dream Destination: %s!\n", destination[0]);
        printf("Price: %d Taka/person\n", price[0]);
        printf("Available Seats: %d\n", seats[0]);
    }
    else if (interest == 2)
    {
        printf("\nYour Dream Destination: %s!\n", destination[1]);
        printf("Price: %d Taka/person\n", price[1]);
        printf("Available Seats: %d\n", seats[1]);
    }
    else if (interest == 3)
    {
        printf("\nYour Dream Destination: %s!\n", destination[2]);
        printf("Price: %d Taka/person\n", price[2]);
        printf("Available Seats: %d\n", seats[2]);
    }
    else
    {
        printf("\nYour Dream Destination: %s!\n", destination[3]);
        printf("Price: %d Taka/person\n", price[3]);
        printf("Available Seats: %d\n", seats[3]);
    }

}


void book(char destination[SIZE][30], int price[], int seats[], int *revenue)
{
    int id;
    int people;
    int total;

    display(destination, price, seats);

    printf("\nEnter Package ID: ");
    scanf("%d", &id);

    if (id < 1 || id > SIZE)
    {
        printf("Invalid Package ID!\n");
        return;
    }

    id--;

    printf("Enter Number of Travelers: ");
    scanf("%d", &people);

    if (people <= 0)
    {
        printf("Invalid number of travelers!\n");
        return;
    }

    if (people > seats[id])
    {
        printf("Not Enough Seats Available!\n");
        return;
    }

    total = price[id] * people;

    seats[id] = seats[id] - people;

    *revenue = *revenue + total;

    printf("\n=================================\n");
    printf("        BOOKING SUCCESSFUL!\n");
    printf("=================================\n");
    printf("Destination: %s\n", destination[id]);
    printf("Travelers: %d\n", people);
    printf("Total Bill: %d Taka\n", total);
    printf("Remaining Seats: %d\n", seats[id]);
    printf("=================================\n");

    animation();
}
