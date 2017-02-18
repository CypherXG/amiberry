#include "sysconfig.h"
#include "sysdeps.h"
#include "m68k.h"
#include "memory.h"
#include "custom.h"
#include "events.h"
#include "newcpu.h"
#include "compiler/compemu.h"
#include "fpu/fpu.h"
#include "cputbl.h"
#include "cpu_emulation.h"
#include "cpummu.h"
#define CPUFUNC(x) x##_ff
#define SET_CFLG_ALWAYS(x) SET_CFLG(x)
#define SET_NFLG_ALWAYS(x) SET_NFLG(x)
#ifdef NOFLAGS
#include "noflags.h"
#endif

#if !defined(PART_1) && !defined(PART_2) && !defined(PART_3) && !defined(PART_4) && !defined(PART_5) && !defined(PART_6) && !defined(PART_7) && !defined(PART_8)
#define PART_1 1
#define PART_2 1
#define PART_3 1
#define PART_4 1
#define PART_5 1
#define PART_6 1
#define PART_7 1
#define PART_8 1
#endif

#ifdef PART_1
/* OR.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0000_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0010_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 20 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0018_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0020_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0028_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0030_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0038_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0039_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 28 * CYCLE_UNIT / 2;
}

/* ORSR.B #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_003c_33)(uae_u32 opcode)
{
{	MakeSR ();
{	uae_s16 src = get_iword_mmu060 (2);
	src &= 0xFF;
	regs.sr |= src;
	MakeFromSR();
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0040_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0050_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0058_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0060_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0068_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0070_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0078_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0079_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* ORSR.W #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_007c_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330018; }
{	MakeSR ();
{	uae_s16 src = get_iword_mmu060 (2);
	regs.sr |= src;
	MakeFromSR();
}}}	m68k_incpci (4);
l_330018: ;
return 8 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0080_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0090_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0098_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_00a0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 30 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_00a8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_00b0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}}return 32 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_00b8_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_00b9_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (10);
return 36 * CYCLE_UNIT / 2;
}

/* CHK2.B #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330027; }
}
}}}	m68k_incpci (4);
l_330027: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.B #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330028; }
}
}}}	m68k_incpci (6);
l_330028: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.B #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330029; }
}
}}}}l_330029: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.B #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00f8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330030; }
}
}}}	m68k_incpci (6);
l_330030: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.B #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00f9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330031; }
}
}}}	m68k_incpci (8);
l_330031: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.B #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330032; }
}
}}}	m68k_incpci (6);
l_330032: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.B #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_00fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s8)get_byte_mmu060 (dsta); upper = (uae_s32)(uae_s8)get_byte_mmu060 (dsta + 1);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s8)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330033; }
}
}}}}l_330033: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BTST.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVPMR.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr memp = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_u16 val = (get_byte_mmu060 (memp) << 8) + get_byte_mmu060 (memp + 2);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_013a_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 2;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_getpci () + 2;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,(d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_013b_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = 3;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* BTST.B Dn,#<data>.B */
uae_u32 REGPARAM2 CPUFUNC(op_013c_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = get_ibyte_mmu060 (2);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVPMR.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uaecptr memp = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_u32 val = (get_byte_mmu060 (memp) << 24) + (get_byte_mmu060 (memp + 2) << 16)
              + (get_byte_mmu060 (memp + 4) << 8) + get_byte_mmu060 (memp + 6);
	m68k_dreg (regs, dstreg) = (val);
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVPRM.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	uaecptr memp = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	put_byte_mmu060 (memp, src >> 8);
	put_byte_mmu060 (memp + 2, src);
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_01a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_01a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_01b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_01b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_01b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_01c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVPRM.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_01c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	uaecptr memp = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	put_byte_mmu060 (memp, src >> 24);
	put_byte_mmu060 (memp + 2, src >> 16);
	put_byte_mmu060 (memp + 4, src >> 8);
	put_byte_mmu060 (memp + 6, src);
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_01d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_01d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_01e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_01e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_01f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_01f8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_01f9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0200_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0210_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 20 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0218_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0220_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0228_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0230_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0238_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0239_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 28 * CYCLE_UNIT / 2;
}

