#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	    if (!newNode) {
	        printf("Memory allocation failed\n");
	        return NULL;
	    }
	    newNode->data = data;
	    newNode->left = newNode->right = NULL;
	    return newNode;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}
struct Node* minValueNode(struct Node* node) {
    struct Node* temp = node;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {  
        if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int searchNode(struct Node* root, int data) {
    if (root == NULL) {
        printf("Empty Tree\n");
        return NULL;
    }
    if (data == root->data) {
        return root->data;
    }
    if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
void main() {
    struct Node* root = NULL;
    int choice, data;
    do {
        printf("\n1. Insert a node\n2. Delete a node\n3. Search a node\n4. Inorder traversal\n5. Preorder traversal\n6. Postorder traversal\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                struct Node* searchResult = searchNode(root, data);
                if (searchResult != NULL) {
                    printf("Node with data %d found.\n", data);
                } else {
                    printf("Node with data %d not found.\n", data);
                }
                break;
            case 4:
                inorderTraversal(root);
                break;
            case 5:
                preorderTraversal(root);
                break;
            case 6:
                postorderTraversal(root);
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);
}
