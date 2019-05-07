#include <libndls.h>
#include <nspireio/nspireio.h>

int fmem(nio_console *csl, void volatile *ptr) {
	uint32_t volatile *t = (uint32_t volatile *) ptr;
	nio_fprintf(csl,"Value: 0x%08x or %d\n",*t,*t);
	return 0;
}

int poke(uint32_t volatile *ptr, uint32_t v) {
	*ptr=v;
	return 0;//that's it?
}

int print_memory_around_ptr(nio_console *csl, volatile void* ptr, uint32_t n) {
  volatile uint8_t* t = (volatile uint8_t*) ptr;
  for (uint32_t i = 0; i < n; i++) {
    nio_fprintf(csl,"%02x ",*(t+i));
    if (i%16 == 15) {
      nio_fprintf(csl,"\n");
    }
  }
  if (n%16 != 0) nio_fprintf(csl,"\n");
  return 0;
}

int search(nio_console *csl, volatile uint32_t* ptr, uint32_t n, int sz) {
	int flag = 1;
	for (int i = 0; i < sz; i++) {
		if (*(ptr+i)==n) {
			nio_fprintf(csl,"Found at: 0x%08x\n",ptr+i);
			flag = 0;
		}
	}
	if (flag) {
		nio_fprintf(csl,"Not found\n");
	}
	return 0;
}

int main(void) {
	assert_ndless_rev(801);
	nio_console csl;
	nio_init(&csl,NIO_MAX_COLS,NIO_MAX_ROWS,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,1);
    int stop = 0;
	while (!stop) {
		char c;
		uint32_t ptr,v;
		v = 0;// Accidentally did something dumb
		nio_fprintf(&csl,">> ");
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
				nio_fprintf(&csl,"Setting 0x%08x to 0x%08x\n",ptr,v);
				poke((void volatile *)ptr,v);
				break;
			case 'h'://hex data
				print_memory_around_ptr(&csl,(void volatile *)ptr,v);
				break;
			case 's'://search
				// searches 0x1000 bytes before and after the first argument
				search(&csl,(uint32_t volatile *)ptr-0x1000,v,0x2000);// I mean, it could be...
				break;
		}
	}
	nio_free(&csl);
	return 0;
}