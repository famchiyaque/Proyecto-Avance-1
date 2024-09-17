#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

void swap(vector<int>& vec, int posA, int posB) {
  int val_at_a = vec[posA];
  vec[posA] = vec[posB];
  vec[posB] = val_at_a;
}

void copyArray(vector<int> &A, vector<int> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

void mergeArray(vector<int> &A, vector<int> &B, int low, int mid, int high) {
	int i_ordenado = low;
    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[i_ordenado] = A[i];
            i++;
        } else {
            B[i_ordenado] = A[j];
            j++;
        }
        i_ordenado++;
    }

    while (i <= mid) {
        B[i_ordenado] = A[i];
        i++;
        i_ordenado++;
    }

    while (j <= high) {
        B[i_ordenado] = A[j];
        j++;
        i_ordenado++;
    }

}

void mergeSplit(vector<int> &A, vector<int> &B, int low, int high) {
	if (low < high) {
        int mid = low + (high - low) / 2;  // Calculate the middle index correctly

        mergeSplit(A, B, low, mid);
        mergeSplit(A, B, mid + 1, high);

        mergeArray(A, B, low, mid, high);
        copyArray(A, B, low, high);
    }

}

void mergeSort(vector<int> &source) {
	// vector<int> v(source);
	vector<int> tmp(source.size());

	mergeSplit(source, tmp, 0, source.size() - 1);

}

int getScore(string& scoreStr) {
    reverse(scoreStr.begin(), scoreStr.end());
    int score = 0;
    for (int i = 0; i < scoreStr.length(); i++) {
        score += ((scoreStr[i] - '0') * pow(10, i));
    }
    return score;
}

bool busqueda_binaria(vector<int>& scores, int size, int score) {
    int pos = size/2;

    while (size > 1) {
        if (size % 2 == 0)  size = size/2;
        else size = size/2 + 1;

        if (scores[pos] == score) {
            scores.erase(scores.begin() + pos);
            return true;
        }
        else if (scores[pos] > score) pos = pos - size/2;
        else pos = pos + size/2;
    }
    return false;
}

void printVector(vector<int>& vec, string vecName) {
    cout << vecName << ": {";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ", ";
    }
    cout << "}" << endl;
}

#endif