; Gabriel Coyote
; 5/6/2021
; Assignment #7

; Develop a MASM assembly program that prompts the user for a signed floating-point value that represents the diameter of a circle
; Then calculate the circle's radius, circumference, and area

; Describe your algorithm/pseudocode/methodology
;				Using a data variable 1/2, I can multiply the diameter to get the radius. I can divide the radius by 1/2 to get the diameter.
;				I can multiply the circumference (pi*2*r) by 1/2 to get (pi*r) then mutiply that by r again to get the area (pi*r*r)
;				No need to pop from the FPU stack

INCLUDE Irvine32.inc

.data		
	myName			BYTE "[Student]: Gabriel Coyote - R11600156",0

	promptEnter		BYTE "Enter the diameter of a circle: ",0
	promptRadius	BYTE "The circle's radius:         ",0
	promptCircum	BYTE "The circle's circumference:  ",0
	promptArea		BYTE "The circle's area:           ",0
	promptError		BYTE "Values must be positive!",0

	varHalf			REAL8 0.5	
.code
main PROC
	
	mov edx, OFFSET myName				; Print my Name & R number
	call WriteString
	call Crlf
	call Crlf

	fldz								; Push 0.0 for error checking input 
RESTART:
	mov edx, OFFSET promptEnter		
	call WriteString					; Prompt the user for circle's diameter
	call ReadFloat						; Push input number on the floating-point stack
	
	fcomi ST(0), ST(1)					; Compare diameter ST(0) with ST(1) := 0
	jnb CALC							; ST(o) not < ST(1)? skip error
	
	mov edx, OFFSET promptError			; Else display for valid number and restart program
	call WriteString
	call Crlf
	fmulp ST(1), ST(0)					; Pop the diameter input from stack, ST(0) := 0
	loop RESTART

CALC:	
	;------------------------------------------------------------
	FMUL varHalf						; St(0) := (diameter * .5)
	mov edx, OFFSET promptRadius
	call WriteString
	call WriteFloat
	call Crlf
	
	FLDPI								; ST(0) := PI, ST(1) := radius
	FLD ST(1)							; ST(0) := radius, ST(1) := pi, ST(2) := radius
	FDIV varHalf						; ST(0) := (radius / .5) or Diameter
	FMUL ST(0), ST(1)					; ST(0) := circumference, ST(1) := pi, ST(2) := radius
	mov edx, OFFSET promptCircum
	call WriteString
	call WriteFloat
	call Crlf

	FMUL varHalf						; ST(0) := pi*radius
	FMUL ST(0), ST(2)					; ST(0) := pi*radius * radius [ST(2)]
	mov edx, OFFSET promptArea
	call WriteString
	call WriteFloat
	;------------------------------------------------------------
	call Crlf
	exit
main ENDP
END main