import Prelude hiding (and,(!!))

isEmpty::[Int] -> Bool
isEmpty[] = True
isEmpty[_] = False


myAnd :: [Bool] -> Bool
myAnd [] = False
myAnd [True] = True
myAnd [False] = False
myAnd (x:y:rest) |  x == y = myAnd(y:rest)
                 | otherwise = False
				
				

myParse :: [a] -> Int -> a
myParse (x:y) n | (n == 0) = x
				| otherwise = myParse y (n-1)


myReplicate :: Int -> a -> [a]
myReplicate  n x	| (n == 0) = []
					| otherwise = (x: myReplicate (n -1) x)
					
					
					
--writes a cartisan product 
car xs ys = [(x,y) | x <- xs, y <-ys]
					

