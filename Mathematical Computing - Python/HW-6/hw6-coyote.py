# hw6-coyote.py
# Gabriel Coyote, Mark Peralta, Vineel Kesavarapu
# All members of the group contributed roughly equally to this work.
# 10/5/2021
# Assignment 6


# GIVEN GCD function
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a%b)

"""---------------------------------"""


# Problem (IV)
def gcd_divops(a,b):
    if b==0:
        return 0
    return 1 + gcd_divops(b, a%b)


"""---------------------------------"""



# Problem (V), SCP I:
#       Let range of m & n be [1,3].
#       Let total_num_divops & pairs both equal 0.
#
"""
Add gcd_divops(1,1) [which is 1] to total_num_divops, 
	  total_num_divops = 1.
	Adding one to pairs leaves us with 1 pairs.
	
Add gcd_divops(1,2) [which is 2] to total_num_divops, 
	  total_num_divops = 3.
	Adding one to pairs leaves us with 2 pairs.
	
Add gcd_divops(1,3) [which is 2] to total_num_divops, 
	  total_num_divops = 5.
	Adding one to pairs leaves us with 3 pairs.
	
Add gcd_divops(2,1) [which is 1] to total_num_divops, 
	  total_num_divops = 6.
	Adding one to pairs leaves us with 4 pairs.
	
Add gcd_divops(2,2) [which is 1] to total_num_divops, 
	  total_num_divops = 7.
	Adding one to pairs leaves us with 5 pairs.
	
Add gcd_divops(2,3) [which is 3] to total_num_divops, 
	  total_num_divops = 10.
	Adding one to pairs leaves us with 6 pairs.
	
Add gcd_divops(3,1) [which is 1] to total_num_divops, 
	  total_num_divops = 11.
	Adding one to pairs leaves us with 7 pairs.
	
Add gcd_divops(3,2) [which is 2] to total_num_divops, 
	  total_num_divops = 13.
	Adding one to pairs leaves us with 8 pairs.
	
Add gcd_divops(3,3) [which is 1] to total_num_divops, 
	  total_num_divops = 14.
	Adding one to pairs leaves us with 9 pairs.


Let avg_num_divops = total_num_divops / pairs,
    so avg_num_divops = 14 / 9.

Average number of division ops for m,n in [1...3]: 1.555556
"""




# Problem (V), SCP II:
#       Suppose we want the average number of divisions done
#       for gcd(m,n) where m and n are permutations in range [1,10],
#       then range[1,100], and range[1,1000].
#       
#       We have function (from part 4) gcd_divops(m,n) that
#       returns the number of division performed for integers m and n.
#
#       Let total_num_divops and pairs be an integer initializes to 0.
#       Let x be the upper bound of the range.
#       Let x := 10 or 100, or 1000.
#
#           For m in range[1,x] do the following.
#               For n in range[1,x] do the following,
#                   compute the gcd_divops(m,n) and add it to the total_num_divops.
#                   Let pairs := pairs + 1.
#
#       Let avg_num_divops := total_num_divops divided by the value in pairs.
#


# Problem (V), SCP III:
#
"""
Add gcd_divops(1,1) [which is 1] to total_num_divops, 
	  total_num_divops = 1.
	Adding one to pairs leaves us with 1 pairs.
	
Add gcd_divops(1,2) [which is 2] to total_num_divops, 
	  total_num_divops = 3.
	Adding one to pairs leaves us with 2 pairs.
	
Add gcd_divops(2,1) [which is 1] to total_num_divops, 
	  total_num_divops = 4.
	Adding one to pairs leaves us with 3 pairs.
	
Add gcd_divops(2,2) [which is 1] to total_num_divops, 
	  total_num_divops = 5.
	Adding one to pairs leaves us with 4 pairs.


Let avg_num_divops = total_num_divops / pairs,
    so avg_num_divops = 5 / 4.

Average number of division ops for m,n in [1...2]: 1.250000
"""






"""
    Answer to Part 5:
    
    It satisfies the worst-case bound
    as the average number of divisions needed <= 2 + 2 log2(b).
    Our guess is that the average number of divisions needed
    will never need more than 2 + 2 log2(b).

"""




range_list = {11,101,1001}
for element in range_list:

    total_num_divops = 0
    pairs = 0
    
    for m in range(1,element):
        for n in range(1,element):
            # for an input (m,n) in the function gcd_divops
            total_num_divops = total_num_divops +(gcd_divops(m,n))
            pairs = pairs + 1
       

    avg_num_divops = total_num_divops / pairs
    print("\nAverage number of division ops for m,n in [1...{0}]: {1}" .format(element-1,avg_num_divops))


# QUESTION 5: 
# [1] How does this seem to compare with the worst-case bound you obtained in Problem 3?
#
#       It satisfies the condition that it will not need more than the worst-case bound 2 + 2log(b) divisions to compute gcd of a & b.
#
# [2] Can you make a guess about the average number of divisions needed?
#
#       The average number of divisions will most likely be under 2+2log(b) divisions.
