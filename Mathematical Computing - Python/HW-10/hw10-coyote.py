# hw10-coyote.py
# Gabriel Coyote, 11/6/21
# Graphical illustration of Newton's Method for functions
# from C to C.

import tkinter as tk
import cmath
import math

# [Note]: From printing the values we get,
#---------------------------------------------------------
#   self.top_left = (-2.002503128911139+1.5025041736227045j)
#                 ~ (-2 + 1.5j)
#   self.pixel_width = 0.0050062578222778474    ~ 0.005
#   self.pixel_height = 0.005008347245409015    ~ 0.005 



# Problem (ii), SCP I:
##########################################################
#
# Given the center of the top_left pixel (-2 + 1.5j) and a pixel width and height of
# 0.005. Then to compute the center_pixel of (3,1) we do the following,
#
#       .005 * 3 = .015,
#       .005 * 1 = .005,
#
#       ( (-2+.015)  + (1.5-.005)j .
#
# The center_pixel of (3,1) is -1.985 + 1.495j.


# Problem (ii), SCP II:
##########################################################
#
# Given a complex number for the top_left pixel, pixel_width and pixel_height, 
# and a (x,y), then to find the center of (x,y) we do the following,
#
#    Set new_real := top_left.real + (pixel_width * x),
#    and new_imag := top_left.imag - (pixel_height * y).
#
#    Then finally let center_pixel := new_real + new_imag*1j,
#    and return center_pixel.


# Problem (ii), SCP III:
##########################################################
#
# Given the center of the top_left pixel (-2 + 1.5j) and a pixel width of .04 and height of
# 0.03. Then to compute the center_pixel of (10,5) we do the following,
#
#       .04 * 10 = .4,
#       .03 * 5 = .15,
#
#       ( (-2+.4)  + (1.5-.15)j .
#
# The center_pixel of (10,5) is -1.6 + 1.35j.


def Newton(Function, Derivative, z0, epsilon):
    z_n = z0

    # Base Case
    if( abs(Function(z_n)) < epsilon):
        return z_n

    # Testing Loop
    for n in range(25):
        if( abs(Derivative(z_n)) < epsilon):
            #print("[ERROR]: |f'(xn)| < epsilon")
            return None

        z_n = z_n - ( Function(z_n)/Derivative(z_n) )
        if( abs(Function(z_n)) < epsilon):
            return z_n

    #print("[ERROR]: Made it out of the testing loop...")
    return None
    


def colorFromRGB(r, g, b):
    # R, G, B are floating point numbers between 0 and 1 describing
    # the intensity level of the Red, Green and Blue components.
    X = [int(r*255), int(g*255), int(b*255)]
    for i in range(3):
        X[i] = min(max(X[i],0), 255)
    color = "#%02x%02x%02x"%(X[0],X[1],X[2])
    return color

def color_from_comp(z):
    x = z.real*2.7
    y = z.imag*2.7
    r = 0.5*(1.0 + math.tanh(x))
    g = 0.5*(1.0 + math.sin(x*y))
    b = 0.5*(1.0 + math.cos(x+y))
    return colorFromRGB(r, g, b)

def F(z):
    
    # Has 7 roots
    # Has one real root
    # The other 6 roots live in the complex plane, equally apart
    return z**7 -1

def dF(z):
    return 7*z**6

#############################################################
class MyApplication(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.pack()
        
        self.screen_width = 800
        self.screen_height = 600
        self.set_region(0+0j, 4)
        self.create_widgets()
        
    def set_region(self, center, region_width):
        # This sets the region of the complex plane to be displayed
        # on the canvas, by specifying the center and width of that region.
        # The height is then determined from the aspect ratio of the canvas.
        # Using those, we set the attributes:
        # self.pixel_width : complex width of each pixel,
        # self.pixel_height: complex height of each pixel
        # self.top_left : complex number at the center of the top-left pixel.
        self.pixel_width = region_width/(self.screen_width-1)
        
        region_height = self.screen_height * region_width/self.screen_width

        self.pixel_height = region_height / (self.screen_height - 1)

        x = center.real - self.pixel_width*(self.screen_width/2)
        y = center.imag + self.pixel_height*(self.screen_height/2)

        self.top_left = x + 1j*y

        #print("self.top_left = {0}".format(self.top_left))
        #print("self.pixel_width = {0}".format(self.pixel_width))
        #print("self.pixel_height = {0}".format(self.pixel_height))
        

    def update_screen(self):
        self.master.update_idletasks()
        self.master.update()

    def create_widgets(self):
        # First, a Canvas widget that we can draw on. It will be 800 pixels wide,
        # and 600 pixels tall.
        self.canvas = tk.Canvas(self.master,
                                width=self.screen_width,
                                height=self.screen_height,
                                background="white")
        # This 'pack' method packs it into the top-level window.        
        self.canvas.pack()

















    def pixel_center(self, x, y):
        # Return the complex number corresponding to the center of the
        # given pixel.
        # This is problem 2; delete the 'pass' statement and write this method.

        new_real = self.top_left.real + (self.pixel_width*x)
        new_imag = self.top_left.imag - (self.pixel_height*y)

        center_pixel = new_real + new_imag*1j
        
        return center_pixel

    def draw_pixel(self, x, y, C):
        self.canvas.create_rectangle(x-0.5, y-0.5, x+0.5, y+0.5, fill=C, outline="")

    def draw_newton_plot(self):
        for i in range(self.screen_width):
            for j in range(self.screen_height):
                z = self.pixel_center(i, j)
                root = Newton(F, dF, z, 0.00001)
                if type(root) is complex:
                    color = color_from_comp(root)
                else:
                    color="black"
                self.draw_pixel(i, j, color)
            if i%20 == 0:
                self.update_screen()


##############################################################



root = tk.Tk()
app = MyApplication(master=root)
app.draw_newton_plot()
app.mainloop()

