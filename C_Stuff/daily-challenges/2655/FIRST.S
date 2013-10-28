; TO DO: fill in your header doc. here
;        (delete this comment)


start:		clr.l d1 ;read in first number
		jsr read_char
		move.l d0,d1
		AND.l #$FF,d1
		sub.l #'0',d1
		

		clr.l d0
	
		clr.l d2 ;read in second number
		jsr read_char
		move.l d0,d2
		AND.l #$FF,d2 
		sub.l #'0',d2

		clr.l d0

		clr.l d3 ;read in third number
		jsr read_char
		move.l d0,d3
		AND.l #$FF,d3
		sub.l #'0',d3
		
		clr.l d0

		mulu #100,d1 ;multiply by 100

		mulu #10,d2 ;multiply by 10
		
		add.l d1,d4
		add.l d2,d4
		add.l d3,d4
	
		clr.l d5
		move.l d4,d5 ;move the value for x into d for storage

		mulu d4,d5 ;square the value
		move.l d5,d6 ;move the squared value to d6		
		add.l d6,d5 ;add the two numbers together
		divu #5,d4 ;divide by 5
		sub.l d4,d5 ;subtract x
		add.l #1,d5 ;add 1

		clr.l d7 
		move.l d5,d7 ;move our value to d7 for modulo
		divu #1000,d7 ;modulo 
		swap d7 ;gets the remainder
			

		clr.l d1
		move.w d7,d1 ;move our answer
		divu #100,d1 ; get our 100s value

		clr.l d2
		move.w d7,d2 
		clr.l d6
		move.w d7,d2
		divu #100,d6
		sub d6,d2
		divu #10,d2

		clr.l d3
		move.w d7,d3
		clr.l d5
		move.w d6,d5
		mulu #100,d5
		sub d5,d3
		clr.l d4
		move.w d2,d4
		mulu #10,d4
		sub d4,d3
		
		add.b #'0',d1
		move.b d1,d0
		jsr write_char

		clr.l d0
		add.b #'0',d2
		move.b d2,d0
		jsr write_char

		clr.l d0
		add.b #'0',d3
		move.b d3,d0
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
