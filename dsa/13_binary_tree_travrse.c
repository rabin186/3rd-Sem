#include<stdio.h>
#include<stdlib.h>

struct bnode {
    int data;
    struct bnode *left;
    struct bnode *right;
};

typedef struct bnode node;
node *root = NULL;

node* createNode(int value) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void insert() {
    int data;
    printf("Please Enter the data to be inserted: ");
    scanf("%d", &data);

    node *newNode = createNode(data);

    if (root == NULL) {
        root = newNode;
        return;
    }

    node *current = root, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else if (data > current->data) {
            current = current->right;
        } else { 
            // Fix: Removed unnecessary {}
            printf("Duplicate values are not allowed in BST!\n");
            free(newNode);
            return;
        }
    }

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void in_order(node *temp) {
    if (temp != NULL) {
        in_order(temp->left);
        printf("%d ", temp->data);
        in_order(temp->right);
    }
}

void pre_order(node *temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        pre_order(temp->left);
        pre_order(temp->right);
    }
}

void post_order(node *temp) {
    if (temp != NULL) {
        post_order(temp->left);
        post_order(temp->right);
        printf("%d ", temp->data);
    }
}

int main() {
    int choice;
    while (1) {  // Fix: Moved the menu inside the loop
        printf("--------------------------------------\n");
        printf("1. Insert value\n");
        printf("2. In-order traverse\n");
        printf("3. Pre-order traverse\n");
        printf("4. Post-order traverse\n");
        printf("5. Exit\n");
        printf("--------------------------------------\n");
        printf("Please Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                printf("In-order Traverse: ");
                in_order(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order Traverse: ");
                pre_order(root);
                printf("\n");
                break;
            case 4:
                printf("Post-order Traverse: ");
                post_order(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
}
