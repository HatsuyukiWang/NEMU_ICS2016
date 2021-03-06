#include "cpu/exec/template-start.h"
#include "cpu/exec/helper.h"
#include "cpu/helper.h"

#define instr push

static void do_execute(){
	if(DATA_BYTE == 1) op_src->val = (int8_t)op_src->val;
	cpu.esp -= 4;
	swaddr_write(cpu.esp, 4, op_src->val, 2); /* R_SS */
	print_asm_template1();
}

make_instr_helper(i)

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(r)
make_instr_helper(rm)
#endif

#undef instr

#include "cpu/exec/template-end.h"

