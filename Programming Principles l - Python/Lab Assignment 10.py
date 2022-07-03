import string

def multi_find(some_string, sub_string, start=0, end=0):
    """
    >>> multi_find("hello my good friend , how is my friend doing", "my",)
    Your some_string:  hello my good friend , how is my friend doing
    Your sub_string:  my
    [6, 30]

    >>> multi_find("testing this testing string", "testing",)
    Your some_string:  testing this testing string
    Your sub_string:  testing
    [0, 13]
    
    """
    
    print("Your some_string: ",some_string)
    print("Your sub_string: ",sub_string)

    end = len(some_string)
    num_appear = 0

    search_string = [sub_string]
    string_field = some_string.split(" ")

    for i in string_field:
        if i == search_string[0]:
            

            num_appear += 1

            

    count = 0
    indices = []

    while num_appear > 0:
        if sub_string in some_string:
            indices.append(some_string.find(sub_string,(some_string.find(sub_string))+count))
            num_appear -= 1
            count += 1

            
    return indices





if __name__ == '__main__':
    from doctest import testmod
    testmod(name='main', verbose = True)
