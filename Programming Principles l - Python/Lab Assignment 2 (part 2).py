import math


numberEntered = input("Enter a postive interger: ")




try:
    i = int(numberEntered)


    print(i)



    while i < 1000:

        j = int(input("Enter another positive interger: "))


        if j < 0:
            print("Stopped early becuase you entered a negative interger.")
            break

        print(j)
        i += j


    if i >= 1000:
        print("Stops(program will terminate because it already exceeded the sum 1000)")


        
except:
    print("Your entered an invalid response; please enter a POSITIVE interger.")
