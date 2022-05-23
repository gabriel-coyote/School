# hw1.py
# Gabriel Coyote, 8/26/21.
# This program has many problems, and will NOT run as-is. 
# For part of this assignment, you need to correct it.

# Possible Input & Output Values
# x^2 - 2x - 15   gives roots of 5 & -3
# 2x^2 + 12x -14  gives roots of -7 & 1


a = float(input("Enter value of 'a': "))
b = float(input("Enter value of 'b': "))
c = float(input("Enter value of 'c': "))

if a == 0:
    print("\nA is 0 so it gives a ZeroDivisionError: float division by zero")
    
x1 = (-b + (b**2 - 4*a*c)**(1/2)) / (2*a)
x2 = (-b - (b**2 - 4*a*c)**(1/2)) / (2*a)

print ("\nThe roots of ",a,"x^2 + ",b,"x + ",c,"are... \n(",x1,", ",x2,")")
