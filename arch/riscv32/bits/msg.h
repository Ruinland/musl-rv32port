struct msqid_ds {
	struct ipc_perm msg_perm;
	unsigned long msg_stime;
    unsigned long padstime;
	unsigned long msg_rtime;
    unsigned long padrtime;
	unsigned long msg_ctime;
    unsigned long padctime;
	unsigned long msg_cbytes;
	msgqnum_t msg_qnum;
	msglen_t msg_qbytes;
	pid_t msg_lspid;
	pid_t msg_lrpid;
	unsigned long __unused[2];
	time_t xmsg_stime;
	time_t xmsg_rtime;
	time_t xmsg_ctime;
};
