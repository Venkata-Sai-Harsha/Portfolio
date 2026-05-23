#include <rpc/rpc.h>

CLIENT *clnt_create(char *host, u_long prog, u_long vers, char *proto);