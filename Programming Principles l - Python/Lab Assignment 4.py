import math

def main():
    """
    >>> main()
    Enter an integer:2,7,
    

    """
    try:
        num=(input("Enter an integer:"))
        if num[0]=="-":
            print("Please enter a POSITITVE number!!!")
        else:

            num_entered = int(num)

            i=1
    
            while(i<=num_entered):
                t=0
                if(num_entered%i==0):
                    j=1
                    while(j<=i):
                        if(i%j==0):
                            t=t+1
                        j=j+1
                    if(t==2):
                        print(i,end=",")
                i=i+1
    except:
        print("Please enter a numeric value!")

if __name__ == '__main__':
    from doctest import testmod
   # testmod(name='main', verbose = True)
