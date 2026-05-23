#include "add.h"
#include <string.h>

int main(int argc, char **argv) {
    CLIENT *cl;
    add_in in_add;
    sub_in in_sub;
    add_out *out_add;
    sub_out *out_sub;

    if (argc != 5) {
        printf("Usage: client <machine> <operation: add/sub> <int1> <int2>\n\n");
        return 1;
    }

    // Create a client handle
    cl = clnt_create(argv[1], ADD_PROG, ADD_VERS, "tcp");

    if (cl == NULL) {
        printf("Error: Unable to create RPC client handle\n");
        return 1;
    }

    // Parse operation type
    if (strcmp(argv[2], "add") == 0) {
        in_add.arg1 = atol(argv[3]);
        in_add.arg2 = atol(argv[4]);
        out_add = add_proc_1(&in_add, cl);

        if (out_add == NULL) {
            printf("Error: %s\n", clnt_sperror(cl, argv[1]));
        } else {
            printf("Result of addition: %ld\n", *out_add);
        }
    } else if (strcmp(argv[2], "sub") == 0) {
        in_sub.arg1 = atol(argv[3]);
        in_sub.arg2 = atol(argv[4]);
        out_sub = sub_proc_1(&in_sub, cl);

        if (out_sub == NULL) {
            printf("Error: %s\n", clnt_sperror(cl, argv[1]));
        } else {
            printf("Result of subtraction: %ld\n", *out_sub);
        }
    } else {
        printf("Invalid operation. Please choose 'add' or 'sub'\n");
    }

    // Destroy the client handle
    clnt_destroy(cl);
    return 0;
}
