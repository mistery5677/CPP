#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int max_fd = 0, next_id = 0;
int ids[65536];
char *msgs[65536];
fd_set active_fds, read_fds, write_fds;
char buf_read[120000], buf_write[120000];

void fatal() {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void send_all(int sender_fd, char *str) {
    for (int i = 0; i <= max_fd; i++) {
        // Envia apenas se o descritor estiver pronto para escrita e não for o remetente
        if (FD_ISSET(i, &write_fds) && i != sender_fd) {
            send(i, str, strlen(str), 0);
        }
    }
}

int extract_message(char **buf, char **msg) {
    char *newbuf;
    int i;

    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i]) {
        if ((*buf)[i] == '\n') {
            newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
            if (newbuf == 0) fatal();
            strcpy(newbuf, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = newbuf;
            return (1);
        }
        i++;
    }
    return (0);
}

char *str_join(char *buf, char *add) {
    char *newbuf;
    int len;

    if (buf == 0)
        len = 0;
    else
        len = strlen(buf);
    newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
    if (newbuf == 0) fatal();
    newbuf[0] = 0;
    if (buf != 0)
        strcat(newbuf, buf);
    free(buf);
    strcat(newbuf, add);
    return (newbuf);
}

int main(int ac, char **av) {
    if (ac != 2) {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }

    int serv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_fd < 0) fatal();

    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // Equivalente a 127.0.0.1
    servaddr.sin_port = htons(atoi(av[1]));

    if (bind(serv_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) fatal();
    if (listen(serv_fd, 100) < 0) fatal();

    FD_ZERO(&active_fds);
    FD_SET(serv_fd, &active_fds);
    max_fd = serv_fd;

    while (1) {
        read_fds = write_fds = active_fds;
        
        // Select espera até que alguma operação de I/O esteja pronta
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0) 
            continue;

        for (int fd = 0; fd <= max_fd; fd++) {
            if (!FD_ISSET(fd, &read_fds)) continue;

            if (fd == serv_fd) {
                // Novo cliente a ligar-se
                int client_fd = accept(serv_fd, NULL, NULL);
                if (client_fd < 0) continue;
                
                if (client_fd > max_fd) max_fd = client_fd;
                
                ids[client_fd] = next_id++;
                msgs[client_fd] = NULL;
                FD_SET(client_fd, &active_fds);
                
                sprintf(buf_write, "server: client %d just arrived\n", ids[client_fd]);
                send_all(client_fd, buf_write);
                break; // Quebra o ciclo para voltar a atualizar o max_fd no select
            } else {
                // Cliente já existente a enviar dados ou a desligar-se
                int bytes_read = recv(fd, buf_read, sizeof(buf_read) - 1, 0);
                if (bytes_read <= 0) { // Cliente desligou
                    sprintf(buf_write, "server: client %d just left\n", ids[fd]);
                    send_all(fd, buf_write);
                    close(fd);
                    free(msgs[fd]);
                    msgs[fd] = NULL;
                    FD_CLR(fd, &active_fds);
                } else { // Cliente enviou uma mensagem
                    buf_read[bytes_read] = '\0';
                    msgs[fd] = str_join(msgs[fd], buf_read);
                    char *msg = NULL;
                    
                    // Extrai as mensagens linha a linha e emite o prefixo
                    while (extract_message(&msgs[fd], &msg)) {
                        sprintf(buf_write, "client %d: ", ids[fd]);
                        send_all(fd, buf_write);
                        send_all(fd, msg);
                        free(msg);
                    }
                }
            }
        }
    }
    return 0;
}