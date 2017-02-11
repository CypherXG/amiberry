 /*
  * UAE - The Un*x Amiga Emulator
  *
  * Target specific stuff, Amiberry version
  *
  * Copyright 1997 Bernd Schmidt
  */

#pragma once
#define TARGET_NAME "amiberry"

#define NO_MAIN_IN_MAIN_C

#define OPTIONSFILENAME "uaeconfig"

extern int emulating;

extern int z3_start_adr;
extern int rtg_start_adr;

void run_gui(void);
void InGameMessage(const char *msg);

void saveAdfDir(void);
void update_display(struct uae_prefs *);
void graphics_subshutdown(void);

void pandora_stop_sound(void);

void keyboard_settrans(void);
int translate_pandora_keys(int symbol, int *modifier);
void SimulateMouseOrJoy(int code, int keypressed);

#define REMAP_MOUSEBUTTON_LEFT    -1
#define REMAP_MOUSEBUTTON_RIGHT   -2
#define REMAP_JOYBUTTON_ONE       -3
#define REMAP_JOYBUTTON_TWO       -4
#define REMAP_JOY_UP              -5
#define REMAP_JOY_DOWN            -6
#define REMAP_JOY_LEFT            -7
#define REMAP_JOY_RIGHT           -8
#define REMAP_CD32_GREEN          -9
#define REMAP_CD32_YELLOW         -10
#define REMAP_CD32_PLAY           -11
#define REMAP_CD32_FFW            -12
#define REMAP_CD32_RWD            -13

extern void free_AmigaMem(void);
extern void alloc_AmigaMem(void);

void reinit_amiga(void);
int count_HDs(struct uae_prefs *p);
extern void gui_force_rtarea_hdchange(void);
extern bool hardfile_testrdb(const TCHAR *filename);

#ifdef __cplusplus
extern "C" {
#endif
	void trace_begin(void);
	void trace_end(void);
#ifdef __cplusplus
}
#endif


static inline size_t uae_tcslcpy(TCHAR *dst, const TCHAR *src, size_t size)
{
	if (size == 0) {
		return 0;
	}
	size_t src_len = _tcslen(src);
	size_t cpy_len = src_len;
	if (cpy_len >= size) {
		cpy_len = size - 1;
	}
	memcpy(dst, src, cpy_len * sizeof(TCHAR));
	dst[cpy_len] = _T('\0');
	return src_len;
}

static inline size_t uae_strlcpy(char *dst, const char *src, size_t size)
{
	if (size == 0) {
		return 0;
	}
	size_t src_len = strlen(src);
	size_t cpy_len = src_len;
	if (cpy_len >= size) {
		cpy_len = size - 1;
	}
	memcpy(dst, src, cpy_len);
	dst[cpy_len] = '\0';
	return src_len;
}

static inline int max(int x, int y)
{
	return x > y ? x : y;
}