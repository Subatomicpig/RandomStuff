prompt :: IO ()
prompt = putStr "Enter A String\n" >>=
		\() -> getLine			 >>=
		\line -> putStr("The Number of Characters ") >>
		print(count(line))
		 
		 
rFile :: IO()
rFile = putStr "Enter A String\n" >>
		getLine 			  	  >>=
		\filename -> readFile(filename)   >>=
		\file -> print(count(file))
		 
count :: String -> Int
count (x:xs) = 1 + count xs
count [] = 0

