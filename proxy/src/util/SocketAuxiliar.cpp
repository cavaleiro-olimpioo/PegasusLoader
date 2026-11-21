#include <unistd.h>
#include <cerrno>
#include <sys/types.h>

class SocketAuxiliar{
    public:
        static bool write_all(int fd, const char* data, size_t len){
            size_t total_sent = 0;

            while (total_sent < len){
                ssize_t sent = write(fd, data + total_sent, len - total_sent);

                if (sent < 0){
                    if (errno == EINTR){
                        continue;
                    }

                    return false;
                }

                if (sent == 0){
                    return false;
                }

                total_sent += static_cast<size_t>(sent);
            }

            return true;
        }
};