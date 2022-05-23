# hw5-coyote.py
# Gabriel Coyote, 9/21/2021
# Assignment 5


# Problem (i), SCP I:
#       Let x=7. Then f(x) = 7^2 + 7 + 41, f(x)=95.     
#       Let x=24. Then f(x) = 24^2 + 24 + 41, f(x)=641. 
#       Let x=8. Then f(x) = 8^2 + 8 + 41, f(x)=113.  

# Problem (i), SCP II:
#       Suppose x is a given number, then to 
#       compute f(x) do the following.
#           f(x) = x^2 + x + 41
#       Then return the value of f(x)

# Problem (i), SCP III:
#       Let x=3. Then f(x) = 3^2 + 3 + 41, f(x)=53.     
#       Let x=5. Then f(x) = 5^2 + 5 + 41, f(x)=71. 
#       Let x=7. Then f(x) = 7^2 + 7 + 41, f(x)=97.     

"""----------------------------------------------------------------------"""

# Problem (ii), SCP I:
#       Let n=3.        
#       f(1) = 43, add this value to my_list.
#       f(2) = 47, add this value to my_list.
#       f(3) = 53, add this value to my_list.
#       Return my list.

# Problem (ii), SCP II:
#       Suppose n is a integer. And, we want a list containing 
#       sequence f(1), f(2),..., f(n).
#       
#           Let my_list be an empty list.
#   
#           Let i=1. Do the following n times,
#               append f(i) to my list.
#           Finally return my list

# Problem (ii), SCP III:
#       Let n=6.        
#       f(1) = 43, add this value to my_list.
#       f(2) = 47, add this value to my_list.
#       f(3) = 53, add this value to my_list.
#       f(4) = 61, add this value to my_list.
#       f(5) = 71, add this value to my_list.
#       f(6) = 83, add this value to my_list.
#       Return my list.

"""----------------------------------------------------------------------"""

# Problem (iii), SCP I:       
#    
#       Let n = 9.
#
#       Since n is not less than or equal to 1,
#       we use our second test.
#
#       If there exists an integer d within range (2, square_root(n) ),
#       in which n is divisible by d then n is not a prime number.
#
#       Range of integer d is (2 to 3).
#           Let d = 2, 9/2 = 4.5, so 2 doesn't work.
#           Let d = 3, 9/3 = 3, we found a integer d that works!
#               Meaning 9 is not a prime number, return False.
#


# Problem (iii), SCP II:
#       Suppose n is an integer, and we want to return True if
#       it is a prime number, else False.
#
#           If n <= 1, then n is not prime so return False.
#   
#           If there exist an integer 'd' within the range (2, x**(1/2) )
#           such that n is divisble by d, then n is not prime so return False.
#
#           Else return True.


# Problem (iii), SCP III:
#    
#       Let n = 13.
#
#       Since n is not less than or equal to 1,
#       we use our second test.
#
#       If there exists an integer d within range (2, square_root(n) ),
#       in which n is divisible by d then n is not a prime number.
#
#       Since the square root of n (3.6) is not a whole number,
#       we will round down.
#
#       Range of integer d is (2 to 3).           
#           Let d = 2, 13/2 = 6.5, so 2 doesn't work.
#           Let d = 3, 13/3 = 4.3, so 3 doesn't work.
#
#       Exhausted all values for integer d, so n (13) is prime.
#       Return True.
   
"""----------------------------------------------------------------------"""


def f(x):
    return (x**2)+x+41


def build_list(n):
    my_list = []
    for i in range(1, n+1):
        my_list.append(f(i))
        
    return my_list


def isprime(n):
    if n <= 1: return False
    
    for i in range(2, int((n**(1/2)))+1 ):
        if n%i == 0: return False
        
    return True



mylist = build_list(50)
for k in mylist:
    if isprime(k):
        print("{0} is prime.".format(k))
    else:
        print("{0} is NOT prime.".format(k))

