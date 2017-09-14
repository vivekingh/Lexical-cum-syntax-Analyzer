Preprocessing: After extracting the folder get the path of testing2.c file and error.c and paste in the file opening syntax in source_code.c file
->Open the source_code.c
->find main function
->Replace /home/vivek/Desktop/final/testing2.c by your pc path for testing2.c
->Replace /home/vivek/Desktop/final/testing2.c by your pc path for error.c as well


Now testing2.c is your input file 
You can modify the content of this file according to the guidelines  given below. 

**Error.txt file is used to preserve all errors in testing2.c and displaying it in output.

1. Compilation and Run of program
	->Go to assignment directory on your pc
	->type gcc -o source_code source_code.c for compiling
	->type ./source_code for executing

2. Input type and format
	->Input should be a c program file which must have format like this
	#include<stdio.h>
	int main()
	{
		int x;
	
	}

	->That was the minimum possible lines of code 
	->Since, my program check '{' and '}' so, you must have not to commit mistake in writting curly bracket
	->Mistakes(in printf,scanf,int,char,float) are only allowed inside the braces
	
	**If you want to give your code as input just replace the content of testing2.c by your content
	**Keep one extra space before closing curly bracket(}).  

3.Output
	->Output may have all errors present in source_code.c on a single run OR
	->It may have one error at a time. Next error will be displayed when you fix the previous one.


**Only plain string is allowed in printf 

**Some sample output and input check the sample folder
