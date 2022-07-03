import math


def num():

    a = int(input("Enter a number: "))
    b = int(input("Enter a number: "))
    c = int(input("Enter the upper limit: "))


    return a,b,c

def cal(x, y, z):

   # """
    #>>> cal(6, 8, 10)
   # 24, 48, 72, 96, 
    
  #  """
    
    i = 0
    n = 1
    while i < 100:
        if (y * n)%x == 0:
            print((y*n), end=", ")
        i = (y*n)
        
        n += 1

def main():
    

    x,y,z= num()
    cal(x, y, z)

main()

       
#if __name__ == '__main__':
   # from doctest import testmod
 #   testmod(name='main', verbose = True)
