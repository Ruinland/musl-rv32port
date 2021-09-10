.global __setjmp
.global _setjmp
.global setjmp
.type __setjmp, %function
.type _setjmp,  %function
.type setjmp,   %function
__setjmp:
_setjmp:
setjmp:
	sw s0,    0(a0)
	sw s1,    8(a0)
	sw s2,    16(a0)
	sw s3,    24(a0)
	sw s4,    32(a0)
	sw s5,    40(a0)
	sw s6,    48(a0)
	sw s7,    56(a0)
	sw s8,    64(a0)
	sw s9,    72(a0)
	sw s10,   80(a0)
	sw s11,   88(a0)
	sw sp,    96(a0)
	sw ra,    104(a0)

#ifndef __riscv_float_abi_soft
	fsw fs0,  112(a0)
	fsw fs1,  120(a0)
	fsw fs2,  128(a0)
	fsw fs3,  136(a0)
	fsw fs4,  144(a0)
	fsw fs5,  152(a0)
	fsw fs6,  160(a0)
	fsw fs7,  168(a0)
	fsw fs8,  176(a0)
	fsw fs9,  184(a0)
	fsw fs10, 192(a0)
	fsw fs11, 200(a0)
#endif

	li a0, 0
	ret
