void lock_init(flock *lock, short type, short whence, off_t start, off_t len);

int readw_lock(int fd);

int writew_lock(int fd);

int unlock(int fd);

pid_t lock_test(int fd, short type, short whence, off_t start, off_t len);
