#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& leftArray, vector<int>& rightArray,vector<int>& array) {
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    //indices

    int i = 0;
    int l = 0;
    int r = 0;

    //main loop
    while(l < leftSize && r < rightSize) {
        if(leftArray[l] < rightArray[r]) {
            array[i] = leftArray[l];
            i++;
            l++;
        } else {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }

    while (l < leftSize) {
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        array[i] = rightArray[r];
        i++;
        r++;
    }
}
void mergeSort(vector<int>& array) {
    int n = array.size();
    if(n <= 1) { // caso base
        return;
    }
    int center = n / 2;
    //crear arrreglo izquierdo y derecho con el size de los elementos
    vector<int> leftArray(center);
    vector<int> rightArray(n - center);

    for (int i = 0; i < n; i++) {
        if(i < center) {
            leftArray[i] = array[i];
        }
        else {
            rightArray[i-center] = array [i];
        }
    }
    //dividir
    mergeSort(leftArray);
    mergeSort(rightArray);

    //conquer
    merge(leftArray, rightArray, array);
}

int main() {
    vector<int> array = {12,3,7,9,14,6,11,2};

    mergeSort(array);

    for (int num: array) {
        cout << num << " ";
    }

    return 0;
}
