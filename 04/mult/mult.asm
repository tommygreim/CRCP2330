// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
		@R3		//Counter = 0
		M=1
		@R2		//Sum = 0
		M=0

 (LOOP)
 		@R3
 		D=M 	//Counter into Data
 		@R1		
 		D=D-M	//Data = Counter - Term2
 		@END
 		D;JGT
 		@R0		
 		D=M 	//Data = Term1
 		@R2
 		M=D+M 	//Sum = Term1 + Sum(current)
 		@R3
 		M=M+1	//Increment Counter
 		@LOOP
 		0;JMP
 (END)	
 		@END
 		0;JMP