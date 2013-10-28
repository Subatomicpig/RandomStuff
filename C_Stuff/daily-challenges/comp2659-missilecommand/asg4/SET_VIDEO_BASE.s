;
;	Comp 2659 Assignment: Missile Command
;	Donovan Paget & Ryan Wright
;
		xdef		_set_video_base
		
address		equ		64		; offset from SP, not A6

_set_video_base:	
		movem.l		d0-7/a0-6,-(sp)
		movea.l		address(sp),a2
		move.l		a2,d0
		lea 		$FFFF8201,a1
		movep.l		d0,7(a1)

		movem.l		(sp)+,d0-7/a0-6
		rts
		

		
		


