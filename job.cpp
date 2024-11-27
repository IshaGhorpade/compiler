#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent a job
struct Job {
    char id;
    int deadline;
    int profit;
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> &jobs, int maxDeadline) {
    // Sort jobs based on profit
    sort(jobs.begin(), jobs.end(), compare);

    vector<int> slot(maxDeadline, -1); // Track which jobs are scheduled
    vector<char> result(maxDeadline, '\0'); // Track job IDs for slots
    int totalProfit = 0;

    for (const auto &job : jobs) {
        // Find a free slot for this job (starting from the last possible slot)
        for (int j = min(maxDeadline, job.deadline) - 1; j >= 0; --j) {
            if (slot[j] == -1) {
                slot[j] = job.profit; // Assign profit to slot
                result[j] = job.id;  // Assign job ID to result
                totalProfit += job.profit; // Update total profit
                break;
            }
        }
    }

    // Display the scheduled jobs
    std::cout << "Scheduled jobs: ";
    for (char job : result) {
        if (job != '\0') cout << job << " ";
    }
    std::cout << "\nTotal profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    int maxDeadline = 3; // Maximum deadline
    jobScheduling(jobs, maxDeadline);

    return 0;
}

