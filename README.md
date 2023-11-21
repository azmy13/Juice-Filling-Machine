# Assignment 1 - Juice Filling Machine

## Introduction

In Assignment 1 (A1) of the ESP practicals (KU), you will implement a calculator for a juice filling machine. Please make sure that you follow the assignment description exactly. Even slight differences can cause testcases to fail.

This document describes the structure of the assignment and the expected functionality of the program.

## Learning Goals

Variables, Data Types, Functions, Conditional Statements (If - Else), Loops

## Specification

There are some general specifications that must be followed for every assignment in this course. A list of these and which point deductions
may result from violating them can be found here:
[Assessment of Assignments - Deductions](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3?pvs=4#e3203e50b1fc4ba787bdbf5fb46262ae)

## Grading
Assignment 1 is worth **18 points**.

Information on how your assignment submission will be assessed can be found here: [Assessment of Assignments](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-d7cca6cc89a344e38ad74dd3ccb73cb3). 
Please read this carefully as it also contains guidelines on what your final code should look like (Coding Standard, Style Guide).

Here you can find an overview of how your total grade for the KU will be calculated: [Procedure and Grading](https://www.notion.so/coding-tugraz/Procedure-and-Grading-59975fee4a9c4047867772cd20caf73d)

## Submission
- Deliverables: `a1.c`
- Push to your repository
- **Deadline: 22.11.2023 23:59 (CEST)**

## Assignment Description
This program implements a calculator for a juice filling machine. Farmers produce different amounts of various juices, which can be filled into canisters. Depending on the user's input, the calculator determines the price for the filling. 

### General Notes
The notes given in this section are important for the entire assignment description.

- `\n` shouldn't be printed as two separate characters, instead they represent the newline character.
- Note the leading and trailing spaces in the text fields, which are not visible. You can make them visible by selecting the text field.
- Words in angle brackets (like `<QUANTITY>`) should be replaced by calculated or given data. They are *not* part of the output itself! For a better understanding you can look at the [example outputs](#example-outputs).
- In the testcases of this assignment only integers will be tested as user input. You don't have to think about other inputs like characters or multiple integers separated by spaces. However, it is possible that values outside the valid integer range occur.
- ` > ` (command prompt) in the output indicates that the program waits for a user input at this point. Execution should only continue after the user has ended the input with `ENTER`.
- If the user's input is invalid, the corresponding error message should be printed. After this, the question is asked again and the user can make a new input. This process is repeated as long as the input is invalid.

### Program Sequence
#### Welcome
When starting the program the following message should be printed in order to welcome the user: 

```
Welcome to the juice filling machine calculator!\n
```

#### User Input: Juice Type
As the next step the user chooses the juice type. This can be either orange or apple juice. Valid inputs are `1` or `2`.

```
\n
Which juice do you want to fill?\n
1. Orange juice\n
2. Apple juice\n
 > 
```

If the user input is invalid, the following error message will be printed:

```
Invalid input! Please choose a valid juice.\n
```

#### User Input: Litres
After choosing the juice type the user has to enter the amount of juice (in litres) which should be filled. The maximum capacity of the filling machine is 1000 litres.

```
\n
How many litres do you want to fill? (1 to 1000)\n
 > 
```

If the user input is invalid, the following error message will be printed:

```
Invalid input! Please choose a valid amount.\n
```

#### User Input: Canister Size
Depending on the juicy type there are different sizes of canisters available. Valid inputs are `5`, `10` or `20` for orange juice and `5`, `15` or `25` for apple juice.

##### Orange Juice

```
\n
Which size of canister would you like to use for your orange juice?\n
- 5 litres\n
- 10 litres\n
- 20 litres\n
 > 
```

##### Apple Juice

```
\n
Which size of canister would you like to use for your apple juice?\n
- 5 litres\n
- 15 litres\n
- 25 litres\n
 > 
```

If the user input is invalid, the following error message will be printed:

```
Invalid input! Please choose a valid canister size.\n
```

#### Calculate Canister Quantity
Now we have gathered all the information we need for the necessary calculations. The filling machine is only capable of filling *full* canisters. Therefore, the calculator evaluates the amount of full canisters and the left-over litres.

```
\n
It is possible to fill <QUANTITY> canisters with the size of <SIZE> litres.\n
```

`<QUANTITY>` should be replaced by the quantity of full canisters and `<SIZE>` by the chosen canister size.

```
This results in <AMOUNT> left-over litres.\n
```
`<AMOUNT>` stands for the amount of left-over litres.

#### Costs Calculation
Then, the calculator computes the total costs to fill the calculated amount of canisters. 

```
\n
The filling costs are:\n
----------------------------------------------\n
- <AMOUNT> litres of <JUICE_TYPE> juice: <JUICE_COSTS> €\n
- <QUANTITY> canisters: <CANISTER_COSTS> €\n
- Flat rate for using the machine: 5.00 €\n
----------------------------------------------\n
This results in a total cost of <TOTAL_COSTS> €.\n
```

- `<AMOUNT>` should be replaced by the *calculated* litres of the *full* canisters
- `<JUICE_TYPE>` should be replaced by either `apple` or `orange` depending on the [user's choice](#user-input-juice-type).
- `<JUICE_COSTS>` should be replaced by the [juice costs](#juice-costs)
- `<QUANTITY>` should be replaced by the quantity of full canisters
- `<CANISTER_COSTS>` should be replaced by the [canister costs](#canister-costs)
- `<TOTAL_COSTS>` should be replaced by the sum of all the costs mentioned above.

> All prices should be printed with two decimal places.

##### Juice Costs
The juice costs depend on whether the user selects apple juice or orange juice. Apple juice costs `0.15 €` per litre, while orange juice costs `0.20 €` per litre. The juice costs are calculated by multiplying the number of litres by the respective costs per litre.

##### Canister Costs
The canister costs vary based on the selected canister size and the quantity of canisters needed for filling. The following table outlines the costs per canister for different sizes:

| Canister size | Costs per canister |
|:-------------:|:------------------:|
|    5 litres   |       0.10 €       |
|   10 litres   |       0.15 €       |
|   15 litres   |       0.20 €       |
|   20 litres   |       0.20 €       |
|   25 litres   |       0.25 €       |

To calculate the total canister costs, you should multiply the costs per canister by the quantity of full canisters needed for filling.

#### User Input: Confirmation
In order to start the filling process, the machine needs the user's confirmation. Valid inputs are `1` or `2`.

```
\n
Are you sure you want to fill the canisters?\n
1. Yes\n
2. No\n
 > 
```

In case the user wants to cancel the process the program restarts from [the juice type input](#user-input-juice-type).

If the user input is invalid, the following error message will be printed:

```
Invalid input! Please choose a valid option.\n
```

#### Finish
After the user has confirmed the filling process the following message should be printed:

```
\n
The canisters will be filled as soon as we receive your payment.\n
Thank you for using the juice filling machine calculator!\n
```

In the end the program terminates with return value `0`.

## Example Outputs

### Example Output 1

```
Welcome to the juice filling machine calculator!

Which juice do you want to fill?
1. Orange juice
2. Apple juice
 > 1

How many litres do you want to fill? (1 to 1000)
 > 50

Which size of canister would you like to use for your orange juice?
- 5 litres
- 10 litres
- 20 litres
 > 10

It is possible to fill 5 canisters with the size of 10 litres.
This results in 0 left-over litres.

The filling costs are:
----------------------------------------------
- 50 litres of orange juice: 10.00 €
- 5 canisters: 0.75 €
- Flat rate for using the machine: 5.00 €
----------------------------------------------
This results in a total cost of 15.75 €.

Are you sure you want to fill the canisters?
1. Yes
2. No
 > 1

The canisters will be filled as soon as we receive your payment.
Thank you for using the juice filling machine calculator!
```

### Example Output 2

```
Welcome to the juice filling machine calculator!

Which juice do you want to fill?
1. Orange juice
2. Apple juice
 > 2

How many litres do you want to fill? (1 to 1000)
 > 1523
Invalid input! Please choose a valid amount.

How many litres do you want to fill? (1 to 1000)
 > 0
Invalid input! Please choose a valid amount.

How many litres do you want to fill? (1 to 1000)
 > 513 

Which size of canister would you like to use for your apple juice?
- 5 litres
- 15 litres
- 25 litres
 > 25

It is possible to fill 20 canisters with the size of 25 litres.
This results in 13 left-over litres.

The filling costs are:
----------------------------------------------
- 500 litres of apple juice: 75.00 €
- 20 canisters: 5.00 €
- Flat rate for using the machine: 5.00 €
----------------------------------------------
This results in a total cost of 85.00 €.

Are you sure you want to fill the canisters?
1. Yes
2. No
 > 1

The canisters will be filled as soon as we receive your payment.
Thank you for using the juice filling machine calculator!
```