#include <libndls.h>
#include <nspireio/nspireio.h>

int fmem(nio_console *csl, void volatile *ptr) {
	uint32_t volatile *t = (uint32_t volatile *) ptr;
	nio_fprintf(csl,"Value: 0x%08x or %d",*t,*t);
	return 0;
}

int poke(uint32_t volatile *ptr, uint32_t v) {
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
		uint32_t ptr,v;
		nio_fscanf(&csl,"%c %lx %lx",&c,&ptr,&v);
		switch (c) {
			case 'q':
				stop=1;
				nio_fprintf(&csl,"Quitting\n");
				break;
			case 'e'://peek
				fmem(&csl,(void volatile *)ptr);
				break;
			case 'o'://poke
				nio_fprintf(&csl,"Setting 0x%08x to 0x%08x",ptr,v);
				poke((void volatile *)ptr,v);
				break;
		}
	}
	nio_free(&csl);
	return 0;
}