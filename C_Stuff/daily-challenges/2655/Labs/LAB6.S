ARRAY_SZ	equ	10
RECORD_SZ	equ	26

used	dc.w	4
list:	dc.b	0
	dc.b	0
	dc.w	6
	dc.b	"apples"
	ds.b	15
	dc.b	0
	dc.b	0
	dc.b	0
	dc.w	2
	dc.b	"bread"
	ds.b	16
	dc.b	0
	dc.b	0
	dc.b	0
	dc.w	8
	dc.b	"canned ham"
	ds.b	11
	dc.b	0
	dc.b	0
	dc.b	0
	dc.w	2
	dc.b	"yams"
	ds.b	17
	ds.b	RECORD_SZ*(ARRAY_SZ-4)

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
; E.G. CALL:	bsr	read_char
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
;		bsr	write_char

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