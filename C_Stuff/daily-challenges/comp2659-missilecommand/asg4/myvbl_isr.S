		xdef _VBL_ISR 
		xref _do_VBL_ISR
		


_VBL_ISR:
			movem.l		d0-7/a0-6,-(sp)
			jsr _do_VBL_ISR
			movem.l		(sp)+,d0-7/a0-6
			rte

