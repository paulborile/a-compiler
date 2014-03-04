	.module	rts

io_char	.word	1	  // Buffer for output,input instructions
io_cnt	.word	1	  // Counter for general pourpose
io_flag	.word	1	  // Sign flag

	.export	writestr
	.export	readstr
	.export	write
	.export	read

writestr:
	pushi	0	   // Local counter for writestr
wrs_loop:
	pushr	1
	pushr	4	   // Take length of string
	cmp
	jge	end_wrs	   // If cnt > length string finish
	pushr	1	   // Take cnt
	pushr	5	   // Take address of string passed
	add
	push*		   // Take value of cnt element of string passed
	pushr	1	   // Dup last top of SP
	pop	io_char    // Put in global var io_char for output
	output	io_char
	pushi	10	   // Line feed
	cmp
	jeq	end_wrs	   // If LF end printing
	pushi	1
	add		   // Add 1 to cnt
	jmp	wrs_loop   // Repeat with next element of string
end_wrs:
	spfree	1
	ret

readstr:
	pushi	0	   // Local counter
//	pushi	62         // Print prompt
//	pop	io_char
//	output	io_char
res_loop:
	pushr	1	   // Dup top of stack
	pushr	5	   // Take address of string
	add		   // Get address of cnt element of the string
	input	io_char	   // Read a char
	push	io_char	   // Get contents of io_char
	pop*		   // Put in cnt element of the string io_char
	pushi	1
	add		   // Add 1 to local counter
	pushr	1	   // Get value of local counter
	pushr	4	   // Get length of the array ( string )
	cmp
	jeq	put_lf	   // jump if # of char read = length of array
	push	io_char	   // Get contents of io_char
	pushi	10	   // Line Feed
	cmp		   // Last char read = LF ?
	jne	res_loop   // If not repeat
put_lf:
	pushi	1
	sub		   // Subtract 1 to local counter
	pushr	4	   // Address of string
	add		   // Address of local counter element of string
	pushi	10	   // Line Feed
	pop*		   // Put in last element of string LF
	ret

read:
	spalloc	7	   // Local array for string
	pushi	1	   // Sign flag
	pushi	0	   // number to read here !
	pushir	3
	pushi	7
	call	readstr	   // read number 
	spfree	2
	pushi 	0
	pop	io_cnt	   // Set io_cnt to 0
	pushr	3	   // Get the contents of the first elem. of string
	pushi	45	   // Ascii code of minus char
	cmp		   // The first char is '-' ?
	jne	no_minus   // If not jump to no_minus
	pushi	-1
	popr	2	   // Set the sign flag to -1
	pushi	1
	pop	io_cnt	   // Set io_cnt to 1
	jmp	re_while
no_minus:
	pushr	3	   // Get the contents of the first elem. of string
	pushi	43	   // Ascii code of plus char
	cmp		   // The first char is '+' ?
	jne	re_while   // If not jump to re_while
	pushi	1
	pop	io_cnt	   // Set io_cnt to 1
re_while:
	pushir	3	   // Address of string read
	push	io_cnt	   // Get contents of io_cnt
	add		   // Address of cnt element of array ( string )
	push*		   // Get the contents of io_cnt elem. of string
	pushi	10	   // Line Feed
	cmp		   // is a LF ?
	jeq	re_e_whi   // If yes jump
	pushi	10
	mul		   // Multiplay the temporary result by 10
	pushir	3	   // Get address of string
	push	io_cnt
	add
	push*		   // Get the io_cnt element of array ( string )
	add		   // Add to temporary result
	pushi	48	   // Ascii code of '0'
	sub		   // Subtract to temporary result
	push	io_cnt
	pushi	1
	add
	pop	io_cnt	   // io_cnt = io_cnt + 1
	jmp	re_while   // repeat
re_e_whi:
	pushr	12	  //  Address of variable passed to read
	pushr	2
	pushr	4	  // Take sign flag
	mul
	pop*		  // Put the result in the variable passed to read
	spfree	9
	ret

write:
	pushi	10
	pushi	32
	pushi	32
	pushi	32
	pushi	32
	pushi	32	  // Allocate a string ( length = 7 ) with space 
	pushi	32	  // inside and at the end LF
	pushi	5
	pop	io_cnt	  // Set io_cnt to 5
	pushr	10	  // Address of number to print
	push*		  //  Value of the number to print
	pushr	1
	pushi	0
	cmp
	jge	wr_plus	  // If number >= 0 jump tp wr_plus
	pushi	-1
	mul		  // Change sign of number
	pushi	45	
	pop	io_flag	  // Set the sign char = '-'
	jmp	wr_loop
wr_plus:
	pushi	32	  // Ascii code of ' '
	pop	io_flag	  // Set the sign char = ' '
wr_loop:
	push	io_cnt
	pushir	3
	add		  // Address of io_cnt elem. of string
	pushr	2	  // Take temporary value of number
	pushr	1	  
	pushi	10
	div
	pushi	10
	mul
	sub		  // Take the intermediate number module 10
	pushi	48	  // Ascii code of '0'
	add		  // Trasform number to ascii code
	pop*		  // Put in the string
	pushi	10
	div		  // Divide by 10 the temporary value of number
	push	io_cnt
	pushi	1
	sub
	pop	io_cnt	  // io_cnt = io_cnt - 1
	pushr	1
	pushi	0
	cmp
	jne	wr_loop	  //  Jump if not end conversion
	push	io_cnt
	pushir	3
	add
	push	io_flag
	pop*
	pushir	2
	pushi	7
	call	writestr
	spfree	2
	spfree	8
	ret

	.end
