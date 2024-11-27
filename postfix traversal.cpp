#include <iostream> 
#include <stack>
using namespace std;
struct Node {
 char data;
 Node* left;
 Node* right;
 Node(char val) {
 data = val;
 left = right = NULL;
 }
};
class ExpressionTree {
public:
 Node* root;
 ExpressionTree() {
 root = NULL;
 }
 Node* constructTree(string postfix) {
 stack<Node*> s;
 for (int i = 0; i < postfix.length(); i++) {
 char ch = postfix[i]; 
 if (isOperator(ch)) {
 Node* node = new Node(ch);
 node->right = s.top(); s.pop();
 node->left = s.top(); s.pop();
 s.push(node);
 } else {
 s.push(new Node(ch));
 }
 }
 return s.top();
 }
 bool isOperator(char ch) {
 return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
 }
 void nonRecursiveInOrder(Node* node) {
 if (node == NULL) return;
 stack<Node*> s;
 Node* current = node;
 while (current != NULL || !s.empty()) {
 while (current != NULL) {
 s.push(current);
 current = current->left;
 }
 current = s.top(); s.pop();
 cout << current->data << " ";
 current = current->right;
 }
 }
 void nonRecursivePreOrder(Node* node) {
 if (node == NULL) return;
 stack<Node*> s;
 s.push(node);
 while (!s.empty()) {
 Node* current = s.top(); s.pop();
 cout << current->data << " ";
 if (current->right != NULL) {
 s.push(current->right);
 }
 if (current->left != NULL) {
 s.push(current->left);
 }
 }
 }
 void nonRecursivePostOrder(Node* node) {
 if (node == NULL) return;
 stack<Node*> s1, s2;
 s1.push(node);
 while (!s1.empty()) {
 Node* current = s1.top(); s1.pop();
 s2.push(current);
 if (current->left != NULL) {
 s1.push(current->left);
 }
 if (current->right != NULL) {
 s1.push(current->right);
 }
 }
 while (!s2.empty()) {
 cout << s2.top()->data << " ";
 s2.pop();
 }
 }
};
int main() {
 string postfix;
 cout << "Enter a postfix expression: ";
 cin >> postfix;
 ExpressionTree et;
 et.root = et.constructTree(postfix);
 cout << "Non-Recursive In-Order Traversal: ";
 et.nonRecursiveInOrder(et.root);
 cout << endl;
 cout << "Non-Recursive Pre-Order Traversal: ";
 et.nonRecursivePreOrder(et.root);
 cout << endl;
 cout << "Non-Recursive Post-Order Traversal: ";
 et.nonRecursivePostOrder(et.root);
 cout << endl;
 return 0;
}

