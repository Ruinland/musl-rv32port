.global __longjmp
.global _longjmp
.global longjmp
.type __longjmp, %function
.type _longjmp,  %function
.type longjmp,   %function
__longjmp:
_longjmp:
longjmp:
	lw s0,    0(a0)
	lw s1,    8(a0)
	lw s2,    16(a0)
	lw s3,    24(a0)
	lw s4,    32(a0)
	lw s5,    40(a0)
	lw s6,    48(a0)
	lw s7,    56(a0)
	lw s8,    64(a0)
	lw s9,    72(a0)
	lw s10,   80(a0)
	lw s11,   88(a0)
	lw sp,    96(a0)
	lw ra,    104(a0)

#ifndef __riscv_float_abi_soft
	flw fs0,  112(a0)
	flw fs1,  120(a0)
	flw fs2,  128(a0)
	flw fs3,  136(a0)
	flw fs4,  144(a0)
	flw fs5,  152(a0)
	flw fs6,  160(a0)
	flw fs7,  168(a0)
	flw fs8,  176(a0)
	flw fs9,  184(a0)
	flw fs10, 192(a0)
	flw fs11, 200(a0)
#endif

	seqz a0, a1
	add a0, a0, a1
	ret
