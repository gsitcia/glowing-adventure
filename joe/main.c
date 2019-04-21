#include <usbdi.h>
#include <usb.h>
#include <libndls.h>
#include <nspireio/nspireio.h>
#include <syscall-list.h>

nio_console csl;

static inline int wa_syscall(int nr)
{
	register int r0 asm("r0");

	asm volatile(
		"swi %[nr]\n"
		: "=r" (r0)
		: [nr] "i" (nr)
		: "memory", "r1", "r2", "r3", "r4", "r12", "lr");

	return r0;
}

int fancyputs(char *s) {
	nio_clear(&csl);
	nio_printf("%s",s);
	return 0;
}

int thing_register(void) {
	fancyputs((char*)"Hello, World!");
	return 0;
}

int main(void) {
	assert_ndless_rev(801);
	//nl_no_scr_redraw(); // is what I wish I could do
    wa_syscall(e_nl_no_scr_redraw);
	nio_init(&csl,NIO_MAX_COLS,1,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,TRUE);
	nio_set_default(&csl);
	nio_fflush(&csl);
	thing_register();
	nio_free(&csl);
	return 0;
}
