import math

print("Make sure all values entered are in meters.")

x = input("What is the length of one parallel side?: ")
y = input("What is the length of the other parallel side?: ")
h = input("What is the height of the trapezoid?: ")


try:
    X = int(x)
    Y = int(y)
    H = int(h)

    area = ((X+Y)*H)/2

    print("The area of the trapziod is: " + str(area))

except:
    print("You entered an invalid response, make sure to enter an interger.")
