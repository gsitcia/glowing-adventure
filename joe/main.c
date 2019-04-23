#include <usbdi.h>
#include <usb.h>
#include <libndls.h>
#include <nspireio/nspireio.h>
#include <syscall-list.h>

nio_console csl;

static int match(device_t self) {
  struct usb_attach_arg *uaa = device_get_ivars(self);
  if (!uaa->iface) {
    return UMATCH_NONE;
  }
  usbd_device_handle dev;
  usbd_interface2device_handle(uaa->iface,&dev);
  char* cp = malloc(1024);
  usbd_devinfo(dev,1,cp);
  fancyputs(cp);
  return UMATCH_NONE;
}

static int (*methods[])(device_t) = {match, NULL, NULL, NULL};

struct ulol_softc {
	device_t sc_dev;
};

static inline int wa_syscall(int nr) {
  //ughhh whyyyyyyyy... sad
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
  usb_register_driver(2, methods, "ulol", 0, sizeof(struct ulol_softc));
	return 0;
}

int main(void) {
	assert_ndless_rev(801);
	//nl_no_scr_redraw(); // is what I wish I could do
	wa_syscall(e_nl_no_scr_redraw);
	nio_init(&csl,NIO_MAX_COLS,2,0,0,NIO_COLOR_WHITE,NIO_COLOR_BLACK,TRUE);
	nio_set_default(&csl);
	nio_fflush(&csl);
	thing_register();
	nl_set_resident();
	return 0;
}
