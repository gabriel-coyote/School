def name():
    file_name = input("Enter the file name: ")
    return file_name



def calc(file_name):
    """
    >>> calc("Lab9.txt")
    The number of words in the text is:  32
    The average word length is:  4.5


    """
    text_file = open(file_name,"r")
    counter = 0
    word_count = []

    for line_str in text_file:
        words = ((line_str.split(" ")))
        
        for j in words:
            if j is not "\n":
                word_count.append(j)
        for i in words:
            if i is not "\n":
                counter += len(i)
                
    
        
    avg_word_length = (counter/len(word_count))
    

    
    print("The number of words in the text is: ",len(word_count))
    print("The average word length is: ", avg_word_length)

    text_file.close()


    

def main():

    file_name = name()
    calc(file_name)

main()



if __name__ == '__main__':
    from doctest import testmod
    testmod(name='main', verbose = True)
