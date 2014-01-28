	.start	pippo

	.import	read
	.import	write
	.import	readstr
	.import	writestr
a	.word	1
b	.word	1

pippo:
	pushi	a
	pushi	1
	pop*	
	pushi	b
	pushi	7
	pop*	
	pushi	a
	push	a
	push	b
	mul	
	pushi	3
	add	
	pop*	
	pushi	b
	push	b
	pushi	1
	push	a
	mul	
	sub	
	pop*	
	pushi	a
	pushi	1
	call	write
	spfree	2
	pushi	b
	pushi	1
	call	write
	spfree	2
	stop	
	.end	
