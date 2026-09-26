#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left, *right;
};

struct Node* createNode(int key)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// INSERT
struct Node* insert(struct Node* root, int key)
{
    if(root == NULL)
        return createNode(key);

    if(key < root->key)
        root->left = insert(root->left, key);
    else if(key > root->key)
        root->right = insert(root->right, key);

    return root;
}

// SEARCH
struct Node* search(struct Node* root, int key)
{
    if(root == NULL || root->key == key)
        return root;

    if(key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

// DISPLAY (INORDER)
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// MINIMUM NODE
struct Node* minValueNode(struct Node* node)
{
    while(node && node->left != NULL)
        node = node->left;

    return node;
}

// DELETE
struct Node* deleteNode(struct Node* root, int key)
{
    if(root == NULL)
        return root;

    if(key < root->key)
        root->left = deleteNode(root->left, key);

    else if(key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right =
            deleteNode(root->right, temp->key);
    }

    return root;
}

// HEIGHT OF NODE
int height(struct Node* root)
{
    if(root == NULL)
        return -1;

    int leftH = height(root->left);
    int rightH = height(root->right);

    return (leftH > rightH ? leftH : rightH) + 1;
}

// DEPTH OF NODE
int depth(struct Node* root, int key)
{
    int d = 0;

    while(root != NULL)
    {
        if(root->key == key)
            return d;

        if(key < root->key)
            root = root->left;
        else
            root = root->right;

        d++;
    }

    return -1;
}

// INORDER SUCCESSOR
struct Node* inorderSuccessor(struct Node* root, int key)
{
    struct Node *curr = search(root,key);
    struct Node *succ = NULL;

    if(curr == NULL)
        return NULL;

    if(curr->right != NULL)
        return minValueNode(curr->right);

    while(root)
    {
        if(key < root->key)
        {
            succ = root;
            root = root->left;
        }
        else if(key > root->key)
            root = root->right;
        else
            break;
    }

    return succ;
}

// INORDER PREDECESSOR
struct Node* inorderPredecessor(struct Node* root, int key)
{
    struct Node *curr = search(root,key);
    struct Node *pred = NULL;

    if(curr == NULL)
        return NULL;

    if(curr->left != NULL)
    {
        curr = curr->left;

        while(curr->right)
            curr = curr->right;

        return curr;
    }

    while(root)
    {
        if(key > root->key)
        {
            pred = root;
            root = root->right;
        }
        else if(key < root->key)
            root = root->left;
        else
            break;
    }

    return pred;
}

// MAIN
int main()
{
    struct Node *root = NULL;
    int choice, key;

    while(1)
    {
        printf("\n\n--- BST MENU ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Display");
        printf("\n5. Height of Tree");
        printf("\n6. Depth of Node");
        printf("\n7. Inorder Successor");
        printf("\n8. Inorder Predecessor");
        printf("\n9. Exit");

        printf("\nEnter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("Enter Key: ");
                scanf("%d",&key);
                root = insert(root,key);
                break;

            case 2:
                printf("Enter Key: ");
                scanf("%d",&key);
                root = deleteNode(root,key);
                break;

            case 3:
                printf("Enter Key: ");
                scanf("%d",&key);

                if(search(root,key))
                    printf("Found");
                else
                    printf("Not Found");
                break;

            case 4:
                printf("BST (Inorder): ");
                inorder(root);
                break;

            case 5:
                printf("Height = %d",
                       height(root));
                break;

            case 6:
                printf("Enter Node: ");
                scanf("%d",&key);

                printf("Depth = %d",
                       depth(root,key));
                break;

            case 7:
            {
                printf("Enter Node: ");
                scanf("%d",&key);

                struct Node *s =
                    inorderSuccessor(root,key);

                if(s)
                    printf("Successor = %d",s->key);
                else
                    printf("No Successor");
                break;
            }

            case 8:
            {
                printf("Enter Node: ");
                scanf("%d",&key);

                struct Node *p =
                    inorderPredecessor(root,key);

                if(p)
                    printf("Predecessor = %d",p->key);
                else
                    printf("No Predecessor");
                break;
            }

            case 9:
                exit(0);
        }
    }
}