#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeEqual(vector<int>& arr){
    int n = arr.size();
    
    // Sort the array in non-increasing order
    sort(arr.begin(), arr.end(), greater<>());

    // Apply XOR operations on adjacent elements
    while (n >= 2) {
        int x = arr[n - 1];
        int y = arr[n - 2];
        int z = x ^ y;
        if (z > x && z > y) {
            // The result of the XOR operation is greater than both x and y,
            // which means we cannot make all elements equal
            return false;
        }
        arr.pop_back();
        arr.pop_back();
        if (z != 0) {
            arr.push_back(z);
            n--;
        }
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (canMakeEqual(arr)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

#include <algorithm>
#include <iostream>
using namespace std;

struct Job {

	char id; // Job Id
	int dead; // Deadline of job
	int profit; // Profit if job is over before or on
				// deadline
};

// Comparator function for sorting jobs
bool comparison(Job a, Job b){
	return (a.profit > b.profit);
}

// Returns maximum profit from jobs
void printJobScheduling(Job arr[], int n){
	// Sort all jobs according to decreasing order of profit
	sort(arr, arr + n, comparison);

	int result[n]; // To store result (Sequence of jobs)
	bool slot[n]; // To keep track of free time slots

	// Initialize all slots to be free
	for (int i = 0; i < n; i++)
		slot[i] = false;

	// Iterate through all given jobs
	for (int i = 0; i < n; i++) {
		// Find a free slot for this job (Note that we start
		// from the last possible slot)
		for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
			// Free slot found
			if (slot[j] == false) {
				result[j] = i; // Add this job to result
				slot[j] = true; // Make this slot occupied
				break;
			}
		}
	}

	// Print the result
	for (int i = 0; i < n; i++)
		if (slot[i])
			cout << arr[result[i]].id << " ";
}

int main(){
	Job arr[] = { { 'a', 2, 100 },
				{ 'b', 1, 19 },
				{ 'c', 2, 27 },
				{ 'd', 1, 25 },
				{ 'e', 3, 15 } };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Following is maximum profit sequence of jobs "
			"\n";

	printJobScheduling(arr, n);
	return 0;
}