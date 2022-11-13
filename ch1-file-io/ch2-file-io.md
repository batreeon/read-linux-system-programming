Both positional calls can be used only on seekable file descriptors. They provide semantics similar to preceding a read( ) or write( ) call with a call to lseek( ), with three differences. First, these calls are easier to use, especially when doing a tricky operation such as moving through a file backward or randomly. Second, they do not update the file pointer upon completion. Finally, and most importantly, they avoid any potential races that might occur when using lseek(). As threads share file descriptors, it would be possible for a different thread in the same program to update the file position after the first thread’s call to lseek( ), but before its read or write operation executed. Such race conditions can be avoided by using the pread( ) and pwrite( ) system calls.
```c
#define _XOPEN_SOURCE 500
#include <unistd.h>

ssize_t pread (int fd, void *buf, size_t count, off_t pos);
ssize_t pwrite (int fd, const void *buf, size_t count, off_t pos);
```

#
Neither operation updates the current file position.
```c
#include <unistd.h>  
#include <sys/types.h>

int ftruncate (int fd, off_t len);
int truncate (const char *path, off_t len);
```