# hw8-coyote.py
# Gabriel Coyote
# 10/24/2021
# ASsignment 8

import math

# Problem (i), SCP I
#####################################################
# Let f(t) = t^2-5, x0=1, epsilon=0.01.
# We start  computing terms in the sequence x0,x1,...
# until one of the termination conditions is met.
#
# x0 = 1
# ---------------------------------------
# Since |f'(x0)|>epsilon, we may compute x1:
# x1 = x0 - f(x0)/f'(x0)
#    = 1- (-4)/(2*1)
#    = 3.
# Since |f(x1)| = 3 >epsilon, not done yet.
# -----------------------------------------
# Since |f'(x1)| = |2*3|=6>epsilon, we may compute x2:
# x2 = x1 - f(x1)/f'(x1)
#    = 3 -4/(2*3) = 7/3
# Since |f(x2)| = |49/9 - 5| = 4/9 > epsilon, not done yet.
# ----------------------------------------
# Since |f'(x2)| = 14/3 > epsilon, we may compute x3:
# x3 = x2 - f(x2)/f'(x2)
#    = 2.238095238095238
# |f(x3)| = 0.009070294784581101 < epsilon,
# so we're done. Return x3 = 2.238095238095238
# -----------------------------------------
# Note: the roots of f are +/-sqrt(5) ~ +/-2.236067977499979,
# and if we had gone forward with one a couple more iterations, we'd obtain:
# x4 = 2.236088956433634, which has |f(x4)| = 0.000004106063.
# x5 = 2.23606797749978, which has ||f(x5)| = 0.0000000000008.
# How does this compare with Heron's method for computing square roots?
# That was the method in ASsignment 2.



# Problem (i), SCP II:
##########################################################
# Given 'function', 'derivative', x0, and epsilon as in the PDF,
#
# Set x <-- x0.
# If |function(x)| < epsilon, return x.
#
# for n from 1 to 25 do:
#       (1) if |dervative(x)| < epsilon, print a failure message and return.
#       (2) Otherwise, set:
#               x <-- x - function(x) / derivate(x)
#       (3) if |function(x)| < epsilon, return x.
#
# If we're here, that means we made it all the way through the loop
# without finding a zero of 'function', so print an error message
# and return None.



# Problem (i), SCP III:
##########################################################
# Let f(t) = t^4-16, x0=1, epsilon=0.1.
#
# x0 = 1
# ---------------------------------------
# Since |f'(x0)|>epsilon, we may compute x1:
# x1 = x0 - f(x0)/f'(x0)
#    = 1- (-15)/(4)
#    = 4.75.
# Since |f(x1)| = 4.75 >epsilon, not done yet.
# -----------------------------------------
# Since |f'(x1)| = |4(4.75^3)|=428.6875>epsilon, we may compute x2:
# x2 = x1 - f(x1)/f'(x1)
#    = 4.75 - (4.75^4 -16) / (4(4.75^3))
#    = 3.599823225
# Since |f(x2)| = |3.599823225^4 - 16| = 151.928612 > epsilon, not done yet.
# ----------------------------------------
# Since |f'(x2)| =  186.5965093 > epsilon, we may compute x3:
# x3 = x2 - f(x2)/f'(x2)
#    = 3.599823225 - (151.928612)/(186.596093)
#    = 2.785613932
# Since |f(x3)| = 44.21209019 > epsilon, not done yet.
# -----------------------------------------
# Since |f'(x3)| = |4(2.78561^3)|= 86.46150063 >epsilon, we may compute x4:
# x4 = x3 - f(x3)/f'(x3)
#    = 2.785613932 - (44.21209019) / (86.46150063)
#    = 2.274263911
# Since |f(x4)| = |2.274263911^4 - 16| = 10.75244251 > epsilon, not done yet.
# ----------------------------------------
# Since |f'(x4)| = |4(2.274263911^3)|= 47.05248564 >epsilon, we may compute x5:
# x5 = x4 - f(x4)/f'(x4)
#    = 2.274263911 - (10.75244251) / (47.05248564)
#    = 2.045743731
# Since |f(x5)| = |2.045743731^4 - 16| = 1.514789251 > epsilon, not done yet.
# ----------------------------------------
# Since |f'(x5)| = |4(2.045743731^3)|= 34.2463017 >epsilon, we may compute x6:
# x6 = x5 - f(x5)/f'(x5)
#    = 2.045743731 - (1.514789251) / (34.2463017)
#    = 2.001511531
# SINCE |f(x6)| = |2.001511531^4 - 16| = .0484238531 < epsilon, we're done.
# Return x6 = 2.001511531.

# Note: the roots of f are +/-sqrt(16) ~ +/- 2,
# and if we had gone forward with one a couple more iterations, we'd obtain:
# Some x value where |f(x_n)| will eventually reach 0.00000 .

######################
# Function: Newton() #
######################

def Newton(Function, Derivative, x0, epsilon):

    x_n = x0

    # Base Case
    if( abs(Function(x_n)) < epsilon):
        return x_n

    # Testing Loop
    for n in range(25):
        if( abs(Derivative(x_n)) < epsilon):
            print("[ERROR]: |f'(xn)| < epsilon")
            return None

        x_n = x_n - ( Function(x_n)/Derivative(x_n) )
        if( abs(Function(x_n)) < epsilon):
            return x_n

    print("[ERROR]: Made it out of the testing loop...")
    return None
    
###########
# Part 2: #
###########

def h(x):
    return (x**5) - (2*(x**4)) + (x**2) - (2*x) + 1



def dh(x):
    return (5*(x**4)) - (8*(x**3)) + (2*x) - 2

# Passing arguments to Newton function with initial guess, x0 = 1.
xn = Newton(h, dh, 1, 1e-10)
if type(xn) is float:
    print("For Function h(x): x^5 - 2x^4 + x^2 - 2x + 1")
    print("For a initial 'guess', x0 = 1:  ")
    print("h(%1.8f) = %1.8f \n" % (xn, abs(h(xn))) )
else:
    print("Newton's method failed with this initial point.")

###########
# Part 3: #
###########

# Note that 'math.exp(4)' :=  e^4

def G(x):
    return math.exp( (-2*(x**2)) ) - 0.5*math.sin(x) - 0.5



def dG(x):
    return -4*x*math.exp( (-2*(x**2)) ) - 0.5*math.cos(x) 

# Passing arguments to Newton function with initial guess, x0 = 1.
xn = Newton(G, dG, 1, 1e-10)
if type(xn) is float:
    print("For Function G(x): e^(-2x^2) - 0.5sin(x) - 0.5")
    print("For a initial 'guess', x0 = 1:  ")
    print("G(%1.8f) = %1.8f \n" % (xn, abs(G(xn))) )
else:
    print("Newton's method failed with this initial point.")



""" #####################################
    #   [GIVEN SNIPPET OF CODE BELOW]   #
    #####################################
"""

def f(t):
    return t**2-5

def df(t):
    return 2*t

xn = Newton(f, df, 1, 1e-10)
if type(xn) is float:
    print("f(%1.8f) = %1.8f" % (xn, f(xn)) )
else:
    print("Newton's method failed with this initial point.")
