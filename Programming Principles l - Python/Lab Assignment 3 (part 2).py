import math

def main():
    num_enter = input("How many rows do you want in your equilateral triangle?: ")


    num = int(num_enter)
    star = "*"
    space = " "
    rows = int(num_enter)
    number_of_stars = 1



    
    while rows>0:


        while number_of_stars<(num*2):
            
            num_star = number_of_stars
            
            while num_star >0:
                print(star, end="")
                num_star -=1
            break

        

        number_of_stars +=2
        num -= 1
        rows -= 1
        print('\n')
   

    print('\n' +"Done with loop")


    
    number_of_spaces = (num*2)-2
    number_of_stars = (num-(num-1))




       
# ANOTHER WAY IS BELOW

import math

def main():
    num = int(input("Enter how many rows you would like:"))

    number = num
    number_of_spaces = (number*2)-2

    for i in range (0, num):
        number_of_spaces = (number)-1
        while number_of_spaces>0:
            print(" ",end="")
            number_of_spaces -=1
        number -=1
        for j in range (0, i+1):
            print("*", end="")
        print()
    print("Done with Loop")
    



