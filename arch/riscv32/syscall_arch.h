//#error WTF in riscv32/syscall_arch.h
#define SYSCALL_FADVISE_6_ARG
#define SYSCALL_IPC_BROKEN_MODE
#define SYS_clock_gettime SYS_clock_gettime64
#define SYS_rt_sigtimedwait SYS_rt_sigtimedwait_time64

#define __SYSCALL_LL_E(x) \
((union { long long ll; long l[2]; }){ .ll = x }).l[0], \
((union { long long ll; long l[2]; }){ .ll = x }).l[1]
#define __SYSCALL_LL_O(x) 0, __SYSCALL_LL_E((x))


#define __asm_syscall(...) \
	__asm__ __volatile__ ("ecall\n\t" \
	: "=r"(a0) : __VA_ARGS__ : "memory"); \
	return a0; \

static inline long __syscall0(long n)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0");
	__asm_syscall("r"(a7))
}

static inline long __syscall1(long n, long a)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0") = a;
	__asm_syscall("r"(a7), "0"(a0))
}

static inline long __syscall2(long n, long a, long b)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0") = a;
	register long a1 __asm__("a1") = b;
	__asm_syscall("r"(a7), "0"(a0), "r"(a1))
}

static inline long __syscall3(long n, long a, long b, long c)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0") = a;
	register long a1 __asm__("a1") = b;
	register long a2 __asm__("a2") = c;
	__asm_syscall("r"(a7), "0"(a0), "r"(a1), "r"(a2))
}

static inline long __syscall4(long n, long a, long b, long c, long d)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0") = a;
	register long a1 __asm__("a1") = b;
	register long a2 __asm__("a2") = c;
	register long a3 __asm__("a3") = d;
	__asm_syscall("r"(a7), "0"(a0), "r"(a1), "r"(a2), "r"(a3))
}

static inline long __syscall5(long n, long a, long b, long c, long d, long e)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0") = a;
	register long a1 __asm__("a1") = b;
	register long a2 __asm__("a2") = c;
	register long a3 __asm__("a3") = d;
	register long a4 __asm__("a4") = e;
	__asm_syscall("r"(a7), "0"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4))
}

static inline long __syscall6(long n, long a, long b, long c, long d, long e, long f)
{
	register long a7 __asm__("a7") = n;
	register long a0 __asm__("a0") = a;
	register long a1 __asm__("a1") = b;
	register long a2 __asm__("a2") = c;
	register long a3 __asm__("a3") = d;
	register long a4 __asm__("a4") = e;
	register long a5 __asm__("a5") = f;
	__asm_syscall("r"(a7), "0"(a0), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5))
}

