#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice, computerChoice;
    int playerScore = 0, computerScore = 0;
    int rounds;

    printf("Welcome to Rock, Paper, Scissors!\n");

    printf("How many rounds would you like to play? ");
    scanf("%d", &rounds);

    // Seed the random number generator
    srand(time(NULL));

    for (int round = 1; round <= rounds; round++) {
        printf("\nRound %d:\n", round);
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &playerChoice);

        // Generate a random choice for the computer (1, 2, or 3)
        computerChoice = rand() % 3 + 1;

        printf("Computer chose: ");
        switch (computerChoice) {
            case 1:
                printf("Rock\n");
                break;
            case 2:
                printf("Paper\n");
                break;
            case 3:
                printf("Scissors\n");
                break;
        }

        // Determine the winner of the round
        if (playerChoice == computerChoice) {
            printf("It's a tie!\n");
        } else if (
            (playerChoice == 1 && computerChoice == 3) ||
            (playerChoice == 2 && computerChoice == 1) ||
            (playerChoice == 3 && computerChoice == 2)
        ) {
            printf("You win this round!\n");
            playerScore++;
        } else {
            printf("Computer wins this round!\n");
            computerScore++;
        }
    }

    // Display the final score
    printf("\nFinal Score:\n");
    printf("You: %d\n", playerScore);
    printf("Computer: %d\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations, you win!\n");
    } else if (playerScore < computerScore) {
        printf("Computer wins. Better luck next time!\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}

