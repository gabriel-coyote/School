# hw3-coyote.py
# Gabriel Coyote, 9/9/2021

# Problem 1, SCP I:
# Let M=10. Then
# 10 = 1^2 + 3^2,
# 10 = 3^2 + 1^2,
# Solutions = 2.


# Problem 1, SCP II:
# Suppose M is a positive integer, and
# M = m^2 + n^2, with m & n in N.
#
# Set count <-- 0.
# Set m <-- 1.
# Set n^2 <-- M - m^2.
#    If the square root of n^2 has no reminders, then
#    it is a natural number and a valid solution. 
#    Print the solutions, count + 1.
# Increase m by 1, and repeat until m^2 >= M
# Return count.


# Problem 1, SCP III:
# Let M=29. Then
# 29 = 2^2 + 5^2,
# 29 = 5^2 + 2^2,
# Solutions = 2.

def count_SOS(M):
    count = 0
    m = 1
    while m**2 < M:
        n = M - (m**2)
        if n%(n**(1/2)) == 0:
            print("%d = %d^2 + %d^2" % (M, m, (n**(1/2))) )
            count = count + 1
        m += 1
    return count
        

M=1
while M >= 1:
    M = int(input("Enter a positive integer M: "))
    numsq = count_SOS(M)
    print("{0} can be written as a sum of squares in {1} ways.".format(M, numsq))
