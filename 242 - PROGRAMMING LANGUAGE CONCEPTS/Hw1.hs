module Hw1 where

type Mapping = [(String, String, String)]
data AST = EmptyAST | ASTNode String AST AST deriving (Show, Read)

writeExpression :: (AST, Mapping) -> String
evaluateAST :: (AST, Mapping) -> (AST, String)
-- DO NOT MODIFY OR DELETE THE LINES ABOVE -- 
-- IMPLEMENT writeExpression and evaluateAST FUNCTION ACCORDING TO GIVEN SIGNATURES -- 


-- negate te mesela ast1 dolu ast2 empty dedik ama tam tersi de olabilir
--aynı durum bu satırda da var: send_write (ASTNode string ast1 ast2) | string=="num"= give_me_str ast1
--burda da | string=="str" ="\""++give_me_str ast1++"\""
--submit edilecek dosya bu

get_third (x,y,z) = z
get_first (x,y,z) = x
get_second (x,y,z) = y


writeExpression (x,y) | y==[] = write_helper1 x 
                      | otherwise = write_helper2 x y






write_helper2 (ASTNode string ast1 ast2) (y) | string=="plus" ="let "++let_func y++" in " ++"("++send_write ast1++"+"++send_write ast2++")"
                                         | string=="times"= "let "++let_func y++" in " ++"("++send_write ast1++"*"++send_write ast2++")"
										 | string=="negate"="let "++let_func y++" in " ++"(-"++send_write (is_empty ast1 ast2)++")"
										 | string=="cat" ="let "++let_func y++" in " ++"("++send_write ast1 ++"++"++send_write ast2 ++")"
										 | string=="len"="let "++let_func y++" in " ++"(length "++send_write (is_empty ast1 ast2) ++")"
										 | string=="num"="let "++let_func y++" in " ++ give_me_str (is_empty ast1 ast2)
										 | otherwise= "let "++let_func y++" in "++string
										 

write_helper1 (ASTNode string ast1 ast2) | string=="plus" ="("++send_write ast1++"+"++send_write ast2++")"
                                         | string=="times"= "("++send_write ast1++"*"++send_write ast2++")"
										 | string=="negate"="(-"++send_write (is_empty ast1 ast2)++")"
										 | string=="cat" ="("++send_write ast1 ++"++"++send_write ast2 ++")"
										 | string=="len"="(length "++send_write (is_empty ast1 ast2) ++")"
										 | string=="num"=give_me_str (is_empty ast1 ast2)
										 | string=="str"=give_me_str (is_empty ast1 ast2)
										 | otherwise= string




send_write (ASTNode string ast1 ast2) | string=="num"= give_me_str (is_empty ast1 ast2)
                                | string=="plus"= "("++send_write ast1++"+"++send_write ast2++")"
                                | string=="times"=  "("++send_write ast1++"*"++send_write ast2++")"
								| string=="negate"="(-"++send_write (is_empty ast1 ast2)++")"
								| string=="str" ="\""++give_me_str (is_empty ast1 ast2)++"\""
								| string=="len"="(length "++send_write (is_empty ast1 ast2) ++")"
								| string=="cat" ="("++send_write ast1 ++"++"++send_write ast2 ++")"
								| otherwise=string





give_me_str (ASTNode string _ _) = string


evaluateAST (x,y) | y==[] =  evaluate_helper1 x x y
				  | otherwise= (printt x y, result x y)




--org = original ast

	
evaluate_helper1 (ASTNode string ast1 ast2) org y | string=="plus" =(org, num_to_str ((send_evaluate ast1 y)+ (send_evaluate ast2 y)))
										 		| string=="times"= (org, num_to_str ((send_evaluate ast1 y) * (send_evaluate ast2 y)))
										 		| string=="negate"=( org ,num_to_str(  (-1) * (send_evaluate (is_empty ast1 ast2) y)))
										 		| string=="num"=(org, (give_me_str (is_empty ast1 ast2)))
										        | string=="cat" = (org , (concatenate ast1 y++ concatenate ast2 y))
										        | string=="len"=(org, num_to_str (length (concatenate (is_empty ast1 ast2) y)))
										 		| string=="str"=(org, (give_me_str (is_empty ast1 ast2)))
										 -- otherwise= (org,string)

