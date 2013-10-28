%sudoku(Path) :- catch(( read_puzzle_file(Path,Puzzle),!,
%					  ( solution(Puzzle,Solution),!,
%%						;
%						writeln("invalid puzzle: no solution'),fail
%						)
%						;
%						writeln("invalid puzzle'),fail
%						),
%						_,
%						(writef('couldn\'t read file %d\n',[Path]),fail)
%						).
%read_puzzle_file(Path,Puzzle) :- open(Path,read,Stream),
%								 read_puzzle(Stream,Puzzle),
%								 close(Stream).
%								 
%read_puzzle(Stream,Puzzle) :- blank(Blank),
%							  read_rows(Stream,1,Blank,Puzzle),
%							  get_char(Stream,end_of_file).
%							  
%read_rows(Stream,Row,OrigPuz,NewPuz) :- Row > 1,!,
%										NewPuz = OrigPuz
%										;
%										read_cols(Stream,Row,1,OrigPuz,InterPuz),
%										get_char(Stream,'\n'),
%										NextROw is Row + 1,
%										read_rows(Stream,NextRow,InterPuz,NewPuz).
%										
%read_cols(Stream,Row,Col,OrigPuz,NewPuz) :- Col > 9,!,
%											NewPuz = OrigPuz
%											;
%											get_char(Stream,Ch),
%											( Ch = ' ',!
%												InterPuz = OrigPuz
%												;
%												char_code(Ch,Code),
%												char_code('0',Zero),
%												Sym is Code - Zero,
%												place(OrigPuz,Row,Col,Sym,InterPuz)
%												),
%												NextCol is Col + 1,
%												read_cols(Stream,Row,NextCol,InterPuz,NewPuz).
%
%write_puzzle(puzzle(_,As,_,_,_)) :- write_rows(1,As).

%write_rows(Row,As) :- Row =< 9, !,
%					   if(memberchk(' ',As),write(' '),write(As)), %if the row is blank write a space otherwise pring the value
%					   Row is Row -1,
%					   write_rows(Row).
					   
%write_Cols(Row,Col,As) :- Col =< 9,!,
%						   (memberchk(' ',As),!,write(Row);write(' ') ),
%							Col is Col - 1,
%							write_Cols(Row,Col,As),
%							write('\n').




%creates a blank puzzle with 5 sets
blank(puzzle(Unas,[],Sets,Sets,Sets)):- numlist(1,9,Inds),
										setof(Row/Col/Reg,
											 (member(Row,Inds),
											  member(Col,Inds),
											  region(Row,Col,Reg)),
											  Unas),
											  setof(I - Inds,
													member(I,Inds),
													Sets
													).
												
%defines region												
region(Row,Col,Reg) :- NextRow is Row - 1,
					   NextCol is Col - 1,
					   Reg is (NextRow - NextRow mod 3 + NextCol // 3) + 1.
					   
%inserts a new symbol from the Unas list to the As list
place(puzzle(Unas,As,RowSets,ColSets,RegSets),Row,Col,Sym,NewPuz) :- 
																	NewPuz = (UnasMinsOne,AsPlusOne,RowPlusOne,ColPlusOne,RegPlusOne),
																	del(Row/Col,puzzle,NewPuz),
																	region(Row,Col,Sym),
																	append(As,[Row/Col],AsPlusOne),
																	append(RowSets,[Row/Col],AsPlusOne),
																	append(ColSets,[Row/Col],AsPlusOne),
																	append(RegSets,[Row/Col],AsPlusOne).



%rowCheck checks if the row is valid 


%colCheck checks if the Col is valid 


%squareCheck checks if the square is valid

%checks if a element is in a list 
find(X,Y,[X,Y|_]).
find(X,Y,[Z|Tail]) :- 
    X\=Z, find(X,Y,Tail).
	
%removes an item from a passed in list
del(1,[X|L],L) :- !.
del(N,[X|L1],[X|L2]) :-
N1 is N - 1,
del(N1,L1,L2).
					   
if(Test,Then) :- Test, !, Then; true.

if(Test,Then,Else) :- Test, !, Then; Else.		   
	
	
%inserts a specific element into a list
ins([_|T], 0, X, [X|T]).
ins([H|T], I, X, [H|R]):- I > 0, I1 is I-1, ins(T, I1, X, R).

					   





