;Project #1, 

.386
.model flat,stdcall
.stack 4096
ExitProcess proto,dwExitCode:dword
INCLUDE Irvine32.inc
WriteString proto
includelib irvine32.lib

.data 
menu1 byte "1. x AND y",0
menu2 byte "2. x OR y",0
menu3 byte "3. NOT x", 0
menu4 byte "4. x XOR y", 0
menu5 byte "5. x ADD y",0
menu6 byte "6. x SUB y",0
menu7 byte "7. Exit Program",0
test1 byte "successful call",0
x	  dword ?
stringx		byte "Please enter an x value",0
stringy		byte "Please enter a y value",0
endprompt   byte "The resulting value is",0
exitstmt	byte "Thank You!",0

.code
main proc
mov eax, 1001010100100010101001110010101b
mov ebx, -192898889d
mov ecx, 2513512637q

MenuOptions::			
	mov EDX, OFFSET menu1		;prints menu option 1
	call WriteString 
	call crlf

	mov EDX, OFFSET menu2		;prints menu option 2
	call WriteString
	call crlf

	mov EDX, OFFSET menu3		;prints menu option 3
	call WriteString 
	call crlf

	mov EDX, OFFSET menu4		;prints menu option 4
	call WriteString 
	call crlf

	mov EDX, OFFSET menu5		;prints menu option 5
	call WriteString 
	call crlf	
	
	mov EDX, OFFSET menu6		;prints menu option 6
	call WriteString 
	call crlf
	
	mov EDX, OFFSET menu7		;prints menu option 7
	call WriteString 
	call crlf
	
	mov EAX, 6

	cmp eax, 1
	je L1
	cmp eax, 2
	je L2
	cmp eax, 3
	je L3
	cmp eax, 4
	je L4
	cmp eax, 5
	je L5
	cmp eax, 6
	je L6
	ja L7

	L1:
		call AND_op
		exit
	L2:
		call OR_op
		exit
	L3: 
		call NOT_op
		exit
	L4:
		call XOR_op
		exit
	L5: 
		call ADD_op
		exit
	L6:
		call SUB_op
	L7:
		mov EDX, OFFSET exitstmt
		call WriteString
		call crlf
		invoke ExitProcess,0
main endp


AND_op proc
	mov EDX, OFFSET stringx		
	call WriteString			; write stringx to the screen 
	call crlf					; new line 
	call ReadHex				; read the integer the user inputed
	mov x, eax					; move the value to x

	mov edx, OFFSET stringy		;write stringy to the screen 
	call WriteString 
	call crlf					;new line 
	call ReadHex				;read the integer the user inputed onto eax

	AND eax, x					;and two values together 
	mov EDX, OFFSET endprompt	;move the endprompt to edx for printing 
	call WriteString			;write string	 
	call crlf					;nex line 
	call WriteHex				;write the anded eax value in hexadecimal
	call crlf					;new line 
	jmp MenuOptions
	ret
AND_op endp
	
OR_op PROC
	mov EDX, OFFSET stringx		
	call WriteString			; write stringx to the screen 
	call crlf					; new line 
	call ReadHex				; read the integer the user inputed
	mov x, eax					; move the value to x

	mov edx, OFFSET stringy		;write stringy to the screen 
	call WriteString 
	call crlf					;new line 
	call ReadHex				;read the integer the user inputed onto eax

	OR eax, x					;or two values together 
	mov EDX, OFFSET endprompt	;move the endprompt to edx for printing 
	call WriteString			;write string	 
	call crlf					;nex line 
	call WriteHex				;write the or-ed eax value in hexadecimal
	call crlf					;new line 
	jmp MenuOptions
	ret
OR_op ENDP

NOT_op PROC
	mov EDX, OFFSET stringx		
	call WriteString			; write stringx to the screen 
	call crlf					; new line 
	call ReadHex				; read the integer the user inputed

	NOT eax						; not the read value 
	mov EDX, OFFSET endprompt	;move the endprompt to edx for printing 
	call WriteString			;write string	 
	call crlf					;nex line 
	call WriteHex				;write the NOTed eax value in hexadecimal
	call crlf					;new line 
	jmp MenuOptions
	ret
NOT_op ENDP

XOR_op PROC 
	mov EDX, OFFSET stringx		
	call WriteString			; write stringx to the screen 
	call crlf					; new line 
	call ReadHex				; read the integer the user inputed
	mov x, eax					; move the value to x

	mov edx, OFFSET stringy		;write stringy to the screen 
	call WriteString 
	call crlf					;new line 
	call ReadHex				;read the integer the user inputed onto eax

	XOR eax, x					;xor two values together 
	mov EDX, OFFSET endprompt	;move the endprompt to edx for printing 
	call WriteString			;write string	 
	call crlf					;nex line 
	call WriteHex				;write the or-ed eax value in hexadecimal
	call crlf					;new line 
	jmp MenuOptions
	ret
XOR_op ENDP

ADD_op PROC
	mov EDX, OFFSET stringx		
	call WriteString			; write stringx to the screen 
	call crlf					; new line 
	call ReadHex				; read the integer the user inputed
	mov x, eax					; move the value to x

	mov edx, OFFSET stringy		;write stringy to the screen 
	call WriteString 
	call crlf					;new line 
	call ReadHex				;read the integer the user inputed onto eax

	ADD eax, x					; add two values together 
	mov EDX, OFFSET endprompt	;move the endprompt to edx for printing 
	call WriteString			;write string	 
	call crlf					;nex line 
	call WriteHex				;write the added eax value in hexadecimal
	call crlf					;new line 
	jmp MenuOptions
	ret
ADD_op ENDP

SUB_op PROC
	mov EDX, OFFSET stringx		
	mov x, 10010011					; move the value to x

	mov edx, OFFSET stringy		;write stringy to the screen 
	mov eax, 10000110

	SUB x, eax					; add two values together 
	mov EDX, OFFSET endprompt	;move the endprompt to edx for printing 
	call WriteString			;write string	 
	call crlf					;nex line 
	mov eax, x					; since the subtracted value was stored in x, mov to eax
	call WriteHex				;write the added eax value in hexadecimal
	call crlf					;new line 
	ret
SUB_op ENDP
end main