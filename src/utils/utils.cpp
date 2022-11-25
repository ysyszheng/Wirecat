#include "utils.h"

void print_payload(const u_char *payload, size_t payload_len) {
  size_t offset = 0;
  size_t cnt = 0;
  u_char str[17];
  while (offset < payload_len) {
    printf("%05zx  ", offset);
    while (cnt < payload_len && cnt - offset < 16) {
      str[cnt - offset] = *(payload + cnt);
      cnt++;
    }
    str[cnt - offset] = '\0';
    for (size_t i = 0; i < 16; i++) {
      if (i < cnt - offset) {
        printf("%02x", str[i]);
      } else {
        printf("  ");
      }
      if (i == 7 || i == 15) {
        printf("  ");
      } else {
        printf(" ");
      }
    }
    for (size_t i = 0; i < 16; i++) {
      if (i < cnt - offset) {
        if (isprint(str[i])) {
          printf("%c", str[i]);
        } else {
          printf(".");
        }
      } else {
        printf(" ");
      }
      if (i == 7) {
        printf("  ");
      }
    }
    offset += 16;
    printf("\n");
  }
}
