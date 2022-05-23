# exam1-coyote.py
# Gabriel Coyote
# 10/2/2021
# Exam 1



# Problem (i), SCP I:
#
#   Let x_1 = 1.
#   Let c = 1, and n = 4.
#       Then x_2 = 1 + (c/(previous term) = 1 + (1 / 1), which is 2.
#       Then x_3 = 1 + (c/(previous term) = 1 + (1 / 2), which is 1.5.
#       Then x_4 = 1 + (c/(previous term) = 1 + (1 / 1.5), which ~ 1.6666.
#
#   Sequence of first 4 terms.
#   Sequence is {x_1,x_2,x_3,x_4}.
#   Sequence is {1, 2, 1.5, 1.6666}.




# Problem (i), SCP II:
#       Suppose N and c is a positive integer. And, we have a
#       a list, or sequence, to return.
#       The sequence contains {x_1,x_2,x_3,...x_n}.
#
#       Let my list contains the given value x_1.
#
#           Do the following until your sequence contains the first N terms.
#
#               Let x_n+1 := 1 + (c/xn), and append this value of x_n+1 to the list.
#               Or in other word new_element := 1 + (c/previous_element), and append this new_element to the list.
#
#       Return my list.  



# Problem (i), SCP III:
#
#   Let x_1 = 1.
#   Let c = 4, and n = 5.
#       Then x_2 = 1 + (c/(previous term) = 1 + (4 / 1), which is 5.
#       Then x_3 = 1 + (c/(previous term) = 1 + (4 / 5), which is 1.8.
#       Then x_4 = 1 + (c/(previous term) = 1 + (4 / 1.8), which ~ 3.222.
#       Then x_5 = 1 + (c/(previous term) = 1 + (4 / 3.222), which ~ 2.2413.
#
#   Sequence of first 5 terms.
#   Sequence is {x_1,x_2,x_3,x_4,x_5}.
#   Sequence is {1, 5, 1.8, 3.222, 2.2413}.


"""
    Problem (ii):

        After trying different c values,
        I notice that positive values converge and negative values diverges.
        
        For positive c values the sequence converges,
        but for c values < -1 it diverges.

        For c < -1 it diverges becuase of this section "c / xn ".
        It will give out a positive if xn is negative, becuase negative / negative is positive.
        It will give out a negative if xn is positive, becuase negative / positive is negative.

        
"""

def get_terms(c, N):
    # My sequence has the first given term x1 = 1
    sequence = [1] 
    x_old = 1
    
    for n in range(1,N):
        x_new = 1 + (c/x_old)
        x_old = x_new
        sequence.append(x_new)
        
    return sequence


while True:
    thisc = float(input("Enter c: "))
    thisN = int(input("how many terms? "))
    seq = get_terms(thisc, thisN)
    print(seq)
