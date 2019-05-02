#include <libndls.h>
#include <nspireio/nspireio.h>

int bob(void) {
	return 0x42;
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
    nio_fprintf(&csl,"test%s\n","ing");
	nio_fprintf(&csl,"An int is %d bytes or something\n",sizeof(int));
    nio_fprintf(&csl,"Next we'll test the changing stuff thing\n");
    wait_key_pressed();
	fmem(&csl,(void *)bob,100);
	wait_key_pressed();
	*(uint8_t*)(void*)bob = 42;
	fmem(&csl,(void *)bob,100);
	nio_fprintf(&csl,"Magic %d",bob());
	nio_free(&csl);
	wait_key_pressed();
	return 0;
}
