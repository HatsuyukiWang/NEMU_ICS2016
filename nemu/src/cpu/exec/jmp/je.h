#include "cpu/exec/helper.h"

make_helper(je_i_b);
make_helper(je_i_v);

#define DATA_BYTE 1
#include "je-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "je-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "je-template.h"
#undef DATA_BYTE

make_helper_v(je_i)
