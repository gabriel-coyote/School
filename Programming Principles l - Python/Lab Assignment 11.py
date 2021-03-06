
def city_country():
    try:
        file_in = open(input("Enter the file name: "), "r")
        file_text = file_in.read()
        file_in.close()
        return file_text
    except:
        print()
        print("An ERROR was found")

def calc(file_txt):
    """
    >>> calc("city_country.txt")
    Your File Reads: 
    city_country.txt
    <BLANKLINE>
    <BLANKLINE>
    Below is the information in a dictionary
    <BLANKLINE>
    {}
    """
    try:
        
        text = file_txt
        words = text.split('\n')
        print("Your File Reads: ")
        print(text)




        clean_words = []
        for i in words:
            j = (i.split(', '))
            for k in j:
                clean_words.append(k)
    
        print()




        city = []
        i = 0
        while i < len(clean_words):
            city.append(clean_words[i])
            i+=2




        country = []
        j = 1
        while j < len(clean_words):
            country.append(clean_words[j])
            j+=2




        country_unique = {country[i]:0 for i in range(len(country))}


        for w in country:
            country_unique[w] +=1

        for w in country_unique:
            print(w, ':', country_unique[w])
        

    
        city_country_dict = dict(zip(tuple(city),country))
        print()
        print("Below is the information in a dictionary\n")
        print(city_country_dict)
    except:
        print("I apologize for the inconvenience, I'm a beginner.")

def main():
    file_txt = city_country()
    calc(file_txt)
    
main()


if __name__ == '__main__':
    from doctest import testmod
    testmod(name='main', verbose = True)
    
