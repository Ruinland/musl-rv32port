struct ipc_perm {
	key_t __ipc_perm_key;
	uid_t uid;
	gid_t gid;
	uid_t cuid;
	gid_t cgid;
	unsigned short mode;
    unsigned short __pad1;
	unsigned short __ipc_perm_seq;
    unsigned short __pad2;
    unsigned long __unused1;
    unsigned long __unused2;
};
