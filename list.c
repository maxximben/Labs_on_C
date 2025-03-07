#include <stdio.h>
#include <stdlib.h>


// Определение структуры узла
struct Node {
    int data;
    struct Node* next;
};

int find_node(struct Node *n, int num) {
  for (int i = 1; i < num; i++) {
    n = n->next;
  }
  return n->data;
}

// Функция для добавления узла в конец списка
void append(struct Node** head_ref, int new_data) {
    // Создание нового узла
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Используем для прохода по списку

    new_node->data = new_data; // Заполнение данных
    new_node->next = NULL; // Новый узел будет последним, поэтому указатель на следующий узел равен NULL

    // Если список пуст, то новый узел становится головой
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Иначе, проходим до последнего узла
    while (last->next != NULL) {
        last = last->next;
    }

    // Меняем указатель последнего узла на новый узел
    last->next = new_node;
}

// Функция для вывода списка
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Основная функция
int main() {
    struct Node* head = NULL; // Начало списка

    // Добавление узлов в список
    
    
    
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    printf("%d\n", find_node(head, 1));
    
    printf("Содержимое списка: ");
    printList(head);

    // Освобождение памяти (не забудьте освободить память в реальной программе)

    return 0;
}
