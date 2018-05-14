#include <iostream>
#include <vector>
#include <stdlib.h>
 
using namespace std;

struct Node {
    int number;
    struct Node *left;
    struct Node *right;
    int height;
};

void maxHeapify (vector<int> &vec, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
 
    if (left < vec.size() && vec[largest] > vec[largest])
        largest = left;
 
    if (right < vec.size() && vec[right] > vec[largest])
        largest = right;
 
    if (largest != i) {
        swap(vec[i], vec[largest]);
 
        maxHeapify(vec, largest);
    }
}

void heapSort (vector<int> &vec) {
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        maxHeapify(vec, i);
 
    for (int  i = vec.size()-1; i >= 0; i--){
        swap(vec[0], vec[i]);
        maxHeapify(vec, 0);
    }
}

void insertionSort (vector<int> &vec) {
    int aux, j;

    for (int i = 1; i < vec.size(); i++) {
        aux = vec[i];
    
        for (j = (i-1); j >= 0 && vec[j] > aux; j--) {
           vec[j+1] = vec[j];
        }

        vec[j+1] = aux;
    }
}

void mergeSort (vector<int> &vec, int half, int left_side, int right_side) {
    vector<int> temp1, temp2;
    int indx1 = (half - left_side) + 1;
    int indx2 = right_side - half;
    
    for (int i = 0; i < indx1; i++) {
        temp1.push_back(vec[left_side + i]);
    }

    for (int i = 0; i < indx2; i++) {
        temp2.push_back(vec[half + 1 + i]);
    }

    int counter1 = 0;
    int counter2 = 0;
    int counter3 = left_side;

    while (counter1 < indx1 && counter2 < indx2) {
        if (temp1[counter1] <= temp2[counter2]) {
            vec[counter3] = temp1[counter1];
            counter1++;
        } else {
            vec[counter3] = temp2[counter2];
            counter2++;
        }
        counter3++;
    }

    while (counter1 < indx1) {
        vec[counter3] = temp1[counter1];
        counter1++;
        counter3++;
    }

    while (counter2 < indx2) {
        vec[counter3] = temp2[counter2];
        counter2++;
        counter3++;
    }
}

void mergeSort (vector<int> &vec, int left_side, int right_side) {
    if (left_side < right_side) {
        int half = left_side + (right_side - left_side)/2;

        mergeSort(vec, left_side, half);
        mergeSort(vec, (half + 1), right_side);
        mergeSort(vec, left_side, half, right_side);
    }
}
 
void printVector (vector<int> vec) {
    for (int i = 0; i < vec.size(); i++)
        cout << "[" << vec[i] << "] ";
    cout << endl;
}
 
int main() {
    vector<int> vec;


    cout << "Merge Sort" << endl;
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(90);
    vec.push_back(10);

    printVector(vec);
    mergeSort(vec, 0, (vec.size() - 1));
    printVector(vec);
    
    cout << "Insertion Sort" << endl;
    vec.push_back(7);
    vec.push_back(2);
    vec.push_back(6);
    vec.push_back(1);

    printVector(vec);
    insertionSort(vec);
    printVector(vec);

    vector<int> vec1;

    cout << "Heap Sort" << endl;
    vec1.push_back(4);
    vec1.push_back(3);
    vec1.push_back(2);
    vec1.push_back(1);

    printVector(vec1);
    heapSort(vec1);
    printVector(vec1);

    return 0;
}