#include <unistd.h>
#include <cerrno>
#include <sys/types.h>
#include <iostream>

class SocketAuxiliar{
    public:
        static ssize_t write_all(int fd, const char* data, size_t len){
            size_t total_sent = 0;

            while (total_sent < len){
                ssize_t sent = write(fd, data + total_sent, len - total_sent);

                if (sent < 0){
                    if (errno == EINTR){
                        std::cout << errno;
                        continue;
                    }

                    std::cout << errno;
                    return total_sent;
                }

                if (sent == 0){
                    std::cout << errno;
                    return total_sent;
                }

                total_sent += static_cast<size_t>(sent);
            }
            
            std::cout << errno;
            return total_sent;
        }
};