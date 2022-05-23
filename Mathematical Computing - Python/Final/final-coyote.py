import random

# final-coyote.py
# Gabriel Coyote, 12/5/21
# FINAL


"""
Problem 2, SCP I:
########################################################

    Let N := 2, so we need to make two random triangles.
    

    Triangle A =
        area:= .11,
        perimeter := 1.5,
        area/perimeter := .07333.

    
    Triangle B =
        area:= .35,
        perimeter := 2.7,
        area/perimeter := .1296.

    Print the following values...
    let avgerage area := (.11 + .35)/2              := .23 .
    Let avgerage perimeter := (1.5 + 2.7) /2        := 2.1 .
    Let avg (area/perimeter) := (.07333+.1296) /2   := .1014 .

    
    Print (average area / avgerage perimeter) := .23 /2.1 := .1095 .

    
    
    



Problem 2, SCP II:
########################################################

    Given a 'N' amount of random triangles, print the
    average area, average perimeter, and average of area/perimeter.

    Do the following,
    initialize total_area & total_perim & ratio to zero.

    For each triangle TRI,
        add TRI's area to the total_area counter,
        add TRI's perimeter to the total_perim counter,
        calculate TRI's (area/perimeter) value and add it to ratio.

    Then print (total_area/N) for average area,
    print (total_perim/N) for average perimeter,
    print (total_area/total_perim) for average of area/perimeter.

    Finally print ( (total_area/N) / (total_perim/N) ) for avg_area/avg_perim.


        



Problem 2, SCP III:
########################################################

    Let N := 3, so we have three random triangles.    

    Triangle A =
        area:= .11,
        perimeter := 1.5,
        area/perimeter := .07333.

    
    Triangle B =
        area:= .35,
        perimeter := 2.7,
        area/perimeter := .1296.

    Triangle C =
        area:= .18 ,
        perimeter := 1.95,
        area/perimeter := .0923.

    Print the following values...
    let avgerage area := (.11 + .35 + .18)/3 := .2133 .
    Let avgerage perimeter := (1.5 + 2.7 + 1.95) /3 := 2.05 .
    Let avg (area/perimeter) := (.07333+.1296 + .0923) /3 := .09841 .

    
    Print (average area / avgerage perimeter) := .2133/2.05 := .10406 .


"""



class Polygon:
    def __init__(self):
        self.x = [] # self.x[i] is the x-coordinate of vertex 'i'.
        self.y = [] # self.y[i] is the y-coordinate of vertex 'i'.

    #######################################################
    def set_vertices(self, coordinates):
        # Set the vertices for this polygon.
        # 'coordinates' is a list of floats, interpretted as follows:
        # coordinates[0] is the x-coordinate of vertex 0,
        # coordinates[1] is the y-coordinate of vertex 0,
        # coordinates[2] is the x-coordinate of vertex 1,
        # coordinates[3] is the y-coordinate of vertex 1,
        # and so on.
        # The polygon has sides connecting:
        # vertex 0 and vertex 1,
        # vertex 1 and vertex 2,
        # ...
        # vertex (n-2) and vertex (n-1)
        # vertex (n-1) and vertex 0.
        n = len(coordinates)
        if n%2 != 0:
            print("set_vertices(): Error! 'coordinates' must contain an even number of elements!")
            return False
        self.x = [coordinates[2*i] for i in range(n//2)]
        self.y = [coordinates[2*i+1] for i in range(n//2)]
        return True

    ########################################################
    def num_vertices(self):
        # Return the number of vertices in this Polygon object
        return len(self.x)

    ########################################################
    def perimeter(self):
        # Return the perimeter of this Polygon object.
        n = self.num_vertices()
        p = 0
        for i in range(1,n+1):
            d2 = (self.x[i%n] - self.x[i-1])**2 + (self.y[i%n] - self.y[i-1])**2
            p += d2**(1/2)
        return p

    ########################################################
    def area(self):
        # Return the area of this Polygon object.
        n = self.num_vertices()
        s = 0
        for i in range(0, n):
            i1 = (i+1)%n
            s += self.x[i]*self.y[i1] - self.x[i1]*self.y[i]
        return abs(s/2)

    #########################################################
    def get_string(self):
        # Return a string representation of this Polygon
        n = self.num_vertices()
        result = "" # Start with empty string, and append each vertex to it.
        for i in range(n):
            result += "({0}, {1}) ".format(self.x[i], self.y[i])
        return result

"""/////////////////////////////////////////////////////"""
def random_triangle():
    vertices = []
    i = 0
    while i < 6:
        x = random.random()
        vertices.append(x)
        i = i + 1
        
    polygon = Polygon()
    polygon.set_vertices(vertices)
    return polygon



def experiment(N):
    area_total = 0
    perim_total = 0
    ratio_AP = 0

    for i in range(N+1):
        triangle = random_triangle()
        area_total = area_total + triangle.area()
        perim_total = perim_total + triangle.perimeter()

        ratio_AP = ratio_AP +( triangle.area() / triangle.perimeter() )


    print("Average Area: {0}\nAverage Perimeter: {1}\nAverage Area/Perimeter: {2}".format((area_total/N),(perim_total/N),(ratio_AP/N)))
    print("\n(avg area) / (avg perim) : {0}".format(( (area_total/N) / (perim_total/N) )))








"""--------------------------"""



for n in [10000 ,100000 ,1000000 ,10000000]:
    print(" ∗∗∗∗∗∗∗∗∗∗∗∗∗∗ {0} triangles ∗∗∗∗∗∗∗∗∗∗∗∗∗ ".format(n))
    experiment (n)
