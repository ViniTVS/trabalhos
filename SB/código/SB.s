.section .data
	topoHeap: .quad 0
	inicioHeap: .quad 0
	tam_aloca:  .quad 0
	op:			.quad 0
	local:		.quad 0
	str0: 		.string "oi \n"
	str1: 		.string "oi %u \n"
	str3: 		.string "valor1: %u \n"
	str4: 		.string "valor2: %u \n"
	str5: 		.string "var: %u \n"
	str6: 		.string "continua igual \n"
	str7: 		.string "volta while \n"
	str2: 		.string "topoHeap: %ld inicioHeap: %ld \n"
	strPrint1: 	.string "precione 1 p/ alocar, 2 p/ liberar e seu tam (tam 0 finaliza a execução): \n"
	strPrint2: 	.string "%ld %ld"
	strPrint3: 	.string "Função: %ld size: %ld \n"
	strTeste:	.string "Aloca_novo \n" 
	strTeste1:	.string "Aloca_topo\n"
	strCab:		.string "################" 
	strOcupado:	.string "+" 
	strLivre:	.string "" 
	strN:		.string " \n" 

.section .text
.globl main

topo_inicio:
	pushq %rbp
	movq %rsp, %rbp

	mov $str2, %rdi
	movq topoHeap, %rsi
	movq inicioHeap, %rdx
	call printf 

	popq %rbp
	ret

alocaEsp:
	# pego o topo e adiciono o valor passado por parâmetro por %rdi
	movq topoHeap, %r10
	addq %r10, %rdi
	movq $12, %rax
	syscall
	
	movq %rax, topoHeap 			# atualizo o topoHeap

	ret

iniciaAlocador:
	movq $0, %rdi					# 0 no %rdi para retornar valor atual da brk
	movq $12, %rax					# 12 no %rax para indicar a syscall a ser chamada
	syscall

	movq %rax, inicioHeap			# coloca o valor de inicioHeap igual a topoHeap
	movq %rax, topoHeap				# coloca o valor de %rax que é o topo da heap na variável topoHeap

	ret


finalizaAlocador:
	movq $0, %rdi				# 0 no %rdi para retornar valor atual da brk
	movq $12, %rax				# 12 no %rax para indicar a syscall a ser chamada
	syscall
	movq %rax, topoHeap			# restaura o valor inicial da heap em topoHeap

liberaMem:

	pushq %rbp
	movq %rsp, %rbp


	# rdi possui a posição de memória a ser liberada
	movq %rdi, %rbx
	subq $16, %rbx				# volto 16 posições de memória p/ chegar à flag

	movq $0, (%rbx)				# zero a flag	

	popq %rbp
	ret



imprime_mapa:

	pushq %rbp
	movq %rsp, %rbp

	movq inicioHeap, %rbx
	movq %rbx, %r14
	movq topoHeap, %r15
	
	cmpq %rbx, %r15				# se nada foi alocado, saio do laço
	je fim_prime_loop

	while_prime:
		movq $strCab, %rdi
		call printf
		
		movq (%r14), %r12			# r12:= conteudo do cabeçalho
		
		addq $8, %r14
		movq (%r14), %r13			# r13 := número de bytes ocupados

		addq $8, %r14				# inicio da memoria ocupada
		addq %r13, %r14			# avanço na memória

		movq %r14, %rsi
		mov $str3, %rdi
		call printf 


		movq $1, %r10
		cmpq %r12, %r10				# r12 == 1?
		je 	imprime_ocupado			# r12 = 1
		jne imprime_livre			# r12 = 0
		
	condition:
		cmpq %r14, %r15				# se chegar no topo, saio

		movq %r15, %rsi
		mov $str4, %rdi
		call printf 
		
		movq %r14, %rsi
		mov $str4, %rdi
		call printf 


		jle fim_prime_loop
		jmp while_prime

	imprime_ocupado:

		movq $0, %r10			
		cmpq %r10, %r13			# se r13 for 0 eu volto
		jle condition

		mov $strOcupado, %rdi
		call printf

		subq $1, %r13
		jmp imprime_ocupado

	imprime_livre:
		movq $0, %r10

		movq %r13, %rsi
		mov $str4, %rdi
		call printf 			
		
		cmpq %r10, %r13			# se r13 for 0 eu volto
		jle condition


		mov $strLivre, %rdi
		call printf

		subq $1, %r13
		jmp imprime_livre

	

	fim_prime_loop:
	popq %rbp
	ret


