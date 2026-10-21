#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

struct Node* find(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (root->data < key) {
        return find(root->right, key);
    }
    return find(root->left, key);
}


void show(struct Node* root) {
    if (root != NULL) {
        show(root->left);
        printf("%d ", root->data);
        show(root->right);
    }
}

struct Node* copyTree(struct Node* root) {
    if (root == NULL) return NULL;
    
    struct Node* newRoot = createNode(root->data);
    newRoot->left = copyTree(root->left);
    newRoot->right = copyTree(root->right);
    
    return newRoot;
}

void mirror(struct Node* root) {
    if (root == NULL) return;
    
    // Swap left and right subtrees
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively mirror the subtrees
    mirror(root->left);
    mirror(root->right);
}


int height(struct Node* root) {
    if (root == NULL) {
        return 0; 
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int main(){
    struct Node* root = NULL;
    int choice;
    int key;
    struct Node* temp = NULL;
    struct Node* copiedRoot = NULL;

	while(1){
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Find\n");
		printf("4.Show\n");
		printf("5.Display Copy\n");
		printf("6.Display Mirror Image\n");
		printf("7.Height and Depth of Tree\n");
		printf("8.Exit\n");

		printf("Enter Your Choice: ");
		scanf("%d",&choice);
		
	switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inserted '%d'.\n", key);
                break;
            case 2:
                printf("Enter a number to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Deleted '%d' (if it existed).\n", key);
                break;
            case 3:
                printf("Enter a number to find: ");
                scanf("%d", &key);
                temp = find(root, key);
                if (temp != NULL) {
                    printf("Item '%d' found in the tree.\n", key);
                } else {
                    printf("Item '%d' not found.\n", key);
                }
                break;
            case 4:
                printf("Tree contents (In-order): ");
                show(root);
                printf("\n");
                break;
            case 5:
                copiedRoot = copyTree(root);
                printf("Tree copied. Copied tree contents: ");
                show(copiedRoot);
                printf("\n");
                break;
            case 6:
                mirror(root);
                printf("Tree has been mirrored. Contents now: ");
                show(root);
                printf("\n");
                // Mirror it back to restore original state if desired so you can keep working normally
                mirror(root); 
                break;
            case 7:
                printf("Height (and max depth) of the Tree is: %d\n", height(root));
                break;
            case 8:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    }
    return 0;
}