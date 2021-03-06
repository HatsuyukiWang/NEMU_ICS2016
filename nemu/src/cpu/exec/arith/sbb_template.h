#include "cpu/exec/template-start.h"
#include "cpu/exec/helper.h"
#include "cpu/helper.h"
#include "../flag.h"

#define instr sbb

static void do_execute(){
	DATA_TYPE src = op_src->val + cpu.CF;
	if (op_src->size == 1 && op_dest->size != 1) op_src->val = (int8_t)op_src->val;
	DATA_TYPE result = op_dest->val - src;

	cpu.CF = op_dest->val < src;
	OPERAND_W(op_dest, result);
	arith_flag(op_dest->val, MSB(op_dest->val), (~src) + 1, MSB((~src) + 1), result, MSB(result));
	print_asm_template2();
}

#if DATA_BYTE == 2 || DATA_BYTE == 4
make_instr_helper(si2rm)
#endif

make_instr_helper(i2a)
make_instr_helper(i2rm)
make_instr_helper(r2rm)
make_instr_helper(rm2r)

#undef instr

#include "cpu/exec/template-end.h"
