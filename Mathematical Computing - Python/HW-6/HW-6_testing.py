

def gcd(a,b):
    print()
    print("Input: gcd({0},{1})".format(a,b))
    if b == 0:
        print("0 division done in the Return statement 'return a': " )
        return a
    print("1 division done in the Return statement 'return gcd(b, a%b)' \nwhich in this case is: 'return gcd({0},{1})'".format(b,a%b))
    return gcd(b, a%b)

print(gcd(1,3))
"""---------------------------------"""

# for part 4
def gcd_divops(a,b):
    if b==0:
        return 0
    return 1 + gcd_divops(b, a%b)

#print()
#print("The number of division is: %d" % gcd_divops(1644,1264))


"""---------------------------------"""




# hw6-coyote.py
# Gabriel Coyote, Mark Peralta, Vineel Kesavarapu
# 10/2/2021
# Assignment 6

"""
    It satisfies the worst-case bound
    as the average number of divisions needed <= 2 + 2 log2(b).
    Our guess is that the average number of divisions needed
    will never need more than 2 + 2 log2(b).

"""
# Problem (V), SCP I:
#      


# Problem (V), SCP II:
#       


# Problem (V), SCP III:
#




#For part 5
inputs_list = []
gcd_divops_list = []

for m in range(1,4):
    for n in range(1,4):
        # for an input (m,n) in the function gcd_divops
        inputs_list.append((m,n))
        gcd_divops_list.append(gcd_divops(m,n))
        
        
for i in range(len(inputs_list)):
    print("gcd_divops({0}) = {1}".format(inputs_list[i], gcd_divops_list[i]))

avg_num_divops = 0
for element in gcd_divops_list:
    avg_num_divops = avg_num_divops + element


avg_num_divops = avg_num_divops / len(inputs_list)

print("Average number of division ops for m,n in [1...4]: %f" %avg_num_divops)
