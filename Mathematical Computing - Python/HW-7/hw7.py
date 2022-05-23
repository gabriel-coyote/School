# hw7.py
# Implementation of a simple Polygon class


"""
  Problem 1, SCP Part I:
  ----------------------------------------------

  
  Problem 1, SCP Part II:
  ----------------------------------------------
  

  Problem 1, SCP Part III:
  ----------------------------------------------

  

  ##############################################

  Problem 2, SCP Part I:
  ----------------------------------------------
  

  Problem 2, SCP Part II:
  ----------------------------------------------


  Problem 2, SCP Part III:
  ----------------------------------------------


"""

class Polygon:
    ###########################################################
    def __init__(self):
        # Initialize a Polygon object.
        self.x = [] # self.x[i] is the x-coordinate of vertex 'i'.
        self.y = [] # self.y[i] is the y-coordinate of vertex 'i'.

    ###########################################################
    def set_vertices(self, coordinates):
        # Set the vertices for this Polygon object.
        # 'coordinates' is a list of floats, interpretted as follows:
        # coordinates[0] is the x-coordinate of vertex 1,
        # coordinates[1] is the y-coordinate of vertex 1,
        # coordinates[2] is the x-coordinate of vertex 2,
        # coordinates[3] is the y-coordinate of vertex 2,
        # and so on.
        # The polygon has sides connecting:
        # vertex 0 and vertex 1,
        # vertex 1 and vertex 2,
        # ...
        # vertex (n-2) and vertex (n-1)
        # vertex (n-1) and vertex 0.
        n = len(coordinates)
        if n%2 != 0:
            print("set_vertices()  Error: 'coordinates' must"+
                  "contain an even number of elements!")
            return False
        self.x = [coordinates[2*i] for i in range(n//2)]
        self.y = [coordinates[2*i+1] for i in range(n//2)]
        return True

    ##########################################################
    def num_vertices(self):
        # Return the number of vertices in this Polygon object.
        return len(self.x)


    ############################################################
    def perimeter(self):
        # Return the perimeter of this Polygon object.

        # Probem 1.
        # Delete this 'pass' statement, and replace it
        # with your implementation.
        pass

    ############################################################
    def area(self):
        # Return the area of this Polygon object.

        # Problem 2.
        # Again, delete this 'pass' statement, and replace it
        # with your implementation.
        pass

    ###########################################################
    def get_string(self):
        # Return a string representation of this Polygon object.
        # It will be a list of of the vertices, in order.
        n = self.num_vertices()
        result = "" # Start with empty string, and append each vertex to it.
        for i in range(n):
            result += "({0}, {1}) ".format(self.x[i], self.y[i])
        return result

############################################
# Do NOT change anything below here!!!!!!! #
############################################

P = Polygon() # Create a Polygon object, P.

# This next line sets 'P' to be the polygon
# whose vertices are (1,0),(2,-1),(3,0),(2,1).
# You should be able to work out by hand what the perimeter
# and area of this polygon are, so I suggest using this as
# one of your examples.
P.set_vertices([1,0,  2,-1,  3,0,  2,1])

# Print out some information about the Polygon P.
print("P has vertices : "+P.get_string())
p = P.perimeter()
print("Its perimeter is {0}".format(p))
a = P.area()
print("Its area is {0}".format(a))