/* ANDSR.B #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_023c_33)(uae_u32 opcode)
{
{	MakeSR ();
{	uae_s16 src = get_iword_mmu060 (2);
	src |= 0xFF00;
	regs.sr &= src;
	MakeFromSR();
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0240_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0250_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0258_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0260_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0268_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0270_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0278_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0279_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* ANDSR.W #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_027c_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330090; }
{	MakeSR ();
{	uae_s16 src = get_iword_mmu060 (2);
	regs.sr &= src;
	MakeFromSR();
}}}	m68k_incpci (4);
l_330090: ;
return 8 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0280_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0290_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0298_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_02a0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 30 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_02a8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_02b0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}}return 32 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_02b8_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_02b9_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (10);
return 36 * CYCLE_UNIT / 2;
}

/* CHK2.W #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330099; }
}
}}}	m68k_incpci (4);
l_330099: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.W #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330100; }
}
}}}	m68k_incpci (6);
l_330100: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.W #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330101; }
}
}}}}l_330101: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.W #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02f8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330102; }
}
}}}	m68k_incpci (6);
l_330102: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.W #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02f9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330103; }
}
}}}	m68k_incpci (8);
l_330103: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.W #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330104; }
}
}}}	m68k_incpci (6);
l_330104: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.W #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_02fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = (uae_s32)(uae_s16)get_word_mmu060 (dsta); upper = (uae_s32)(uae_s16)get_word_mmu060 (dsta + 2);
	if ((extra & 0x8000) == 0) reg = (uae_s32)(uae_s16)reg;
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330105; }
}
}}}}l_330105: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* SUB.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0400_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0410_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0418_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0420_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0428_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0430_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0438_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0439_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 28 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0440_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0450_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0458_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0460_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0468_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0470_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0478_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0479_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0480_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0490_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0498_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_04a0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 30 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_04a8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_04b0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_04b8_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_04b9_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (10);
return 36 * CYCLE_UNIT / 2;
}

/* CHK2.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330130; }
}
}}}	m68k_incpci (4);
l_330130: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330131; }
}
}}}	m68k_incpci (6);
l_330131: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330132; }
}
}}}}l_330132: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04f8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330133; }
}
}}}	m68k_incpci (6);
l_330133: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04f9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330134; }
}
}}}	m68k_incpci (8);
l_330134: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330135; }
}
}}}	m68k_incpci (6);
l_330135: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK2.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_04fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
	{uae_s32 upper,lower,reg = regs.regs[(extra >> 12) & 15];
	lower = get_long_mmu060 (dsta); upper = get_long_mmu060 (dsta + 4);
	SET_ZFLG (upper == reg || lower == reg);
	SET_CFLG_ALWAYS (lower <= upper ? reg < lower || reg > upper : reg > upper || reg < lower);
	if ((extra & 0x800) && GET_CFLG ()) { Exception (6); goto l_330136; }
}
}}}}l_330136: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* ADD.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0600_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0610_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0618_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0620_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0628_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0630_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0638_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0639_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 28 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0640_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0650_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0658_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0660_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0668_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0670_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0678_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0679_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0680_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0690_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0698_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_06a0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 30 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_06a8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_06b0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}}return 32 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_06b8_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_06b9_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (10);
return 36 * CYCLE_UNIT / 2;
}

/* RTM.L Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* RTM.L An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06f8_33)(uae_u32 opcode)
{
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06f9_33)(uae_u32 opcode)
{
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06fa_33)(uae_u32 opcode)
{
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* CALLM.L (d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_06fb_33)(uae_u32 opcode)
{
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* BTST.L #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0800_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0810_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0818_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0820_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0828_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0830_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0838_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0839_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (8);
return 20 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_083a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* BTST.B #<data>.W,(d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_083b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* BCHG.L #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0840_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0850_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0858_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0860_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0868_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0870_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0878_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCHG.B #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0879_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	dst ^= (1 << src);
	SET_ZFLG (((uae_u32)dst & (1 << src)) >> src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* BCLR.L #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0880_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0890_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0898_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_08a0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_08a8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_08b0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_08b8_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BCLR.B #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_08b9_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst &= ~(1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* BSET.L #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_08c0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= 31;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	m68k_dreg (regs, dstreg) = (dst);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_08d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_08d8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_08e0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_08e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_08f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_08f8_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BSET.B #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_08f9_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= 7;
	SET_ZFLG (1 ^ ((dst >> src) & 1));
	dst |= (1 << src);
	put_rmw_byte_mmu060 (dsta, dst);
}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0a00_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a10_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0a18_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a20_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a28_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0a30_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0a38_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0a39_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 28 * CYCLE_UNIT / 2;
}

/* EORSR.B #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_0a3c_33)(uae_u32 opcode)
{
{	MakeSR ();
{	uae_s16 src = get_iword_mmu060 (2);
	src &= 0xFF;
	regs.sr ^= src;
	MakeFromSR();
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0a40_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a50_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0a58_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a60_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a68_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0a70_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0a78_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0a79_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* EORSR.W #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_0a7c_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330221; }
{	MakeSR ();
{	uae_s16 src = get_iword_mmu060 (2);
	regs.sr ^= src;
	MakeFromSR();
}}}	m68k_incpci (4);
l_330221: ;
return 8 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0a80_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0a90_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0a98_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0aa0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 30 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0aa8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0ab0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}}return 32 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0ab8_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (8);
return 32 * CYCLE_UNIT / 2;
}

/* EOR.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0ab9_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (10);
return 36 * CYCLE_UNIT / 2;
}

/* CAS.B #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ad0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}	m68k_incpci (4);
return 20 * CYCLE_UNIT / 2;
}

#endif
/* CAS.B #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ad8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* CAS.B #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ae0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

#endif
/* CAS.B #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ae8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

#endif
#endif

#ifdef PART_2
/* CAS.B #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0af0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

#endif
/* CAS.B #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0af8_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}	m68k_incpci (6);
return 24 * CYCLE_UNIT / 2;
}

#endif
/* CAS.B #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0af9_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_lrmw_byte_mmu060 (dsta);
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s8)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(m68k_dreg (regs, rc))) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_byte_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_byte_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xff) | (dst & 0xff);
}}}}}}}}	m68k_incpci (8);
return 28 * CYCLE_UNIT / 2;
}

#endif
/* CMP.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0c00_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c10_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0c18_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c20_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c28_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0c30_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0c38_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0c39_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0c3a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

#endif
/* CMP.B #<data>.B,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0c3b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 dst = get_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 20 * CYCLE_UNIT / 2;
}

#endif
/* CMP.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0c40_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c50_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0c58_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c60_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c68_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0c70_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0c78_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0c79_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (8);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0c7a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CMP.W #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0c7b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 dst = get_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

#endif
/* CMP.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_0c80_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0c90_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_0c98_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_0ca0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_0ca8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_0cb0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_0cb8_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_0cb9_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (10);
return 28 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 6;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (6);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (8);
return 24 * CYCLE_UNIT / 2;
}

#endif
/* CMP.L #<data>.L,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cbb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (6);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 dst = get_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cd0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (4);
		op_unimpl (opcode);
		goto l_330267;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}	m68k_incpci (4);
l_330267: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cd8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
		m68k_areg (regs, dstreg) -= 2;
	m68k_incpci (4);
		op_unimpl (opcode);
		goto l_330268;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}	m68k_incpci (4);
l_330268: ;
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ce0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
		m68k_areg (regs, dstreg) += 2;
	m68k_incpci (4);
		op_unimpl (opcode);
		goto l_330269;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}	m68k_incpci (4);
l_330269: ;
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ce8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (6);
		op_unimpl (opcode);
		goto l_330270;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}	m68k_incpci (6);
l_330270: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cf0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
		op_unimpl (opcode);
		goto l_330271;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}}l_330271: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cf8_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (6);
		op_unimpl (opcode);
		goto l_330272;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}	m68k_incpci (6);
l_330272: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* CAS.W #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cf9_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s16 dst = get_lrmw_word_mmu060 (dsta);
	if ((dsta & 1) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (8);
		op_unimpl (opcode);
		goto l_330273;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, rc))) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_word_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_word_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = (m68k_dreg(regs, rc) & ~0xffff) | (dst & 0xffff);
}}}}}}}}	m68k_incpci (8);
l_330273: ;
return 28 * CYCLE_UNIT / 2;
}

#endif
/* CAS2.W #<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0cfc_33)(uae_u32 opcode)
{
{{	uae_s32 extra;
	extra = get_ilong_mmu060 (2);
	uae_u32 rn1 = regs.regs[(extra >> 28) & 15];
	uae_u32 rn2 = regs.regs[(extra >> 12) & 15];
	uae_u16 dst1 = get_lrmw_word_mmu060 (rn1), dst2 = get_lrmw_word_mmu060 (rn2);
{uae_u32 newv = ((uae_s16)(dst1)) - ((uae_s16)(m68k_dreg (regs, (extra >> 16) & 7)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, (extra >> 16) & 7))) < 0;
	int flgo = ((uae_s16)(dst1)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, (extra >> 16) & 7))) > ((uae_u16)(dst1)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
{uae_u32 newv = ((uae_s16)(dst2)) - ((uae_s16)(m68k_dreg (regs, extra & 7)));
{	int flgs = ((uae_s16)(m68k_dreg (regs, extra & 7))) < 0;
	int flgo = ((uae_s16)(dst2)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(m68k_dreg (regs, extra & 7))) > ((uae_u16)(dst2)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
	put_lrmw_word_mmu060 (rn1, m68k_dreg (regs, (extra >> 22) & 7));
	put_lrmw_word_mmu060 (rn2, m68k_dreg (regs, (extra >> 6) & 7));
	}}
}}}}	if (! GET_ZFLG ()) {
	m68k_dreg (regs, (extra >> 6) & 7) = (m68k_dreg (regs, (extra >> 6) & 7) & ~0xffff) | (dst2 & 0xffff);
	m68k_dreg (regs, (extra >> 22) & 7) = (m68k_dreg (regs, (extra >> 22) & 7) & ~0xffff) | (dst1 & 0xffff);
	}
}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e10_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330275; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	dfc060_put_byte (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_s8 src = sfc060_get_byte (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}	m68k_incpci (4);
l_330275: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e18_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330276; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	dfc060_put_byte (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_s8 src = sfc060_get_byte (srca);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}	m68k_incpci (4);
l_330276: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e20_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330277; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	dfc060_put_byte (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 src = sfc060_get_byte (srca);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = srca;
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}	m68k_incpci (4);
l_330277: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e28_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330278; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	dfc060_put_byte (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 src = sfc060_get_byte (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}	m68k_incpci (6);
l_330278: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e30_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330279; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	dfc060_put_byte (dsta, src);
}}}else{{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
{	uae_s8 src = sfc060_get_byte (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}}l_330279: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e38_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330280; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	dfc060_put_byte (dsta, src);
}}else{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s8 src = sfc060_get_byte (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}	m68k_incpci (6);
l_330280: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.B #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e39_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330281; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	dfc060_put_byte (dsta, src);
}}else{{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_s8 src = sfc060_get_byte (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s8)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xff) | ((src) & 0xff);
	}
}}}}}}	m68k_incpci (8);
l_330281: ;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e50_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330282; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	dfc060_put_word (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_s16 src = sfc060_get_word (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}	m68k_incpci (4);
l_330282: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e58_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330283; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	dfc060_put_word (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_s16 src = sfc060_get_word (srca);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}	m68k_incpci (4);
l_330283: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e60_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330284; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	dfc060_put_word (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - 2;
{	uae_s16 src = sfc060_get_word (srca);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = srca;
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}	m68k_incpci (4);
l_330284: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e68_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330285; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	dfc060_put_word (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 src = sfc060_get_word (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}	m68k_incpci (6);
l_330285: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e70_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330286; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	dfc060_put_word (dsta, src);
}}}else{{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
{	uae_s16 src = sfc060_get_word (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}}l_330286: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e78_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330287; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	dfc060_put_word (dsta, src);
}}else{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s16 src = sfc060_get_word (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}	m68k_incpci (6);
l_330287: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.W #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e79_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330288; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	dfc060_put_word (dsta, src);
}}else{{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_s16 src = sfc060_get_word (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = (uae_s32)(uae_s16)src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (m68k_dreg (regs, (extra >> 12) & 7) & ~0xffff) | ((src) & 0xffff);
	}
}}}}}}	m68k_incpci (8);
l_330288: ;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e90_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330289; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	dfc060_put_long (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_s32 src = sfc060_get_long (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}	m68k_incpci (4);
l_330289: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0e98_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330290; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	dfc060_put_long (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_s32 src = sfc060_get_long (srca);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}	m68k_incpci (4);
l_330290: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ea0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330291; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	dfc060_put_long (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - 4;
{	uae_s32 src = sfc060_get_long (srca);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = srca;
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}	m68k_incpci (4);
l_330291: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ea8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330292; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	dfc060_put_long (dsta, src);
}}else{{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 src = sfc060_get_long (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}	m68k_incpci (6);
l_330292: ;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0eb0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_330293; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	dfc060_put_long (dsta, src);
}}}else{{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
{	uae_s32 src = sfc060_get_long (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}}l_330293: ;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0eb8_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330294; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	dfc060_put_long (dsta, src);
}}else{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 src = sfc060_get_long (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}	m68k_incpci (6);
l_330294: ;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* MOVES.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0eb9_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330295; }
{{	uae_s16 extra = get_iword_mmu060 (2);
	if (extra & 0x800)
{	uae_u32 src = regs.regs[(extra >> 12) & 15];
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	dfc060_put_long (dsta, src);
}}else{{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_s32 src = sfc060_get_long (srca);
	if (extra & 0x8000) {
	m68k_areg (regs, (extra >> 12) & 7) = src;
	} else {
	m68k_dreg (regs, (extra >> 12) & 7) = (src);
	}
}}}}}}	m68k_incpci (8);
l_330295: ;
return 40 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ed0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (4);
		op_unimpl (opcode);
		goto l_330296;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}	m68k_incpci (4);
l_330296: ;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ed8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
		m68k_areg (regs, dstreg) -= 4;
	m68k_incpci (4);
		op_unimpl (opcode);
		goto l_330297;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}	m68k_incpci (4);
l_330297: ;
	mmufixup[0].reg = -1;
return 32 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ee0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
		m68k_areg (regs, dstreg) += 4;
	m68k_incpci (4);
		op_unimpl (opcode);
		goto l_330298;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}	m68k_incpci (4);
l_330298: ;
	mmufixup[0].reg = -1;
return 34 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ee8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (6);
		op_unimpl (opcode);
		goto l_330299;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}	m68k_incpci (6);
l_330299: ;
return 36 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ef0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
		op_unimpl (opcode);
		goto l_330300;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}}l_330300: ;
return 36 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ef8_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (6);
		op_unimpl (opcode);
		goto l_330301;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}	m68k_incpci (6);
l_330301: ;
return 36 * CYCLE_UNIT / 2;
}

#endif
/* CAS.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0ef9_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s32 dst = get_lrmw_long_mmu060 (dsta);
	if ((dsta & 3) && currprefs.int_no_unimplemented && get_cpu_model () == 68060) {
	m68k_incpci (8);
		op_unimpl (opcode);
		goto l_330302;
	}
{	int ru = (src >> 6) & 7;
	int rc = src & 7;
{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(m68k_dreg (regs, rc)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, rc))) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, rc))) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
		put_lrmw_long_mmu060 (dsta, (m68k_dreg (regs, ru)));
	}else{
		put_lrmw_long_mmu060 (dsta, dst);
		m68k_dreg(regs, rc) = dst;
}}}}}}}}	m68k_incpci (8);
l_330302: ;
return 40 * CYCLE_UNIT / 2;
}

#endif
/* CAS2.L #<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_0efc_33)(uae_u32 opcode)
{
{{	uae_s32 extra;
	extra = get_ilong_mmu060 (2);
	uae_u32 rn1 = regs.regs[(extra >> 28) & 15];
	uae_u32 rn2 = regs.regs[(extra >> 12) & 15];
	uae_u32 dst1 = get_lrmw_long_mmu060 (rn1), dst2 = get_lrmw_long_mmu060 (rn2);
{uae_u32 newv = ((uae_s32)(dst1)) - ((uae_s32)(m68k_dreg (regs, (extra >> 16) & 7)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, (extra >> 16) & 7))) < 0;
	int flgo = ((uae_s32)(dst1)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, (extra >> 16) & 7))) > ((uae_u32)(dst1)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
{uae_u32 newv = ((uae_s32)(dst2)) - ((uae_s32)(m68k_dreg (regs, extra & 7)));
{	int flgs = ((uae_s32)(m68k_dreg (regs, extra & 7))) < 0;
	int flgo = ((uae_s32)(dst2)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(m68k_dreg (regs, extra & 7))) > ((uae_u32)(dst2)));
	SET_NFLG (flgn != 0);
	if (GET_ZFLG ()) {
	put_lrmw_long_mmu060 (rn1, m68k_dreg (regs, (extra >> 22) & 7));
	put_lrmw_long_mmu060 (rn2, m68k_dreg (regs, (extra >> 6) & 7));
	}}
}}}}	if (! GET_ZFLG ()) {
	m68k_dreg (regs, (extra >> 6) & 7) = dst2;
	m68k_dreg (regs, (extra >> 22) & 7) = dst1;
	}
}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MOVE.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_1039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (6);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_103a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_103b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_103c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_10bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_10fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1138_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_1139_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_113a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_113b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_113c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1178_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_1179_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_117a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_117b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_117c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_1180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_1190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_1198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_11bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_11fc_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.B (An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B (An)+,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.B -(An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,An,Xn),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (xxx).L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (10);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.B (d16,PC),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B (d8,PC,Xn),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.B #<data>.B,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_13fc_33)(uae_u32 opcode)
{
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_byte_mmu060 (dsta, src);
	m68k_incpci (8);
}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.L An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2008_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_2039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_203a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_203b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_203c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (6);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.L Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_2040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.L An,An */
uae_u32 REGPARAM2 CPUFUNC(op_2048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.L (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_2050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.L (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_2058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.L -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_2060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_2068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_2070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_2078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_2079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_207a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_207b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	m68k_areg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.L #<data>.L,An */
uae_u32 REGPARAM2 CPUFUNC(op_207c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	m68k_areg (regs, dstreg) = (src);
	m68k_incpci (6);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_20bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_20fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L An,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2138_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_2139_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_213a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_213b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_213c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2178_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_2179_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_217a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_217b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_217c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_2180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_2188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_2190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_3
/* MOVE.L (An)+,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_2198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_21bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 26 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_21fc_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.L Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L An,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.L (An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L (An)+,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* MOVE.L -(An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 30 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,An,Xn),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (xxx).L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (10);
}}}}return 36 * CYCLE_UNIT / 2;
}

/* MOVE.L (d16,PC),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L (d8,PC,Xn),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}}return 32 * CYCLE_UNIT / 2;
}

/* MOVE.L #<data>.L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_23fc_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_long_mmu060 (dsta, src);
	m68k_incpci (10);
}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.W An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3008_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_3039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (6);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_303a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_303b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_303c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
	m68k_incpci (4);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVEA.W Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_3040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.W An,An */
uae_u32 REGPARAM2 CPUFUNC(op_3048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* MOVEA.W (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_3050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (2);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVEA.W (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_3058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVEA.W -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_3060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_3068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_3070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_3078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_3079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (6);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_307a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (4);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_307b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVEA.W #<data>.W,An */
uae_u32 REGPARAM2 CPUFUNC(op_307c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	src = (uae_s32)(uae_s16)src;
	m68k_areg (regs, dstreg) = (uae_s32)(uae_s16)(src);
	m68k_incpci (4);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_30bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_30fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W An,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3138_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_3139_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_313a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_313b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_313c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3178_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_3179_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_317a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_317b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_317c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_3180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_3188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_3190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_3198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (6);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 1);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_31bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}return 12 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (2);
}}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_31fc_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W An,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}return 16 * CYCLE_UNIT / 2;
}

/* MOVE.W (An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W (An)+,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* MOVE.W -(An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (6);
}}}}	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,An),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,An,Xn),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (xxx).L,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (6);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (10);
}}}}return 28 * CYCLE_UNIT / 2;
}

/* MOVE.W (d16,PC),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (8);
}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W (d8,PC,Xn),(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (4);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* MOVE.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_33fc_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_word_mmu060 (dsta, src);
	m68k_incpci (8);
}}}return 20 * CYCLE_UNIT / 2;
}

/* NEGX.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((newv) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEGX.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NEGX.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NEGX.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4038_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4039_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (srca, newv);
}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((newv) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEGX.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NEGX.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_rmw_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NEGX.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NEGX.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4078_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEGX.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4079_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (srca, newv);
}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.L Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, srcreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEGX.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.L (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* NEGX.L -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_40a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_rmw_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* NEGX.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_40a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEGX.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_40b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* NEGX.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_40b8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEGX.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_40b9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 newv = 0 - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (srca, newv);
}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* MVSR2.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_40c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330632; }
{{	MakeSR ();
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((regs.sr) & 0xffff);
}}}	m68k_incpci (2);
l_330632: ;
return 4 * CYCLE_UNIT / 2;
}

/* MVSR2.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_40d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330633; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}	m68k_incpci (2);
l_330633: ;
return 8 * CYCLE_UNIT / 2;
}

/* MVSR2.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_40d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330634; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}	m68k_incpci (2);
l_330634: ;
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MVSR2.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_40e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330635; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}	m68k_incpci (2);
l_330635: ;
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* MVSR2.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_40e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330636; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}	m68k_incpci (4);
l_330636: ;
return 12 * CYCLE_UNIT / 2;
}

/* MVSR2.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_40f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330637; }
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}}l_330637: ;
return 12 * CYCLE_UNIT / 2;
}

/* MVSR2.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_40f8_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330638; }
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}	m68k_incpci (4);
l_330638: ;
return 12 * CYCLE_UNIT / 2;
}

/* MVSR2.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_40f9_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330639; }
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr);
}}}	m68k_incpci (6);
l_330639: ;
return 16 * CYCLE_UNIT / 2;
}

/* CHK.L Dn,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330640;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330640;
	}
}}}l_330640: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (An),Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330641;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330641;
	}
}}}}l_330641: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (An)+,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330642;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330642;
	}
}}}}l_330642: ;
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L -(An),Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330643;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330643;
	}
}}}}l_330643: ;
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (d16,An),Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330644;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330644;
	}
}}}}l_330644: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (d8,An,Xn),Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330645;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330645;
	}
}}}}}l_330645: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (xxx).W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4138_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330646;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330646;
	}
}}}}l_330646: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (xxx).L,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4139_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (6);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330647;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330647;
	}
}}}}l_330647: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (d16,PC),Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_413a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330648;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330648;
	}
}}}}l_330648: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L (d8,PC,Xn),Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_413b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330649;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330649;
	}
}}}}}l_330649: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* CHK.L #<data>.L,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_413c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (6);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330650;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330650;
	}
}}}l_330650: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* CHK.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330651;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330651;
	}
}}}l_330651: ;
return 4 * CYCLE_UNIT / 2;
}

/* CHK.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330652;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330652;
	}
}}}}l_330652: ;
return 8 * CYCLE_UNIT / 2;
}

/* CHK.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330653;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330653;
	}
}}}}l_330653: ;
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* CHK.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (2);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330654;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330654;
	}
}}}}l_330654: ;
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* CHK.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330655;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330655;
	}
}}}}l_330655: ;
return 12 * CYCLE_UNIT / 2;
}

/* CHK.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330656;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330656;
	}
}}}}}l_330656: ;
return 12 * CYCLE_UNIT / 2;
}

/* CHK.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330657;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330657;
	}
}}}}l_330657: ;
return 12 * CYCLE_UNIT / 2;
}

/* CHK.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (6);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330658;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330658;
	}
}}}}l_330658: ;
return 16 * CYCLE_UNIT / 2;
}

/* CHK.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330659;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330659;
	}
}}}}l_330659: ;
return 12 * CYCLE_UNIT / 2;
}

/* CHK.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330660;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330660;
	}
}}}}}l_330660: ;
return 12 * CYCLE_UNIT / 2;
}

/* CHK.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_41bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (dst > src) {
		SET_NFLG (0);
		Exception (6);
		goto l_330661;
	}
	if ((uae_s32)dst < 0) {
		SET_NFLG (1);
		Exception (6);
		goto l_330661;
	}
}}}l_330661: ;
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_41d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LEA.L (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_41e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_41f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	m68k_areg (regs, dstreg) = (srca);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_41f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_41f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* LEA.L (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_41fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	m68k_areg (regs, dstreg) = (srca);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* LEA.L (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_41fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	m68k_areg (regs, dstreg) = (srca);
}}}}return 8 * CYCLE_UNIT / 2;
}

/* CLR.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4200_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((0) & 0xff);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CLR.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4210_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* CLR.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4218_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* CLR.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4220_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* CLR.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4228_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4230_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}}return 12 * CYCLE_UNIT / 2;
}

/* CLR.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4238_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4239_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(0)) == 0);
	SET_NFLG (((uae_s8)(0)) < 0);
	put_byte_mmu060 (srca, 0);
}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4240_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((0) & 0xffff);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CLR.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4250_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* CLR.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4258_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* CLR.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4260_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* CLR.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4268_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4270_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}}return 12 * CYCLE_UNIT / 2;
}

/* CLR.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4278_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4279_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(0)) == 0);
	SET_NFLG (((uae_s16)(0)) < 0);
	put_word_mmu060 (srca, 0);
}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.L Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4280_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	m68k_dreg (regs, srcreg) = (0);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CLR.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4290_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* CLR.L (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4298_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* CLR.L -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_42a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* CLR.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_42a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_42b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}}return 16 * CYCLE_UNIT / 2;
}

/* CLR.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_42b8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CLR.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_42b9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(0)) == 0);
	SET_NFLG (((uae_s32)(0)) < 0);
	put_long_mmu060 (srca, 0);
}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* MVSR2.B Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	MakeSR ();
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((regs.sr & 0xff) & 0xffff);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B (An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B -(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B (d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B (d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B (xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MVSR2.B (xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_42f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
	MakeSR ();
	put_word_mmu060 (srca, regs.sr & 0xff);
}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

#endif
#endif

#ifdef PART_4
/* NEG.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4400_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((dst) & 0xff);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEG.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4410_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEG.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4418_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NEG.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4420_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NEG.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4428_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4430_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NEG.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4438_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4439_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{{uae_u32 dst = ((uae_s8)(0)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(0)) < 0;
	int flgn = ((uae_s8)(dst)) < 0;
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4440_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEG.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4450_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NEG.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4458_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NEG.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4460_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_rmw_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NEG.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4468_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4470_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NEG.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4478_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NEG.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4479_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{{uae_u32 dst = ((uae_s16)(0)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(0)) < 0;
	int flgn = ((uae_s16)(dst)) < 0;
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.L Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4480_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NEG.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4490_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* NEG.L (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4498_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* NEG.L -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_44a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_rmw_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* NEG.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_44a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEG.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_44b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* NEG.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_44b8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* NEG.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_44b9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{{uae_u32 dst = ((uae_s32)(0)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(0)) < 0;
	int flgn = ((uae_s32)(dst)) < 0;
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(0)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* MV2SR.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_44c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MV2SR.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_44d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* MV2SR.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_44d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MV2SR.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_44e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_44e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_44f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_44f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_44f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_44fa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.B (d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_44fb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.B #<data>.B */
uae_u32 REGPARAM2 CPUFUNC(op_44fc_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	MakeSR ();
	regs.sr &= 0xFF00;
	regs.sr |= src & 0xFF;
	MakeFromSR();
}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* NOT.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4600_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((dst) & 0xff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NOT.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4610_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NOT.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4618_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NOT.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4620_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NOT.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4628_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4630_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NOT.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4638_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4639_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(dst)) == 0);
	SET_NFLG (((uae_s8)(dst)) < 0);
	put_rmw_byte_mmu060 (srca, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4640_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NOT.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4650_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NOT.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4658_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NOT.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4660_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_rmw_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NOT.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4668_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4670_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NOT.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4678_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NOT.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4679_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_rmw_word_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	put_rmw_word_mmu060 (srca, dst);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.L Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4680_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* NOT.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4690_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* NOT.L (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4698_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* NOT.L -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_46a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_rmw_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* NOT.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_46a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* NOT.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_46b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* NOT.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_46b8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* NOT.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_46b9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_rmw_long_mmu060 (srca);
{	uae_u32 dst = ~src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	put_rmw_long_mmu060 (srca, dst);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* MV2SR.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_46c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330760; }
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	regs.sr = src;
	MakeFromSR();
}}}	m68k_incpci (2);
l_330760: ;
return 4 * CYCLE_UNIT / 2;
}

