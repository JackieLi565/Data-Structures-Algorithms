The following questions will be answered with the following tower input tower(5, 2, 3):

Question 1: How will the first recursive call to tower() be invoked?

Answer: The first recursive call to tower() will be tower(4, 2, 1), as it will first calcualte the spare = 6 - (2 + 3) = 1, after it will than call tower with the following args: tower(5 - 1, start, spare), which calcualting the values is tower(4, 2, 1).

Question 2: How many recursive calls to towers() will be made before this first recursive call actually returns to the initial incovation

Answer: Using the formula (2^n)-1 where n in the amount of inputs or plates, if we have 5 plates (2^5)-1 = 31, therefore it will take 31 recursive calls to return to the inital invocation.

Question 3: Once towers(5, 2, 3) has invoked its first recursive call to towers() and this incovation has returned, what will be printed to stdout?

Answer: the move printed out will be: Tower 2 to Tower 3 (Move 16).

Question 4: How will the second recursive call be invoked?

Answer: the second recursive call will be towers(3, 2, 3)

The next following question will be answered with tower inputs of 
towers(8, 1, 2).

Question: How many lines will be printed to stdout if towers(8, 1, 2)

Answer: the amount of lines will be equal to the amount of recursive calls, therefore using he formula (2^n)-1 where n equal to 8 the answer will be 255.


