#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <ctime>
#include <climits>

using namespace std;

struct User {
    string name;
    string dateOfBirth;
    int comments;

    User() : name(""), dateOfBirth(""), comments(0) {}

    User(string n, string dob, int c) : name(n), dateOfBirth(dob), comments(c) {}
};

class FriendNetwork {
private:
    unordered_map<string, list<string>> adjList;
    unordered_map<string, User> userData;

public:
    void addUser(string name, string dob, int comments) {
         userData[name] = User(name, dob, comments);
    }

    void addFriendship(string user1, string user2) {
        adjList[user1].push_back(user2);
        adjList[user2].push_back(user1);
    }

    string findMaxFriends() {
        string maxFriendUser = "";
        int maxFriends = 0;

        for (auto &entry : adjList) {
            if (entry.second.size() > maxFriends) {
                maxFriends = entry.second.size();
                maxFriendUser = entry.first;
            }
        }

        return maxFriendUser;
    }

    void findMaxMinComments(string &maxCommentUser, string &minCommentUser) {
        int maxComments = INT_MIN;
        int minComments = INT_MAX;

        for (auto &entry : userData) {
            if (entry.second.comments > maxComments) {
                maxComments = entry.second.comments;
                maxCommentUser = entry.first;
            }

            if (entry.second.comments < minComments) {
                minComments = entry.second.comments;
                minCommentUser = entry.first;
            }
        }
    }

    vector<string> findBirthdaysThisMonth() {
        vector<string> birthdayUsers;
        time_t t = time(0);
        struct tm *now = localtime(&t);
        int currentMonth = now->tm_mon + 1;

        for (auto &entry : userData) {
            int userMonth = stoi(entry.second.dateOfBirth.substr(3, 2));
            if (userMonth == currentMonth) {
                birthdayUsers.push_back(entry.first);
            }
        }
         
        return birthdayUsers;
    }

    void DFS(string startUser) {
        unordered_map<string, bool> visited;
        stack<string> st;
        st.push(startUser);

        while (!st.empty()) {
            string user = st.top();
            st.pop();
              if (!visited[user]) {
                cout << user << " ";
                visited[user] = true;
            }

            for (auto &friendName : adjList[user]) {
                if (!visited[friendName]) {
                    st.push(friendName);
                }
            }
        }

        cout << endl;
    }

    void BFS(string startUser) {
        unordered_map<string, bool> visited;
        queue<string> q;
        q.push(startUser);
        visited[startUser] = true;

        while (!q.empty()) {
            string user = q.front();
            q.pop();

            cout << user << " ";

            for (auto &friendName : adjList[user]) {
                if (!visited[friendName]) {
                    q.push(friendName);
                    visited[friendName] = true;
                }
            }
        }
 cout << endl;
    }
};

int main() {
    FriendNetwork network;
    int choice;

    do {
        cout << "\n----- Menu -----\n";
        cout << "1. Add User\n";
        cout << "2. Add Friendship\n";
        cout << "3. Find User with Maximum Friends\n";
        cout << "4. Find User with Maximum and Minimum Comments\n";
        cout << "5. Find Users with Birthdays This Month\n";
        cout << "6. Perform DFS Traversal\n";
        cout << "7. Perform BFS Traversal\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, dob;
                int comments;
                cout << "Enter user name: ";
                cin >> name;
                cout << "Enter date of birth (DD-MM-YYYY): ";
                cin >> dob;
                cout << "Enter number of comments: ";
                cin >> comments;
                network.addUser(name, dob, comments);
                break;
            }
 case 2: {
                string user1, user2;
                cout << "Enter first user name: ";
                cin >> user1;
                cout << "Enter second user name: ";
                cin >> user2;
                network.addFriendship(user1, user2);
                break;
            }
            case 3: {
                string maxFriendsUser = network.findMaxFriends();
                cout << "User with maximum friends: " << maxFriendsUser << endl;
                break;
            }
            case 4: {
                string maxCommentUser, minCommentUser;
                network.findMaxMinComments(maxCommentUser, minCommentUser);
                cout << "User with maximum comments: " << maxCommentUser << endl;
                cout << "User with minimum comments: " << minCommentUser << endl;
                break;
            }
            case 5: {
                vector<string> birthdayUsers = network.findBirthdaysThisMonth();
                cout << "Users with birthdays this month: ";
                for (auto &user : birthdayUsers) {
                    cout << user << " ";
                }
                cout << endl;
                break;
            }
            case 6: {
                string startUser;
                cout << "Enter starting user for DFS: ";
                cin >> startUser;
                cout << "DFS traversal: ";
                network.DFS(startUser);
                break;
            }
            case 7: {
                string startUser;
                cout << "Enter starting user for BFS: ";
                cin >> startUser;
                cout << "BFS traversal: ";
                network.BFS(startUser);
                break;
            }
            case 8:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);

    return 0;
}
