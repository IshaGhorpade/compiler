#include <iostream>
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
class BinaryTree {
public:
 Node* root; 
 BinaryTree() {
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
 int findDepth(Node* node) {
 if (node == NULL) {
 return 0;
 }
 int leftDepth = findDepth(node->left);
 int rightDepth = findDepth(node->right);
 return max(leftDepth, rightDepth) + 1;
 }
 void displayLeafNodes(Node* node) {
 if (node == NULL) {
 return;
 }
 if (node->left == NULL && node->right == NULL) {
 cout << node->data << " ";
 }
 displayLeafNodes(node->left);
 displayLeafNodes(node->right);
 }
 Node* copyTree(Node* node) {
 if (node == NULL) {
 return NULL;
 }
 Node* newNode = new Node(node->data);
 newNode->left = copyTree(node->left);
 newNode->right = copyTree(node->right);
 return newNode;
 }
};
int main() {
 BinaryTree bt, copyBt;
 int choice, value;
 
 do {
 cout << "\nBinary Tree Operations Menu:\n";
 cout << "1. Insert a Node\n";
 cout << "2. Display In-Order\n";
 cout << "3. Find Depth of the Tree\n";
 cout << "4. Display Leaf Nodes\n";
 cout << "5. Create and Display Copy of the Tree\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 
 switch (choice) {
 case 1:
 cout << "Enter value to insert: ";
 cin >> value;
 bt.root = bt.insert(bt.root, value);
 break;
 case 2:
 cout << "In-Order Display: ";
 bt.inOrder(bt.root);
 cout << endl;
 break;
 case 3:
 cout << "Depth of Tree: " << bt.findDepth(bt.root) << endl;
 break;
 case 4:
 cout << "Leaf Nodes: ";
 bt.displayLeafNodes(bt.root);
 cout << endl;
 break;
 case 5:
 copyBt.root = bt.copyTree(bt.root);
 cout << "In-Order Display of Copied Tree: ";
 bt.inOrder(copyBt.root);
 cout << endl;
 break;
 case 6:
 cout << "Exiting..." << endl;
 break; 
 default:
 cout << "Invalid choice. Please try again.\n";
 break;
 }
 } while (choice != 6);
 return 0;
}

