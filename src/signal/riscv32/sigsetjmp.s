.global sigsetjmp
.global __sigsetjmp
.type sigsetjmp, %function
.type __sigsetjmp, %function
sigsetjmp:
__sigsetjmp:
	bnez a1, 1f
	tail setjmp
1:

	sw ra, 208(a0)
	sw s0, 224(a0)
	mv s0, a0

	call setjmp

	mv a1, a0
	mv a0, s0
	lw s0, 224(a0)
	lw ra, 208(a0)

.hidden __sigsetjmp_tail
	tail __sigsetjmp_tail
