;Gabriel Coyote, 4/1/2021, Assignment 3

;Brief Dresciption: 
;	Decode a hard-coded string, and print it. Must use indirect addressing and loop(s).

;Methodology
;	ECX is for loop counter, and acts like an index for decodedString (Start from END to Beginning)
;	As ECX decrementes becuase of the loop, we move down the index for decodedString
;
;	Loop for each character in encodedString
;		Starting from beginning to end of encodedString, get one character and store it in al
;		Subtract al by one, to get new character
;		Starting from the end to Beginning of decodedString, store al
;		

INCLUDE Irvine32.inc

.data		; Data segment.  Feel free to add variables before or after this block, but don't add anything in between the following 4 memory operands.
	
	myName BYTE "Gabriel Coyote : R11600156",0

	encodedString BYTE "/vpz!offc!fdop!ebi!idjix!gp!mmb!uvc!fwjmb!offc!sfwf!ebi!idjix!gp!fopo!-utve!djnpub!fojg!gp!eovpn!b!fdvepsq!emvpx!vpz!-fnju!b!ub!npub!fop!-tsf{ffxu!iujx!usbqb!gmftsvpz!ldjq!pu!fsfx!vpz!gj!ubiu!opjupo!hojutfssb!zmuihjmt!b!tj!uJ"
	nullTerm BYTE 0										; Null Terminator for encodedString. 
	decodedString BYTE SIZEOF encodedString DUP('?')	; Storage location for the final decoded string. You MUST put the final result in this variable!
	nullTerm2 BYTE 0									; Null Terminator for decodedString


.code
main PROC

	mov		esi, OFFSET encodedString		;Indirect Addressing encodedString
	mov		ecx, SIZEOF encodedString		;Loop Counter

L1: mov		al, [esi]						;Move encodedString Char to al
	sub		al, 1							;Subtract 1 to create new character
	mov		decodedString[ecx-1], al		;Reverse store character into decodedString 
	add		esi, 1							;Move to encodedString next Byte(char)
	loop L1

	mov		edx, OFFSET myName
	call	Writestring
	call	Crlf
	mov		edx, OFFSET decodedString
	call	Writestring
	call	Crlf
	exit

main ENDP
END main