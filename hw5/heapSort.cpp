//Yunqi Shen
//Merge Sort
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
int counter;
void heapSort(vector<int> &v, int n);
void heapify(vector<int>&v, int n, int i); //Build a heap
void printVector(const vector<int>&);
void writeResult(const vector<int>&,const string &);

int main(int arg, char*argv[]) {	
	cout << "These are the 9 sample files available only: \ndus-2.txt (2) \ndus-4.txt (4) \ndus-6.txt (6) \ndus-8.txt (8) \ndus-10.txt (10) \ndus-12.txt (12) \ndus-16.txt (16) \ndus-20.txt (20) \ndus-24.txt (24) \n(Indices in the parentheses) " << endl;
	cout << "Please type the index of the file that you want to sort: (type 0 to exit)";
	int input;
	cin >> input;
	if (input == 0)
		return 0;
	else if ((input != 2) && (input != 4) && (input != 6) && (input != 8) && (input != 10) && (input != 12) && (input != 16) && (input != 20) && (input != 24)) {
		cout << "Input is invalid." << endl;
		return 1;
	}
	string filenames, sorted_filenames;
	vector<int> data, sorted_data;
	switch (input){
	case 2: filenames = "dus-2.txt"; sorted_filenames = "sorted-2.txt"; break;
	case 4: filenames = "dus-4.txt"; sorted_filenames = "sorted-4.txt"; break;
	case 6: filenames = "dus-6.txt"; sorted_filenames = "sorted-6.txt"; break;
	case 8: filenames = "dus-8.txt"; sorted_filenames = "sorted-8.txt"; break;
	case 10: filenames = "dus-10.txt"; sorted_filenames = "sorted-10.txt"; break;
	case 12: filenames = "dus-12.txt"; sorted_filenames = "sorted-12.txt"; break;
	case 16: filenames = "dus-16.txt"; sorted_filenames = "sorted-16.txt"; break;
	case 20: filenames = "dus-20.txt"; sorted_filenames = "sorted-20.txt"; break;
	case 24: filenames = "dus-24.txt"; sorted_filenames = "sorted-24.txt"; break;
	}
	ifstream file(filenames.c_str());
	if (file.fail()) {
		cerr<<("The file cannot be opened.") << endl;
		return 0;
	}
	if (file.is_open()) {
		int value;
		int size=0;
		while (!file.eof()) {
			while (file >> value) {
				data.push_back(value);
				size++;
			}
		}
	}
	file.close();
	//printVector(data);
	counter = 0;
	//int v_size = sizeof(data)/sizeof(data[0]);
 
    heapSort(data, data.size());

	cout << "\nThe sorted array is in the following:" << endl;
	printVector(data);
	cout << endl << "The total nubmers of swaps of Heap Sort for this file: " << counter<<endl;
	
	return 0;
}
void printVector(const vector<int>&v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i]<<" ";
	cout << endl;
}

void writeResult(const vector<int>& v,const string & filenames)
{
	ofstream file(filenames.c_str());
	if (file.fail()) {
		cerr << ("The file cannot be opened.") << endl;
		return;
	}
	
	if (file.is_open()) {
		for (unsigned i = 0; i < v.size(); i++)
			file << v[i] << " ";	
	}

}
// Merges two sub-vectors of v.
// First sub-vector is v[l..m]
// Second sub-vector is v[m+1..r]


//To make a subtree rooted with node i which is
// an index in v[] into a heap. n is size of heap
void heapify(vector<int>&v, int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
 
    // If left child is larger than root
    if (l < n && v[l] > v[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < n && v[r] > v[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i)
    {	int tmp;
        tmp= v[i];
        v[i]= v[largest];
        v[largest]=tmp;
        counter++;
        
 
        // Recursively heapify the affected sub-tree
        heapify(v, n, largest);
    }
}
 
// main function to do heap sort
void heapSort(vector<int> &v, int n)
{
    // Build heap (revange vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end        
        int tmp;
        tmp=v[0];
        v[0]=v[i];
        v[i]=tmp;
        counter++;
 
        // call max heapify on the reduced heap
        heapify(v, i, 0);
    }
}
 

