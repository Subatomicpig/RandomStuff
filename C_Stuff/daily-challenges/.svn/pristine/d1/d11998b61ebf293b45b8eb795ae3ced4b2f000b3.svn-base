start:		subq.l	#2,sp			; reserve space for answer
		move.w	#5,-(sp)		; compute 5!
		jsr	fact
		addq.l	#2,sp
		move.w	(sp)+,d0		; d0.w = 5!

;----- subroutine: fact -----

n		equ	8
answer		equ	10

; d0 = n
; d1 = n-1

fact:		link	a6,#0			; pre-logic setup
		movem.w	d0/d1,-(sp)

		move.w	n(a6),d0		; if n == 0
		bne	recursive_case

base_case:	move.w	#1,answer(a6)		; then base case
		bra	fact_done		; answer = 1

recursive_case:	move.w	d0,d1			; else recursive case
		subq.w	#1,d1
		subq.l	#2,sp
		move.w	d1,-(sp)		; compute (n-1)!
		jsr	fact
		addq.l	#2,sp
		mulu.w	(sp)+,d0
		move.w	d0,answer(a6)		; answer = n * (n-1)!

fact_done:	movem.w	(sp)+,d0/d1		; post-logic clean up
		unlk	a6
		rts
