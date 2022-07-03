; Gabriel Coyote
; 4/20/2021
; Assignment #4

; Develop four procedures for performing basic string operations (concat, repetitation, lower & upper-case)

; Describe your algorithm/pseudocode/methodology
;				 I stored the Original OFFSET of the register into another register, before altering anything, then return the OFFSET back to EDI
; For strcat ... I copyied the string1 up until the null terminator, from there copy the string2 into newString
; For strrep ... I just 'cmp' to jump if there are no more reptitions, else repeat the string, I used EBX as a loop counter for how many strings to read/copy
; For strlower ..I check to see if the readed char is a uppercase letter based on hex values, if it's upper change it to lower and store it, else store char
; For strupperr .I check to see if the readed char is a lowercase letter based on hex values, if it's lower change it to upper and store it, else store char

INCLUDE Irvine32.inc


.data
	textString BYTE "You entered the string: "
	inputString BYTE 50 DUP(0)
	hardcodeString BYTE " for CS2350. ", 0
	newString BYTE 500 DUP(0)
	
	prompt BYTE "Enter a string to manipulate: ",0
	msg1 BYTE "Post Concatenation: ",0
	msg2 BYTE "Post Repetition:    ",0
	msg3 BYTE "Post Lowercase:     ",0
	msg4 BYTE "Post Uppercase:     ",0
	
	; Place your additional memory operands below (if any)
	myName BYTE "MY NAME:            Gabriel Coyote  R11600156",0
.code
main PROC																; DO NOT CHANGE THE CODE WITHIN THE MAIN PROCEDURE.
	; Prompt the user for string input (50 character maximum)
	mov edx, OFFSET prompt
	call WriteString

	; Read in the user's response
	mov edx, OFFSET inputString
	mov ecx, SIZEOF inputString
	call ReadString

	; Print the user's response to the screen.
	mov edx, OFFSET textString
	call WriteString
	call Crlf			; Print end line character.
	
	; -------------------------------------------------------------
	; Code block for calling strcat and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET inputString
	mov edx, OFFSET hardcodeString
	call strcat
	mov edx, OFFSET msg1
	call WriteString	; Print msg1
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	; -------------------------------------------------------------
	; Code block for calling strrep and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET newString
	mov eax, 3
	call strrep
	mov edx, OFFSET msg2
	call WriteString	; Print msg2
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	; -------------------------------------------------------------
	; Code block for calling strlower and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET newString
	call strlower
	mov edx, OFFSET msg3
	call WriteString	; Print msg3
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	; -------------------------------------------------------------
	; Code block for calling strlower and printing results to screen.
	mov edi, OFFSET newString
	mov esi, OFFSET newString
	call strupper
	mov edx, OFFSET msg4
	call WriteString	; Print msg4
	mov edx, edi		; Move the address in EDI to EDX
	call WriteString	; Print output of strcat
	call Crlf			; Print end line character.
	; -------------------------------------------------------------


	exit
main ENDP




; [strcat] -----------------------------------------------------------
strcat PROC
	mov ebx, edi					;Store original OFFSET of edi in ebx
	INVOKE Str_length, esi
	mov ecx, eax					; Loop Counter
	
L1:
	mov al, [esi]					; Get a char from input string
	cmp al, 00h						; If encounter a null terminator, jump & start copy of hardcode string
	je Next
	mov [edi], al					; Store it in the new String
	inc esi
	inc edi
	loop L1

Next:
	INVOKE Str_length, edx
	mov ecx, eax					; Loop Counter
	
L2:
	mov al, [edx]					; Get a char from Hardcode string
	mov [edi], al					; Store it in the new String
	inc edx
	inc edi
	loop L2
	
	mov edi, ebx					; Return Stored OFFSET of edi back to edi
	ret
strcat ENDP
; [END OF strcat] -----------------------------------------------------------



; [strrep] -----------------------------------------------------------
strrep PROC
	mov edx, eax					; Store eax value(reptition) in edx
	cmp edx, 0						; If there are no reptition, return
	jle Done						

	mov ebp, edi					; Store original OFFSET of edi in ebp
	mov ebx, 0						; Holds the amount of char in original input string
	INVOKE Str_length, edi
	mov ecx, eax					; Loop counter
	
L1:
	mov al, [esi]					; Reptition String 1 time
	cmp al, 00h
	je Next
	mov [edi], al
	inc edi
	inc esi
	inc ebx
	loop L1

Next:								; EBX now holds the total amount of char in the original input string (ESI)
	dec edx							; Since we already did Loop L1, reptition minus 1
	cmp edx, 0
	jle Done						; If no more reptition go to Done/return
	mov esi, ebp					; Return original OFFSET of edi
	mov ecx, ebx

L2:									; WHile Reptition are left, keep reptiting
	mov al, [esi]
	mov [edi], al
	inc edi
	inc esi
	loop L2
	loop Next
	
Done:
	mov al, 00h
	mov [edi], al					; Add null terminator to end of new created string
	mov edi, ebp					; Return EDI pointing to beginning of new created String
	ret
strrep ENDP
; [END OF strrep] -----------------------------------------------------------



; [strlower] -----------------------------------------------------------
strlower PROC
	mov ebp, esi					; Store Original OFFSET of ESI
	INVOKE Str_length, edi		
	mov ecx, eax					; Loop counter

L1:									; Uppercase char get alter (values: 41h to 5Ah)
	mov al, [esi]					; Store a char from input string
	cmp al, 41h					
	jb Next							; If al < 41h ...not a Uppercase Letter jump to Next
	cmp al, 5Ah
	ja Next							; If al > 5Ah ... not a Uppercase letter Jump to Next

	or al, 00100000b				; Change al to Lowercase
	mov [edi], al					; Store it
	inc esi
	inc edi
	loop L1

Next:								; For non-uppercase char just store it, no altering
	mov [edi], al
	inc edi
	inc esi
	loop L1

	mov edi, ebp					; Return original OFFSET pointing to beginning of new created String
	ret
strlower ENDP
; [END OF strlower] -----------------------------------------------------------



; [strupper] -----------------------------------------------------------
strupper PROC
	mov ebp, esi					; Store original OFFSET
	INVOKE Str_length, edi
	mov ecx, eax					; Loop counter

L1:									; Lowercase char get alter (values: 61h to 7Ah)
	mov al, [esi]					; Store a char from input string
	cmp al, 61h					
	jb Next							; If al < 61h ...not a Lowercase Letter jump to Next
	cmp al, 7Ah
	ja Next							; If al > 7Ah ... not a Lowercase letter Jump to Next

	and al, 11011111b				; Change al to UpperCase
	mov [edi], al					; Store it
	inc esi
	inc edi
	loop L1

Next:								; For non-lowercase char just store it, no altering
	mov [edi], al
	inc edi
	inc esi
	loop L1

	mov edi, ebp					; Return OFFSET pointing to beginning of new created String
	mov edx, OFFSET myName			; Print my name and R number
	call WriteString
	call Crlf

	ret
strupper ENDP
; [END OF strupper] -----------------------------------------------------------

END main