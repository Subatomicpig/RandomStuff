% binary "parent" relation, defined by facts:

parent(carl,curtis).
parent(ruth,curtis).
parent(carl,rob).
parent(ruth,rob).
parent(claire,sue).
parent(don,sue).
parent(claire,dianna).
parent(don,dianna).
parent(rob,megan).
parent(rob,justin).
parent(rob,jessica).
parent(sue,megan).
parent(sue,justin).
parent(sue,jessica).
parent(curtis,bob).

% unary "male" relation, defined by facts:

male(carl).
male(don).
male(curtis).
male(rob).
male(justin).

% various relations, defined by rules:

female(X) :- not(male(X)).
father(X,Y) :- parent(X,Y),male(X).
mother(X,Y) :- parent(X,Y),female(X).
child(X,Y) :- parent(Y,X).
sibling(X,Y) :- parent(Z,X),parent(Z,Y),not(X=Y).

descendant(X,Y) :-	ancestor(X,Z).
isGrandfather(X) :- grandfather(X,_).
grandfather(X,Z) :- parent(X,Y),grandparent(X,Z),male(X).
grandparent(X,Z) :- parent(X,Y),parent(Y,Z).


ancestor(X,Z) :- parent(X,Y),ancestor(Y,Z).
ancestor(X,Y) :- parent(X,Y).