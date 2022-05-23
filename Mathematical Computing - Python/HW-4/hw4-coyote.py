# hw4-coyote.py
# Gabriel Coyote, 9/16/2021
# Assignment 4


# Problem (i), SCP I:
#       Let n=15. Then g(n) = g(15) = (3(15) + 1)/2 = 23,
#                       since n is odd.
#       Let n= 23. Then g(n) = g(23) = (3(23)+1)/2 = 35,
#                       since n is odd.
#       Let n=35. Then g(n) = g(35) = (3(35)+1)/2 = 53,
#                       since n is odd.
#       Let n=53. Then g(n) = g(53) = (3(53)+1)/2 = 80,
#                       since n is even.
#       Let n=80. Then g(n) = g(80) = 80/2 = 40,
#                       since n is even.
#       Let n=40. Then g(n) = g(40) = 40/2 = 20,
#                       since n is even.
#       Let n=20. Then g(n) = g(20) = 20/2 = 10,
#                       since n is even.
#       Let n=10Then g(n) = g(10) = 10/2 = 5,
#                       since n is odd.
#       Let n=5. Then g(n) = g(5) = (3(5)+1)/2 = 8,
#                       since n is even.
#       Let n=8. Then g(n) = g(8) = 8/2 = 4,
#                       since n is even.
#       Let n=4. Then g(n) = g(4) = 4/2 = 2,
#                   since n is even.
#       Let n=2. Then g(n) = g(2) = 2/2 =1


# Problem (i), SCP II:
#       Suppose n is a positive integer. Then
#       to compute g(n) do the following.
#
#               If n is a even number, then
#                   g(n) := n/2 .
#               Else, n must be an odd number, so
#                   g(n) := (3n+1)/2 .
#               Return the integer value g(n).


# Problem (i), SCP III:
#       Let n=16. Then g(n) = g(16) = 16/2 = 8,
#                       since n is even.
#       Let n=8. Then g(n) = g(8) = 8/2 = 4,
#                       since n is even.
#       Let n=4. Then g(n) = g(4) = 4/2 = 2,
#                   since n is even.
#       Let n=2. Then g(n) = g(2) = 2/2 =1

"""----------------------------------------------------------------------"""

# Problem (ii), SCP I:
#       Suppose n is a positive integer. And, we have a list containing
#       sequence n, g(n), g(g(n)), g(g(g(n))), ... up to the first appreance of 1.
#
#       Let n = 22, add this value to the list
#       Let n=22, g(22) = 11, add this value to the list.
#       Let n=11, g(11) = 17, add this value to the list.
#       Let n=17, g(17) = 26, add this value to the list.
#       Let n=26, g(26) = 13, add this value to the list.
#       Let n=13, g(13) = 20, add this value to the list.
#       Let n=20, g(20) = 10, add this value to the list.
#       Let n=10, g(10) = 5, add this value to the list.
#       Let n=5, g(5) = 8, add this value to the list.
#       Let n=8, g(8) = 4, add this value to the list.
#       Let n=4, g(4) = 2, add this value to the list.
#       Let n=2, g(2) = 1, add this value to the list.
#
#       We reached our first appreance of 1, so then
#       return the list.



# Problem (ii), SCP II:
#       Suppose n is a positive integer. And, we have a list containing
#       sequence n, g(n), g(g(n)), g(g(g(n))), ... up to the first appreance of 1.
#               
#           Let my list contain the value n,
#               let my item := n .
#               
#               While my item != 1 do the following, 
#                       let item := the return value of the function g(n).
#                         Append item to my list.
#
#               Finally return my list.


# Problem (ii), SCP III:
#       Suppose n is a positive integer. And, we have a list containing
#       sequence n, g(n), g(g(n)), g(g(g(n))), ... up to the first appreance of 1.
#
#       Let n = 16, add this value to the list
#       Let n=16, g(16) = 8, add this value to the list.
#       Let n=8, g(8) = 4, add this value to the list.
#       Let n=4, g(4) = 2, add this value to the list.
#       Let n=2, g(2) = 1, add this value to the list.
#
#       We reached our first appreance of 1, so then
#       return the list.


def g3n1(n):
    if n % 2 == 0:
        gn = n//2
    else:
        gn = (3*n+1)//2
    return gn



def sequence(n):
    mylist = [n]
    
    item = n
    while item != 1:
        item = g3n1(item)
        mylist.append(item)
    return mylist



n = int(input("Enter a positive integer n:"))
seq = sequence(n)
print("The resulting sequence is: {0}".format(seq))
print("It has length {0}".format(len(seq)))
