import math

def main():
    num_enter = input("Enter a number: ")
    try:

        digit_sum = 0
        
        num= int(num_enter)

        if num<0:
            print("Please enter a Positive Integer")
        elif num == 0:
            print("0")
        elif num>0:
            for char in num_enter:
                digit_sum += num%10
                num = num//10

            print("Sum of digits is: ",digit_sum)

    except:
        print("Please enter a numeric postive integer!")


    

