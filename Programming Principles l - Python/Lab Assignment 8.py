import string
import copy

consonants = ['b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z']


def enter_text():
    inputted_text = input("Enter a text: ")
    return inputted_text





def calc(txt):
#    """
#    >>> calc("this is fun")
#    tothohisos isos fofunon


#    """
    

    text = list(txt)
    my_list = list()
    n = 0


    for j in range(len(txt)):
        
        for i in range(len(consonants)):
            if txt[n] == consonants[i]:
                my_list.append(txt[n])

                my_list.append("o")

        for j in range(len(consonants)):
            if txt[n] != consonants[j]:
                my_list.append(txt[n])
                break
                
        n += 1
    print(''.join(my_list))


    
def main():
    txt = enter_text()
    calc(txt)

main()


if __name__ == '__main__':
    from doctest import testmod
    #testmod(name='main', verbose = True)
