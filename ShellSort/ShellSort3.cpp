#include <iostream>
using namespace std;

void shellSort(int array[], int n) {
	
    for (int gap = n / 2; gap > 0; gap = gap / 2) {
    	// gap = 1
	    for (int i = gap; i < n; i++) {
    	// i = 1 ; 1 < n
	        int temp = array[i], j;
    			
	        for (j = i; gap <= j && array[j - gap] > temp; j = j - gap) {
    		    
	            array[j] = array[j - gap];
            }
    
	        array[j] = temp;
        }
    }
}

int main() {
    int array[] = {23, 8, 16, 24, 35, 45, 1}, n = sizeof(array) / sizeof(array[0]);
    cout << "Array sebelum diurutkan: ";
   
    for (int i = 0; i < n; cout << array[i++] << " ");
    cout << endl << endl;
   
    shellSort(array, n);
    cout << "Array setelah diurutkan: ";
    
	for (int i = 0; i < n; cout << array[i++] << " ");
    cout << endl;
    
    return 0;
}