alocaMem:
	# ##################################################################### #
	#																		#
	#	%rax = (retorno) espaço de memória alocado para ser usado			#
	#	%rbx = var p/ caminhar em memória									#
	#	(%rbx) = valor escrito no espaço de memória							#
	#	%r11 = tam_aloca													#
	#	%r12 = checagem de dados do end de memória							#
	#	%r15 = end de mem do topo da Heap									#
	#																		#
	# ##################################################################### #

	pushq %rbp
	movq %rsp, %rbp

	
	movq tam_aloca, %r14		# passa para %rax o valor a ser alocado (num_bytes)
	movq inicioHeap, %rbx		# move inicioHeap para %rbx
	movq topoHeap, %r15			# move topoHeap para %rcx

	cmpq %rbx, %r15				# verifico se ainda não aloquei nada
	je aloca_topo				# caso não tenha, aloco no topo


	while:							# laço para procurar bloco de memória livre, se não encontrar aloca novo bloco
	
		movq (%rbx), %r12			# r12 = flag 
		movq $0, %r10				# r10 = 0
		cmpq %r12, %r10				# r12 == 0?
		je aloca_usado				# se sim, aloca na memória


		addq $8, %rbx				# avanço p/ o tamanho do espaço que foi alocado
		movq (%rbx), %r12			# r12 = tam ocupado por aquela posição

		addq $8, %rbx				# avanço p/ o inicio do espaço alocado
		addq %r12, %rbx				# avanço p/ o próximo espaço


		movq %rbx, %rsi
		mov $str5, %rdi
		call printf 


		cmp %rbx, %r15				# compara a posição de memória atual com a do topo
		je aloca_topo				# se for igual ao topo atual, aloco no topo
		jg while					# se o topo for maior que a posição atual, volto pro laço

	fim_while:
		# cmpq $0, %r8				# se não achou bloco livre de memória vai para o aloca para alocar memória
		# je aloca
		jmp finish

	volta_while:
		# rbx está no valor de mem da seção
		movq (%rbx), %r12			# r11 = valor do endereço

		mov $str7, %rdi
		call printf 


		movq %r12, %rsi
		mov $str3, %rdi
		call printf 

		movq %rbx, %rsi
		mov $str4, %rdi
		call printf

		addq $8, %rbx				# vou p/ inicio da seção
		
		
		movq %rbx, %rsi
		mov $str3, %rdi
		call printf
		
		addq %r12, %rbx				# avanço-a

		movq %rbx, %rsi
		mov $str4, %rdi
		call printf 


		movq topoHeap, %r15			# move topoHeap para %r15

		movq %r15, %rsi
		mov $str4, %rdi
		call printf 
		
		movq %rbx, %rsi
		mov $str3, %rdi
		call printf 
		



		mov $str7, %rdi
		call printf 


		cmpq %rbx, %r15				# verifico se cheguei no topo ainda não aloquei nada
		jle aloca_topo				# caso não tenha, aloco no topo

		mov $str7, %rdi
		call printf 

		jmp while

	


	aloca_usado:

		# rbx está no end da flag
		movq tam_aloca, %r14		# passa para %r14 o tam a ser alocado (num_bytes)
		addq $8, %rbx				# avanço p/ o valor livre de mem.
		movq (%rbx), %r12			# r12 := valor livre
		
		movq (%rbx), %r15			# r15 := valor livre
		movq (%rbx), %r13			# r15 := valor livre
		
		movq %r13, %rsi
		mov $str4, %rdi
		call printf 

		# espaço livre + 16 tem que ser menor que o desejado p/ alocar
		cmpq %r12, %r14				# tam a ser alocado > valor livre ?
		jg volta_while				# volto ao loop p/ inserir

		subq %r14, %r15				# r15 := valor livre - novo alocado

		movq %r15, %rsi
		mov $str4, %rdi
		call printf 

		movq $16, %r10				# r10 := 16
		cmpq %r10, %r15				# valor livre - alocado > 16?
		jle continua_igual			# se for menor


		movq %r14, %rsi
		mov $str3, %rdi
		call printf 

		subq $8, %rbx				# volto ao espaço da flag

		movq %rbx, %rsi
		mov $str4, %rdi
		call printf 

		movq (%rbx), %rsi
		mov $str5, %rdi
		call printf 


		movq $1, (%rbx)				# coloco a flag de ocupado

		movq (%rbx), %rsi
		mov $str3, %rdi
		call printf 

		addq $8, %rbx				# vou p/ tamamanho da seção de mem.
		movq %r14, (%rbx)			# o tam de mem recebe o novo valor alocado

		movq %rbx, %rsi
		mov $str4, %rdi
		call printf 

		movq (%rbx), %rsi
		mov $str3, %rdi
		call printf 

		addq $8, %rbx				# inicio da mem seção de mem.
		movq %rbx, %rax				# rax := novo inicio de mem alocada

		movq %rbx, %rsi
		mov $str3, %rdi
		call printf 

		addq %r14, %rbx				# avanço a mem. p/ escrever a nova flag

		movq %rbx, %rsi
		mov $str3, %rdi
		call printf 


		movq $0, (%rbx)				# flag do 2° fica 0
		
		addq $8, %rbx				# avanço p/ local de tam ocupado 

		movq %rbx, %rsi
		mov $str4, %rdi
		call printf 

		subq $16, %r15				# valor restante de mem. - cabeçalho
		
		movq %r15, (%rbx)			# tam da 2° := r12

		movq (%rbx), %rsi
		mov $str4, %rdi
		call printf 

		jmp finish


	continua_igual:

		mov $str6, %rdi
		call printf 

		subq $8, %rbx				# volto p/ a flag
		movq $1, (%rbx)				# marco que está ocupada

		movq %rbx, %rsi
		mov $str3, %rdi
		call printf 

		addq $16, %rbx				# vou p/ inicio da seção de mem.
		movq %rbx, %rax				# rax := novo inicio de mem alocada


		jmp finish


	aloca_topo:

		mov $strTeste1, %rdi
		call printf

	call topo_inicio 


		movq $8, %rdi				# abro espaço p/ escrever a flag
		call alocaEsp

		mov $strTeste1, %rdi
		call printf
		
		movq %rbx, %rsi
		mov $str3, %rdi
		call printf 

	call topo_inicio 


		movq $1, (%rbx)				# coloca no conteúdo da falg de ocupado



		mov $strTeste1, %rdi
		call printf

		addq $8, %rbx				# desloca se 8 bytes para chegar no bloco campo de tamanho
		movq $8, %rdi				# abro espaço p/ escrever a o tam
		call alocaEsp

	call topo_inicio 


		movq tam_aloca, %r11		# passa para %r11 o tam a ser alocado (num_bytes)
		movq %r11, (%rbx)			# escrevo em memória o tam
		

		addq $8, %rbx				# desloca se 8 bytes para chegar no campo a ser escrito
		movq tam_aloca, %rdi		# abro espaço em memória p/ alocar o espaço desejado
		call alocaEsp
		

	call topo_inicio 

		movq %rbx, %rax				# rax := novo inicio de mem alocada
		jmp finish			


	finish:
		# addq $8, %rsp
		popq %rbp
		ret

