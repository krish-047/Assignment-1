#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Function to calculate the median from two merged score lists
double calculateMedianMerged(const vector<int>& classScores1, const vector<int>& classScores2) {
    int size1 = classScores1.size();  // Total students in class 1
    int size2 = classScores2.size();  // Total students in class 2
    int combinedSize = size1 + size2;

    if (combinedSize == 0) {
        throw invalid_argument("Both score lists are empty.");
    }
    
    // Indices for iterating through the two lists
    int index1 = 0, index2 = 0;
    vector<int> combinedScores;
    
    // Merge the two lists in sorted order
    while (index1 < size1 && index2 < size2) {
        if (classScores1[index1] <= classScores2[index2]) {
            combinedScores.push_back(classScores1[index1]);
            index1++;
        } else {
            combinedScores.push_back(classScores2[index2]);
            index2++;
        }
    }
    
    // Add remaining elements from classScores1, if any
    while (index1 < size1) {
        combinedScores.push_back(classScores1[index1]);
        index1++;
    }

    // Add remaining elements from classScores2, if any
    while (index2 < size2) {
        combinedScores.push_back(classScores2[index2]);
        index2++;
    }
    
    // Determine the median of the merged list
    if (combinedSize % 2 == 1) {
        // Odd total number of scores
        return combinedScores[combinedSize / 2];
    } else {
        // Even total number of scores
        int middle1 = combinedScores[(combinedSize / 2) - 1];
        int middle2 = combinedScores[combinedSize / 2];
        return (middle1 + middle2) / 2.0;  // Use floating-point division to avoid integer truncation
    }
}

int main() {
    vector<int> classScores1, classScores2;
    int size1, size2, score;

    // Input for classScores1
    //cout << "Enter the number of students in class 1: ";
    cin >> size1;
    //cout << "Enter the scores for class 1:" << endl;
    for (int i = 0; i < size1; i++) {
        cin >> score;
        classScores1.push_back(score);
    }

    // Input for classScores2
    //cout << "Enter the number of students in class 2: ";
    cin >> size2;
    //cout << "Enter the scores for class 2:" << endl;
    for (int i = 0; i < size2; i++) {
        cin >> score;
        classScores2.push_back(score);
    }

    // Handle empty score lists
    if (classScores1.empty() || classScores2.empty()) {
        cout << "Empty Array" << endl;
        return 1;
    }

    // Try to calculate and print the median, handle potential errors
    try {
        double median = calculateMedianMerged(classScores1, classScores2);
        cout << "Median = " << median << endl;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
