%isReverse
%t(t(t(nil,1,nil),3,t(nil,4,nil)),5,t(nil,8,t(nil,11,nil)))

%checks the middle first
in_BST(X,t(_,X,_)) :- !.
%checks the left
in_BST(X,t(L,Y,_)) :- (X < Y), !, in_BST(X,L).
%checks the right
in_BST(X,t(_,_,R)) :- in_BST(X,R).


%defines relation to call this function
:- op(650,yfx,rev).

X rev Y :- isReverseOf(X,Y).

%reverses two lists
isReverseOf([],[]).
isReverseOf([H|T],Lyst) :- isReverseOf(T,Treversed),append(Treversed,[H],Lyst).