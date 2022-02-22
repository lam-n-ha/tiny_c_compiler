.file	"return2.c"
.text
.section	.text.startup, "ax", @progbits
.p2align 4
.globl	main
.type	main, @function
main:
movl	$3, %eax
not	%eax
ret
