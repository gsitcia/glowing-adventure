#include <os.h>
#include <usbdi.h>
#include <usb.h>
#include <libndls.h>
#include <nspireio/nspireio.h>

nio_console csl;

int fancyputs(char *s) {
    return 0;
}

int main(void) {
	assert_ndless_rev(801);
	nio_init(&csl,NIO_MAX_COLS,1,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,true);
    nio_set_default(&csl);
    nio_fflush(&csl);
	nio_free(&csl);
	wait_key_pressed();
	return 0;
}
