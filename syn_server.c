#include "syn_server.h"


int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PORT>\n", argv[0]);
        return -1;
    }

    int port = atoi(argv[1]);
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_sock);
        return -1;
    }

    // 设定一个较小的队列长度以便更快地观察满队列现象
    if (listen(server_sock, 10) < 0) {
        perror("listen");
        close(server_sock);
        return -1;
    }

    printf("Server is listening on port %d\n", port);
    while (1) {
        // 不调用 accept，保持在 SYN 队列状态
        sleep(1);
    }

    close(server_sock);
    return 0;
}
