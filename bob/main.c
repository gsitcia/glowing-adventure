#include <libndls.h>
#include <nspireio/nspireio.h>

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

int poke(int *ptr, int v) {
	*ptr=v;
	return 0;//that's it?
}

int main(void) {
	assert_ndless_rev(801);
	nio_console csl;
	nio_init(&csl,NIO_MAX_COLS,NIO_MAX_ROWS,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,1);
    int stop = 0;
	while (!stop) {
		char c;
		unsigned int ptr,v;
		nio_fscanf(&csl,"%c %i %i",&c,&ptr,&v);
		switch (c) {
			case 'e'://peek
				fmem(&csl,(void *)ptr,v);
				break;
			case 'o'://poke
				poke((void *)ptr,v);
				break;
			case 'q':
				stop=1;
				break;
		}
	}
	nio_free(&csl);
	return 0;
}