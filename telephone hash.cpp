#include <iostream>
#include <vector>
using namespace std;
class HashTable {
private:
int size;
vector<int> indexArr;
vector<int> valueArr;
public:
// Constructor to initialize the hash table
HashTable(int size) {
this->size = size;
indexArr.resize(size, -1);
valueArr.resize(size, -1);
}
// Hash function to calculate the index
int hashFunction(int key) {
return key % size;
}
// Linear probing function to resolve collisions
int linearProbing(int hashIndex) {
int originalIndex = hashIndex;
while (indexArr[hashIndex] != -1) {
hashIndex = (hashIndex + 1) % size;
// If we return to the original index, the table is full
if (hashIndex == originalIndex) {
cout << "Hash table is full, cannot insert more elements.\n";
return -1;
}
}
return hashIndex;
}
// Insert function to add key-value pairs to the hash table
void insert(int key, int value) {
int hashIndex = hashFunction(key);
cout << "Initial index for key " << key << ": " << hashIndex << "\n";
// If a collision occurs, use linear probing
if (indexArr[hashIndex] != -1) {
cout << "Collision detected for key " << key << ". Resolving collision...\n";
hashIndex = linearProbing(hashIndex);
if (hashIndex == -1) return; // Table is full
cout << "Collision resolved. New index for key " << key << ": " << hashIndex
<< "\n";
}
// Insert the key-value pair
indexArr[hashIndex] = key;
valueArr[hashIndex] = value;
}
// Display the hash table
void display() {
cout << "\nFinal hash table:\n";
for (int i = 0; i < size; i++) {
if (indexArr[i] != -1)
cout << "Index " << i << ": " << "Key: " << indexArr[i] << ", Value: " <<
valueArr[i] << "\n";
else
cout << "Index " << i << ": Empty\n";
}
}
};
int main() {
int size = 20;
HashTable hashTable(size);
// Sample key-value pairs to insert
long long int arr[9][2] = {
{1, 9823664459}, {2, 9010204534}, {42, 8964902417},
{4, 1234509876}, {12, 9756453527}, {14, 9080903456},
{17, 8624962417}, {13, 8905671234}, {37, 9878124567}
};
// Insert key-value pairs into the hash table
for (int i = 0; i < 9; i++) {
int key = arr[i][0];
int value = arr[i][1];
hashTable.insert(key, value);
}
// Display the final hash table
hashTable.display();
return 0;
}

