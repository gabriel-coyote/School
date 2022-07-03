import math

numberEntered = input("Enter an interger: ")

try:
    number = int(numberEntered)
    i = 1

    result = 0

    while i <= number:
        i += 1
        result += i
        
    print("The sum of consectuive integers starting at 1 for your number is: ",
      result - number)


except:
    print("You entered an invalid response; please enter an INTERGER.")
    

