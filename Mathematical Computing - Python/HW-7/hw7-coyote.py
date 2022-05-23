# This is the general format;
#       You can reword it, and change line spaces.
#       




"""
  Problem 1, SCP Part I:
  ----------------------------------------------
        Suppose a polygon has these vertices coordinates,
        (1,0),(2,-1),(3,0),(2,1).

        To calculate the perimeter we need to know the edges' length.
        We can use the distance formula to calculate the edges length,
        length of edge = sqrt( (x_2-x_1)^2 + (y_2-y_1)^2 ).
        
        Edge 0 = sqrt((2-1)^2+(-1-0)^2)  =sqrt(2),
        Edge 1 = sqrt((3-2)^2+(0-(-1))^2)=sqrt(2),
        Edge 2 = sqrt((2-3)^2+(1-0)^2)   =sqrt(2),
        Edge 3 = sqrt((1-2)^2+(0-1)^2)   =sqrt(2),

        Perimeter := 4*sqrt(2) ,
        return perimeter.
        
  
  Problem 1, SCP Part II:
  ----------------------------------------------
        Suppose we represent a polygon in a plane,
        with n vertices (x_0, y_0), (x_1, y_1),...,(x_n-1, y_n-1).

        In addition, suppose an edge has a starting vertex coordinate (x & y value),
        and ending vertex coordinate (x & y value). 

            Let perimeter := perim, and
                let perim := 0.

                For each edge in polygon do the following,
                    perim += sqrt((x[ending_edge] - x[starting_edge])^2  + (y[ending_edge] - y[starting_edge])^2)

                {In other words: for each j from 0 to n-1 do:
                    perim += ((x[(i+1)%n] - x[i])**2  + (y[(i+1)%n] - y[i])**2) **(1/2)}
                    
            Finally return perim.
                
  Problem 1, SCP Part III:
  ----------------------------------------------
        Suppose a polygon has these vertices coordinates,
        (0,0),(4,0),(2,3).
        
        Edge 0 = sqrt((4-0)^2+(0-0)^2)  =4,
        Edge 1 = sqrt((2-4)^2+(3-0)^2)  =sqrt(13),
        Edge 2 = sqrt((0-2)^2+(0-3)^2)  =sqrt(13),

        Perimeter := 4+sqrt(13)+sqrt(13),
        ~ 11.211 ,
        return perimeter.
  

  ##############################################

  Problem 2, SCP Part I:
  ----------------------------------------------
        Suppose a polygon has these vertices coordinates,
        (1,0),(2,-1),(3,0),(2,1).

        With x & y values of,
            x[0]=1, y[0]=0  ,
            x[1]=2, y[1]=-1 ,
            x[2]=3, y[2]=0  ,
            x[3]=2, y[3]=1  .
        
        To calculate the area we do the following,
        A = .5 * | (x_0*y_1 - x_1*y_0)+(x_1*y_2 - x_2*y_1)+...+(x_n-1*y_0 - x_0*y_n-1) |.

        In other words we do the following,
            1st term = (1*(-1) - 2*0) = -1,
            2nd term = (2*0 - 3*(-1)) = 3,
            3rd term = (3*1 - 2*0)    = 3,
            4th term = (2*0 - 1*1)    = -1.

        Area = .5 * | (-1) + 3 + 3 + (-1) | = 2.

            
  Problem 2, SCP Part II:
  ----------------------------------------------
        Suppose we represent a polygon in a plane,
        with n vertices (x_0, y_0), (x_1, y_1),...,(x_n-1, y_n-1).

        To find its area using the formula derived from Green's Theorem,
        we do the following:
        
            There are terms we must caculate and then sum up.
            The terms follow this pattern,
                (x_0*y_1 - x_1*y_0) + (x_1*y_2 -  x_2*y_1) +...+ (x_n-1*y_0 -  x_0*y_n-1).
                { (term)            + (term)               +...+ (term)                 }


            So do the following:
                Let Area := 0,
                and   n  := the number of vertices.

                For i in range(n) do the following,
                    let term =  (x[i]*y[(i+1)%n] - x[(i+1)%n]*y[i]).
                    Area += term.

                Return (1/2)*abs(Area).

  Problem 2, SCP Part III:
  ----------------------------------------------
        Suppose a polygon has these vertices coordinates,
        (0,0),(4,0),(2,3).

        With x & y values of,
            x[0]=0, y[0]=0  ,
            x[1]=4, y[1]=0  ,
            x[2]=2, y[2]=3  .

        To calculate the area we do the following,
        A = .5 * | (x_0*y_1 - x_1*y_0)+(x_1*y_2 - x_2*y_1)+...+(x_n-1*y_0 - x_0*y_n-1) |.

        In other words we do the following,
            1st term = (0*0 - 4*0)   = 0,
            2nd term = (4*3 - 2*(0)) = 12,
            3rd term = (2*0 - 0*3)   = 0,
           
        Area = .5 * | 0 + 12 + 0 | = 6.

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
        """
        ##########################################
        # You can have different variables names #
        ##########################################
        """
        
        perim = 0
        n = self.num_vertices()
        
        for i in range(n):
            perim += ( (self.x[(i+1)%n] - self.x[i])**2  + (self.y[(i+1)%n] - self.y[i])**2 )**(1/2)

        return perim

    ############################################################
    def area(self):
        """
        ##########################################
        # You can have different variables names #
        ##########################################
        """
        
        area = 0
        n = self.num_vertices()
        
        for i in range(n):
            term = (self.x[i]*self.y[(i+1)%n] - self.x[(i+1)%n]*self.y[i])
            area += term
            
        return (1/2)*abs(area)
    
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
