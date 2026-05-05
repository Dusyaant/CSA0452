#include <stdio.h>
#include <sys/msg.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
} message;

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);
    message.msg_type = 1;
    printf("Write Message: ");
    fgets(message.msg_text, 100, stdin);
    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Sent: %s", message.msg_text);
    return 0;
}
