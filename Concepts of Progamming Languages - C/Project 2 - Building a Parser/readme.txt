
[TEAM MEMBERS]
---Ryan Hutchlings
---Gabriel Coyote

[MUST HAVE MinGW to compile the C source code]

Download MinGW here: http://sourceforge.net/projects/mingw/files/latest/download?source=files
and install it.
_________________________________


Once MinGw is Install Continue these steps...


[HOW to compile the source code]

1.) Extract the .zip file  (This contains my "main.c")
2.) Copy and Paste the C file ("main.c") into the "bin" folder of "C:/MinGW/bin" 	(Default path)
3.) Click the Windows key (on your keyboard)
4.) Type "cmd", then click enter
5.) Type "cd C:/MinGW/bin", then click enter (When MinGW is on C drive which is the defualt path)
6.) Type "gcc -o parser.exe main.c", then click enter
7.) The "parser.exe" will be in the "bin" folder ("C:/MinGW/bin") 
8.) Close the Command Prompt (cmd) 


[RUNNING the executable]

1.) Move the "parser.exe" from the "bin" folder ("C:/MinGW/bin") to the same folder/path with your .txt file that you want to test
2.) Click the Windows key (on your keyboard)
3.) Type "cmd" then click enter
4.) Type in the filepath that contains the parser.exe, then click enter
	(For me I typed   "cd C:/Users/gabri/Documents"    becuase the parser.exe, along with my .txt file, is in "Documents")
5.) Type "parser X.txt" then click enter
	(where 'X' is your .txt Filename) 
	(For me I typed	  "parser test2.txt" )
6.) YOUR DONE! the parser.exe will run the text file
	(Output will be shown in the Command Prompt) 


[OPTIONAL]

7.) To test another simple type "parser Y.txt" 
`	(where 'Y' is your .txt Filename)