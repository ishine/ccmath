.data
	.align 4
	.type  m,@object
	.size  m,4
m:	
	.long 16807
.text
	.align 16
.globl lrana
	.type     lrana,@function
lrana:	
	movl   4(%esp),%eax
	movl   m,%ecx
	mull   %ecx
	shldl  $1,%eax,%edx
	btrl   $31,%eax
	addl   %edx,%eax
	btl    $31,%eax
	jnc    .A
	addl   $1,%eax
	btrl   $31,%eax
.A:	
	ret