/* MV2SR.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_46d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330761; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (2);
l_330761: ;
return 8 * CYCLE_UNIT / 2;
}

/* MV2SR.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_46d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330762; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (2);
l_330762: ;
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* MV2SR.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_46e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330763; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (2);
l_330763: ;
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_46e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330764; }
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (4);
l_330764: ;
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_46f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330765; }
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}}l_330765: ;
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_46f8_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330766; }
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (4);
l_330766: ;
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_46f9_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330767; }
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (6);
l_330767: ;
return 16 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_46fa_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330768; }
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}	m68k_incpci (4);
l_330768: ;
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.W (d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_46fb_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330769; }
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
	regs.sr = src;
	MakeFromSR();
}}}}}l_330769: ;
return 12 * CYCLE_UNIT / 2;
}

/* MV2SR.W #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_46fc_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330770; }
{{	uae_s16 src = get_iword_mmu060 (2);
	regs.sr = src;
	MakeFromSR();
}}}	m68k_incpci (4);
l_330770: ;
return 8 * CYCLE_UNIT / 2;
}

/* NBCD.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4800_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((newv) & 0xff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LINK.L An,#<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4808_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
{	uae_s32 offs;
	offs = get_ilong_mmu060 (2);
{	uaecptr olda;
	olda = m68k_areg (regs, 7) - 4;
	mmufixup[1].reg = 7;
	mmufixup[1].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = olda;
{	uae_s32 src = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = (m68k_areg(regs, 7));
	m68k_areg(regs, 7) += offs;
	put_long_mmu060 (olda, src);
}}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

#endif
/* NBCD.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4810_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* NBCD.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4818_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* NBCD.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4820_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* NBCD.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4828_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NBCD.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4830_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* NBCD.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4838_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* NBCD.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4839_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_rmw_byte_mmu060 (srca);
{	uae_u16 newv_lo = - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = - (src & 0xF0);
	uae_u16 newv;
	int cflg, tmp_newv;
	if (newv_lo > 9) { newv_lo -= 6; }
	tmp_newv = newv = newv_hi + newv_lo;
	cflg = (newv & 0x1F0) > 0x90;
	if (cflg) newv -= 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (srca, newv);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SWAP.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4840_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_u32 dst = ((src >> 16)&0xFFFF) | ((src&0xFFFF)<<16);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* BKPTQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4848_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	m68k_incpci (2);
	op_illg (opcode);
}return 4 * CYCLE_UNIT / 2;
}

#endif
/* PEA.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4850_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* PEA.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4868_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4870_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4878_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4879_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}	m68k_incpci (6);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* PEA.L (d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_487a_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* PEA.L (d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_487b_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uaecptr dsta;
	dsta = m68k_areg (regs, 7) - 4;
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = dsta;
	put_long_mmu060 (dsta, srca);
}}}}	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* EXT.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4880_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_u16 dst = (uae_s16)(uae_s8)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(dst)) == 0);
	SET_NFLG (((uae_s16)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | ((dst) & 0xffff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4890_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_word_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_word_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 2;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_48a0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - 0;
{	uae_u16 amask = mask & 0xff, dmask = (mask >> 8) & 0xff;
	while (amask) {
		srca -= 2;
		put_word_mmu060 (srca, m68k_areg (regs, movem_index2[amask]));
		amask = movem_next[amask];
	}
	while (dmask) {
		srca -= 2;
		put_word_mmu060 (srca, m68k_dreg (regs, movem_index2[dmask]));
		dmask = movem_next[dmask];
	}
	m68k_areg (regs, dstreg) = srca;
}}}	m68k_incpci (4);
return 10 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_48a8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_word_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_word_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 2;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_48b0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_word_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_word_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 2;
		amask = movem_next[amask];
	}
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_48b8_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_word_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_word_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 2;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMLE.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_48b9_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_word_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_word_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 2;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

/* EXT.L Dn */
uae_u32 REGPARAM2 CPUFUNC(op_48c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_u32 dst = (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_48d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_long_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_long_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 4;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_48e0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) - 0;
{	uae_u16 amask = mask & 0xff, dmask = (mask >> 8) & 0xff;
	while (amask) {
		srca -= 4;
		put_long_mmu060 (srca, m68k_areg (regs, movem_index2[amask]));
		amask = movem_next[amask];
	}
	while (dmask) {
		srca -= 4;
		put_long_mmu060 (srca, m68k_dreg (regs, movem_index2[dmask]));
		dmask = movem_next[dmask];
	}
	m68k_areg (regs, dstreg) = srca;
}}}	m68k_incpci (4);
return 10 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_48e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_long_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_long_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 4;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_48f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_long_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_long_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 4;
		amask = movem_next[amask];
	}
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_48f8_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_long_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_long_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 4;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMLE.L #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_48f9_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_u16 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
	while (dmask) {
		put_long_mmu060 (srca, m68k_dreg (regs, movem_index1[dmask]));
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		put_long_mmu060 (srca, m68k_areg (regs, movem_index1[amask]));
		srca += 4;
		amask = movem_next[amask];
	}
}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

/* EXT.B Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_49c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_u32 dst = (uae_s32)(uae_s8)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(dst)) == 0);
	SET_NFLG (((uae_s32)(dst)) < 0);
	m68k_dreg (regs, srcreg) = (dst);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

#endif
/* TST.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4a00_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* TST.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a10_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* TST.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4a18_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* TST.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a20_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* TST.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a28_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4a30_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* TST.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4a38_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4a39_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TST.B (d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4a3a_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TST.B (d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4a3b_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* TST.W Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4a40_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* TST.W An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4a48_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_areg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

#endif
/* TST.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a50_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* TST.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4a58_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* TST.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a60_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* TST.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a68_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4a70_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}}return 12 * CYCLE_UNIT / 2;
}

/* TST.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4a78_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* TST.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4a79_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TST.W (d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4a7a_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TST.W (d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4a7b_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* TST.L Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4a80_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* TST.L An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4a88_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

#endif
/* TST.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4a90_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* TST.L (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4a98_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* TST.L -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4aa0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* TST.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4aa8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* TST.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4ab0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* TST.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4ab8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* TST.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4ab9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* TST.L (d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4aba_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* TST.L (d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4abb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
}}}}return 16 * CYCLE_UNIT / 2;
}

#endif
/* TAS.B Dn */
uae_u32 REGPARAM2 CPUFUNC(op_4ac0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((src) & 0xff);
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* TAS.B (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ad0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* TAS.B (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4ad8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* TAS.B -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ae0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* TAS.B (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ae8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* TAS.B (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4af0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}}return 16 * CYCLE_UNIT / 2;
}

/* TAS.B (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4af8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* TAS.B (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4af9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_lrmw_byte_mmu060 (srca);
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	src |= 0x80;
	put_lrmw_byte_mmu060 (srca, src);
}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* MULL.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c00_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (!m68k_mull(opcode, dst, extra)) goto l_330844;
}}}l_330844: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c10_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (4);
	if (!m68k_mull(opcode, dst, extra)) goto l_330845;
}}}}l_330845: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c18_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	m68k_incpci (4);
	if (!m68k_mull(opcode, dst, extra)) goto l_330846;
}}}}l_330846: ;
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c20_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	m68k_incpci (4);
	if (!m68k_mull(opcode, dst, extra)) goto l_330847;
}}}}l_330847: ;
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c28_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (6);
	if (!m68k_mull(opcode, dst, extra)) goto l_330848;
}}}}l_330848: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c30_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_long_mmu060 (dsta);
	if (!m68k_mull(opcode, dst, extra)) goto l_330849;
}}}}}l_330849: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c38_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (6);
	if (!m68k_mull(opcode, dst, extra)) goto l_330850;
}}}}l_330850: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c39_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (8);
	if (!m68k_mull(opcode, dst, extra)) goto l_330851;
}}}}l_330851: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c3a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (6);
	if (!m68k_mull(opcode, dst, extra)) goto l_330852;
}}}}l_330852: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c3b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 dst = get_long_mmu060 (dsta);
	if (!m68k_mull(opcode, dst, extra)) goto l_330853;
}}}}}l_330853: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* MULL.L #<data>.W,#<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c3c_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uae_s32 dst;
	dst = get_ilong_mmu060 (4);
	m68k_incpci (8);
	if (!m68k_mull(opcode, dst, extra)) goto l_330854;
}}}l_330854: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c40_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_incpci (4);
	if (!m68k_divl(opcode, dst, extra)) goto l_330855;
}}}l_330855: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c50_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (4);
	if (!m68k_divl(opcode, dst, extra)) goto l_330856;
}}}}l_330856: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c58_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	m68k_incpci (4);
	if (!m68k_divl(opcode, dst, extra)) goto l_330857;
}}}}l_330857: ;
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c60_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	m68k_incpci (4);
	if (!m68k_divl(opcode, dst, extra)) goto l_330858;
}}}}l_330858: ;
	mmufixup[0].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c68_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (6);
	if (!m68k_divl(opcode, dst, extra)) goto l_330859;
}}}}l_330859: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c70_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_long_mmu060 (dsta);
	if (!m68k_divl(opcode, dst, extra)) goto l_330860;
}}}}}l_330860: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c78_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (6);
	if (!m68k_divl(opcode, dst, extra)) goto l_330861;
}}}}l_330861: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c79_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (8);
	if (!m68k_divl(opcode, dst, extra)) goto l_330862;
}}}}l_330862: ;
return 24 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c7a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_s32 dst = get_long_mmu060 (dsta);
	m68k_incpci (6);
	if (!m68k_divl(opcode, dst, extra)) goto l_330863;
}}}}l_330863: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c7b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 dst = get_long_mmu060 (dsta);
	if (!m68k_divl(opcode, dst, extra)) goto l_330864;
}}}}}l_330864: ;
return 20 * CYCLE_UNIT / 2;
}

#endif
/* DIVL.L #<data>.W,#<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4c7c_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uae_s32 dst;
	dst = get_ilong_mmu060 (4);
	m68k_incpci (8);
	if (!m68k_divl(opcode, dst, extra)) goto l_330865;
}}}l_330865: ;
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MVMEL.W #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4c90_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4c98_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	m68k_areg (regs, dstreg) = srca;
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ca8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4cb0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4cb8_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4cb9_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_4cba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_getpci () + 4;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.W #<data>.W,(d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4cbb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = (uae_s32)(uae_s16)get_word_mmu060 (srca);
		srca += 2;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_4cd0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_4cd8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	m68k_areg (regs, dstreg) = srca;
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ce8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4cf0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	m68k_incpci (4);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}}return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4cf8_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4cf9_33)(uae_u32 opcode)
{
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = get_ilong_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_4cfa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr srca;
	srca = m68k_getpci () + 4;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MVMEL.L #<data>.W,(d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4cfb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{	uae_u16 mask = get_iword_mmu060 (2);
	uae_u32 dmask = mask & 0xff, amask = (mask >> 8) & 0xff;
{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_u32 tmp[16];
	int tmpreg[16];
	int idx = 0;
	while (dmask) {
		tmpreg[idx] = movem_index1[dmask] + 0;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		dmask = movem_next[dmask];
	}
	while (amask) {
		tmpreg[idx] = movem_index1[amask] + 8;
		tmp[idx++] = get_long_mmu060 (srca);
		srca += 4;
		amask = movem_next[amask];
	}
	while (--idx >= 0) {
		regs.regs[tmpreg[idx]] = tmp[idx];
	}
}}}}return 12 * CYCLE_UNIT / 2;
}

/* TRAPQ.L #<data> */
uae_u32 REGPARAM2 CPUFUNC(op_4e40_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 15);
{{	uae_u32 src = srcreg;
	m68k_incpci (2);
	Exception (src + 32);
}}return 4 * CYCLE_UNIT / 2;
}

/* LINK.W An,#<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_4e50_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
{	uaecptr olda;
	olda = m68k_areg (regs, 7) - 4;
	mmufixup[1].reg = 7;
	mmufixup[1].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) = olda;
{	uae_s32 src = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = (m68k_areg(regs, 7));
	m68k_areg(regs, 7) += offs;
	put_long_mmu060 (olda, src);
}}}}	m68k_incpci (4);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 18 * CYCLE_UNIT / 2;
}

/* UNLK.L An */
uae_u32 REGPARAM2 CPUFUNC(op_4e58_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s32 src = m68k_areg (regs, srcreg);
	uae_s32 old = get_long_mmu060 (src);
	m68k_areg (regs, 7) = src + 4;
	m68k_areg (regs, srcreg) = old;
}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* MVR2USP.L An */
uae_u32 REGPARAM2 CPUFUNC(op_4e60_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330885; }
{{	uae_s32 src = m68k_areg (regs, srcreg);
	regs.usp = src;
}}}	m68k_incpci (2);
l_330885: ;
return 4 * CYCLE_UNIT / 2;
}

