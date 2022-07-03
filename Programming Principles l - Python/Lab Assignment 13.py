



def check(string):
    """
    >>> check("()")
    True
    >>> check(")(")
    False
    >>> check("(()")
    False
    >>> check("(()())")
    True
    """
    if "()" in string:
        return check(string.replace("()",""))
    elif string == '':
        return True
    else:
        return False

    
def main():
    string = input("Enter a string composed of only: ')' & '('  \n")
    print("Is string valid, with regards to parenthesis matching: ",check(string))


    
if __name__ == '__main__':
    from doctest import testmod
    #testmod(name='main', verbose = True)
