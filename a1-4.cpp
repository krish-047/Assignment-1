#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

double findMedianCombined(const vector<int>& scores1, const vector<int>& scores2) {
    int n = scores1.size();  // Number of students in section 1
    int m = scores2.size();  // Number of students in section 2
    int total = n + m;
    
    if (total == 0) {
        throw invalid_argument("Both score lists are empty.");
    }
    
    // Initialize two pointers for each section
    int i = 0, j = 0;
    vector<int> merged;
    
    // Merge process: similar to merge sort
    while (i < n && j < m) {
        if (scores1[i] <= scores2[j]) {
            merged.push_back(scores1[i]);
            i++;
        } else {
            merged.push_back(scores2[j]);
            j++;
        }
    }
    
    // Append remaining elements from section 1
    while (i < n) {
        merged.push_back(scores1[i]);
        i++;
    }

    // Append remaining elements from section 2
    while (j < m) {
        merged.push_back(scores2[j]);
        j++;
    }
    
    // Find the median from the merged array
    if (total % 2 == 1) {
        // Odd number of students
        return merged[total / 2];
    } else {
        // Even number of students
        int mid1 = merged[(total / 2) - 1];
        int mid2 = merged[total / 2];
        return (mid1 + mid2) / 2.0;
    }
}

int main() {
    vector<int> scores1, scores2;
    int n, m, score;

    // Input for scores1
    //cout << "Enter the size of the array1: ";
    cin >> n;
    //cout << "The array elements are:" << endl;
    for (int i = 0; i < n; i++) {
        
        cin >> score;
        scores1.push_back(score);
    }

    // Input for scores2
    //cout << "Enter the size of the array2: ";
    cin >> m;
    //cout << "The array elements are:" << endl;
    
    for (int i = 0; i < m; i++) {
        
        cin >> score;
        scores2.push_back(score);
    }

    if (scores1.size() == 0 || scores2.size() == 0) {
        cout << "Empty Array" << endl;
        return 1;
    }

    try {
        double median = findMedianCombined(scores1, scores2);
        cout << "Median = " << median << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
