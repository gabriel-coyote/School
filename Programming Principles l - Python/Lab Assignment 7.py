import string

def name():
    
    file_name = input("What is your file name?: ")
    search_word = input("What word are you looking for the occurence for?: ")

    return file_name,search_word



def cal(file_name,search_word):
    """
    >>> cal("new.txt","to")
    Number of occurence for the word =  3
    
    """
    text_file = open(file_name,"r")

    counter = 0
    
    for line_str in text_file:
        words = ((line_str.split(" ")))
        for i in range(len(words)):
            if str(words[i]) == search_word:
                counter += 1
    print("Number of occurence for the word = ",counter)

def main():
    file_name,search_word = name()
    cal(file_name,search_word)
    
main()


        

if __name__ == '__main__':
    from doctest import testmod
    testmod(name='main', verbose = True)

