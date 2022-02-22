.file	"return2.c"
.text
.section	.text.startup, "ax", @progbits
.p2align 4
.globl	main
.type	main, @function
main:
movl	$0, %eax
movl	$0, %eax
movl	$2, %eax
ret
