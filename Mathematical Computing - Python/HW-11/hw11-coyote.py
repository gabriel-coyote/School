# hw11-coyote.py
# Gabriel Coyote, 11/14/2021

import tkinter as tk
import cmath
import math


# Problem (i), SCP I:
##########################################################
#   Given an integer 'N' := 4 and a complex number 'c' := 2 + 1j.
#
#   Set z0 := 0, and
#   z_1 := z_0^2 + c    := 0^2 + (2+1j),        z_1 := (2+1j).
#   |z_1| < 20, so compute next term. 
#   z_2 := z_1^2 + c    := (2+1j)^2 + (2+1j),   z_2 := (5+5j).
#   |z_2| < 20, so compute next term.
#   z_3 := z_2^2 + c    := (5+5j)^2 + (2+1j),   z_3 := (2+51j).
#   |z_3| > 20, so returning 3.
#



# Problem (i), SCP II:
##########################################################
#   Given a a complex number 'c' and a integer 'N', we must compute a
#   sequence until an element |z_k| > 20, or we reach the the 'N' term.
#   While returning the last term reached, so do the following.
#
#       Set z_k := 0,
#       for i in range (N+1) do the following.
#           Set new value of z_k := z_k^2 + c,
#               and if |z_k| > 20 then return i.
#
#       Otherwise return N. 



# Problem (i), SCP III:
##########################################################
#   Given an integer 'N' := 6 and a complex number 'c' := 1-2j.
#
#   Set z0 := 0, and
#
#   z_1 := z_0^2 + c    := 0^2 + (1-2j),        z_1 := (1-2j).
#   |z_1| < 20, so compute next term.
#   z_2 := z_1^2 + c    := (1-2j)^2 + (1-2j),   z_2 := (-2-6j).
#   |z_2| < 20, so compute next term.
#   z_3 := z_2^2 + c    := (-2-6j)^2 + (1-2j),  z_3 := (-31+22j).
#   |z_3| > 20, so returning 3.



########################################################
def Iterate(c, N):
    # Problem 1 is to write this function.
    #
    # Consider the sequence of complex numbers defined by
    # z_0 = 0,
    # z_{n+1} = z_n^2 + c.
    # Start computing this sequence until we either encounter
    # an element with |z_k| > 20 or we reach z_N.
    # Return the number of elements which were computed.

    # Delete this return statement and place your code here.
    # return 0

    z_k = 0
    for i in range(N+1):
        z_k = (z_k**2) + c
        if(abs(z_k) > 20):
            return i
        
        
    return N

#########################################################
def colorFromRGB(r, g, b):
    # R, G, B are floating point numbers between 0 and 1 describing
    # the intensity level of the Red, Green and Blue components.
    X = [int(r*255), int(g*255), int(b*255)]
    for i in range(3):
        if X[i]<0:
            X[i] = 0
        if X[i]>255:
            X[i]=255
    color = "#%02x%02x%02x"%(X[0],X[1],X[2])
    return color


