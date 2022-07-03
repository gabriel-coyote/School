import os


def name():
    file_name = input("Enter the File Name you want copied: ")
    if '.txt' in file_name:
        return file_name
    else:
        print('This program only accepts ".txt" extensions!')
    


def check(File_name):

    copied_file = "copy_"+File_name
    
    try:
        
        if os.path.exists(File_name) == True:
            print("The source file exists.")
            print()
            
            if os.path.exists(copied_file) == True:
                User_answer = input("A destinaition file exists, do you want to overwrite it?\n""ENTER: 'yes' or 'no'\n")
            
                if User_answer == 'yes':
                    file_in = open(File_name,'r')
                    file_out = open(copied_file,'w')
                    for line in file_in:
                        file_out.append(line)
                else:
                    quit()
            else:
                file_in = open(File_name,'r')
                file_out = open(copied_file,'w')
                for line in file_in:
                    file_out.append(line)
                
        else:
            print("The source file doesn't exist.")
            print()
    except:
        print("An error occurred")

def main():
    File_name = name()
    check(File_name)


                
