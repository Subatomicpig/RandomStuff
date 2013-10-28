NULL		equ	0


NODE_DATA 	equ 	0
NODE_LEFT	equ	4
NODE_RIGHT	equ	8
NODE_SIZE 	equ 	12

LOCAL_DEPTH	equ	0;



start:		subq.l	#4,sp	;save space for result
		pea	five	;adds the adress for five to the stack
		jsr	depth	;go to the depth subroutine		



		bsr	exit


; example binary tree, with node "five" at the root:

five:		dc.l	5
		dc.l	two
		dc.l	eight

two:		dc.l	2
		dc.l	one
		dc.l	four

one:		dc.l	1
		dc.l	NULL
		dc.l	NULL

four:		dc.l	4
		dc.l	three
		dc.l	NULL

three:		dc.l	3
		dc.l	NULL
		dc.l	NULL

eight:		dc.l	8
		dc.l	NULL
		dc.l	nine

nine:		dc.l	9
		dc.l	NULL
		dc.l	NULL


;----- SUBROUTINE: depth -----

; [TO DO] parameter and local variable offset constants go here

depth:			
		link	a6,#0		  ;space for local variables
		move.l	d0-d2/a0-a2,-(sp) ;save the contents
		move.l	NODE_DATA(a6),d0
		
	



		rts




;----- SUBROUTINE: exit -----
;
; PURPOSE: terminates the program.  This routine never returns.

exit:		clr.w	-(sp)
		trap	#1
