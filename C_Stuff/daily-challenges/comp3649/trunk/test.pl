



sudoku(L) :- L = [AA,AB,AC,AD,AE,AF,AG,AH,AI,
				  BA,BB,BC,BD,BE,BF,BG,BH,BI,
				  CA,CB,CC,CD,CE,CF,CG,CH,CI,
				  DA,DB,DC,DD,DE,DF,DG,DH,DI,
				  EA,EB,EC,ED,EE,EF,EG,EH,EI,
				  FA,FB,FC,FD,FE,FF,FG,FH,FI,
				  GA,GB,GC,GD,GE,GF,GG,GH,GI,
				  HA,HB,HC,HD,HE,HF,HG,HH,HI,
				  IA,IB,IC,ID,IE,IF,IG,IH,II,], (L in 1..9),
				  
				  all_different([AA, AB, AC, BA, BB, BC, CA, CB, CC]),
				  all_different([AD, AE, AF, BD, BE, BF, CD, CE, CF]),
				  all_different([AG, AH, AI, BG, BH, BI, CG, CH, CI]),
				  all_different([DA, DB, DC, EA, EB, EC, FA, FB, FC]),
				  all_different([DD, DE, DF, ED, EE, EF, FD, FE, FF]),
				  all_different([DG, DH, DI, EG, EH, EI, FG, FH, FI]),
				  all_different([GA, GB, GC, HA, HB, HC, IA, IB, IC]),
				  all_different([GD, GE, GF, HD, HE, HF, ID, IE, IF]), 
				  all_different([GG, GH, GI, HG, HH, HI, IG, IH, II]),
				  all_different([AA, AB, AC, AD, AE, AF, AG, AH, AI]),
				  all_different([BA, BB, BC, BD, BE, BF, BG, BH, BI]),
				  all_different([CA, CB, CC, CD, CE, CF, CG, CH, CI]),
				  all_different([DA, DB, DC, DD, DE, DF, DG, DH, DI]),
				  all_different([EA, EB, EC, ED, EE, EF, EG, EH, EI]),
				  all_different([FA, FB, FC, FD, FE, FF, FG, FH, FI]),
				  all_different([GA, GB, GC, GD, GE, GF, GG, GH, GI]),
				  all_different([HA, HB, HC, HD, HE, HF, HG, HH, HI]),
				  all_different([IA, IB, IC, ID, IE, IF, IG, IH, II]),
				  all_different([AA, BA, CA, DA, EA, FA, GA, HA, IA]),
				  all_different([AB, BB, CB, DB, EB, FB, GB, HB, IB]),
				  all_different([AC, BC, CC, DC, EC, FC, GC, HC, IC]),
				  all_different([AD, BD, CD, DD, ED, FD, GD, HD, ID]),
				  all_different([AE, BE, CE, DE, EE, FE, GE, HE, IE]),
				  all_different([AF, BF, CF, DF, EF, FF, GF, HF, IF]),
				  all_different([AG, BG, CG, DG, EG, FG, GG, HG, IG]),
				  all_different([AH, BH, CH, DH, EH, FH, GH, HH, IH]),
				  all_different([AI, BI, CI, DI, EI, FI, GI, HI, II]),
				  
				  
				  Label(L).
				  
				  portray(Matrix) :- is_list(Matrix),
									 length(Matrix,81),
									 !,print_9x9(81,Matrix).
				  
				  print_9x9(81,[D|L]) :- write('\t['), print(D), !, print_9x9(80,L).
				  print_9x9(0,[]) :- write(']').
				  print_9x9(N,[D|L]) :- 
				  write(','),
				  (N mod 9 =:= 0 -> write('\n\t ') ; true ),
				  print(D), !,
				  N1 is N - 1,
				  print_9x9(N1,L).
				  
									
				  
				  
				  