/* MVUSP2R.L An */
uae_u32 REGPARAM2 CPUFUNC(op_4e68_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_330886; }
{{	m68k_areg (regs, srcreg) = (regs.usp);
}}}	m68k_incpci (2);
l_330886: ;
return 4 * CYCLE_UNIT / 2;
}

/* RESET.L  */
uae_u32 REGPARAM2 CPUFUNC(op_4e70_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330887; }
{	cpureset ();
	m68k_incpci (2);
}}l_330887: ;
return 4 * CYCLE_UNIT / 2;
}

/* NOP.L  */
uae_u32 REGPARAM2 CPUFUNC(op_4e71_33)(uae_u32 opcode)
{
{}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* STOP.L #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_4e72_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330889; }
{{	uae_s16 src = get_iword_mmu060 (2);
	regs.sr = src;
	MakeFromSR();
	m68k_setstopped ();
	m68k_incpci (4);
}}}l_330889: ;
return 8 * CYCLE_UNIT / 2;
}

/* RTE.L  */
uae_u32 REGPARAM2 CPUFUNC(op_4e73_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330890; }
{	uae_u16 newsr; uae_u32 newpc;
	for (;;) {
		uaecptr a = m68k_areg (regs, 7);
		uae_u16 sr = get_word_mmu060 (a);
		uae_u32 pc = get_long_mmu060 (a + 2);
		uae_u16 format = get_word_mmu060 (a + 2 + 4);
		int frame = format >> 12;
		int offset = 8;
		newsr = sr; newpc = pc;
		if (frame == 0x0) { m68k_areg (regs, 7) += offset; break; }
		else if (frame == 0x1) { m68k_areg (regs, 7) += offset; }
		else if (frame == 0x2) { m68k_areg (regs, 7) += offset + 4; break; }
		else if (frame == 0x4) { m68k_do_rte_mmu060 (a); m68k_areg (regs, 7) += offset + 8; break; }
		else if (frame == 0x8) { m68k_areg (regs, 7) += offset + 50; break; }
		else if (frame == 0x7) { m68k_areg (regs, 7) += offset + 52; break; }
		else if (frame == 0x9) { m68k_areg (regs, 7) += offset + 12; break; }
		else if (frame == 0xa) { m68k_areg (regs, 7) += offset + 24; break; }
		else if (frame == 0xb) { m68k_areg (regs, 7) += offset + 84; break; }
		else { m68k_areg (regs, 7) += offset; Exception (14); goto l_330890; }
		regs.sr = newsr;
	MakeFromSR();
}
	regs.sr = newsr;
	MakeFromSR();
	if (newpc & 1) {
		exception3i (0x4E73, newpc);
		goto l_330890;
	}
	m68k_setpci (newpc);
}}l_330890: ;
return 4 * CYCLE_UNIT / 2;
}

/* RTD.L #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_4e74_33)(uae_u32 opcode)
{
{{	uae_s16 offs = get_iword_mmu060 (2);
{	uaecptr pca;
	pca = m68k_areg (regs, 7);
{	uae_s32 pc = get_long_mmu060 (pca);
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) += 4;
	m68k_areg(regs, 7) += offs;
	if (pc & 1) {
		exception3i (0x4E74, pc);
		goto l_330891;
	}
	m68k_setpci (pc);
}}}}l_330891: ;
	mmufixup[0].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* RTS.L  */
uae_u32 REGPARAM2 CPUFUNC(op_4e75_33)(uae_u32 opcode)
{
{	uaecptr pc = m68k_getpci ();
	m68k_do_rts_mmu060 ();
	if (m68k_getpci () & 1) {
		uaecptr faultpc = m68k_getpci ();
	m68k_setpci (pc);
		exception3i (0x4E75, faultpc);
		goto l_330892;
	}
}l_330892: ;
return 4 * CYCLE_UNIT / 2;
}

/* TRAPV.L  */
uae_u32 REGPARAM2 CPUFUNC(op_4e76_33)(uae_u32 opcode)
{
{	m68k_incpci (2);
	if (GET_VFLG ()) {
		Exception (7);
		goto l_330893;
	}
}l_330893: ;
return 4 * CYCLE_UNIT / 2;
}

/* RTR.L  */
uae_u32 REGPARAM2 CPUFUNC(op_4e77_33)(uae_u32 opcode)
{
{	uaecptr oldpc = m68k_getpci ();
	MakeSR ();
{	uaecptr sra;
	sra = m68k_areg (regs, 7);
{	uae_s16 sr = get_word_mmu060 (sra);
	mmufixup[0].reg = 7;
	mmufixup[0].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) += 2;
{	uaecptr pca;
	pca = m68k_areg (regs, 7);
{	uae_s32 pc = get_long_mmu060 (pca);
	mmufixup[1].reg = 7;
	mmufixup[1].value = m68k_areg (regs, 7);
	m68k_areg (regs, 7) += 4;
	regs.sr &= 0xFF00; sr &= 0xFF;
	regs.sr |= sr;
	m68k_setpci (pc);
	MakeFromSR();
	if (m68k_getpci () & 1) {
		uaecptr faultpc = m68k_getpci ();
	m68k_setpci (oldpc);
		exception3i (0x4E77, faultpc);
		goto l_330894;
	}
}}}}}l_330894: ;
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* MOVEC2.L #<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4e7a_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330895; }
{{	uae_s16 src = get_iword_mmu060 (2);
{	int regno = (src >> 12) & 15;
	uae_u32 *regp = regs.regs + regno;
	if (! m68k_movec2(src & 0xFFF, regp)) goto l_330895;
}}}}	m68k_incpci (4);
l_330895: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MOVE2C.L #<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_4e7b_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_330896; }
{{	uae_s16 src = get_iword_mmu060 (2);
{	int regno = (src >> 12) & 15;
	uae_u32 *regp = regs.regs + regno;
	if (! m68k_move2c(src & 0xFFF, regp)) goto l_330896;
}}}}	m68k_incpci (4);
l_330896: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* JSR.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4e90_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uaecptr oldpc = m68k_getpci () + 2;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330897;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}l_330897: ;
return 4 * CYCLE_UNIT / 2;
}

/* JSR.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ea8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uaecptr oldpc = m68k_getpci () + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330898;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}l_330898: ;
return 8 * CYCLE_UNIT / 2;
}

/* JSR.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4eb0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uaecptr oldpc = m68k_getpci () + 0;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330899;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}}l_330899: ;
return 8 * CYCLE_UNIT / 2;
}

/* JSR.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4eb8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uaecptr oldpc = m68k_getpci () + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330900;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}l_330900: ;
return 8 * CYCLE_UNIT / 2;
}

/* JSR.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4eb9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uaecptr oldpc = m68k_getpci () + 6;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330901;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}l_330901: ;
return 12 * CYCLE_UNIT / 2;
}

/* JSR.L (d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_4eba_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uaecptr oldpc = m68k_getpci () + 4;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330902;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}l_330902: ;
return 8 * CYCLE_UNIT / 2;
}

/* JSR.L (d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4ebb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uaecptr oldpc = m68k_getpci () + 0;
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330903;
	}
	put_long_mmu060 (m68k_areg (regs, 7) - 4, oldpc);
	m68k_areg (regs, 7) -= 4;
	m68k_setpci (srca);
}}}}l_330903: ;
return 8 * CYCLE_UNIT / 2;
}

/* JMP.L (An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ed0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330904;
	}
	m68k_setpci (srca);
}}l_330904: ;
return 4 * CYCLE_UNIT / 2;
}

/* JMP.L (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_4ee8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330905;
	}
	m68k_setpci (srca);
}}l_330905: ;
return 8 * CYCLE_UNIT / 2;
}

/* JMP.L (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4ef0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330906;
	}
	m68k_setpci (srca);
}}}l_330906: ;
return 8 * CYCLE_UNIT / 2;
}

/* JMP.L (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_4ef8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330907;
	}
	m68k_setpci (srca);
}}l_330907: ;
return 8 * CYCLE_UNIT / 2;
}

/* JMP.L (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_4ef9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330908;
	}
	m68k_setpci (srca);
}}l_330908: ;
return 12 * CYCLE_UNIT / 2;
}

/* JMP.L (d16,PC) */
uae_u32 REGPARAM2 CPUFUNC(op_4efa_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330909;
	}
	m68k_setpci (srca);
}}l_330909: ;
return 8 * CYCLE_UNIT / 2;
}

