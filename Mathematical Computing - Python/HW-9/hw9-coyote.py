# hw9-coyote.py
# Gabriel Coyote, 10/31/21
###################################

import tkinter as tk


# Define a class for our application,
# which inherits from tk.Frame.
class MyApplication(tk.Frame):
    ##########################################
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.pack()
        # self.handle_list is to remember handles
        # to some of the things we draw,
        # so that we can erase them later.
        self.handle_list = []
        # Create all the widgets we want in
        # our window at the beginning.
        self.create_widgets()
        
    ##########################################
    def create_widgets(self):
        # Create the widgets we want our window to have at startup.

        # First, a Canvas widget that we can draw on.
        # It will be 800 pixels wide, and 600 pixels tall.
        self.canvas = tk.Canvas(self.master, width=800, height=600, background="white")
        # This 'pack' method packs it into the top-level window.        
        self.canvas.pack()

        # Create a button with label "Draw", which calls the member
        # function self.draw() below when it's activated.
        self.draw_button = tk.Button(text="Draw", command=self.draw)
        # Pack the button into the window.
        self.draw_button.pack()

        # Create another button, with label "Clear" which calls the
        # member function self.clear() when it's activated.
        self.clear_button = tk.Button(text="Clear", command=self.clear)
        self.clear_button.pack()

        
    def draw(self):

    
        
        """ #########
            # SPACE #
            #########
        """
        h = self.canvas.create_rectangle(0, 0, 800, 600, fill="#000029")
        self.handle_list.append(h)
     
        
        """ #########
            #  MOON #
            #########
        """
        h = self.canvas.create_oval(10,10,60,60,fill="#ededff")
        self.handle_list.append(h)
        
        h = self.canvas.create_oval(20,20,30,30,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(35,35,40,40,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(45,45,50,50,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(35,15,40,20,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(20,35,25,40,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(50,50,55,55,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(50,27,60,37,fill="#e5e5e5")
        self.handle_list.append(h)
        h = self.canvas.create_oval(20,45,30,50,fill="#e5e5e5")
        self.handle_list.append(h)
        

        """ #########
            # Earth #
            #########
        """
        h = self.canvas.create_oval(50,140,150,240,fill="#006FCF")
        self.handle_list.append(h)

        h = self.canvas.create_polygon(75,165,   75,175,     91,200,     100,220,   100,190,    110,190,
                                        110,200,    117, 180,   113,170,    135, 165,   105,165,    102, 170,   100,165,
                                        75,165,     fill="#00E00A")
        self.handle_list.append(h)

        
        """ #########
            # UFO's #
            #########
        """
        h = self.canvas.create_oval(688,70,708,90,fill="#C4E4F7")
        self.handle_list.append(h)
        h = self.canvas.create_oval(675,80,720,100,fill="#C4E4F7")
        self.handle_list.append(h)
        
        ##########################
        # Draw a bunch of lines. #
        ##########################

        """
        #######
        # SUN #
        #######
        """
        from math import sin, cos, pi

        r = 100
        inc = 2*pi/100
        t = 0
        length = 1.2

        h = self.canvas.create_oval(517,317,683,483,fill="yellow")
        self.handle_list.append(h)
        for i in range(100):
            
            x1 = r*sin(t)
            y1 = r*cos(t)
            x2 = r*sin(t+length)
            y2 = r*cos(t+length)

            x1 += 600
            y1 += 400
            x2 += 600
            y2 += 400
            h = self.canvas.create_line(x1,y1,x2,y2,fill="#f5d714")
            self.handle_list.append(h)
    
            t+=inc
            

        
        """ #########
            # Stars #
            #########
        """

        h = self.canvas.create_polygon(100,100,     103,103,        100,106,        97,103,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(200,40,      203,43,         200,46,         197,43,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(300,10,      303,13,         300,16,         297,13,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(400,70,      403,73,        400,76,          397,73,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(500,30,      503,33,        500,36,          497,33,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(600,300,     603,303,        600,306,        597,303,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(700,400,     703,403,        700,406,        697,403,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(100,250,     103,253,        100,256,        97,253,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(200,240,      203,243,       200,246,         197,243,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(300,210,      303,213,       300,216,         297,213,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(400,270,      403,273,       400,276,         397,273,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(500,230,      503,233,       500,236,        497,233,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(170,300,     173,303,        170,306,        167,303,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(450,400,     453,403,        450,406,        447,403,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(50,500,      53,503,         50,506,        47,503,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(80,350,      83,353,         80,356,        87,353,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(150,220,     153,223,        150,226,        147,223,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(750,50,      753,53,         750,56,        747,53,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(150,500,     153,503,        150,506,        147,503,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(250,350,     253,353,        250,356,        247,353,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(350,500,     353,503,        350,506,        347,503,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(450,450,     453,453,        450,456,        447,453,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(550,150,     553,153,        550,156,        547,153,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(650,400,     653,403,        650,406,        647,403,fill="#FFFFFF")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(750,350,     753,353,        750,356,        747,353,fill="#FFFFFF")
        self.handle_list.append(h)

        

        
        """ ##############
            # ME in Space#
            ##############
        """
        # Name: GABE . C
        h = self.canvas.create_line( 300,50, 300,25, 280,25, 280,100, 300,100, 300,70, 290,70,fill = "white")
        self.handle_list.append(h)
        h = self.canvas.create_line( 310,100, 320,25, 330,100,fill = "white")
        self.handle_list.append(h)
        h = self.canvas.create_line( 340,100, 340,25, 355,40, 340,55, 355,70, 340,100,fill = "white")
        self.handle_list.append(h)
        h = self.canvas.create_line( 360,100, 360,25, 375,25, 360,25, 360,55, 375,55, 360,55, 360,100, 375,100,fill = "white")
        self.handle_list.append(h)

        h = self.canvas.create_line( 435,100, 420,100, 420,25, 435, 25,fill = "white")
        self.handle_list.append(h)

        #Astronuat Backpack
        h = self.canvas.create_polygon(370,405, 400, 435,   370, 435,fill="grey", outline="black")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(400, 435,   370, 435, 385, 450,fill="grey", outline="black")
        self.handle_list.append(h)
        
        #Astronuat helmet
        h = self.canvas.create_arc(355,340,435,420,start=0,extent=270,fill="black", outline="white")
        self.handle_list.append(h)
        h = self.canvas.create_arc(355,340,435,420,start=180,extent=270,fill="#c5c5c5")
        self.handle_list.append(h)

        
        #Astronuat outline
        h = self.canvas.create_polygon(250,400,    270,425,    320,370,    325,380,    220,500,    240,525,
                                    300,460,    305,465,    243,538,    263,563,    365,450,    370,460,
                                    320,520,    340,545,    390,485,    400,460,    340,350,    315,340,
                                    250,400,
                                    fill="#c5c5c5", outline="#e8e8e8")
        self.handle_list.append(h)
        
        
        #Astronuat Flag
        h = self.canvas.create_polygon(330,390,  350,375,   370,410,  350,425, 330,390,fill="red")
        self.handle_list.append(h)
        h = self.canvas.create_line(333,387,353,422,fill="white")
        self.handle_list.append(h)
        h = self.canvas.create_line(338,382,358,417,fill="white")
        self.handle_list.append(h)
        h = self.canvas.create_line(343,377,363,412,fill="white")
        self.handle_list.append(h)
        h = self.canvas.create_polygon(340,385,  350,375,   360,395,  350,405, 340,385,fill="blue")
        self.handle_list.append(h)
        

        
       





















































        
    ##############################################
    def clear(self):
        # To clear the things we drew in the 'draw'
        # function, we just ask the canvas to delete them,
        # one at a time, by their handles.
        # You should not need to modify anythingin this method.
        while len(self.handle_list)>0:
            h = self.handle_list.pop()
            self.canvas.delete(h)


########################################
# Do not change anything below here!   #
########################################
# Instantiate the Tk class.
# This should only ever be done once in a program.
# Think of it as 'firing up' the library, getting it ready to do stuff.
root = tk.Tk()

# Create an instance of the MyApplication class we defined above.
app = MyApplication(root)

# Pass flow control over to the Tkinter library, so it can do things
# like wait for keyboard and mouse events, redraw the window when needed,...
# One of the things it will do is watch for buttons we created and invoke
# the 'callback functions' we gave them. It will run indefinitely,
# until the operating system sends it a 'quit' command (e.g.,
# if we close the window).
app.mainloop()
