import random

def rollDice(): # Random number generator return a number 1-6
    return random.randint(1, 6)

def humanTurn(humanTotalScore): #Fuction for the human turn
    turnTotal = 0
    print("It's your turn! Enter 'r' to roll.") #print statement
    action = input()
    ended = False #to show when it is ended

    while not ended and action == "r":
        roll = rollDice() #initializing the random number generator
        if roll == 1:
            print("You rolled a 1. Your turn ends with no points.")
            ended = True
        else: #if it is not a 1
            turnTotal += roll
            print("You rolled:", roll)
            print("Your score this round is:", turnTotal)
            print("If you hold, your total score would be:", humanTotalScore + turnTotal)
            print("Press 'h' to hold or 'r' to roll again.")
            action = input()

    if ended:
        return 0
    return turnTotal

def computerTurn(computerTotalScore): #Function for the computer turn
    turnTotal = 0
    print("It's the computer's turn!") #print statemnt
    ended = False

    while True: #while it is the computers turn
        roll = rollDice()
        if roll == 1: #if statement when a 1 is rolled
            print("The computer rolled 1. The computer loses its turn. Enter 'c' to continue.")
            ended = True
            break
        else: #for every other case
            turnTotal += roll
            print("The computer rolled:", roll)
            print("The computer's score this round is:", turnTotal)
            print("If the computer holds, its total score would be:", computerTotalScore + turnTotal)
            if turnTotal >= 20:
                print("The computer holds. Enter 'c' to continue.")
                break

    if ended:
        return 0
    return turnTotal

def playGame(): #initializes the game
    humanTotalScore = 0 #begining value
    computerTotalScore = 0 #begining value

    while True: #while game is running
        print("----- Human's Turn -----")
        print("Human's total score:", humanTotalScore)
        humanTurnScore = humanTurn(humanTotalScore)
        if humanTurnScore == 0:
            pass  # The message for rolling a 1 is already printed in the 'humanTurn' function
        else:
            humanTotalScore += humanTurnScore
            print("You scored", humanTurnScore, "points this turn.")
            print("Your total score is now", humanTotalScore)
        if humanTotalScore >= 100:
            print("Congratulations! You win!")
            break

        print("\n----- Computer's Turn -----")
        print("Computer's total score:", computerTotalScore)
        computerTurnScore = computerTurn(computerTotalScore)
        if computerTurnScore == 0:
            pass  # The message for rolling a 1 is already printed in the 'computerTurn' function
        else:
            computerTotalScore += computerTurnScore
            print("Computer scored", computerTurnScore, "points this turn.")
            print("Computer's total score is now", computerTotalScore)
        if computerTotalScore >= 100:
            print("Sorry, the computer wins.")
            break

        print("Press 'y' to continue or 'n' to exit:")
        choice = input()
        if choice == "n":
            break

playGame() #plays the game
