.section .data
.globl str1

	str1: 		.string "oi %d \n"
.section .text
.globl teste_1
.globl teste_2

teste_1:
	movq $12, %rax
	movq $0, %rdi

	syscall
	ret

teste_2:
	# movq %rdi, %rdi
	# como rdi é o parâmetro
	# não preciso muda-lo
	pushq %rbp					
	movq %rsp, %rbp
	
	# movq %rdi, %rax
	movq 16(%rbp) , % rax

	movq %rax, %rsi
	mov $str1, %rdi
	call printf 

	movq %rax, %rdi
	movq $12, %rax
	syscall

	popq %rbp
	ret
