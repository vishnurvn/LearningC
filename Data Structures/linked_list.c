#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

void printLinkedList(struct Node *node) {
    while (node->next != NULL) {
        printf("%c\n", node->value);
        node = node->next;
    }
}

int main() {
    FILE *fp;
    char buff;
    struct Node *head = NULL;
    struct Node *current;

    fp = fopen("./file.txt", "r");
    while((buff = fgetc(fp)) != EOF) {
        if (!(buff == 10)) {
            if (head == NULL) {
                head = (struct Node*)malloc(sizeof(struct Node));
                head->value = buff;
                head->next = NULL;
                current = head;
            } else {
                struct Node *node;
                node = (struct Node*)malloc(sizeof(struct Node));
                node->value = buff;
                node->next = NULL;
                current->next = node;
                current = node;
            }
        }
    }

    fclose(fp);
    printLinkedList(head);
    return 0;
}
