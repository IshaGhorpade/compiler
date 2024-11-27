#include <iostream> 
#include <queue>
using namespace std;
struct Node {
 int data;
 Node* left;
 Node* right;
 Node(int val) {
 data = val;
 left = right = NULL;
 }
};
class BST {
public:
 Node* root;
 BST() {
 root = NULL;
 }
 Node* insert(Node* node, int data) {
 if (node == NULL) {
 return new Node(data);
 }
 if (data < node->data) {
 node->left = insert(node->left, data);
 } else {
 node->right = insert(node->right, data);
 }
 return node;
 }
 void inOrder(Node* node) {
 if (node == NULL) {
 return;
 }
 inOrder(node->left);
 cout << node->data << " ";
 inOrder(node->right);
 }
 bool search(Node* node, int key) {
 if (node == NULL) {
 return false;
 }
 if (node->data == key) {
 return true;
 }
 if (key < node->data) {
 return search(node->left, key);
 } else {
 return search(node->right, key);
 }
 }
 Node* findMin(Node* node) {
 while (node && node->left != NULL) {
 node = node->left;
 }
 return node;
 }
 Node* deleteNode(Node* node, int key) {
 if (node == NULL) return node;
 if (key < node->data) {
 node->left = deleteNode(node->left, key);
 } else if (key > node->data) {
 node->right = deleteNode(node->right, key);
 } else {
 if (node->left == NULL) {
 Node* temp = node->right;
 delete node;
 return temp;
 } else if (node->right == NULL) {
 Node* temp = node->left;
 delete node;
 return temp;
 } 
 Node* temp = findMin(node->right);
 node->data = temp->data;
 node->right = deleteNode(node->right, temp->data);
 }
 return node;
 }
};
int main() {
 BST bst;
 int choice, value;
 do {
 cout << "\nBinary Search Tree Operations Menu:\n";
 cout << "1. Insert a Node\n";
 cout << "2. In-Order Display\n";
 cout << "3. Search for a Node\n";
 cout << "4. Delete a Node\n";
 cout << "5. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter value to insert: ";
 cin >> value;
 bst.root = bst.insert(bst.root, value);
 break;
 case 2:
 cout << "In-Order Display: ";
 bst.inOrder(bst.root);
 cout << endl;
 break;
 
 case 3:
 cout << "Enter value to search: ";
 cin >> value;
 cout << (bst.search(bst.root, value) ? "Found" : "Not Found") << endl;
 break; 
 case 4:
 cout << "Enter value to delete: ";
 cin >> value;
 bst.root = bst.deleteNode(bst.root, value);
 cout << "In-Order Display after Deletion: ";
 bst.inOrder(bst.root);
 cout << endl;
 break; 
 case 5:
 cout << "Exiting...\n";
 break;
 default:
 cout << "Invalid choice. Please try again.\n";
 }
 } while (choice != 5);
 return 0;
}