main:




	jmp teste


iterage:

	# subq $16, %rbp
	mov $strPrint1, %rdi	# impressão de texto
	call printf

	# código retirado do algoritmos 2.16 do livro:
	movq %rbp, %rax			
	subq $16, %rax
	movq %rax, %rdx
	movq %rbp, %rax
	subq $8, %rax
	movq %rax , %rsi
	mov $strPrint2, %rdi	
	call scanf
	movq -16(%rbp), %rdx	# valor de tam
	movq -8(%rbp) , %rsi	# valor de op

	movq %rdx, tam_aloca	# tam aloca recebe valor
	movq %rsi, op

	movq $0, %rax			# compara se o valor digitado
	cmpq %rax, %rdx			# em tam é 0
	je fim_iterage			# tam == 0, finaliza o programa

	mov $strPrint3, %rdi
	# mov tam_aloca, %rsi
	call printf	

	jmp iterage


teste:
	pushq %rbp
	movq %rsp, %rbp
	call iniciaAlocador

	# teste p/ alocar 

	call topo_inicio 
	
	movq $300, tam_aloca
	movq tam_aloca, %rsi
	mov $str3, %rdi
	call printf 
	
	call alocaMem
	movq %rax, %r14

	call topo_inicio 

	movq $100, tam_aloca
	movq tam_aloca, %rsi
	mov $str3, %rdi
	call printf 

	call alocaMem

	movq %rax, %r13

	# addq $8, %rsp			# var local 


	movq $80, tam_aloca
	movq tam_aloca, %rsi
	mov $str3, %rdi
	call printf 

	call topo_inicio 

	movq $666, tam_aloca	
	movq tam_aloca, %rsi
	mov $str3, %rdi
	call printf 
	
	call alocaMem


	call topo_inicio 

	

	movq %r13, %rsi
	mov $str1, %rdi
	call printf 


	movq %r13, %rdi
	call liberaMem

	call imprime_mapa


	movq $110, tam_aloca
	movq tam_aloca, %rsi
	mov $str3, %rdi
	call printf 





	call alocaMem
	call imprime_mapa

	# call imprime_mapa


	mov $strN, %rdi
	call printf 

	call topo_inicio 


	jmp fim_iterage




	call alocaMem


fim_iterage:

	mov $strN, %rdi
	call printf

	popq %rbp
	
	movq $60, %rax
	movq $1, %rdi
	syscall

