#include <sys/wait.h>
#include <signal.h>
#include "syscall.h"

pid_t waitpid(pid_t pid, int *status, int options)
{
    #if __riscv_xlen != 32
	return syscall_cp(SYS_wait4, pid, status, options, 0);
    #else // generic wait4
	pid_t ret;
	idtype_t idtype = P_PID;
	siginfo_t infop;

	if (pid < -1)
	  {
	    idtype = P_PGID;
	    pid *= -1;
	  }
	else if (pid == -1)
	  {
	    idtype = P_ALL;
	  }
	else if (pid == 0)
	  {
	    /* Linux Kernels 5.4+ support pid 0 with P_PGID to specify wait on
	     * the current PID's group. Earlier kernels will return -EINVAL.
	     */
	    idtype = P_PGID;
	  }

	options |= WEXITED;

	ret = syscall_cp (SYS_waitid, idtype, pid, &infop, options, 0);
	//ret = SYSCALL_CANCEL (waitid, idtype, pid, &infop, options, NULL);

	if (ret < 0)
	  {
	    return ret;
	  }

	if (status)
	  {
	    *status = 0;
	    switch (infop.si_code)
	  	{
	  	case CLD_EXITED:
	  		*status = infop.si_status << 8;
	  		break;
	  	case CLD_DUMPED:
	  		*status = 0x80;
	  		/* Fallthrough */
	  	case CLD_KILLED:
	  		*status |= infop.si_status;
	  		break;
	  	case CLD_TRAPPED:
	  	case CLD_STOPPED:
	  		*status = infop.si_status << 8 | 0x7f;
	  		break;
	  	case CLD_CONTINUED:
	  		*status = 0xffff;
	  		break;
	  	}
	  }

	return infop.si_pid;
    #endif // rv32 waitid hack
}
