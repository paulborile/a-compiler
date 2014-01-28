	.start	fatt1

	.import	read
	.import	write
	.import	readstr
	.import	writestr
flag	.word	3000
cnt	.word	1
i	.word	1

fatt1:
	pushi	i
	pushi	0
	pop*	
L100:
	push	i
	pushi	3000
	cmp	
	jge	L101
	pushi	flag
	push	i
	add	
	pushi	1
	pop*	
	pushi	i
	push	i
	pushi	1
	add	
	pop*	
	jmp	L100
L101:
	pushi	i
	pushi	2
	pop*	
L102:
	push	i
	pushi	3000
	cmp	
	jge	L103
	pushi	flag
	push	i
	add	
	push*	
	pushi	1
	cmp	
	jne	L104
	pushi	i
	pushi	1
	call	write
	spfree	2
	pushi	cnt
	push	i
	pop*	
L105:
	push	cnt
	pushi	3000
	cmp	
	jge	L106
	pushi	flag
	push	cnt
	add	
	pushi	0
	pop*	
	pushi	cnt
	push	cnt
	push	i
	add	
	pop*	
	jmp	L105
L106:
	jmp	L107
L104:
L107:
	pushi	i
	push	i
	pushi	1
	add	
	pop*	
	jmp	L102
L103:
	stop	
	.end	
