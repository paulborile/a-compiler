	.start	small

	.import	m_pop
	.import	m_push
top	.word	1
bottom	.word	1

small:
	pushi	top
	pushi	1
	pop*	
	pushi	top
	pushi	1
	call	m_push
	spfree	2
	pushi	top
	pushi	1
	call	m_pop
	spfree	2
	stop	
