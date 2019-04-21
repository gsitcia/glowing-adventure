#include <libndls.h>
#include <nspireio/nspireio.h>

int main(void) {
	assert_ndless_rev(801);
	nio_console csl;
	nio_init(&csl,NIO_MAX_COLS,NIO_MAX_ROWS,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,1);
	nio_fputs("Hello World!",&csl);
	nio_free(&csl);
	wait_key_pressed();
	return 0;
}
