; Gabriel Coyote
; 4/23/2021
; Assignment #5

; Develop a MASM assembly program that uses symmetric encryption. 
; Takes in a message and key, and outputs a encyrpt/decrypt result string (Using XOR)

; Describe your algorithm/pseudocode/methodology
;				Go through Character by character of the inputed message to XOR with the key's character
;				Increment ESI & EDI to get the next character (message, and key respectfully)
;				If key runs out of character, then reset it's EDI to it's OFFSET
;				Store the XOR character into the result string

INCLUDE Irvine32.inc

.data	
	
	myName BYTE "[Student]: Gabriel Coyote - R11600156",0

	textString		BYTE "Enter Message: ",0
	messageString	BYTE 500 DUP(0)
	textKeyString	BYTE "Enter Key:     ",0
	keyString		BYTE 20 DUP(0)

	result		 BYTE "Result:        ", 0
	resultString BYTE 500 DUP(0)

.code
main PROC

	; Prompt the user for input message (500 character maximum)
	mov edx, OFFSET textString
	call WriteString

	; Read in the user's response
	mov edx, OFFSET messageString
	mov ecx, SIZEOF messageString
	call ReadString

	; Prompt the user for Key (20 character maximum)
	mov edx, OFFSET textKeyString
	call WriteString

	; Read in the user's Key
	mov edx, OFFSET keyString
	mov ecx, SIZEOF keyString
	call ReadString

	; Start Cryption
	mov esi, OFFSET messageString			; For indexing through message
	mov edi, OFFSET keyString				; For indexing through key
	mov ebp, OFFSET resultString			; For indexing through result
L1:
	mov al, [esi]							; Store one character from message
	cmp al, 00h								; Compare to see if its a null terminator
	je DONE
	
	mov bl, [edi]							; Store one character from key
	cmp bl, 00h								; Compare to see if its a null terminator
	jne SKIP								; If current char from key is a null terminator reset it
	mov edi, OFFSET keyString				; Reset key to beginning for XOR
SKIP:
	xor al, [edi]							; XOR the character with key
	mov [ebp], al							; Store XOR character into result 
	inc esi
	inc edi
	inc ebp
	loop L1

DONE:
	mov al, 00h
	mov [edi], al							; Add null terminator to end of result


	; Print my Name & Rnumber
	call Crlf
	mov edx, OFFSET myName
	call WriteString
	call Crlf

	; Prompt text 
	mov edx, OFFSET result
	call WriteString

	; Print the resultString
	mov edx, OFFSET resultString
	call WriteString
	call Crlf


	exit
main ENDP
END main