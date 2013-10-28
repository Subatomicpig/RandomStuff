		cmp.l d1,d0
		bhs check_d2_d0
		cmp.l d1,d2
		bhs check_d2_d0
		move d0,d3
		move.d1,d4
		move d4,d0
		move d3,d1
check_d2_d0:
		cmp.l d2,d0
		bhs check_d2_d1
		cmp.l d2,d1
		bhs check_d2_d1
		move d0,d3
		move d2,d4
		move d3,d2
		move d4,d0
check_d2_d1:
		cmp.l d2,d1
		bhs out_sort
		move d1,d3
		move d2,d4
		move d3,d2
		move d4,d1
out_sort: