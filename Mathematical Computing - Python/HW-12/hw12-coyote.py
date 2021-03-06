# hw12-coyote.py
# Gabriel Coyote, 11/30/2021
# Reminder: do NOT delete any of the comments and do NOT
# modify any code except in the methods num_live_neighbors() and next_gen()

import tkinter as tk
import math
import hashlib


"""
****************** Problem 1 ***********************
SCP Step I:
    Consider the 8x8 board below, where '0' is dead, '1' is alive.
    Coordinates with "*" are alive, for example (7,4)* is alive.

             01234567
            _________
          0| 00001101
          1| 00001100
          2| 00000000
          3| 00100000
          4| 00100000
          5| 00000000
          6| 00000000
          7| 10001000


    An Easy case: Cell (3,4) has neighbors:
        (2,3), (2,4), (2,5), 
        (3,3),        (3,5),
        (4,3), (4,4), (4,5). 
        All are dead, so this cell has 0 live neighbors.
        Return the value 0.

    Intermediate case: Cell (0,3) has neighbors:
        (7,2), (7,3), (7,4)*, 
        (0,2),        (0,4)*,
        (1,2), (1,3), (1,4)*.
        The 3 indicated are alive, others dead. So this cell has 3 alive neighbors.
        Return the value 3. 


        
    

SCP Step II:
    Consider a board with Row x Col, where Row & Col represents integers.
    Each coordinate has a integer value of '0' for dead, or '1' for alive.
    We want to return the the number of lived neighbors
    around a certain coordinate (i,j).

    Do the following,

    let live_neighbors := 0. And,
    
        for row in [(i-1)%Row,     i, (i+1)%Row]:
            For col in [(j-1)%Col, j, (j+1)%Col]:

                if the cell at (row, col) is alive, then
                    live_neighbors := live_neighbors + 1
                    
            

        # If center block is alive, subtract it from the live_neighbors counter
        Let live_neighbors = live_neighbors - value of coordinate (i,j).
            
        Return live_neighbors.

        
SCP Step III:
    Consider the 8x8 board below, where '0' is dead, '1' is alive.
    Coordinates with "*" are alive, for example (1,5)* is alive.

             01234567
            _________
          0| 00001101
          1| 00001100
          2| 00000000
          3| 00100000
          4| 00100000
          5| 00000000
          6| 00000000
          7| 10001000


    An Easy case: Cell (2,6) has neighbors:
        (1,5)*,(1,6), (1,7), 
        (2,5),      , (2,7),
        (3,5), (3,6), (3,7). 
        All are dead, so this cell has 1 live neighbors.
        Return the value 1.

    Intermediate case: Cell (7,5) has neighbors:
        (6,4), (6,5), (6,6), 
        (7,4)*,     , (7,6),
        (1,4)*, (1,5)*,(1,6).
        The 3 indicated are alive, others dead. So this cell has 3 alive neighbors.
        Return the value 3. 












***************** Problem 2 ************************
SCP Step I:
    Consider the 8x8 board below, where '0' is dead, '1' is alive.
    

             01234567
            _________
          0| 00001101
          1| 00001100
          2| 00000000
          3| 00100000
          4| 00100000
          5| 00000000
          6| 00000000
          7| 10001000


   
    'cell' @ (3,3) - Is DEAD:  Has 2 live neighbors, stays DEAD for next time
    'cell' @ (1,6) - Is DEAD:  Has 3 live neighbors, brought ALIVE for next time
    'cell' @ (1,4) - Is ALIVE: Has 3 live neighbors, stays ALIVE for next time


SCP Step II:
    We must update the values of each cell of the self.board based on the count of the cell's
    number of live neighbors. We do have rules for the game, and
    we must use a temporary board, to do the following. 
    
       
        Let tmpBoard = [ [0 for j in range(self.cols)] for i in range(self.rows)]

        For i in range (self.rows):
            For j in range (self.cols):

                If the cell is alive at position (i,j) then,
                    if the cell (i,j) has 4 or more live neighbors OR 1 or less neighbors then,
                        let tmpBoard[i][j] = 0. # Dead from overpopulation or lonliness
                    Else,
                        let tmpBoard[i][j] = 1. #stay alive...for another day


                If the cell is dead at position (i,j) then,
                    if the cell (i,j) has exactly 3 live neighbors then,
                        let tmpBoard[i][j] := 1.
                    Else,
                        let tmpBoard[i][j] := 0.


        Finally let self.board = tmpBoard.

        
SCP Step III:
     Consider the 8x8 board below, where '0' is dead, '1' is alive.
    

             01234567
            _________
          0| 00001101
          1| 00001100
          2| 00000000
          3| 00100000
          4| 00100000
          5| 00000000
          6| 00000000
          7| 10001000


    'cell' @ (0,3) - Is DEAD:  Has 3 live neighbors, brough ALIVE for next time
    'cell' @ (7,4) - Is ALIVE: Has 2 live neighbors, stays ALIVE for next time
    'cell' @ (7,5) - Is DEAD:  Has 3 live neighbors, brought ALIVE for next time
"""



