;Information Section
;Ryan Wright
;rwrig664@mymru.ca
;comp2655_001
;Asg#1
;Due Oct 17
;first.s
;Paul Pospisil

;program purpose section
;The purpose of this program is to write the math equation
;y=(2X^2 - x/5 + 1)%1000 in assembly
;input: takes 3 digits 0-9 
;output: a 3 digit number 

;method
;takes 3 different inputs converts them to one 3 digit number
;digit 1 multiply 100
;digit 2 multiply 10
;add all the digits together
;multiply the digit by a copy
;multiply by two
;divide original number by 5 and add 1
;divide by 1000 swap to get remainder
;convert back to ascii for correct output

;Program Status everything works

;Registers table 
;d1 = first digit
;d2 = second digit
;d3 = fourth digit
;d4 = 3 digit number
;d5 = store 
;d6 = temporary storage 
;d7 = stores final number

;constant - N/A

start:		
read_01:	clr.l 	d1 	
		jsr read_char
		move.l 	d0,d1
		AND.l 	#$FF,d1
		sub.l 	#'0',d1

		clr.l 	d0
	
read_02: 	clr.l 	d2 	
		jsr read_char
		move.l 	d0,d2
		AND.l 	#$FF,d2 
		sub.l 	#'0',d2

		clr.l 	d0

read_d3:	clr.l 	d3 	
		jsr read_char
		move.l 	d0,d3
		AND.l 	#$FF,d3
		sub.l 	#'0',d3
		
		clr.l 	d0

getFullNumber:	mulu 	#100,d1 
		mulu 	#10,d2 		
		add.l 	d1,d4
		add.l 	d2,d4
		add.l 	d3,d4
	
		clr.l 	d5
		move.l 	d4,d5 

formula:	mulu 	d4,d5 
		move.l 	d5,d6 		
		add.l 	d6,d5 
		divu 	#5,d4 
		sub.w 	d4,d5 		
		add.l 	#1,d5 

X % 100:	clr.l 	d7 
		move.l 	d5,d7 ;move our value to d7 for modulo
		divu 	#1000,d7 ;modulo 
		swap 	d7 ;gets the remainder
			

100's:		clr.l 	d1
		move.w 	d7,d1 ;move our answer
		divu 	#100,d1 ; get our 100s value

10's:		clr.l 	d2
		move.w 	d7,d2	;move final answer to d2
		clr.l 	d6
		move.w 	d1,d6
		mulu	#100,d6
		sub.w 	d6,d2
		divu 	#10,d2

1's:		clr.l 	d3
		move.w 	d7,d3
		clr.l 	d5
		move.w 	d6,d5
		sub.w 	d5,d3
		clr.l 	d4
		move.w 	d2,d4
		mulu 	#10,d4
		sub.w 	d4,d3
		
space:		clr.l 	d0
		add 	#10,d0
		jsr write_char

		add.b 	#48,d1
		move.b 	d1,d0
		jsr write_char

		clr.l 	d0
		add.b 	#48,d2
		move.b 	d2,d0
		jsr write_char

		clr.l 	d0
		add.b 	#48,d3
		move.b 	d3,d0
		jsr write_char

		jsr	exit


;----- SUBROUTINE: read_char -----
;
; PURPOSE: waits for and reads a single keystroke from the keyboard.
;
; CALLER OUTPUT: returns the ASCII value of the key in the low byte
;                of D0.
;
; IMPORTANT: NOTE THAT THE HIGHER_ORDER BYTES OF D0 ARE UNDEFINED.
;            DON'T ASSUME THEY ARE ZEROED OUT!
;
; E.G. CALL:	jsr	read_char
;		... now use D0.b ...

read_char:	movem.l	d1-d2/a0-a2,-(sp)
		move.w	#1,-(sp)
		trap	#1
		addq.l	#2,sp	
		movem.l	(sp)+,d1-d2/a0-a2
		rts


;----- SUBROUTINE: write_char -----
;
; PURPOSE: writes a single character to the screen.
;
; CALLER INPUT: takes the ASCII value of the character in the low byte
;               of D0.
;
; E.G. CALL:	move.b	#'a',d0
;		jsr	write_char

write_char:	movem.l	d0-d2/a0-a2,-(sp)
		and.w	#$00FF,d0
		move.w	d0,-(sp)
		move.w	#2,-(sp)
		trap	#1
		addq.l	#4,sp
		movem.l	(sp)+,d0-d2/a0-a2
		rts


;----- SUBROUTINE: exit -----
;
; PURPOSE: terminates the program.  This routine never returns.

exit:		clr.w	-(sp)
		trap	#1
