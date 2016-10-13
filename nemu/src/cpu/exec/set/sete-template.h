#include "cpu/exec/template-start.h"

#define instr sete

static void do_execute() {
	if (cpu.ZF == 1) OPERAND_W(op_src, 1);
	else OPERAND_W(op_src, 0);
	print_asm_template1();
}

make_instr_helper(rm)

#undef instr

#include "cpu/exec/template-end.h"
