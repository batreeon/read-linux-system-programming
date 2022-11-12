#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("./text.txt", O_WRONLY);
    int offset = lseek(fd, 0, SEEK_END);
    printf("1: %d\n", offset);

    int ret;
    ret = ftruncate(fd, 45);
    if (ret == -1)
    {
        perror("truncate");
        return -1;
    }

    printf("2: %d\n", offset);
    return 0;
}