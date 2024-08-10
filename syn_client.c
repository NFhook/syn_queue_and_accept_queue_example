#include "syn_client.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        return -1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    for (int i = 0; i < 1000; i++) {  // 模拟大量连接请求
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            return -1;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server_addr.sin_addr);

        // 不执行 connect，只发送 SYN 包
        connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

        // 不关闭连接，继续创建新的连接
        // close(sock);
    }

    printf("SYN requests sent\n");
    return 0;
}
