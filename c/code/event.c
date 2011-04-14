#include <stdio.h>
#include <unistd.h>
#include <sys/eventfd.h>
#include <sys/types.h>
#include <inttypes.h>

#define FLAGS (EFD_CLOEXEC)

int main(void) {
  uint64_t fd = eventfd(2, FLAGS);
  uint64_t data = 0;
  uint64_t payload = 25;

  printf("%" PRId64 "\n", fd);
  printf("write value %zi\n", write(fd, &payload, 8));
  printf("write value %zi\n", write(fd, &payload, 8));
  fsync(fd);

  if (read(fd, &data, 8)) {
    printf("data read %" PRId64 "\n", data);
  }

  close(fd);

  return 1;
}