/* JMP.L (d8,PC,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_4efb_33)(uae_u32 opcode)
{
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
	if (srca & 1) {
		exception3i (opcode, srca);
		goto l_330910;
	}
	m68k_setpci (srca);
}}}l_330910: ;
return 8 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_5000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_5018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_5028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_5030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_5038_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.B #<data>,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_5039_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_5040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDAQ.W #<data>,An */
uae_u32 REGPARAM2 CPUFUNC(op_5048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_5058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_5068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_5070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_5078_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDQ.W #<data>,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_5079_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_5080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDAQ.L #<data>,An */
uae_u32 REGPARAM2 CPUFUNC(op_5088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_5098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_50a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_50a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_5
/* ADDQ.L #<data>,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_50b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_50b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADDQ.L #<data>,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_50b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* Scc.B Dn (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (0) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (0)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_330938;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_330938: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (T) */
uae_u32 REGPARAM2 CPUFUNC(op_50f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (0) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (T) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_50fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (0)) { Exception (7); goto l_330946; }
}}	m68k_incpci (4);
l_330946: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (T) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_50fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (0)) { Exception (7); goto l_330947; }
}}	m68k_incpci (6);
l_330947: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (T) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_50fc_33)(uae_u32 opcode)
{
{	if (cctrue (0)) { Exception (7); goto l_330948; }
}	m68k_incpci (2);
l_330948: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* SUBQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_5100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_5118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_5128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_5130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_5138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.B #<data>,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_5139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_5140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBAQ.W #<data>,An */
uae_u32 REGPARAM2 CPUFUNC(op_5148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_5158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_5168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_5170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_5178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBQ.W #<data>,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_5179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_5180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBAQ.L #<data>,An */
uae_u32 REGPARAM2 CPUFUNC(op_5188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_5190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_5198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_51a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_51a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_51b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_51b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUBQ.L #<data>,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_51b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
{{	uae_u32 src = srcreg;
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* Scc.B Dn (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (1) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (1)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_330976;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_330976: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (F) */
uae_u32 REGPARAM2 CPUFUNC(op_51f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (1) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (F) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_51fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (1)) { Exception (7); goto l_330984; }
}}	m68k_incpci (4);
l_330984: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (F) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_51fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (1)) { Exception (7); goto l_330985; }
}}	m68k_incpci (6);
l_330985: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (F) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_51fc_33)(uae_u32 opcode)
{
{	if (cctrue (1)) { Exception (7); goto l_330986; }
}	m68k_incpci (2);
l_330986: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (2) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (2)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_330988;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_330988: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_52f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (2) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (HI) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_52fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (2)) { Exception (7); goto l_330996; }
}}	m68k_incpci (4);
l_330996: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (HI) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_52fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (2)) { Exception (7); goto l_330997; }
}}	m68k_incpci (6);
l_330997: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (HI) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_52fc_33)(uae_u32 opcode)
{
{	if (cctrue (2)) { Exception (7); goto l_330998; }
}	m68k_incpci (2);
l_330998: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (3) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (3)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331000;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331000: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_53f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (3) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (LS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_53fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (3)) { Exception (7); goto l_331008; }
}}	m68k_incpci (4);
l_331008: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (LS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_53fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (3)) { Exception (7); goto l_331009; }
}}	m68k_incpci (6);
l_331009: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (LS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_53fc_33)(uae_u32 opcode)
{
{	if (cctrue (3)) { Exception (7); goto l_331010; }
}	m68k_incpci (2);
l_331010: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (4) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (4)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331012;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331012: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_54f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (4) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (CC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_54fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (4)) { Exception (7); goto l_331020; }
}}	m68k_incpci (4);
l_331020: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (CC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_54fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (4)) { Exception (7); goto l_331021; }
}}	m68k_incpci (6);
l_331021: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (CC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_54fc_33)(uae_u32 opcode)
{
{	if (cctrue (4)) { Exception (7); goto l_331022; }
}	m68k_incpci (2);
l_331022: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (5) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (5)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331024;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331024: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_55f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (5) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (CS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_55fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (5)) { Exception (7); goto l_331032; }
}}	m68k_incpci (4);
l_331032: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (CS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_55fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (5)) { Exception (7); goto l_331033; }
}}	m68k_incpci (6);
l_331033: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (CS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_55fc_33)(uae_u32 opcode)
{
{	if (cctrue (5)) { Exception (7); goto l_331034; }
}	m68k_incpci (2);
l_331034: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (6) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (6)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331036;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331036: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_56f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (6) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (NE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_56fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (6)) { Exception (7); goto l_331044; }
}}	m68k_incpci (4);
l_331044: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (NE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_56fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (6)) { Exception (7); goto l_331045; }
}}	m68k_incpci (6);
l_331045: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (NE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_56fc_33)(uae_u32 opcode)
{
{	if (cctrue (6)) { Exception (7); goto l_331046; }
}	m68k_incpci (2);
l_331046: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (7) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (7)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331048;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331048: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_57f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (7) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (EQ) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_57fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (7)) { Exception (7); goto l_331056; }
}}	m68k_incpci (4);
l_331056: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (EQ) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_57fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (7)) { Exception (7); goto l_331057; }
}}	m68k_incpci (6);
l_331057: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (EQ) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_57fc_33)(uae_u32 opcode)
{
{	if (cctrue (7)) { Exception (7); goto l_331058; }
}	m68k_incpci (2);
l_331058: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (8) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (8)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331060;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331060: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_58f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (8) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (VC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_58fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (8)) { Exception (7); goto l_331068; }
}}	m68k_incpci (4);
l_331068: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (VC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_58fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (8)) { Exception (7); goto l_331069; }
}}	m68k_incpci (6);
l_331069: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (VC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_58fc_33)(uae_u32 opcode)
{
{	if (cctrue (8)) { Exception (7); goto l_331070; }
}	m68k_incpci (2);
l_331070: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (9) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (9)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331072;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331072: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59f8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_59f9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (9) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (VS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_59fa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (9)) { Exception (7); goto l_331080; }
}}	m68k_incpci (4);
l_331080: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (VS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_59fb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (9)) { Exception (7); goto l_331081; }
}}	m68k_incpci (6);
l_331081: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (VS) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_59fc_33)(uae_u32 opcode)
{
{	if (cctrue (9)) { Exception (7); goto l_331082; }
}	m68k_incpci (2);
l_331082: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5ac0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (10) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5ac8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (10)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331084;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331084: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5ad0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5ad8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5ae0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5ae8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5af0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5af8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_5af9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (10) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (PL) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5afa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (10)) { Exception (7); goto l_331092; }
}}	m68k_incpci (4);
l_331092: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (PL) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5afb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (10)) { Exception (7); goto l_331093; }
}}	m68k_incpci (6);
l_331093: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (PL) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5afc_33)(uae_u32 opcode)
{
{	if (cctrue (10)) { Exception (7); goto l_331094; }
}	m68k_incpci (2);
l_331094: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bc0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (11) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bc8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (11)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331096;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331096: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bd0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bd8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5be0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5be8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bf0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bf8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_5bf9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (11) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (MI) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5bfa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (11)) { Exception (7); goto l_331104; }
}}	m68k_incpci (4);
l_331104: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (MI) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5bfb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (11)) { Exception (7); goto l_331105; }
}}	m68k_incpci (6);
l_331105: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (MI) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5bfc_33)(uae_u32 opcode)
{
{	if (cctrue (11)) { Exception (7); goto l_331106; }
}	m68k_incpci (2);
l_331106: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cc0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (12) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cc8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (12)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331108;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331108: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cd0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cd8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5ce0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5ce8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cf0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cf8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_5cf9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (12) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (GE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5cfa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (12)) { Exception (7); goto l_331116; }
}}	m68k_incpci (4);
l_331116: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (GE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5cfb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (12)) { Exception (7); goto l_331117; }
}}	m68k_incpci (6);
l_331117: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (GE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5cfc_33)(uae_u32 opcode)
{
{	if (cctrue (12)) { Exception (7); goto l_331118; }
}	m68k_incpci (2);
l_331118: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5dc0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (13) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5dc8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (13)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331120;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331120: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5dd0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5dd8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5de0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5de8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5df0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5df8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_5df9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (13) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (LT) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5dfa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (13)) { Exception (7); goto l_331128; }
}}	m68k_incpci (4);
l_331128: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (LT) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5dfb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (13)) { Exception (7); goto l_331129; }
}}	m68k_incpci (6);
l_331129: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (LT) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5dfc_33)(uae_u32 opcode)
{
{	if (cctrue (13)) { Exception (7); goto l_331130; }
}	m68k_incpci (2);
l_331130: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ec0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (14) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ec8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (14)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331132;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331132: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ed0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ed8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ee0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ee8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ef0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ef8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_5ef9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (14) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (GT) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5efa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (14)) { Exception (7); goto l_331140; }
}}	m68k_incpci (4);
l_331140: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (GT) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5efb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (14)) { Exception (7); goto l_331141; }
}}	m68k_incpci (6);
l_331141: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (GT) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5efc_33)(uae_u32 opcode)
{
{	if (cctrue (14)) { Exception (7); goto l_331142; }
}	m68k_incpci (2);
l_331142: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Scc.B Dn (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5fc0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{{{	int val = cctrue (15) ? 0xff : 0;
	m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* DBcc.W Dn,#<data>.W (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5fc8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 offs = get_iword_mmu060 (2);
	uaecptr oldpc = m68k_getpci ();
	if (!cctrue (15)) {
	m68k_incpci ((uae_s32)offs + 2);
			m68k_dreg (regs, srcreg) = (m68k_dreg (regs, srcreg) & ~0xffff) | (((src - 1)) & 0xffff);
		if (src) {
			if (offs & 1) {
				exception3i (opcode, m68k_getpci () + 2 + (uae_s32)offs + 2);
				goto l_331144;
			}
			return 12 * CYCLE_UNIT / 2;
		}
	} else {
	}
	m68k_setpci (oldpc + 4);
}}}l_331144: ;
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (An) (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5fd0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B (An)+ (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5fd8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* Scc.B -(An) (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5fe0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* Scc.B (d16,An) (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5fe8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (d8,An,Xn) (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5ff0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).W (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5ff8_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* Scc.B (xxx).L (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_5ff9_33)(uae_u32 opcode)
{
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{{	int val = cctrue (15) ? 0xff : 0;
	put_byte_mmu060 (srca, val);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* TRAPcc.L #<data>.W (LE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5ffa_33)(uae_u32 opcode)
{
{{	uae_s16 dummy = get_iword_mmu060 (2);
	if (cctrue (15)) { Exception (7); goto l_331152; }
}}	m68k_incpci (4);
l_331152: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L #<data>.L (LE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5ffb_33)(uae_u32 opcode)
{
{{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (2);
	if (cctrue (15)) { Exception (7); goto l_331153; }
}}	m68k_incpci (6);
l_331153: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* TRAPcc.L  (LE) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_5ffc_33)(uae_u32 opcode)
{
{	if (cctrue (15)) { Exception (7); goto l_331154; }
}	m68k_incpci (2);
l_331154: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* Bcc.W #<data>.W (T) */
uae_u32 REGPARAM2 CPUFUNC(op_6000_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (0)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331155;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331155: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (T) */
uae_u32 REGPARAM2 CPUFUNC(op_6001_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (0)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331156;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331156: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (T) */
uae_u32 REGPARAM2 CPUFUNC(op_60ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (0)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331157;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331157: ;
return 12 * CYCLE_UNIT / 2;
}

/* BSR.W #<data>.W */
uae_u32 REGPARAM2 CPUFUNC(op_6100_33)(uae_u32 opcode)
{
{	uae_s32 s;
{	uae_s16 src = get_iword_mmu060 (2);
	s = (uae_s32)src + 2;
	if (src & 1) {
		exception3b (opcode, m68k_getpci () + s, 0, 1, m68k_getpci () + s);
		goto l_331158;
	}
	m68k_do_bsr_mmu060 (m68k_getpci () + 4, s);
}}l_331158: ;
return 8 * CYCLE_UNIT / 2;
}

/* BSRQ.B #<data> */
uae_u32 REGPARAM2 CPUFUNC(op_6101_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{	uae_s32 s;
{	uae_u32 src = srcreg;
	s = (uae_s32)src + 2;
	if (src & 1) {
		exception3b (opcode, m68k_getpci () + s, 0, 1, m68k_getpci () + s);
		goto l_331159;
	}
	m68k_do_bsr_mmu060 (m68k_getpci () + 2, s);
}}l_331159: ;
return 4 * CYCLE_UNIT / 2;
}

/* BSR.L #<data>.L */
uae_u32 REGPARAM2 CPUFUNC(op_61ff_33)(uae_u32 opcode)
{
{	uae_s32 s;
{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	s = (uae_s32)src + 2;
	if (src & 1) {
		exception3b (opcode, m68k_getpci () + s, 0, 1, m68k_getpci () + s);
		goto l_331160;
	}
	m68k_do_bsr_mmu060 (m68k_getpci () + 6, s);
}}l_331160: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_6200_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (2)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331161;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331161: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_6201_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (2)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331162;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331162: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (HI) */
uae_u32 REGPARAM2 CPUFUNC(op_62ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (2)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331163;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331163: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_6300_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (3)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331164;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331164: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_6301_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (3)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331165;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331165: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (LS) */
uae_u32 REGPARAM2 CPUFUNC(op_63ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (3)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331166;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331166: ;
return 12 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_6
/* Bcc.W #<data>.W (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_6400_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (4)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331167;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331167: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_6401_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (4)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331168;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331168: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (CC) */
uae_u32 REGPARAM2 CPUFUNC(op_64ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (4)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331169;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331169: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_6500_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (5)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331170;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331170: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_6501_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (5)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331171;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331171: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (CS) */
uae_u32 REGPARAM2 CPUFUNC(op_65ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (5)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331172;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331172: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_6600_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (6)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331173;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331173: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_6601_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (6)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331174;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331174: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (NE) */
uae_u32 REGPARAM2 CPUFUNC(op_66ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (6)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331175;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331175: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_6700_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (7)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331176;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331176: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_6701_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (7)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331177;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331177: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (EQ) */
uae_u32 REGPARAM2 CPUFUNC(op_67ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (7)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331178;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331178: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_6800_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (8)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331179;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331179: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_6801_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (8)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331180;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331180: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (VC) */
uae_u32 REGPARAM2 CPUFUNC(op_68ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (8)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331181;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331181: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_6900_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (9)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331182;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331182: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_6901_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (9)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331183;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331183: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (VS) */
uae_u32 REGPARAM2 CPUFUNC(op_69ff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (9)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331184;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331184: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_6a00_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (10)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331185;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331185: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_6a01_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (10)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331186;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331186: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (PL) */
uae_u32 REGPARAM2 CPUFUNC(op_6aff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (10)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331187;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331187: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_6b00_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (11)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331188;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331188: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_6b01_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (11)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331189;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331189: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (MI) */
uae_u32 REGPARAM2 CPUFUNC(op_6bff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (11)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331190;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331190: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_6c00_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (12)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331191;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331191: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_6c01_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (12)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331192;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331192: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (GE) */
uae_u32 REGPARAM2 CPUFUNC(op_6cff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (12)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331193;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331193: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_6d00_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (13)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331194;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331194: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_6d01_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (13)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331195;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331195: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (LT) */
uae_u32 REGPARAM2 CPUFUNC(op_6dff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (13)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331196;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331196: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_6e00_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (14)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331197;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331197: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_6e01_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (14)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331198;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331198: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (GT) */
uae_u32 REGPARAM2 CPUFUNC(op_6eff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (14)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331199;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331199: ;
return 12 * CYCLE_UNIT / 2;
}

/* Bcc.W #<data>.W (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_6f00_33)(uae_u32 opcode)
{
{{	uae_s16 src = get_iword_mmu060 (2);
	if (!cctrue (15)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331200;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (4);
}}l_331200: ;
return 12 * CYCLE_UNIT / 2;
}

/* BccQ.B #<data> (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_6f01_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
{{	uae_u32 src = srcreg;
	if (!cctrue (15)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331201;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (2);
}}l_331201: ;
return 8 * CYCLE_UNIT / 2;
}

/* Bcc.L #<data>.L (LE) */
uae_u32 REGPARAM2 CPUFUNC(op_6fff_33)(uae_u32 opcode)
{
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
	if (!cctrue (15)) goto didnt_jump;
	if (src & 1) {
		exception3i (opcode, m68k_getpci () + 2 + (uae_s32)src);
		goto l_331202;
	}
	m68k_incpci ((uae_s32)src + 2);
	return 10 * CYCLE_UNIT / 2;
didnt_jump:;
	m68k_incpci (6);
}}l_331202: ;
return 12 * CYCLE_UNIT / 2;
}

/* MOVEQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_7000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (uae_s32)(uae_s8)(opcode & 255);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_u32 src = srcreg;
{	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
	m68k_incpci (2);
}}}return 4 * CYCLE_UNIT / 2;
}

/* OR.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* OR.B (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.B (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* OR.B -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* OR.B (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* OR.B (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_803a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_803b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* OR.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_803c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* OR.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* OR.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* OR.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* OR.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* OR.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_807a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_807b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* OR.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_807c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* OR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* OR.L (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.L (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* OR.L -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* OR.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.L (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* OR.L (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.L (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.L (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* OR.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* DIVU.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331237;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (2);
	}
}}}l_331237: ;
return 110 * CYCLE_UNIT / 2;
}

/* DIVU.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331238;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (2);
	}
}}}}l_331238: ;
return 114 * CYCLE_UNIT / 2;
}

/* DIVU.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331239;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (2);
	}
}}}}l_331239: ;
	mmufixup[0].reg = -1;
return 114 * CYCLE_UNIT / 2;
}

/* DIVU.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331240;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (2);
	}
}}}}l_331240: ;
	mmufixup[0].reg = -1;
return 116 * CYCLE_UNIT / 2;
}

/* DIVU.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331241;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (4);
	}
}}}}l_331241: ;
return 118 * CYCLE_UNIT / 2;
}

/* DIVU.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (0);
		Exception (5);
		goto l_331242;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
}}}}}l_331242: ;
return 118 * CYCLE_UNIT / 2;
}

/* DIVU.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331243;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (4);
	}
}}}}l_331243: ;
return 118 * CYCLE_UNIT / 2;
}

/* DIVU.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (6);
		Exception (5);
		goto l_331244;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (6);
	}
}}}}l_331244: ;
return 122 * CYCLE_UNIT / 2;
}

/* DIVU.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331245;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (4);
	}
}}}}l_331245: ;
return 118 * CYCLE_UNIT / 2;
}

/* DIVU.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (0);
		Exception (5);
		goto l_331246;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
}}}}}l_331246: ;
return 118 * CYCLE_UNIT / 2;
}

/* DIVU.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_80fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	CLEAR_CZNV ();
	if (src == 0) {
		divbyzero_special (0, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331247;
	} else {
		uae_u32 newv = (uae_u32)dst / (uae_u32)(uae_u16)src;
		uae_u32 rem = (uae_u32)dst % (uae_u32)(uae_u16)src;
		if (newv > 0xffff) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	m68k_incpci (4);
	}
}}}l_331247: ;
return 114 * CYCLE_UNIT / 2;
}

/* SBCD.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_8100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{	uae_u16 newv_lo = (dst & 0xF) - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	uae_u16 newv, tmp_newv;
	int bcd = 0;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo & 0xF0) { newv -= 6; bcd = 6; };
	if ((((dst & 0xFF) - (src & 0xFF) - (GET_XFLG () ? 1 : 0)) & 0x100) > 0xFF) { newv -= 0x60; }
	SET_CFLG ((((dst & 0xFF) - (src & 0xFF) - bcd - (GET_XFLG () ? 1 : 0)) & 0x300) > 0xFF);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SBCD.B -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_8108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u16 newv_lo = (dst & 0xF) - (src & 0xF) - (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (dst & 0xF0) - (src & 0xF0);
	uae_u16 newv, tmp_newv;
	int bcd = 0;
	newv = tmp_newv = newv_hi + newv_lo;
	if (newv_lo & 0xF0) { newv -= 6; bcd = 6; };
	if ((((dst & 0xFF) - (src & 0xFF) - (GET_XFLG () ? 1 : 0)) & 0x100) > 0xFF) { newv -= 0x60; }
	SET_CFLG ((((dst & 0xFF) - (src & 0xFF) - bcd - (GET_XFLG () ? 1 : 0)) & 0x300) > 0xFF);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_8110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_8118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* OR.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_8120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_8128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_8130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_8138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_8139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* PACK.L Dn,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_8140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val = m68k_dreg (regs, srcreg) + get_iword_mmu060 (2);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & 0xffffff00) | ((val >> 4) & 0xf0) | (val & 0xf);
}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* PACK.L -(An),-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_8148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) -= areg_byteinc[srcreg];
	val = (uae_u16)get_byte_mmu060 (m68k_areg (regs, srcreg));
	m68k_areg (regs, srcreg) -= areg_byteinc[srcreg];
	val = (val | ((uae_u16)get_byte_mmu060 (m68k_areg (regs, srcreg)) << 8)) + get_iword_mmu060 (2);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) -= areg_byteinc[dstreg];
	put_byte_mmu060 (m68k_areg (regs, dstreg),((val >> 4) & 0xf0) | (val & 0xf));
}	m68k_incpci (4);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* OR.W Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_8150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_8158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* OR.W Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_8160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_8168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_8170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_8178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* OR.W Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_8179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* UNPK.L Dn,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_8180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val = m68k_dreg (regs, srcreg);
	val = (((val << 4) & 0xf00) | (val & 0xf)) + get_iword_mmu060 (2);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & 0xffff0000) | (val & 0xffff);
}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* UNPK.L -(An),-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_8188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{	uae_u16 val;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) -= areg_byteinc[srcreg];
	val = (uae_u16)get_byte_mmu060 (m68k_areg (regs, srcreg));
	val = (((val << 4) & 0xf00) | (val & 0xf)) + get_iword_mmu060 (2);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) -= 2 * areg_byteinc[dstreg];
	put_byte_mmu060 (m68k_areg (regs, dstreg) + areg_byteinc[dstreg], val);
	put_byte_mmu060 (m68k_areg (regs, dstreg), val >> 8);
}	m68k_incpci (4);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* OR.L Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_8190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_8198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* OR.L Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_81a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_81a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_81b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_81b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* OR.L Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_81b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src |= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* DIVS.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331275;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (2);
}}}l_331275: ;
return 142 * CYCLE_UNIT / 2;
}

/* DIVS.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331276;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (2);
}}}}l_331276: ;
return 146 * CYCLE_UNIT / 2;
}

/* DIVS.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331277;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (2);
}}}}l_331277: ;
	mmufixup[0].reg = -1;
return 146 * CYCLE_UNIT / 2;
}

/* DIVS.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (2);
		Exception (5);
		goto l_331278;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (2);
}}}}l_331278: ;
	mmufixup[0].reg = -1;
return 148 * CYCLE_UNIT / 2;
}

/* DIVS.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331279;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (4);
}}}}l_331279: ;
return 150 * CYCLE_UNIT / 2;
}

/* DIVS.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (0);
		Exception (5);
		goto l_331280;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
}}}}}l_331280: ;
return 150 * CYCLE_UNIT / 2;
}

/* DIVS.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331281;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (4);
}}}}l_331281: ;
return 150 * CYCLE_UNIT / 2;
}

/* DIVS.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (6);
		Exception (5);
		goto l_331282;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (6);
}}}}l_331282: ;
return 154 * CYCLE_UNIT / 2;
}

/* DIVS.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331283;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (4);
}}}}l_331283: ;
return 150 * CYCLE_UNIT / 2;
}

/* DIVS.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (0);
		Exception (5);
		goto l_331284;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
}}}}}l_331284: ;
return 150 * CYCLE_UNIT / 2;
}

/* DIVS.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_81fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	if (src == 0) {
		divbyzero_special (1, dst);
	m68k_incpci (4);
		Exception (5);
		goto l_331285;
	}
	CLEAR_CZNV ();
	if (dst == 0x80000000 && src == -1) {
		SET_VFLG (1);
		SET_NFLG (1);
	} else {
		uae_s32 newv = (uae_s32)dst / (uae_s32)(uae_s16)src;
		uae_u16 rem = (uae_s32)dst % (uae_s32)(uae_s16)src;
		if ((newv & 0xffff8000) != 0 && (newv & 0xffff8000) != 0xffff8000) {
			SET_VFLG (1);
			SET_NFLG (1);
		} else {
			if (((uae_s16)rem < 0) != ((uae_s32)dst < 0)) rem = -rem;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_NFLG (((uae_s16)(newv)) < 0);
			newv = (newv & 0xffff) | ((uae_u32)rem << 16);
			m68k_dreg (regs, dstreg) = (newv);
		}
	}
	m68k_incpci (4);
}}}l_331285: ;
return 146 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.B (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.B (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* SUB.B -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* SUB.B (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_903a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_903b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* SUB.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_903c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.W An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* SUB.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* SUB.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_907a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_907b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* SUB.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_907c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.L An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUB.L (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.L (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* SUB.L -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* SUB.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.L (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUB.L (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.L (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.L (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUB.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_90bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_90c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBA.W An,An */
uae_u32 REGPARAM2 CPUFUNC(op_90c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBA.W (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_90d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* SUBA.W (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_90d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* SUBA.W -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_90e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* SUBA.W (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_90e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_90f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_90f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_90f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.W (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_90fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_90fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* SUBA.W #<data>.W,An */
uae_u32 REGPARAM2 CPUFUNC(op_90fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* SUBX.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBX.B -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_9118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_9128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_9130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_9138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_9139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBX.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBX.W -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_9158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_9168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_9170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_9178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUB.W Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_9179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBX.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_9180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBX.L -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u32 newv = dst - src - (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgo) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgn) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_9190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_9198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_91a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_91a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_91b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_91b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* SUB.L Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_91b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgo) & (flgn ^ flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* SUBA.L Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_91c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBA.L An,An */
uae_u32 REGPARAM2 CPUFUNC(op_91c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* SUBA.L (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_91d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.L (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_91d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* SUBA.L -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_91e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* SUBA.L (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_91e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.L (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_91f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUBA.L (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_91f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.L (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_91f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* SUBA.L (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_91fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* SUBA.L (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_91fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* SUBA.L #<data>.L,An */
uae_u32 REGPARAM2 CPUFUNC(op_91fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst - src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.B (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.B (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* CMP.B -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* CMP.B (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.B (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b03a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.B (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b03b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* CMP.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b03c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.W An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* CMP.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* CMP.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b07a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b07b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* CMP.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b07c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* CMP.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.L An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMP.L (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* CMP.L (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* CMP.L -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* CMP.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_7
/* CMP.L (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* CMP.L (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.L (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMP.L (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMP.L (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* CMP.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b0bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_b0c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPA.W An,An */
uae_u32 REGPARAM2 CPUFUNC(op_b0c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPA.W (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_b0d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* CMPA.W (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_b0d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* CMPA.W -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_b0e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* CMPA.W (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_b0e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_b0f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_b0f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_b0f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.W (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_b0fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_b0fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* CMPA.W #<data>.W,An */
uae_u32 REGPARAM2 CPUFUNC(op_b0fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPM.B (An)+,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_b108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_byte_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) - ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u8)(src)) > ((uae_u8)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_b110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_b118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_b120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_b128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_b130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_b138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_b139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPM.W (An)+,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_b148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_word_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) - ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u16)(src)) > ((uae_u16)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_b150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_b158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_b160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_b168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_b170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_b178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* EOR.W Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_b179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_b180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPM.L (An)+,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_b188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_long_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_b190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_b198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_b1a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_b1a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_b1b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_b1b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* EOR.L Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_b1b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src ^= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* CMPA.L Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_b1c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPA.L An,An */
uae_u32 REGPARAM2 CPUFUNC(op_b1c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* CMPA.L (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_b1d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.L (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_b1d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* CMPA.L -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_b1e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* CMPA.L (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_b1e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.L (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_b1f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* CMPA.L (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_b1f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.L (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_b1f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* CMPA.L (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_b1fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* CMPA.L (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_b1fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* CMPA.L #<data>.L,An */
uae_u32 REGPARAM2 CPUFUNC(op_b1fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) - ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs != flgo) && (flgn != flgo));
	SET_CFLG (((uae_u32)(src)) > ((uae_u32)(dst)));
	SET_NFLG (flgn != 0);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.B (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.B (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* AND.B -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* AND.B (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* AND.B (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c03a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c03b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* AND.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c03c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((src) & 0xff);
}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* AND.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* AND.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* AND.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* AND.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c07a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c07b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}}}return 12 * CYCLE_UNIT / 2;
}

/* AND.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c07c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((src) & 0xffff);
}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* AND.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.L (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.L (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* AND.L -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* AND.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.L (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* AND.L (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.L (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.L (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* AND.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* MULU.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (2);
}}}}return 58 * CYCLE_UNIT / 2;
}

/* MULU.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (2);
}}}}}return 62 * CYCLE_UNIT / 2;
}

/* MULU.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (2);
}}}}}	mmufixup[0].reg = -1;
return 62 * CYCLE_UNIT / 2;
}

/* MULU.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (2);
}}}}}	mmufixup[0].reg = -1;
return 64 * CYCLE_UNIT / 2;
}

/* MULU.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (4);
}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULU.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULU.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (4);
}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULU.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (6);
}}}}}return 70 * CYCLE_UNIT / 2;
}

/* MULU.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (4);
}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULU.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULU.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c0fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_u32)(uae_u16)dst * (uae_u32)(uae_u16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
	m68k_incpci (4);
}}}}return 62 * CYCLE_UNIT / 2;
}

/* ABCD.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{	uae_u16 newv_lo = (src & 0xF) + (dst & 0xF) + (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	uae_u16 newv, tmp_newv;
	int cflg;
	newv = tmp_newv = newv_hi + newv_lo;	if (newv_lo > 9) { newv += 6; }
	cflg = (newv & 0x3F0) > 0x90;
	if (cflg) newv += 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ABCD.B -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u16 newv_lo = (src & 0xF) + (dst & 0xF) + (GET_XFLG () ? 1 : 0);
	uae_u16 newv_hi = (src & 0xF0) + (dst & 0xF0);
	uae_u16 newv, tmp_newv;
	int cflg;
	newv = tmp_newv = newv_hi + newv_lo;	if (newv_lo > 9) { newv += 6; }
	cflg = (newv & 0x3F0) > 0x90;
	if (cflg) newv += 0x60;
	SET_CFLG (cflg);
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_c118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* AND.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_c128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_c130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_c138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_c139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s8)(src)) == 0);
	SET_NFLG (((uae_s8)(src)) < 0);
	put_rmw_byte_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* EXG.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
	m68k_dreg (regs, srcreg) = (dst);
	m68k_dreg (regs, dstreg) = (src);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* EXG.L An,An */
uae_u32 REGPARAM2 CPUFUNC(op_c148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	m68k_areg (regs, srcreg) = (dst);
	m68k_areg (regs, dstreg) = (src);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_c158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* AND.W Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_c168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_c170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_c178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* AND.W Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_c179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(src)) == 0);
	SET_NFLG (((uae_s16)(src)) < 0);
	put_rmw_word_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* EXG.L Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_c188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
	m68k_dreg (regs, srcreg) = (dst);
	m68k_areg (regs, dstreg) = (src);
}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_c198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* AND.L Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_c1a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_c1a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_c1b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}}return 24 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_c1b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* AND.L Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_c1b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	src &= dst;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(src)) == 0);
	SET_NFLG (((uae_s32)(src)) < 0);
	put_rmw_long_mmu060 (dsta, src);
}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* MULS.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 58 * CYCLE_UNIT / 2;
}

/* MULS.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 62 * CYCLE_UNIT / 2;
}

/* MULS.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 62 * CYCLE_UNIT / 2;
}

/* MULS.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 64 * CYCLE_UNIT / 2;
}

/* MULS.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 66 * CYCLE_UNIT / 2;
}

/* MULS.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULS.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 66 * CYCLE_UNIT / 2;
}

/* MULS.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (6);
return 70 * CYCLE_UNIT / 2;
}

/* MULS.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 66 * CYCLE_UNIT / 2;
}

/* MULS.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}return 66 * CYCLE_UNIT / 2;
}

/* MULS.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_c1fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = (uae_s32)(uae_s16)dst * (uae_s32)(uae_s16)src;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}	m68k_incpci (4);
return 62 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.B (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.B (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += areg_byteinc[srcreg];
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* ADD.B -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* ADD.B (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d038_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d039_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d03a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d03b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s8 src = get_byte_mmu060 (srca);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* ADD.B #<data>.B,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d03c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = get_ibyte_mmu060 (2);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.W An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.W (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* ADD.W -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* ADD.W (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d078_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d079_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d07a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d07b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* ADD.W #<data>.W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d07c_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.L An,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADD.L (An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.L (An)+,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ADD.L -(An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ADD.L (d16,An),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.L (d8,An,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADD.L (xxx).W,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0b8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.L (xxx).L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0b9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L (d16,PC),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0ba_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.L (d8,PC,Xn),Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0bb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADD.L #<data>.L,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d0bc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_d0c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDA.W An,An */
uae_u32 REGPARAM2 CPUFUNC(op_d0c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDA.W (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_d0d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 8 * CYCLE_UNIT / 2;
}

/* ADDA.W (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_d0d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 8 * CYCLE_UNIT / 2;
}

/* ADDA.W -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_d0e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 10 * CYCLE_UNIT / 2;
}

/* ADDA.W (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_d0e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_d0f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_d0f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_d0f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (6);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.W (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_d0fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_d0fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s16 src = get_word_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 12 * CYCLE_UNIT / 2;
}

/* ADDA.W #<data>.W,An */
uae_u32 REGPARAM2 CPUFUNC(op_d0fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = get_iword_mmu060 (2);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

/* ADDX.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uae_s8 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((newv) & 0xff);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDX.B -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - areg_byteinc[srcreg];
{	uae_s8 src = get_byte_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s8)(newv)) == 0));
	SET_NFLG (((uae_s8)(newv)) < 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_d118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += areg_byteinc[dstreg];
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - areg_byteinc[dstreg];
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_d128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_d130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_d138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.B Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_d139_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s8 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s8 dst = get_rmw_byte_mmu060 (dsta);
{{uae_u32 newv = ((uae_s8)(dst)) + ((uae_s8)(src));
{	int flgs = ((uae_s8)(src)) < 0;
	int flgo = ((uae_s8)(dst)) < 0;
	int flgn = ((uae_s8)(newv)) < 0;
	SET_ZFLG (((uae_s8)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u8)(~dst)) < ((uae_u8)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_byte_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDX.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uae_s16 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((newv) & 0xffff);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDX.W -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 2;
{	uae_s16 src = get_word_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s16)(newv)) == 0));
	SET_NFLG (((uae_s16)(newv)) < 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_d158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 2;
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 2;
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_d168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_d170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_d178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADD.W Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_d179_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s16 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s16 dst = get_rmw_word_mmu060 (dsta);
{{uae_u32 newv = ((uae_s16)(dst)) + ((uae_s16)(src));
{	int flgs = ((uae_s16)(src)) < 0;
	int flgo = ((uae_s16)(dst)) < 0;
	int flgn = ((uae_s16)(newv)) < 0;
	SET_ZFLG (((uae_s16)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u16)(~dst)) < ((uae_u16)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_word_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDX.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_d180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_dreg (regs, dstreg);
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	m68k_dreg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDX.L -(An),-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[1].reg = dstreg;
	mmufixup[1].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{	uae_u32 newv = dst + src + (GET_XFLG () ? 1 : 0);
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (flgs ^ ((flgs ^ flgo) & (flgo ^ flgn)));
	COPY_CARRY ();
	SET_ZFLG (GET_ZFLG () & (((uae_s32)(newv)) == 0));
	SET_NFLG (((uae_s32)(newv)) < 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
	mmufixup[1].reg = -1;
return 28 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_d198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) += 4;
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 20 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,-(An) */
uae_u32 REGPARAM2 CPUFUNC(op_d1a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) - 4;
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
	mmufixup[0].reg = dstreg;
	mmufixup[0].value = m68k_areg (regs, dstreg);
	m68k_areg (regs, dstreg) = dsta;
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 22 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_d1a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_d1b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	m68k_incpci (2);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}}return 24 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_d1b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (4);
return 24 * CYCLE_UNIT / 2;
}

/* ADD.L Dn,(xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_d1b9_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (2);
{	uae_s32 dst = get_rmw_long_mmu060 (dsta);
{{uae_u32 newv = ((uae_s32)(dst)) + ((uae_s32)(src));
{	int flgs = ((uae_s32)(src)) < 0;
	int flgo = ((uae_s32)(dst)) < 0;
	int flgn = ((uae_s32)(newv)) < 0;
	SET_ZFLG (((uae_s32)(newv)) == 0);
	SET_VFLG ((flgs ^ flgn) & (flgo ^ flgn));
	SET_CFLG (((uae_u32)(~dst)) < ((uae_u32)(src)));
	COPY_CARRY ();
	SET_NFLG (flgn != 0);
	put_rmw_long_mmu060 (dsta, newv);
}}}}}}}	m68k_incpci (6);
return 28 * CYCLE_UNIT / 2;
}

/* ADDA.L Dn,An */
uae_u32 REGPARAM2 CPUFUNC(op_d1c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_dreg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDA.L An,An */
uae_u32 REGPARAM2 CPUFUNC(op_d1c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src = m68k_areg (regs, srcreg);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ADDA.L (An),An */
uae_u32 REGPARAM2 CPUFUNC(op_d1d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.L (An)+,An */
uae_u32 REGPARAM2 CPUFUNC(op_d1d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg);
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ADDA.L -(An),An */
uae_u32 REGPARAM2 CPUFUNC(op_d1e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) - 4;
{	uae_s32 src = get_long_mmu060 (srca);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = srca;
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ADDA.L (d16,An),An */
uae_u32 REGPARAM2 CPUFUNC(op_d1e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.L (d8,An,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_d1f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	m68k_incpci (2);
{	srca = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADDA.L (xxx).W,An */
uae_u32 REGPARAM2 CPUFUNC(op_d1f8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.L (xxx).L,An */
uae_u32 REGPARAM2 CPUFUNC(op_d1f9_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = get_ilong_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ADDA.L (d16,PC),An */
uae_u32 REGPARAM2 CPUFUNC(op_d1fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr srca;
	srca = m68k_getpci () + 2;
	srca += (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ADDA.L (d8,PC,Xn),An */
uae_u32 REGPARAM2 CPUFUNC(op_d1fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uaecptr tmppc;
	uaecptr srca;
	m68k_incpci (2);
{	tmppc = m68k_getpci ();
	srca = x_get_disp_ea_020 (tmppc, 0);
{	uae_s32 src = get_long_mmu060 (srca);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ADDA.L #<data>.L,An */
uae_u32 REGPARAM2 CPUFUNC(op_d1fc_33)(uae_u32 opcode)
{
	uae_u32 dstreg = (opcode >> 9) & 7;
{{	uae_s32 src;
	src = get_ilong_mmu060 (2);
{	uae_s32 dst = m68k_areg (regs, dstreg);
{	uae_u32 newv = dst + src;
	m68k_areg (regs, dstreg) = (newv);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

/* ASRQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	uae_u32 sign = (0x80 & val) >> 7;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		val = 0xff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xff << (8 - cnt)) & (uae_u32)-sign;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSRQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e008_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG ((cnt == 8) & (val >> 7));
		COPY_CARRY ();
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXRQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (7 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* RORQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 hival;
	cnt &= 7;
	hival = val << (8 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xff;
	SET_CFLG ((val & 0x80) >> 7);
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASR.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	uae_u32 sign = (0x80 & val) >> 7;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		val = 0xff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xff << (8 - cnt)) & (uae_u32)-sign;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSR.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG ((cnt == 8) & (val >> 7));
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXR.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 36) cnt -= 36;
	if (cnt >= 18) cnt -= 18;
	if (cnt >= 9) cnt -= 9;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (7 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROR.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e038_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 7;
	hival = val << (8 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xff;
	SET_CFLG ((val & 0x80) >> 7);
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASRQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e040_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = (0x8000 & val) >> 15;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		val = 0xffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffff << (16 - cnt)) & (uae_u32)-sign;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

#endif

#ifdef PART_8
/* LSRQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e048_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG ((cnt == 16) & (val >> 15));
		COPY_CARRY ();
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXRQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e050_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (15 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* RORQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e058_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 hival;
	cnt &= 15;
	hival = val << (16 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffff;
	SET_CFLG ((val & 0x8000) >> 15);
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASR.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e060_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = (0x8000 & val) >> 15;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		val = 0xffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffff << (16 - cnt)) & (uae_u32)-sign;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSR.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e068_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG ((cnt == 16) & (val >> 15));
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXR.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e070_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 34) cnt -= 34;
	if (cnt >= 17) cnt -= 17;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (15 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROR.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e078_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 15;
	hival = val << (16 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffff;
	SET_CFLG ((val & 0x8000) >> 15);
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASRQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e080_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	uae_u32 sign = (0x80000000 & val) >> 31;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		val = 0xffffffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffffffff << (32 - cnt)) & (uae_u32)-sign;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSRQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e088_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG ((cnt == 32) & (val >> 31));
		COPY_CARRY ();
		val = 0;
	} else {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXRQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e090_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (31 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* RORQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e098_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 hival;
	cnt &= 31;
	hival = val << (32 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffffffff;
	SET_CFLG ((val & 0x80000000) >> 31);
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e0a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	uae_u32 sign = (0x80000000 & val) >> 31;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		val = 0xffffffff & (uae_u32)-sign;
		SET_CFLG (sign);
		COPY_CARRY ();
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
		val |= (0xffffffff << (32 - cnt)) & (uae_u32)-sign;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e0a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG ((cnt == 32) & (val >> 31));
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val >>= cnt - 1;
		SET_CFLG (val & 1);
		COPY_CARRY ();
		val >>= 1;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e0b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 33) cnt -= 33;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 hival = (val << 1) | GET_XFLG ();
	hival <<= (31 - cnt);
	val >>= cnt;
	carry = val & 1;
	val >>= 1;
	val |= hival;
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROR.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e0b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {	uae_u32 hival;
	cnt &= 31;
	hival = val << (32 - cnt);
	val >>= cnt;
	val |= hival;
	val &= 0xffffffff;
	SET_CFLG ((val & 0x80000000) >> 31);
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASRW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e0d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ASRW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e0d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ASRW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e0e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ASRW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e0e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASRW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e0f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ASRW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e0f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASRW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e0f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 cflg = val & 1;
	val = (val >> 1) | sign;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (cflg);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ASLQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e100_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSLQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e108_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXLQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e110_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (7 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROLQ.B #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e118_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 loval;
	cnt &= 7;
	loval = val >> (8 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASL.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e120_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xff << (7 - cnt)) & 0xff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSL.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e128_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 8) {
		SET_CFLG (cnt == 8 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80) >> 7);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xff;
	}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXL.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e130_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 36) cnt -= 36;
	if (cnt >= 18) cnt -= 18;
	if (cnt >= 9) cnt -= 9;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (7 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROL.B Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e138_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s8 cnt = m68k_dreg (regs, srcreg);
{	uae_s8 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u8)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 7;
	loval = val >> (8 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s8)(val)) == 0);
	SET_NFLG (((uae_s8)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xff) | ((val) & 0xff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASLQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e140_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSLQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e148_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXLQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e150_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (15 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROLQ.W #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e158_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 loval;
	cnt &= 15;
	loval = val >> (16 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASL.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e160_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xffff << (15 - cnt)) & 0xffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSL.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e168_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 16) {
		SET_CFLG (cnt == 16 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x8000) >> 15);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffff;
	}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXL.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e170_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 34) cnt -= 34;
	if (cnt >= 17) cnt -= 17;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (15 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROL.W Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e178_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 cnt = m68k_dreg (regs, srcreg);
{	uae_s16 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = (uae_u16)data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 15;
	loval = val >> (16 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	m68k_dreg (regs, dstreg) = (m68k_dreg (regs, dstreg) & ~0xffff) | ((val) & 0xffff);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASLQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e180_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSLQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e188_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXLQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e190_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (31 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROLQ.L #<data>,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e198_33)(uae_u32 opcode)
{
	uae_u32 srcreg = imm8_table[((opcode >> 9) & 7)];
	uae_u32 dstreg = opcode & 7;
{{	uae_u32 cnt = srcreg;
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
{	uae_u32 loval;
	cnt &= 31;
	loval = val >> (32 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffffffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASL.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e1a0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_VFLG (val != 0);
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		uae_u32 mask = (0xffffffff << (31 - cnt)) & 0xffffffff;
		SET_VFLG ((val & mask) != mask && (val & mask) != 0);
		val <<= cnt - 1;
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
		val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* LSL.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e1a8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 32) {
		SET_CFLG (cnt == 32 ? val & 1 : 0);
		COPY_CARRY ();
		val = 0;
	} else if (cnt > 0) {
		val <<= (cnt - 1);
		SET_CFLG ((val & 0x80000000) >> 31);
		COPY_CARRY ();
		val <<= 1;
	val &= 0xffffffff;
	}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROXL.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e1b0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt >= 33) cnt -= 33;
	if (cnt > 0) {
	cnt--;
	{
	uae_u32 carry;
	uae_u32 loval = val >> (31 - cnt);
	carry = loval & 1;
	val = (((val << 1) | GET_XFLG ()) << cnt) | (loval >> 1);
	SET_XFLG (carry);
	val &= 0xffffffff;
	} }
	SET_CFLG (GET_XFLG ());
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ROL.L Dn,Dn */
uae_u32 REGPARAM2 CPUFUNC(op_e1b8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 9) & 7);
	uae_u32 dstreg = opcode & 7;
{{	uae_s32 cnt = m68k_dreg (regs, srcreg);
{	uae_s32 data = m68k_dreg (regs, dstreg);
{	uae_u32 val = data;
	int ccnt = cnt & 63;
	cnt &= 63;
	CLEAR_CZNV ();
	if (cnt > 0) {
	uae_u32 loval;
	cnt &= 31;
	loval = val >> (32 - cnt);
	val <<= cnt;
	val |= loval;
	val &= 0xffffffff;
	SET_CFLG (val & 1);
}
	SET_ZFLG (((uae_s32)(val)) == 0);
	SET_NFLG (((uae_s32)(val)) < 0);
	m68k_dreg (regs, dstreg) = (val);
}}}}	m68k_incpci (2);
return 4 * CYCLE_UNIT / 2;
}

/* ASLW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e1d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ASLW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e1d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ASLW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e1e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ASLW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e1e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASLW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e1f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ASLW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e1f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ASLW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e1f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 sign = 0x8000 & val;
	uae_u32 sign2;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	sign2 = 0x8000 & val;
	SET_CFLG (sign != 0);
	COPY_CARRY ();
	SET_VFLG (GET_VFLG () | (sign2 != sign));
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* LSRW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e2d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* LSRW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e2d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* LSRW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e2e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* LSRW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e2e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSRW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e2f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* LSRW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e2f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSRW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e2f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u32 val = (uae_u16)data;
	uae_u32 carry = val & 1;
	val >>= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* LSLW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e3d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* LSLW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e3d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* LSLW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e3e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* LSLW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e3e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSLW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e3f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* LSLW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e3f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* LSLW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e3f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ROXRW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e4d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROXRW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e4d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ROXRW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e4e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ROXRW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e4e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXRW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e4f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ROXRW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e4f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXRW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e4f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (GET_XFLG ()) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ROXLW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e5d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROXLW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e5d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ROXLW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e5e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ROXLW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e5e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXLW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e5f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ROXLW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e5f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROXLW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e5f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (GET_XFLG ()) val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	COPY_CARRY ();
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* RORW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e6d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* RORW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e6d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* RORW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e6e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* RORW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e6e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* RORW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e6f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* RORW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e6f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* RORW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e6f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 1;
	val >>= 1;
	if (carry) val |= 0x8000;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* ROLW.W (An) */
uae_u32 REGPARAM2 CPUFUNC(op_e7d0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
return 12 * CYCLE_UNIT / 2;
}

/* ROLW.W (An)+ */
uae_u32 REGPARAM2 CPUFUNC(op_e7d8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 2;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 12 * CYCLE_UNIT / 2;
}

/* ROLW.W -(An) */
uae_u32 REGPARAM2 CPUFUNC(op_e7e0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) - 2;
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = dataa;
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (2);
	mmufixup[0].reg = -1;
return 14 * CYCLE_UNIT / 2;
}

/* ROLW.W (d16,An) */
uae_u32 REGPARAM2 CPUFUNC(op_e7e8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	dataa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROLW.W (d8,An,Xn) */
uae_u32 REGPARAM2 CPUFUNC(op_e7f0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{{	uaecptr dataa;
	m68k_incpci (2);
{	dataa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}}return 16 * CYCLE_UNIT / 2;
}

/* ROLW.W (xxx).W */
uae_u32 REGPARAM2 CPUFUNC(op_e7f8_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = (uae_s32)(uae_s16)get_iword_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (4);
return 16 * CYCLE_UNIT / 2;
}

/* ROLW.W (xxx).L */
uae_u32 REGPARAM2 CPUFUNC(op_e7f9_33)(uae_u32 opcode)
{
{{	uaecptr dataa;
	dataa = get_ilong_mmu060 (2);
{	uae_s16 data = get_rmw_word_mmu060 (dataa);
{	uae_u16 val = data;
	uae_u32 carry = val & 0x8000;
	val <<= 1;
	if (carry)  val |= 1;
	CLEAR_CZNV ();
	SET_ZFLG (((uae_s16)(val)) == 0);
	SET_NFLG (((uae_s16)(val)) < 0);
	SET_CFLG (carry >> 15);
	put_rmw_word_mmu060 (dataa, val);
}}}}	m68k_incpci (6);
return 20 * CYCLE_UNIT / 2;
}

/* BFTST.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8c0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8f8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8f9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFTST.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e8fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9c0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9d0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9e8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9f0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9f8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9f9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9fa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTU.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_e9fb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCHG.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eac0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFCHG.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ead0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFCHG.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eae8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCHG.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eaf0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCHG.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eaf8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCHG.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eaf9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = tmp ^ (0xffffffffu >> (32 - width));
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebc0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebd0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebe8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebf0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebf8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebf9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebfa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFEXTS.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ebfb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp = (uae_s32)tmp >> (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	m68k_dreg (regs, (extra >> 12) & 7) = tmp;
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCLR.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ecc0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFCLR.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ecd0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFCLR.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ece8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCLR.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ecf0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCLR.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ecf8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFCLR.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ecf9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0;
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edc0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edd0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_ede8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edf0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edf8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edf9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edfa_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_getpci () + 4;
	dsta += (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFFFO.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_edfb_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr tmppc;
	uaecptr dsta;
	m68k_incpci (4);
{	tmppc = m68k_getpci ();
	dsta = x_get_disp_ea_020 (tmppc, 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = x_get_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	{ uae_u32 mask = 1 << (width - 1);
	while (mask) { if (tmp & mask) break; mask >>= 1; offset++; }}
	m68k_dreg (regs, (extra >> 12) & 7) = offset;
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFSET.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eec0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFSET.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eed0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFSET.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eee8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFSET.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eef0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFSET.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eef8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFSET.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eef9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = 0xffffffffu >> (32 - width);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* BFINS.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_efc0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp = m68k_dreg(regs, dstreg);
	offset &= 0x1f;
	tmp = (tmp << offset) | (tmp >> (32 - offset));
	bdata[0] = tmp & ((1 << (32 - width)) - 1);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg (regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	tmp = bdata[0] | (tmp << (32 - width));
	m68k_dreg(regs, dstreg) = (tmp >> offset) | (tmp << (32 - offset));
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFINS.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_efd0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg (regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* BFINS.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_efe8_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = m68k_areg (regs, dstreg) + (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg (regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFINS.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eff0_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	m68k_incpci (4);
{	dsta = x_get_disp_ea_020 (m68k_areg (regs, dstreg), 0);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg (regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}}return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFINS.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eff8_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = (uae_s32)(uae_s16)get_iword_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg (regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* BFINS.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_eff9_33)(uae_u32 opcode)
{
{{	uae_s16 extra = get_iword_mmu060 (2);
{	uaecptr dsta;
	dsta = get_ilong_mmu060 (4);
{	uae_u32 bdata[2];
	uae_s32 offset = extra & 0x800 ? m68k_dreg(regs, (extra >> 6) & 7) : (extra >> 6) & 0x1f;
	int width = (((extra & 0x20 ? m68k_dreg(regs, extra & 7) : extra) -1) & 0x1f) +1;
	uae_u32 tmp;
	dsta += offset >> 3;
	tmp = mmu060_get_rmw_bitfield (dsta, bdata, offset, width);
	SET_NFLG_ALWAYS (((uae_s32)tmp) < 0 ? 1 : 0);
	tmp >>= (32 - width);
	SET_ZFLG (tmp == 0); SET_VFLG (0); SET_CFLG (0);
	tmp = m68k_dreg (regs, (extra >> 12) & 7);
	tmp = tmp & (0xffffffffu >> (32 - width));
	SET_NFLG (tmp & (1 << (width - 1)) ? 1 : 0);
	SET_ZFLG (tmp == 0);
	mmu060_put_rmw_bitfield(dsta, bdata, tmp, offset, width);
}}}}	m68k_incpci (8);
return 16 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L Dn,#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f000_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331785; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	uae_u16 extraa = 0;
	mmu_op30 (pc, opcode, extra, extraa);
}}l_331785: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L An,#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f008_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331786; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	uae_u16 extraa = 0;
	mmu_op30 (pc, opcode, extra, extraa);
}}l_331786: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L (An),#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f010_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331787; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
	extraa = m68k_areg (regs, srcreg);
	mmu_op30 (pc, opcode, extra, extraa);
}}}l_331787: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L (An)+,#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f018_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331788; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
	extraa = m68k_areg (regs, srcreg);
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) += 4;
	mmu_op30 (pc, opcode, extra, extraa);
}}}l_331788: ;
	mmufixup[0].reg = -1;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L -(An),#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f020_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331789; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
	extraa = m68k_areg (regs, srcreg) - 4;
	mmufixup[0].reg = srcreg;
	mmufixup[0].value = m68k_areg (regs, srcreg);
	m68k_areg (regs, srcreg) = extraa;
	mmu_op30 (pc, opcode, extra, extraa);
}}}l_331789: ;
	mmufixup[0].reg = -1;
return 6 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L (d16,An),#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f028_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331790; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
	extraa = m68k_areg (regs, srcreg) + (uae_s32)(uae_s16)get_iword_mmu060 (0);
	m68k_incpci (2);
	mmu_op30 (pc, opcode, extra, extraa);
}}}l_331790: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L (d8,An,Xn),#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f030_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331791; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
{	extraa = x_get_disp_ea_020 (m68k_areg (regs, srcreg), 0);
	mmu_op30 (pc, opcode, extra, extraa);
}}}}l_331791: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L (xxx).W,#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f038_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331792; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
	extraa = (uae_s32)(uae_s16)get_iword_mmu060 (0);
	m68k_incpci (2);
	mmu_op30 (pc, opcode, extra, extraa);
}}}l_331792: ;
return 8 * CYCLE_UNIT / 2;
}

#endif
/* MMUOP030.L (xxx).L,#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f039_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331793; }
{	uaecptr pc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
{	uaecptr extraa;
	extraa = get_ilong_mmu060 (0);
	m68k_incpci (4);
	mmu_op30 (pc, opcode, extra, extraa);
}}}l_331793: ;
return 12 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f200_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f208_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f210_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f218_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f220_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f228_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f230_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f238_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f239_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f23a_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 2;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,(d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f23b_33)(uae_u32 opcode)
{
	uae_u32 dstreg = 3;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FPP.L #<data>.W,#<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f23c_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_arithmetic(opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f240_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FDBcc.L #<data>.W,Dn */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f248_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_dbcc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f250_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f258_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,-(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f260_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,(d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f268_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,(d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f270_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,(xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f278_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FScc.L #<data>.W,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f279_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
{	uae_s16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_scc (opcode, extra);
}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FTRAPcc.L #<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f27a_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
	uaecptr oldpc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
{	uae_s16 dummy = get_iword_mmu060 (4);
	m68k_incpci (6);
	fpuop_trapcc (opcode, oldpc, extra);
}
#endif
}return 12 * CYCLE_UNIT / 2;
}

#endif
/* FTRAPcc.L #<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f27b_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
	uaecptr oldpc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
{	uae_s32 dummy;
	dummy = get_ilong_mmu060 (4);
	m68k_incpci (8);
	fpuop_trapcc (opcode, oldpc, extra);
}
#endif
}return 16 * CYCLE_UNIT / 2;
}

#endif
/* FTRAPcc.L  */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f27c_33)(uae_u32 opcode)
{
{
#ifdef FPUEMU
	uaecptr oldpc = m68k_getpci ();
	uae_u16 extra = get_iword_mmu060 (2);
	m68k_incpci (4);
	fpuop_trapcc (opcode, oldpc, extra);

#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FBccQ.L #<data>,#<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f280_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 63);
{
#ifdef FPUEMU
	m68k_incpci (2);
{	uaecptr pc = m68k_getpci ();
{	uae_s16 extra = get_iword_mmu060 (0);
	m68k_incpci (2);
	fpuop_bcc (opcode, pc,extra);
}}
#endif
}return 8 * CYCLE_UNIT / 2;
}

#endif
/* FBccQ.L #<data>,#<data>.L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f2c0_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 63);
{
#ifdef FPUEMU
	m68k_incpci (2);
{	uaecptr pc = m68k_getpci ();
{	uae_s32 extra;
	extra = get_ilong_mmu060 (0);
	m68k_incpci (4);
	fpuop_bcc (opcode, pc,extra);
}}
#endif
}return 12 * CYCLE_UNIT / 2;
}

#endif
/* FSAVE.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f310_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331820; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_save (opcode);

#endif
}}l_331820: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FSAVE.L -(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f320_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331821; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_save (opcode);

#endif
}}l_331821: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FSAVE.L (d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f328_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331822; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_save (opcode);

#endif
}}l_331822: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FSAVE.L (d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f330_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331823; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_save (opcode);

#endif
}}l_331823: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FSAVE.L (xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f338_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331824; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_save (opcode);

#endif
}}l_331824: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FSAVE.L (xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f339_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331825; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_save (opcode);

#endif
}}l_331825: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f350_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331826; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331826: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f358_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331827; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331827: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (d16,An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f368_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331828; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331828: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (d8,An,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f370_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331829; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331829: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (xxx).W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f378_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331830; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331830: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f379_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331831; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331831: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (d16,PC) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f37a_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331832; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331832: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* FRESTORE.L (d8,PC,Xn) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f37b_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331833; }
{
#ifdef FPUEMU
	m68k_incpci (2);
	fpuop_restore (opcode);

#endif
}}l_331833: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVLQ.L #<data>,An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f408_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_331834; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331834: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVPQ.L #<data>,An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f410_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_331835; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331835: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f418_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331836; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331836: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f419_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331837; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331837: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f41a_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331838; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331838: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f41b_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331839; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331839: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f41c_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331840; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331840: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f41d_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331841; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331841: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f41e_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331842; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331842: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CINVAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f41f_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331843; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331843: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHLQ.L #<data>,An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f428_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_331844; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331844: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHPQ.L #<data>,An */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f430_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
	uae_u32 dstreg = opcode & 7;
{if (!regs.s) { Exception (8); goto l_331845; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331845: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f438_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331846; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331846: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f439_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331847; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331847: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f43a_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331848; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331848: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f43b_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331849; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331849: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f43c_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331850; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331850: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f43d_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331851; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331851: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f43e_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331852; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331852: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* CPUSHAQ.L #<data> */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f43f_33)(uae_u32 opcode)
{
	uae_u32 srcreg = ((opcode >> 6) & 3);
{if (!regs.s) { Exception (8); goto l_331853; }
{	flush_mmu060(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
	if (opcode & 0x80)
		flush_icache(m68k_areg (regs, opcode & 3), (opcode >> 6) & 3);
}}	m68k_incpci (2);
l_331853: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PFLUSHN.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f500_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331854; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331854: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PFLUSH.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f508_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331855; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331855: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PFLUSHAN.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f510_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331856; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331856: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PFLUSHA.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f518_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331857; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331857: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PTESTW.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f548_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331858; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331858: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PTESTR.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f568_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331859; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331859: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PLPAW.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f588_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331860; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331860: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* PLPAR.L (An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f5c8_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{if (!regs.s) { Exception (8); goto l_331861; }
{	m68k_incpci (2);
	mmu_op (opcode, 0);
}}l_331861: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
/* MOVE16.L (An)+,(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f600_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	uae_u32 v[4];
{	uaecptr memsa;
	memsa = m68k_areg (regs, srcreg);
{	uaecptr memda;
	memda = get_ilong_mmu060 (2);
	get_move16_mmu (memsa, v);
	put_move16_mmu (memda, v);
	m68k_areg (regs, srcreg) += 16;
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MOVE16.L (xxx).L,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f608_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u32 v[4];
{	uaecptr memsa;
	memsa = get_ilong_mmu060 (2);
{	uaecptr memda;
	memda = m68k_areg (regs, dstreg);
	get_move16_mmu (memsa, v);
	put_move16_mmu (memda, v);
	m68k_areg (regs, dstreg) += 16;
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MOVE16.L (An),(xxx).L */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f610_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
{	uae_u32 v[4];
{	uaecptr memsa;
	memsa = m68k_areg (regs, srcreg);
{	uaecptr memda;
	memda = get_ilong_mmu060 (2);
	get_move16_mmu (memsa, v);
	put_move16_mmu (memda, v);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MOVE16.L (xxx).L,(An) */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f618_33)(uae_u32 opcode)
{
	uae_u32 dstreg = opcode & 7;
{	uae_u32 v[4];
{	uaecptr memsa;
	memsa = get_ilong_mmu060 (2);
{	uaecptr memda;
	memda = m68k_areg (regs, dstreg);
	get_move16_mmu (memsa, v);
	put_move16_mmu (memda, v);
}}}	m68k_incpci (6);
return 12 * CYCLE_UNIT / 2;
}

#endif
/* MOVE16.L (An)+,(An)+ */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f620_33)(uae_u32 opcode)
{
	uae_u32 srcreg = (opcode & 7);
	uae_u32 dstreg = 0;
{	uae_u32 v[4];
	uaecptr mems = m68k_areg (regs, srcreg) & ~15, memd;
	dstreg = (get_iword_mmu060 (2) >> 12) & 7;
	memd = m68k_areg (regs, dstreg) & ~15;
	get_move16_mmu (mems, v);
	put_move16_mmu (memd, v);
	if (srcreg != dstreg)
		m68k_areg (regs, srcreg) += 16;
	m68k_areg (regs, dstreg) += 16;
}	m68k_incpci (4);
return 8 * CYCLE_UNIT / 2;
}

#endif
/* LPSTOP.L #<data>.W */
#ifndef CPUEMU_68000_ONLY
uae_u32 REGPARAM2 CPUFUNC(op_f800_33)(uae_u32 opcode)
{
{if (!regs.s) { Exception (8); goto l_331867; }
{	uae_u16 sw = get_iword_mmu060 (2);
	uae_u16 sr;
	if (sw != (0x100|0x80|0x40)) { Exception (4); goto l_331867; }
	sr = get_iword_mmu060 (4);
	if (!(sr & 0x8000)) { Exception (8); goto l_331867; }
	regs.sr = sr;
	MakeFromSR();
	m68k_setstopped();
	m68k_incpci (6);
}}l_331867: ;
return 4 * CYCLE_UNIT / 2;
}

#endif
#endif

