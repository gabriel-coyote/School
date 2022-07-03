; Gabriel Coyote
; 4/30/2021
; Assignment #6

; Develop a MASM assembly program that prompts the user for a (signed) 32-bit integer 
; Then calculate/print out the corresponding Roman numeral.

; Describe your algorithm/pseudocode/methodology
;				I had a number SDWORD array to hold all numbers listed to divide with
;				Then i declared all the symbols possible, but i reverse the string ex. 900 = CM is now MC
;				Becuase i saved the string as a DWORD which is stored in memory differently then a BYTE string
;				I get the user input then divide by 1000, then 900, then 800, and so on
;				If i get a reminder in EAX I transfer that to ecx to use as a loop to print the current symbol

INCLUDE Irvine32.inc

.data		
	
	myName BYTE "[Student]: Gabriel Coyote - R11600156",0

	promptString	BYTE "Enter a positive Arabic Numeral (0 to quit): ",0
	negativeString	BYTE "Values below 0 are not permitted, please try again.",0
	resultString	BYTE "Your Arabic Numeral in Roman Numeral form is: ",0

	numberArray		SDWORD 1000,900,800,700,600,500,400,300,200,100,90,80,70,60,50,40,30,20,10,9,8,7,6,5,4,3,2,1
	numberSize = ($ - numberArray) / 4

	symbols DWORD "M",0
	sym2	DWORD "MC",0
	sym3	DWORD "CCCD",0
	sym4	DWORD "CCD",0
	sym5	DWORD "CD",0
	sym6	DWORD "D",0
	sym7	DWORD "DC",0
	sym8	DWORD "CCC",0
	sym9	DWORD "CC",0
	sym10	DWORD "C",0
	sym11	DWORD "CX",0
	sym12	DWORD "XXXL",0
	sym13	DWORD "XXL",0
	sym14	DWORD "XL",0
	sym15	DWORD "L",0
	sym16	DWORD "LX",0
	sym17	DWORD "XXX",0
	sym18	DWORD "XX",0
	sym19	DWORD "X",0
	sym20	DWORD "XI",0
	sym21	DWORD "IIIV",0
	sym22	DWORD "IIV",0
	sym23	DWORD "IV",0
	sym24	DWORD "V",0
	sym25	DWORD "VI",0
	sym26	DWORD "III",0
	sym27	DWORD "II",0
	sym28	DWORD "I",0


.code
main PROC
	
	mov edx, OFFSET myName				; Print my Name & R number
	call WriteString
	call Crlf
	call Crlf

RESTART:
	mov edx, OFFSET promptString		
	call WriteString					; Prompt the user for input Nmber
	call ReadInt						; Read input number into EAX

	; Test for negative input numbers
	cmp eax, 0d							; Compare input number with 0
	jg CALC								; If input number > 0, calculate Roman Numerals
	je QUIT								; If input number == 0, quit program
	
	mov edx, OFFSET negativeString		; Else display for valid number and restart program
	call WriteString
	call Crlf
	call Crlf
	loop RESTART

CALC:	
	mov edx, OFFSET resultString
	call WriteString					; Display text before Roman Numerals
	
	;------------------------------------------------------------
	mov edx, 0							; Zeros out edx
	mov esi, OFFSET numberArray			
	mov edi, OFFSET symbols
	

	
	mov ecx, numberSize					; Loop counter
L1:
	mov ebp, ecx						; Store outside loop counter into EBP
	mov ebx, [esi]						; EBX is the divisor (reg32)
	div ebx								; Divde by integer in ebx
	
	mov ebx, edx						; Move reminder EDX into EBX to store
	cmp eax, 0d							; If quotient is 0, don't write
	je	SKIP							

	mov ecx, eax					; Your quotient is how many times to write current symbol
L2:
	mov edx, edi
	call WriteString
	loop L2



SKIP:
	mov eax, ebx					; Move Stored reminder EBX into EAX for next division
	mov edx, 0						; Zeros out edx for next division
	mov ecx, ebp					; Return original outside loop counter for decrementing

	inc esi							; Increment esi 4 times(4 bytes total) to get next number to use as divisor
	inc esi
	inc esi
	inc esi
	add edi, 8						; To get next symbol

	loop L1
	
	;------------------------------------------------------------
	call Crlf
	call Crlf
	loop RESTART



QUIT:
	call Crlf
	exit


main ENDP
END main