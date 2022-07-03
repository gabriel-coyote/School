import os


in_file_name = input('Enter an existing file: ')
out_file_name = input('Enter a new destination file: ')

try:
    in_file = open(in_file_name, 'r')
except:
    print('Cannot open file' + ' ' + in_file_name)
    quit()
