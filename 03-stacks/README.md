# the stack adt

a stack is a list with the restriction tha t insertions and deletions can be performed in only one position, namely, the end of the list called the top.

### postfix expressions

suppose we have a pocket calculator and would like to compute the cost of a shopping trip.  to do so we add a list of numbers and multiply the result by 1.06; this computes the purcahse price of some items with local sales tax added.  if the items are 4.99, 5.99, and 6.99 then a natural way to enter this would be the sequence 

$$4.99 * 1.06 + 5.99 + 6.99 * 1.06$$

find an algorithm that would figure out the presedence

1.  +, * ()
2.  convert the infix expression to post fix expression
3.  compute postfix

algorithm 1:  an empty stack s
-  if we see an operand, output it
-  if we see an operator, pop all operators in s that have the same or a higher precedence then ad it and push the current operator to s.  exception:  if we see "(" we push it to s.  if we see ")" we pop all operators in s until "(" inclusive
-  when all tokens are processed pop all elements in s