##############################################################
class MyApplication(tk.Frame):
    def __init__(self, master, centerX, centerY, width, height):
        super().__init__(master)
        self.master = master
        self.canvasW = 800
        self.canvasH = 600
        self.w = tk.Canvas(self.master, width=self.canvasW, height=self.canvasH)
        self.w.pack()
        self.maxIts = 100
        self.TL_x = centerX - width/2.0
        self.TL_y = centerY + height/2.0
        self.BR_x = centerX + width/2.0
        self.BR_y = centerY - height/2.0
        self.cartesianWidth = self.BR_x - self.TL_x
        self.cartesianHeight = self.TL_y - self.BR_y

 
        self.drawingInProgress = False
        self.master.bind('<KeyPress>', self.keydown)
        self.master.bind('<KeyRelease>', self.keyup)
        self.interrupt_drawing = False
        self.create_color_list()
    ###########################################################
    def create_color_list(self):
        self.colors = []
        for k in range(self.maxIts+1):
            if k==self.maxIts:
                self.colors.append(colorFromRGB(0,0,0))
            else:
                t = (k/float(self.maxIts))*2.0*3.1415926535
                B = (1.0+math.cos(1.0+t*3.1415926/5.0))/2.0
                G = (0.5+math.cos(1.0+t+3.0*3.1415926/5.0))/2.0
                R = (0.8+math.cos(1.0+t+2.0*3.1415926/5.0))/2.0
                self.colors.append(colorFromRGB(R, G, B))

    ##############################################################
    def keydown(self, e):
        # If there is a drawing in progress, interrupt it
        # by setting this flag, which will be periodically checked by the
        # drawing function:
        if self.drawingInProgress:
            self.interrupt_drawing= True
            return
            
        
        w = self.BR_x - self.TL_x
        h = self.TL_y - self.BR_y
        cx = self.TL_x + w/2.0
        cy = self.BR_y + h/2.0
        print("Currently: %f x %f, centered at %f,%f" % (w,h,cx,cy))
        if e.keysym == 'Up':
            cy -= h/3.0
        if e.keysym == 'Down':
            cy += h/3.0
        if e.keysym == 'Left':
            cx -= w/3.0
        if e.keysym == 'Right':
            cx += w/3.0
        if e.keysym == 'equal': # Zoom in
            w *= 0.6 
            h *= 0.6
        if e.keysym == 'minus': # Zoom out
            w *= 1.0/0.6
            h *= 1.0/0.6
        # Recompute the coordinates of the top-left corner and bottom right corner.
        self.TL_x = cx - w/2.0
        self.TL_y = cy + h/2.0
        self.BR_x = cx + w/2.0
        self.BR_y = cy - h/2.0
        self.cartesianWidth = self.BR_x - self.TL_x
        self.cartesianHeight = self.TL_y - self.BR_y
        
        
        # Clear the canvas and free associated memory:
        self.w.delete("all")
        # And re-draw
        self.update_screen()
        self.drawScreen()
        
    #####################################
    def keyup(self, e):
        pass

    #####################################
    def update_screen(self):
        self.master.update_idletasks()
        self.master.update()

    #####################################
    def drawScreen(self):
        self.drawIt()
        self.update_screen()

    #####################################
    def label_screen(self, color):
        t1 = "%f+%fi"%(self.TL_x,self.TL_y)
        t2 = "%f+%fi"%(self.BR_x,self.BR_y)
        self.w.create_text(0, 0, text=t1,anchor="nw",fill=color) 
        self.w.create_text(self.canvasW-1, self.canvasH-1, text=t2,anchor="se",fill=color)

    #######################################################        
    def plotPoint(self,x, y, color):
        self.w.create_rectangle(x, y, x+1, y+1, fill=color,outline='')

    #######################################################
    def pixelW(self):
        # Gives the width of each pixel in Cartesian coordinates.
        return (self.BR_x - self.TL_x)/float(self.canvasW)
    
    ########################################################
    def pixelH(self):
        # Gives the height of each pixel in Cartesian coordinates.
        return (self.TL_y - self.BR_y)/float(self.canvasH)

    #########################################################
    def canvas_width(self):
        return self.canvasW

    #########################################################
    def canvas_height(self):
        return self.canvasH

    #########################################################
    def canvas_to_cartesian(self, pixelX, pixelY):
        # Returns Cartesian coordinates associated with (a corner of)
        # the given pixel.
        x = self.TL_x + pixelX * self.pw;
        y = self.BR_y + pixelY * self.ph
        return x,y

    #########################################################
    def drawIt(self):
        w = self.canvasW
        h = self.canvasH
        self.pw = self.pixelW()
        self.ph = self.pixelH()

        self.drawingInProgress = True # Ignore events until this is done.
        ##############################################################
        # Loop over all the pixels in the plot. Determine a color for
        # each pixel and plot it.
        ##############################################################
        for i in range(w):
            x,y = self.canvas_to_cartesian(i,0)
            for j in range(h):
                # Get the cartesian coordinates (x,y) of the pixel at
                # position (i,j) in the window. (Don't need to change)
                #x,y = self.canvas_to_cartesian(i, j)
                y += self.ph
                # Do some calculation that tells me how to color the
                # point (x,y):
                color = self.getPointColor(x, y)


                # Plot the point.
                self.plotPoint(i,j,color)

            if (i%20==0):
                # This will update the actual on-screen window. We only do
                # it once in a while because it is a relatively slow operation.
                # If we did it after each individual pixel it would slow
                # things down a lot and you might not have that kind of time to wait.
                self.update_screen()
                if self.interrupt_drawing == True:
                    self.interrupt_drawing = False
                    self.drawingInProgress = False
                    return
        self.update_screen()
        self.drawingInProgress = False
        # Draw coordinate labels on the image so we can tell what the scale is.
        self.label_screen("white");
        self.update_screen()

    ############################################################
    def getPointColor(self,x, y):
        # Do something to figure out what color the point (x,y)
        # should be painted.
        k = Iterate(x+y*1j, self.maxIts)
        # Choose a color that depends on k.
        return self.colors[k]



root = tk.Tk()
app = MyApplication(root,0,0,4,3)
app.drawScreen()
app.mainloop()
