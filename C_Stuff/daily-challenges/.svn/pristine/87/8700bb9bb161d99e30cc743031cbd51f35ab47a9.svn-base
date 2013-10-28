	xref FileOpen,FileClose,FileCharRead,Exit,KybdCharRead,ScrnCharWrite

CR:		equ 13
LF:		equ 10
NULL:		equ 0

STRING_LEN 	equ 13
COUNT_SZ 	equ 4
CHARS		equ 0
WORDS		equ 4
LINES		equ 8
PARA		equ 12


;d2 will be newline_Count
;d3 will be the inword bool value

start:  	bsr 	FileOpen
		cmp.l 	#0,d0
		bne 	writeError
		bra 	readFile

writeError:	
		lea	fileError,a1 ;load the string
loop:
		move.b 	(a1)+,d0
		beq 	exit
		bsr 	ScrnCharWrite
		bne 	loop
		
		clr.l	d2
		clr.l	d3		;set in word to false
		add.l 	#2,d2		;set newline count to 2

		
readFile:
		cmp	#0,d1		;compare to see if we are at end of file
		beq 	printArray
		bsr 	FileCharRead	;reads a char
		bsr	ScrnCharWrite	;writes the current char to the screen

newLine:	cmp.l 	#CR,d0		;check for CR
		bne	charCount	;if its not a new line skip to char count
		lea 	ARRAY,a2
		adda.l	#LINES,a2
		add.l	#1,(a2)		;add to the value in the array
		add.l 	#1,d2 		;incrament the newline count
		cmp.l	#2,d2		;check if newline count is 2
		bne	charCount	;if its not move on to count the char
		suba.l	#LINES,a2	;go back to the start of the array
		adda.l	#PARA,a2	;offset
		add.l	#1,(a2)		;incrament the value for paragraph

charCount:	
		cmp.l	#$20,d0		;check for space
		beq	elseCharCount	;equal loop back
		cmp.l	#9,d0		;check for tab	
		beq	elseCharCount	;equal loop back
		cmp.l	#CR,d0		
		beq	elseCharCount	;equal loop back
		lea 	ARRAY,a2	;load array for adding char
		adda.l	#CHARS,a2
		add.l	#1,(a2)
		

		cmp.l	#0,d3		;check if we are in a word
		beq	branchLoop
		adda.l	#WORDS,a2
		lea	ARRAY,a2
		add.l	#1,(a2)		;add 1 to the word checker
		add.l	#1,d3		;set the in word to true
		clr.l	d2		;clear the new line count
	
elseCharCount:	
		cmp.l	#1,d3		;if in word is true
		clr.l	d3		;clear it and set to false

		

branchLoop:	dbra	d1,readFile 	;decrement the program count and loop back 

lastIf:		cmp.l	#1,d3		;check if in a word
		bne	exit
		cmp.l	#1,d2		;check if newline count =1
		bne	exit
		lea	ARRAY,a2
		adda.l	#PARA,a2
		add.l	#1,(a2)
	


printArray:	lea	ARRAY,a2
		adda.l	#LINES,a2
		move.l	(a2),d0
		add.l	#'0',d0
		bsr	ScrnCharWrite
		move.l	#CR,d0
		bsr	ScrnCharWrite
		move.l	#LF,d0		
		bsr	ScrnCharWrite


		lea	ARRAY,a2
		adda.l	#CHARS,a2
		move.l	(a2),d0
		add.l	#'0',d0
		bsr	ScrnCharWrite
		move.l	#CR,d0
		bsr	ScrnCharWrite
		move.l	#LF,D0
		bsr	ScrnCharWrite
				
		lea	ARRAY,a2
		adda.l	#PARA,a2
		move.l	(a2),d0
		add.l	#'0',d0
		bsr	ScrnCharWrite
		move.l	#CR,d0
		bsr	ScrnCharWrite
		move.l	#LF,d0
		bsr	ScrnCharWrite		
		
		
		lea	ARRAY,a2
		adda.l	#WORDS,a2
		move.l	(a2),d0	
		add.l	#'0',d0
		bsr	ScrnCharWrite
		move.l	#CR,d0
		bsr	ScrnCharWrite
		move.l	#LF,d0
		bsr	ScrnCharWrite

			
exit:		bsr Exit

ARRAY:		ds.l	4		;set the array to 4 long words

fileError:
	dc.b 	"Error Opening File",CR,LF,NULL

h1:	dc.b	"Characters:",CR,LF,NULL
h2:	dc.b	"Words:",CR,LF,NULL
h3:	dc.b	"Lines:",CR,LF,NULL
h4:	dc.b	"Paragraphs:",CR,LF,NULL