# hw2-coyote.py
# Gabriel Coyote, 9/2/2021.


# Problem 1, SCP I:
# Let c=3 and N=3. Then
# x_0 = 1,
# x_1 = (1/2)*(1 + 3/1) = 2,
# x_2 = (1/2)*(2 + 3/2) = 1.75,
# x_3 = (1/2)*(1.75 + 3/1.75) ~ 1.73214


# Problem 1, SCP II:
# Suppose c>=1 and N is a positive integer.
# Set x <-- 1.
# Do the following N times:
#   Set x <-- (1/2)*(x + c/x).


# Problem 1, SCP III:
# Let c=5 and N=3. Then
# x_0 = 1,
# x_1 = (1/2)*(1 + 5/1) = 3,
# x_2 = (1/2)*(3 + 5/3) = 14/6,
# x_3 = (1/2)*({14/6} + 5/{14/6}) ~ 2.23809


C = float(input("Enter a floating point number greater or equal to 1 for \"C\": "))
N = int(input("Enter a positive integer for \"N\": "))


x = 1
while N != 0:
    x = (1/2)*(x + C/x)
    N -= 1

print("\nThe value at the Nth term: %.8f" % x) 
