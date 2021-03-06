#include <stdio.h>
#include <stdint.h>

typedef enum {
  FALSE,
  TRUE
} Bool;

int main()
{
  uint8_t *p;
  Bool status;
  char buf[] = {
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
  };

  /* align buffer to 0x20 border */
  p = (uint8_t*)(((uintptr_t)buf + 31) & ~31);

  /* validate buffer */
  status = NaClSegmentValidates(p, 32, p);
  printf("validation %s\n", status == TRUE ? "successful" : "failed");
  printf("buf = 0x%lX, aligned = 0x%lX\n", (uintptr_t)buf, (uintptr_t)p);

  return status;
}
