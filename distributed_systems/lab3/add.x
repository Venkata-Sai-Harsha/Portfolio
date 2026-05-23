struct add_in {
	long arg1;
	long arg2;
};

struct sub_in{
	long arg1;
	long arg2;
};

typedef long add_out;
typedef long sub_out;

program ADD_PROG {
     version ADD_VERS {
         add_out ADD_PROC(add_in) = 1;
         sub_out SUB_PROC(sub_in) = 2;
     } = 1;
} = 0x3543000;