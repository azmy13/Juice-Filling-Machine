//-----------------------------------------------------------------------------
// a1.c
//
// <This C program is a simple juice filling machine calculator. The user is prompted to choose between filling juices(Orange & 
/// Apple) The costs include the juice cost (based on the chosen juice type), canister cost (based on the selected canister size), 
/// and a fixed machine rate. The user is then presented with a summary of the costs and asked for confirmation to proceed with the 
/// filling>
//
// Group: <>
//
// Author: <12037259>
//-----------------------------------------------------------------------------

#include <stdio.h>
const int MAX_LITRES = 1000;
#define MACHINE_RATE 5
#define APPLE_COST 0.15
#define ORANGE_COST 0.20



//---------------------------------------------------------------------------------------------------------------------
///
/// This function prompts the user for confirmation to fill the canisters. The user is presented with options to either 
/// confirm (option 1 - Yes) or cancel the operation (option 2 - No). The function ensures that the user provides a valid 
/// input, and it loops until a valid choice is made.
///
/// Returns the user's choice: 1 if the user confirms, and 2 if the user cancels.

int getConfirmation() {
    int answer;
   

    do {
        printf("\nAre you sure you want to fill the canisters?\n1. Yes\n2. No\n > ");
        scanf("%d", &answer);

        if (answer != 1 && answer != 2) {
            printf("Invalid input! Please choose a valid option.\n");
            // Clear the input buffer to avoid issues in subsequent input
            while (getchar() != '\n');
        }
    } while (answer != 1 && answer != 2 );
    return answer;
}

//-----------------------------------------------------------------------------
///
/// This function, named repeatCode, represents a juice filling machine calculator. It interacts with the user to determine the type 
/// of juice, the desired quantity in liters, and the size of canisters to be used. It then calculates the number of canisters 
/// needed, the quantity that can be filled, and the associated costs.
///
///

void repeatCode() 
{
    int juice_number;
    int litres;
    int canister_size;
    int quantity;
    float juice_cost;
    float total_cost;
    int canister_count;
    float canister_rate;
    float canister_cost;
    int answer;
    int left_over_litres;
    

    // User choice for the juice type

    do 
    {
        
        printf("\nWhich juice do you want to fill?\n1. Orange juice\n2. Apple juice\n > ");
        scanf("%d", &juice_number);
        if (juice_number != 1 && juice_number != 2) {
            printf("Invalid input! Please choose a valid juice.\n");
            
        }
    } while (juice_number != 1 && juice_number != 2);

    // Litres input
    do 
    {
        printf("\nHow many litres do you want to fill? (1 to 1000)\n > ");
        scanf("%i", &litres);
        if (litres < 1 || litres > MAX_LITRES) {
            printf("Invalid input! Please choose a valid amount.\n");
        }
    } while (litres < 1 || litres > MAX_LITRES);


    do
    {
        printf("\nWhich size of canister would you like to use for your %s juice?\n",(juice_number == 1) ? "orange" : "apple");
        printf("- 5 litres\n");
        if (juice_number == 1) 
        {
            printf("- 10 litres\n- 20 litres\n");
        } else 
        {
            printf("- 15 litres\n- 25 litres\n");
        }
        printf(" > ");
        scanf("%d", &canister_size);
        if (juice_number == 1) 
        {
            if (canister_size == 5) 
            {
                canister_rate = 0.10;
            } else if (canister_size == 10) 
            {
                canister_rate = 0.15;
            } else 
            {
                canister_rate = 0.20;
            }
        } else 
        {
            if (canister_size == 5) 
            {
                canister_rate = 0.10;
            } else if (canister_size == 15) 
            {
                canister_rate = 0.20;
            } else 
            {
                canister_rate = 0.25;
            }
        }
        if (canister_size != 5 && ((juice_number == 1 && canister_size != 10 && canister_size != 20) || (juice_number == 2
            && canister_size != 15 && canister_size != 25))) 
        {
            printf("Invalid input! Please choose a valid canister size.\n");
        }
    } while (canister_size != 5 && ((juice_number == 1 && canister_size != 10 && canister_size != 20) || (juice_number == 2
         && canister_size != 15 && canister_size != 25)));


    // Calculate Canister Quantity

    canister_count = litres / canister_size;
    quantity = (canister_count * canister_size);
    left_over_litres = litres % canister_size;
    printf("\nIt is possible to fill %d canisters with the size of %d litres.\n", canister_count, canister_size);
    printf("This results in %d left-over litres.\n", left_over_litres);
    
    // Costs Calculation

    juice_cost = (quantity * (juice_number ==1 ? ORANGE_COST : APPLE_COST));
    canister_cost = canister_rate * canister_count;
    total_cost = juice_cost + canister_cost + MACHINE_RATE;
    printf("\nThe filling costs are:\n----------------------------------------------\n");
    printf("- %d litres of %s juice: %.2f €\n- %d canisters: %.2f €\n", quantity, (juice_number == 1) ? "orange" : "apple",
         juice_cost, canister_count, canister_cost);
    printf("- Flat rate for using the machine: 5.00 €\n----------------------------------------------\n");
    printf("This results in a total cost of %.2f €.\n", total_cost);
    
    // Get user confirmation

    answer = getConfirmation();
    if (answer == 1) {
        printf("\nThe canisters will be filled as soon as we receive your payment.\nThank you for using the juice filling machine calculator!\n");
    } else {
        // Repeat the code if the user enters 2
        repeatCode();
    }
}

//---------------------------------------------------------------------------------------------------------------------
///
/// This is the main function of the juice filling machine calculator program. It serves as the entry point for the program.
/// Upon execution, it displays a welcome message to the user and then calls the `repeatCode` function to start the 
/// juice filling machine calculator. After the calculator completes its operation, the program returns 0, indicating
/// successful execution.
// Returns 0 to indicate successful program execution.
///

int main() 
{
    // Welcome Msg
    printf("Welcome to the juice filling machine calculator!\n");
    // Call the function to start the program
    repeatCode();
    return 0;
}

