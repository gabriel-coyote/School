

def main(num=''):
  #  """Prints inputted three digit number if in correct order.
  #  >>> main('678')
  #  Enter a three-digit-number: Your number 678 is in the correct order!

  #  """
    check = False

    while check ==False:
        try:
            num = int(input("Enter a three-digit-number: "))
            
            if num > 999 or num < 100:
                print("Please enter a three-digit-number!\n")

                
            else:
                num=str(num)
                if num[0] < num[1] and num[1] < num[2]:
                    check = True

                    
        except:
            print("Please enter a numeric value!\n")
            
    print("Your number",num,"is in the correct order!")

#if __name__ == '__main__':
  #  from doctest import testmod
  #  testmod(name='main', verbose = True)

