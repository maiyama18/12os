#include "defines.h"
#include "serial.h"
#include "lib.h"

static int init(void) {
  extern int erodata, data_start, edata, bss_start, ebss;

  memcpy(&data_start, &erodata, (long)&edata - (long)&data_start);
  memset(&bss_start, 0, (long)&ebss - (long)&bss_start);

  serial_init(SERIAL_DEFAULT_DEVICE);

  return 0;
}

int var_data = 0x10;
int var_bss;
static int var_static_data = 0x20;
static int var_static_bss;

static void print_values(void) {
  puts("var_data = "); putxval(var_data, 0); puts("\n");
  puts("var_bss = "); putxval(var_bss, 0); puts("\n");
  puts("var_static_data = "); putxval(var_static_data, 0); puts("\n");
  puts("var_static_bss = "); putxval(var_static_bss, 0); puts("\n");
}

int main(void) {
  puts("hello world!\n");

  init();

  print_values();

  puts("overwrite\n");

  var_data = 0x30;
  var_bss = 0x40;
  var_static_data = 0x50;
  var_static_bss = 0x60;

  print_values();

  while (1)
    ;

  return 0;
}
