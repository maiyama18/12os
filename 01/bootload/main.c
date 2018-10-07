#include "defines.h"
#include "serial.h"
#include "lib.h"

volatile int a = 100;

int main(void) {
  serial_init(SERIAL_DEFAULT_DEVICE);

  puts("Hello World!\n");

  putxval(0x10, 0); puts("\n");
  putxval(0xffff, 0); puts("\n");
  putxval(0xffff, 8); puts("\n");
  putxval(a, 8); puts("\n");
  a = 80;
  putxval(a, 8); puts("\n");

  while (1)
    ;

  return 0;
}
