ID 		equ	0
YEARS		equ	2
SALARY		equ	4
EMPLOYEE	equ	8

NUM_EMPLOYEE	equ	10
EMPLOYEE_SZ	equ	8


		lea	EMP,a1

		clr.l	d0
		move.w	#NUM_EMPLOYEE-1,d0
		clr.l	d5
		clr.l	d1
		move.w	#1000,d1	

loopStart:
		cmp.b	#0,d0
		beq	loopEnd
		move.w	d2,ID(a1,d5)
		move.b	#1,YEARS(a1,d5)
		move.l	#30000,SALARY(a1,d5)
		add.b	#EMPLOYEE_SZ,d5		;incrament the offset		
		add.w	#1,d2	
		dbra	d0,loopStart
loopEnd:



EMP		ds.b	NUM_EMPLOYEE * EMPLOYEE_SZ







