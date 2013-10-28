


%write stars helper function write out a number of stars
write_stars(0) :- nl,!.
write_stars(Len) :- Len > 0,
					write('*'),
					X is Len - 1,
					write_stars(X).
					
					
%writes a triangle of base size
tri(0).
tri(Base) :- Base > 0,
			 X is Base - 1,
			 tri(X),
			 write_stars(Base).
			 
if(Test,Then) :- Test,!,Then;true.