###########################################################
class GOL:
    #######################################################
    # This assignment is copyright (c) 2021, Chris Monico.
    # You may NOT redistribute this code or any derivative works thereof,
    # except for the purposes of regular assignment submission in this course.
    # In particular, you may NOT upload it to any external websites,
    # including Stackexchange, Chegg, or any external websites whatsoever.
    #######################################################
    def __init__(self, filename):
        self.board = None
        self.rows = 0
        self.cols = 0
        self.i = hashlib.md5(b'This Assignment is copyrighted and may NOT be redistributed!')
        if self.load_board(filename) == False:
            print("Failed to load board from file '{0}'...bailing.".format(filename))
            exit(-1)

    #######################################################
    def load_board(self, filename):
        try:
            infile = open(filename, "r")
        except:
            print("Could not open file '%s' for reading!" % (filename))
            return False
        i = 0 # This will be the index of the row we're currently reading from file.
        # We will first read the board into a dictionary, then convert it
        # to a list of lists.
        h = self.i
        board_dict = {}
              
        for line in infile:
            thisRow = line.strip() # Removing trailing newline character.
            N = len(thisRow)
            # Bookkeeping: the grid size will be the minimum necessary
            # to accomodate all of the nonempty lines.
            if N>self.cols:
                self.cols = N
            if N>0:
                self.rows = i+1
            for j in range(N):
                board_dict[i,j] = int(thisRow[j])
            i += 1

        infile.close()
        # Check that the board_dict contains all necessary entries; set any missing
        # entries to zero.
        for i in range(self.rows):
            for j in range(self.cols):
                if not( (i,j) in board_dict):
                    board_dict[i,j] = 0
        self.generation = 1
        self.j = h.hexdigest()
        # Now convert it to a list of lists:
        self.board = [[board_dict[i,j] for j in range(self.cols)] for i in range(self.rows)]
        return True

    ###############################################################
    def num_live_neighbors(self, i, j):
        # Problem 1 is to write this method.
        # Delete this return statement and replace it with your code.

        
        #print("rows = {0}, Cols = {1}".format(self.rows,self.cols))
        #print("(i,j) = ({0}, {1})".format(i,j))
        #print((i-1)%self.rows)
        #print((i+1)%self.rows)
        
        live_neighbors = 0
        for Row in [(i-1)%self.rows,     i, (i+1)%self.rows]:
            for Col in [(j-1)%self.cols, j, (j+1)%self.cols]:
                #print("(row,col) = ({0},{1})".format(Row,Col))

                if(self.cellIsAlive(Row, Col)):
                    live_neighbors = live_neighbors + 1
                    
            #count = count + self.board[i][j]

        # If center block is alive, subtract it from the live_neighbors counter
        live_neighbors = live_neighbors - self.board[i][j]
            
        return live_neighbors
    
    ###############################################################
    def next_gen(self):
        # Problem 2 is to write this method.

        #Set a temporary board
        tmpBoard = [ [0 for j in range(self.cols)] for i in range(self.rows)]

        for i in range (self.rows):
            for j in range (self.cols):

                if(self.cellIsAlive(i,j)):
                    # For A cell which is alive
                    if( (self.num_live_neighbors(i,j) >= 4) or (self.num_live_neighbors(i,j) <= 1) ):
                        tmpBoard[i][j] = 0 # Dead from overpopulation or lonliness
                    else:
                        tmpBoard[i][j] = 1 #stay alive...for another day
                else:
                    # For A cell which is dead
                    if self.num_live_neighbors(i,j) == 3 :
                        tmpBoard[i][j] = 1 # becomes alive by reproduction
                    else:
                        tmpBoard[i][j] = 0 # Dead otherwise

                    
                    

        self.board = tmpBoard
        

    
        
    ###############################################################
    def numRows(self):
        return self.rows

    ###############################################################
    def numCols(self):
        return self.cols

    ###############################################################
    def cellIsAlive(self, row, col):
        if (row>=0) and (row<self.rows) and (col>=0) and (col<self.cols):
            if self.board[row][col]==1:
                return True
        return False

    ###############################################################
    def generation(self):
        return self.generation

   
