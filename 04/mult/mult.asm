// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

// Put your code here.
		@3
		M=0
		@2
		M=0

 (LOOP)
 		@3
 		D=M
 		@1
 		D=D-A
 		@END
 		D;JGT
 		@1
 		D=A
 		@2
 		M=D+M
 		@3
 		M=M+1
 		@LOOP
 		0;JMP
 (END)	
 		@END
 		0;JMP