result (ASTNode string ast1 ast2) y | string=="plus" = num_to_str ((send_evaluate ast1 y)+ (send_evaluate ast2 y))
										 		| string=="times"=  num_to_str ((send_evaluate ast1 y) * (send_evaluate ast2 y))
										 		| string=="negate"=num_to_str(  (-1) * (send_evaluate (is_empty ast1 ast2) y))
										 		| string=="num"= (give_me_str (is_empty ast1 ast2))
										        | string=="cat" =  (concatenate ast1 y ++ concatenate ast2 y)
										        | string=="len"= num_to_str (length (concatenate (is_empty ast1 ast2) y))
										 		| string=="str"= (give_me_str (is_empty ast1 ast2))
										 		| otherwise= find_for_strings string y

send_evaluate (ASTNode string ast1 ast2) y| string=="plus" =(send_evaluate ast1 y) + (send_evaluate ast2 y)
										 |  string=="num"=str_to_num (is_empty ast1 ast2)
                                         | string=="times"= (send_evaluate ast1 y) * (send_evaluate ast2 y)
										 | string=="negate"= (-1) * (send_evaluate (is_empty ast1 ast2) y)  
										 | string=="len"= length (concatenate (is_empty ast1 ast2) y)
										 | otherwise= find_for_numeric string y


										 

find_for_numeric _ []= 0									
find_for_numeric string (y:ys) | get_first y==string = str_to_num2( get_third y)
				               | otherwise=find_for_numeric string ys

let_func [] =""
let_func (y:ys) | ys /= [] = let_func_helper y ++";"++let_func ys
                | otherwise=let_func_helper y

let_func_helper tuple | get_second (tuple) =="num" = (get_first tuple) ++"="++ (get_third tuple)
					 | get_second (tuple) =="str" = (get_first tuple) ++"="++"\""++ (get_third tuple)++"\""										  
			--((printt org), result)							
										--  otherwise= (org,string)
str_to_num2 string= read string :: Int
str_to_num (ASTNode string ast1 ast2) = read string :: Int
num_to_str num = show num
concatenate (ASTNode string ast1 ast2) y | string=="cat" = (concatenate ast1 y++ concatenate ast2 y)
									   | string=="str"=give_me_str (is_empty ast1 ast2)
									   | otherwise=find_for_strings string y
find_for_strings _ [] = ""
find_for_strings string (y:ys) | string== get_first y = get_third y
							   | otherwise=find_for_strings string ys

find_for_print _ [] = ""
find_for_print string (y:ys)   | string== get_first y = get_second y
							   | otherwise=find_for_print string ys


is_numeric string y | find_for_print string y =="num" = 1
                    | otherwise=0



printt_helper string y | is_numeric string y==1 = (ASTNode "num" (ASTNode (find_for_strings string y) EmptyAST EmptyAST) EmptyAST)
                       | otherwise=(ASTNode "str" (ASTNode (find_for_strings string y) EmptyAST EmptyAST) EmptyAST)

printt EmptyAST _= EmptyAST
printt (ASTNode string ast1 ast2) y | string=="plus"= (ASTNode string (printt ast1 y) (printt ast2 y))
                                  | string=="times"= (ASTNode string (printt ast1 y) (printt ast2 y))
                                  | string=="str"= (ASTNode string (ASTNode (give_me_str (is_empty ast1 ast2)) EmptyAST EmptyAST) EmptyAST)
                                  | string=="negate"= (ASTNode string (printt ast1 y) (printt ast2 y))
                                  | string=="cat"= (ASTNode string (printt ast1 y) (printt ast2 y))
                                  | string=="num"= (ASTNode string (ASTNode (give_me_str (is_empty ast1 ast2)) EmptyAST EmptyAST) EmptyAST)
                                  | string=="len"= (ASTNode string (printt ast1 y) (printt ast2 y))
                                  | otherwise= printt_helper string y



                                  


is_empty EmptyAST y= y
is_empty x EmptyAST =x        

