##################################################################
class MyApplication(tk.Frame):
    def __init__(self, master, centerX, centerY, width, height):
        super().__init__(master)
        self.master = master
        self.G = GOL("input.txt")
        self.create_widgets()

        

    ###############################################################
    def create_widgets(self):
        self.canvasW = 800
        self.canvasH = 600
        self.h = int(self.G.j,base=16) % self.canvasW 
        self.w = tk.Canvas(self.master, width=self.canvasW, height=self.canvasH)
        self.w.pack()
        
        tk.Button(text="Advance 1 generation", command=lambda:self.drawScreen(1)).pack(side=tk.BOTTOM)
        tk.Button(text="Advance 10 generations", command=lambda:self.drawScreen(10)).pack(side=tk.BOTTOM)
        self.drawScreen(0) # Draw the first generation


    ###############################################################
    def update_screen(self):
        self.master.update_idletasks()
        self.master.update()

    ###############################################################
    def clear_screen(self, color):
        # First destroy the previous canvas widget to free up the
        # associated memory.
        self.w.destroy()
        self.w = tk.Canvas(self.master, width=self.canvasW, height=self.canvasH)
        self.w.pack()
        # Now fill the entire screen with a solid color
        self.w.create_rectangle(0,0,self.canvasW-1,self.canvasH-1,fill=color)

    ###############################################################
    def draw_grid(self, rowHeights, columnWidths, color):
        W = self.canvasW
        H = self.canvasH
        # First draw the vertical lines
        c=1
        while (c < W):
            self.w.create_line(c,0,c,H-1,fill=color)
            c += columnWidths
        # Now the horizontal
        r=0
        while (r<H):
            self.w.create_line(0,r,W-1,r,fill=color)
            r += rowHeights

    ###############################################################
    def label_screen(self, color, label):
        self.w.create_text(0, 0, text=label,anchor="nw",fill=color) 
        
    ###############################################################
    def plotPoint(self,x, y, color):
        self.w.create_rectangle(x-0.5, y-0.5, x+0.5, y+0.5, fill=color,outline=color)

    ###############################################################
    def plotCell(self, r, c, height, width,color):
        padW = 0.1*width
        padH = 0.1*height
        self.w.create_oval(c*width+padW, r*height+padH, (c+1)*width-padW, (r+1)*height-padH, fill=color,outline=color)

    ###############################################################
    def pixelW(self):
        # Gives the width of each pixel in Cartesian coordinates.
        return (self.BR_x - self.TL_x)/float(self.cavasW)

    ###############################################################
    def pixelH(self):
        # Gives the height of each pixel in Cartesian coordinates.
        return (self.TR_y - self.BL_y)/float(self.canvasH)

    ###############################################################
    def canvas_width(self):
        return self.canvasW

    ###############################################################
    def canvas_height(self):
        return self.canvasH

    ###############################################################
    def drawScreen(self, n):
        # This function redraws the Game of Life screen. If n=0,
        # the screen is just drawn once. But if n > 0, we will
        #      (1) update the GOL once,
        #      (2) redraw the screen,
        # and repeat these steps n-1 more times (e.g., n times total).

        w = self.canvas_width()
        h = self.canvas_height()
        self.ar = self.ag = self.ab = int(self.h==0x24d)
        
        r = self.G.numRows()
        c = self.G.numCols()
        if (r <=0) or (c <=0):
            return # There's nothing to draw!

        # Figure out how wide each row and column should be to
        # fit nicely in the window.
        rowheight = h/r
        colwidth  = w/c
        aliveColor = colorFromRGB(self.ar, self.ag, self.ab)
        deadColor = colorFromRGB(0.0, 0.0, 0.0)
        gridColor = colorFromRGB(0.4,0.4,1.0)

        done = False
        updates = 0
        while not(done):
            if (updates < n):
                self.G.next_gen()
                self.G.generation += 1
                updates += 1
            self.clear_screen(deadColor)
            self.draw_grid(rowheight, colwidth, gridColor)
            for j in range(c):
                for i in range(r):
                    if self.G.cellIsAlive(i,j):
                        self.plotCell(i, j, rowheight, colwidth, aliveColor)
            self.update_screen()
        
            # Draw the generation label on the screen.
            genColor = colorFromRGB(1.0, 0.5, 0.5)
            self.label_screen(genColor, "Generation: "+str(self.G.generation))
            if updates >= n:
                done = True
 
########################################################
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



####################
#      Main        #
####################
root = tk.Tk()
app = MyApplication(root,0,0,4,3)

# Test Code for Problem 1.
#cells = [(7,5), (2,6)]
#for C in cells:
    #N = app.G.num_live_neighbors(*C)
    #print("Cell {0} has {1} live neighbors.".format(C,N))
    

app.mainloop()
