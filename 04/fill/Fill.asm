// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(KEYCHECK)	
 			@KBD
 			D=M
 			@SETBLACK
 			D;JNE
	 		@SETWHITE
	 		0;JMP
(SETBLACK)
			@R4
			M=-1
			@START
			0;JMP
(SETWHITE)
			@R4
			M=0
			@START
			0;JMP
(START)
			@R0		//Counter
			M=0
			@8191
			D=A
			@R1		//Number of words on screen
			M=D
 (FILL)
	 		@R1
	 		D=M
	 		@R0
	 		D=M-D
	 		@KEYCHECK
	 		D;JGT
	 		@R0
	 		D=M
			@SCREEN
			D=A+D
			@R3
			M=D
			@R4
			D=M
			@R3
			A=M
			M=D
			@R0
			M = M + 1
			@FILL
			0;JMP