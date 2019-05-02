#include <libndls.h>
#include <nspireio/nspireio.h>

int bob(void) {
	return 42;
}

int fmem(nio_console *csl, void *ptr, int n) {
	uint8_t *t = (uint8_t *) ptr;
	for (int i = 0; i < n; i++) {
		nio_fprintf(csl,"%02x ",*(t+i));
		if (i%16==15) {
			nio_fprintf(csl,"\n");
		}
	}
	if (n%16 != 0) nio_fprintf(csl,"\n");
	return 0;
}

int main(void) {
	assert_ndless_rev(801);
	nio_console csl;
	nio_init(&csl,NIO_MAX_COLS,NIO_MAX_ROWS,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,1);
    fprintf(&csl,"test%s\n","ing");
    wait_key_pressed();
	//fmem(&csl,(void *)bob,100);
	nio_free(&csl);
	wait_key_pressed();
	return 0;
}
