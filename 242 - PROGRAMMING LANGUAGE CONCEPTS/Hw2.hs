module Hw2 where

data ASTResult = ASTError String | ASTJust (String, String, Int) deriving (Show, Read)
data ASTDatum = ASTSimpleDatum String | ASTLetDatum String deriving (Show, Read)
data AST = EmptyAST | ASTNode ASTDatum AST AST deriving (Show, Read)

isNumber :: String -> Bool
eagerEvaluation :: AST -> ASTResult
normalEvaluation :: AST -> ASTResult

-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT isNumber, eagerEvaluation and normalEvaluation FUNCTIONS ACCORDING TO GIVEN SIGNATURES 

is_empty EmptyAST y= y
is_empty x EmptyAST =x 


olay x  | x==[]=False
		| (get_second (x!!0)) == "" = True
		| otherwise =False

ff str =(reads str) :: [(Int, String)]  

is_there_space [] = False
is_there_space (x:xs) | x==' '=True
					  | otherwise = is_there_space xs


isNumber str | is_there_space str==True= False
			 |otherwise = olay (ff str )

is_String str =
    case (reads str) :: [(Int, String)] of
      [(_, "")] -> False
      _         -> True


is_error_num (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="str"=True
														 | string=="num"= check_is_num (is_empty ast1 ast2)
														 | string=="plus"=(is_error_num ast1) && (is_error_num ast2)
														 | string=="times"=(is_error_num ast1) && (is_error_num ast2)
														 | string=="cat"=True
														 | string=="len"= (is_error_str (is_empty ast1 ast2))
														 | string=="negate"= (is_error_num (is_empty ast1 ast2)) 

is_error_str (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="num"=True
														 | otherwise=False

check_is_num (ASTNode (ASTSimpleDatum string) ast11 ast12)  =  (is_String string)
--check_is_str (ASTNode (ASTSimpleDatum string) ast11 ast12)  =  not (is_String string)


is_error (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="num" = check_is_num (is_empty ast1 ast2)
													 | string=="plus"= (is_error_num ast1) || (is_error_num ast2)
													 | string=="times"=(is_error_num ast1) || (is_error_num ast2)
													 | string=="negate"=(is_error_num (is_empty ast1 ast2)) 
													 | string=="cat"= (is_error_str ast1) || (is_error_str ast2)
													 | string=="len" = (is_error_str (is_empty ast1 ast2)) 





check_give (ASTNode (ASTSimpleDatum string) ast11 ast12) |  (is_String string) == False = ""
														 | otherwise = ("the value '"++string++"' is not a number!")

give_error (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="num" = check_give (is_empty ast1 ast2)
													 | string=="plus"=  if( type_error_for_num ast1) then ( "plus operation is not defined between "++give_type ast1++" and "++give_type ast2++"!")
													 		else
													 	if (is_error ast1) then give_error ast1
													 				else

														 			if ( type_error_for_num ast2) then ( "plus operation is not defined between "++give_type ast1++" and "++give_type ast2++"!")
														 				else
														 				
														 						give_error ast2
													 | string=="times"=  if( type_error_for_num ast1) then ( "times operation is not defined between "++give_type ast1++" and "++give_type ast2++"!")
													 		else
													 	if (is_error ast1) then give_error ast1
													 				else

														 			if ( type_error_for_num ast2) then ( "times operation is not defined between "++give_type ast1++" and "++give_type ast2++"!")
														 				else
														 				
														 						give_error ast2
													| string=="negate"= if (type_error_for_num (is_empty ast1 ast2)) then ( "negate operation is not defined on "++give_type (is_empty ast1 ast2)++"!")
														else give_error (is_empty ast1 ast2)
													| string=="cat"= if( type_error_for_str ast1) then ( "cat operation is not defined between "++give_type ast1++" and "++give_type ast2++"!")
													 		else
													 	if (is_error ast1) then give_error ast1
													 				else

														 			if ( type_error_for_str ast2) then ( "cat operation is not defined between "++give_type ast1++" and "++give_type ast2++"!")
														 				else
														 				
														 						give_error ast2
													 | string=="len"= if (is_error (is_empty ast1 ast2)) then give_error (is_empty ast1 ast2) 
													 	else ( "len operation is not defined on "++give_type (is_empty ast1 ast2)++"!")
													 	 
														

													 	



give_type (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="num" = "num"
													  | string=="str" ="str"
													  | string=="plus" ="num"
													  | string=="times" ="num"
													  | string=="negate" ="num"
													  | string=="cat" ="str"
													  | string=="len" ="num"

type_error_for_num (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="num"=False
													   | string=="str"=True
													   |otherwise=False

type_error_for_str (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="num"=True
													    		| string=="str"=False
													           |otherwise=False

control EmptyAST = True
control (ASTNode (ASTSimpleDatum string) ast1 ast2) = True && control ast1 && control ast2
control (ASTNode (ASTLetDatum string) ast1 ast2) = False 

eagerEvaluation ast | control ast== True = eagerEvaluation1 ast
					| otherwise= ASTJust (convert (eager_high [] ast ast) (step_eager  ast))


eagerEvaluation1 ast |is_error ast  ==True = ASTError ( give_error ast)
					| otherwise = ASTJust (convert (eager_high [] ast ast) (step_eager  ast))
						--ASTJust (eager_ev ast)

eager_high (my_list) (ASTNode (ASTSimpleDatum string) ast1 ast2) ast | string=="plus"= (num_to_str (eager_ev (my_list) ast ), "num")
													 | string=="times"= (num_to_str (eager_ev (my_list) ast ), "num")
													 | string=="negate"= (num_to_str (eager_ev (my_list) ast ), "num")
													 | string=="num"= (num_to_str (eager_ev (my_list) ast ), "num")
													 | string=="len"= (num_to_str (eager_ev (my_list) ast ), "num")
													 | string=="cat"= (concatenate (my_list) ast,"str")
													 | string=="str"= (concatenate (my_list) ast,"str")

eager_high (my_list) (ASTNode (ASTLetDatum string) ast1 ast2) ast = if (give_type ast1=="num") then (num_to_str (eager_ev (my_list) ast ), "num")
																	else (concatenate (my_list) ast,"str")




eager_ev (my_list) (ASTNode (ASTSimpleDatum string) ast1 ast2)  | string=="plus"=   (eager_ev (my_list) ast1) + (eager_ev (my_list) ast2)
													 | string=="times"= (eager_ev (my_list) ast1) * (eager_ev  (my_list) ast2)
													 | string=="negate"=(-1)* (eager_ev (my_list) (is_empty ast1 ast2))
													 | string=="num"= (str_to_num ( is_empty ast1 ast2))
													 | string=="len"=length (concatenate (my_list) (is_empty ast1 ast2))

													 
													 | otherwise= find string (my_list)

													 

eager_ev (my_list) (ASTNode (ASTLetDatum string) ast1 ast2) | (are_there ast2 string)==False= eager_ev (new_list my_list ast1 string) ast2 
															| otherwise= eager_ev (my_list) ast2

concatenate (my_list) (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="str" = give_me_str (is_empty ast1 ast2)
														      | string=="cat"=concatenate (my_list) ast1 ++ concatenate (my_list) ast2
														      | otherwise= find_str string (my_list)

concatenate (my_list) (ASTNode (ASTLetDatum string) ast1 ast2)| (are_there ast2 string)==False= concatenate (new_list_str (my_list) ast1 string) ast2 
													| otherwise= concatenate (my_list) ast2
														
are_there EmptyAST _ =False
are_there (ASTNode (ASTSimpleDatum string) ast1 ast2) x = ((are_there ast1 x) || (are_there ast2 x))
are_there (ASTNode (ASTLetDatum string) ast1 ast2) x | string==x= True
													 | otherwise= False ||are_there ast1 x || are_there ast2 x

--ASTJust (result,type,#steps)
-- otherwise= 
-- string=="cat"= concatenate ast1 ast2



str_to_num (ASTNode (ASTSimpleDatum string) ast1 ast2) = read string :: Int
str_to_num2 string= read string :: Int


new_list my_list ast x = my_list++[( (num_to_str (eager_ev my_list ast )),x)] 

new_list_str my_list ast x = my_list++[( (concatenate my_list ast ),x)] 




find _ [] = (-9999)
find string (x:xs) | get_second x==string =str_to_num2  (get_first x)
				   | otherwise= find string xs


find_str _ [] = ("")
find_str string (x:xs) | get_second x==string =(get_first x)
				   | otherwise= find_str string xs



get_first (x,y) = x
get_second (x,y) = y

give_me_str (ASTNode (ASTSimpleDatum string) _ _) = string
num_to_str num = show num


--4(ASTNode (ASTLetDatum "x") (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) (ASTNode (ASTLetDatum "y") ((ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "1") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) ) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST)) ))
--6(ASTNode (ASTSimpleDatum "plus") ( (ASTNode (ASTLetDatum "x") ((ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "4") EmptyAST EmptyAST) EmptyAST)) ((ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))) ) ) ((ASTNode (ASTLetDatum "y") ((ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST)) ((ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "y") EmptyAST EmptyAST))) ) ) )

--7(ASTNode (ASTSimpleDatum "cat") ((ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "ab") EmptyAST EmptyAST) EmptyAST))( (ASTNode (ASTLetDatum "x") ((ASTNode (ASTSimpleDatum "str") (ASTNode (ASTSimpleDatum "c") EmptyAST EmptyAST) EmptyAST)) ((ASTNode (ASTSimpleDatum "cat")(ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x") EmptyAST EmptyAST))) )))



step_eager  EmptyAST =0
step_eager  (ASTNode (ASTLetDatum string) ast1 ast2) =step_eager  ast1 + step_eager ast2
step_eager  (ASTNode (ASTSimpleDatum string) ast1 ast2) | string=="plus" = 1 + step_eager ast1 + step_eager  ast2
														   | string=="times" = 1 + step_eager  ast1 + step_eager ast2
														   | string=="cat" = 1 + step_eager  ast1 + step_eager  ast2
														   | string=="len" = 1 + step_eager  ast1 + step_eager  ast2
														   | string=="negate" = 1 + step_eager  ast1 + step_eager ast2
														   | string=="num" = step_eager  ast1 + step_eager  ast2
														   | string=="str" = step_eager  ast1 + step_eager  ast2
														   | otherwise=  step_eager  ast1 + step_eager  ast2


convert (x,y) z = (x,y,z)


normalEvaluation ast | control ast== True = normalEvaluation1 ast
					| otherwise= ASTJust (convert (eager_high [] ast ast) (step_normal [] ast))


normalEvaluation1 ast |is_error ast  ==True = ASTError ( give_error ast)
					| otherwise = ASTJust (convert (eager_high [] ast ast) (step_normal [] ast))


step_normal _ (EmptyAST) = 0
step_normal liste (ASTNode (ASTSimpleDatum string) ast1 ast2) |string=="num" = (step_normal liste ast1 )+ (step_normal liste ast2)
															  |string=="str" = (step_normal liste ast1 )+ (step_normal liste ast2)
															  |  string=="plus" = 1 + step_normal liste ast1 + step_normal liste ast2
														   | string=="times" = 1 + step_normal liste ast1 + step_normal liste ast2
														   | string=="cat" = 1 + step_normal liste ast1 + step_normal liste ast2
														   | string=="len" = 1 + step_normal liste ast1 + step_normal liste ast2
														   | string=="negate" = 1 + step_normal liste ast1 + step_normal liste ast2
														   
														   | otherwise=  (step_normal liste ast1 )+ (step_normal liste ast2)





step_normal liste (ASTNode (ASTLetDatum string) ast1 ast2)       | (are_there ast2 string)== False= (step_normal_helper (liste ++ (put string (step_normal_helper liste ast1))) ast2 )
															| otherwise=  (step_normal liste ast2)


step_normal_helper liste EmptyAST = 0
step_normal_helper liste (ASTNode (ASTLetDatum string) ast1 ast2) | (are_there ast2 string)== False= (step_normal_helper (liste++(put string (step_normal_helper liste ast1))) ast2 )
																  | otherwise = step_normal_helper liste ast2


step_normal_helper liste (ASTNode (ASTSimpleDatum string) ast1 ast2) |  string=="plus" = 1 + step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | string=="times" = 1 + step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | string=="cat" = 1 + step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | string=="len" = 1 + step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | string=="negate" = 1 + step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | string=="num"= step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | string=="str"= step_normal_helper liste ast1 + step_normal_helper liste ast2
														   | otherwise=  (find_normal_step string liste) +step_normal_helper liste ast1 + step_normal_helper liste ast2


put string num = [(string,num)]


find_normal_step _ [] = 0
find_normal_step string (x:xs) | get_first x==string = get_second x
							   | otherwise= find_normal_step string xs










--(ASTNode (ASTLetDatum "x") ( (ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTLetDatum "y") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "2") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "num") (ASTNode (ASTSimpleDatum "3") EmptyAST EmptyAST) EmptyAST) (ASTNode (ASTSimpleDatum "y" ) EmptyAST EmptyAST) )   ))) ((ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x" ) EmptyAST EmptyAST) ((ASTNode (ASTLetDatum "z") ( ASTNode (ASTSimpleDatum "plus") (ASTNode (ASTSimpleDatum "x" ) EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "x" ) EmptyAST EmptyAST) )( ASTNode (ASTSimpleDatum "times") (ASTNode (ASTSimpleDatum "x" ) EmptyAST EmptyAST) (ASTNode (ASTSimpleDatum "z" ) EmptyAST EmptyAST) ))))) )
