//Yunqi Shen
//Bubble Sort
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int counter;
void bubbleSort(vector<int> &v);
void printVector(const vector<int>&);
void writeResult(const vector<int>&, const string &);

int main(int arg, char*argv[]) {
	cout << "These are the 9 sample files available only: dus-2.txt (2), dus-4.txt (4) ... dus-24.txt (24). (Indice in the parentheses)" << endl;
	cout << "Please type the index of the file that you want to sort: (type 0 to exit)";
	int input;
	cin >> input;
	if (input == 0)
		return 0;
	else if ((input != 2) && (input != 4) && (input != 6) && (input != 8) && (input != 10) && (input != 12) && (input != 16) && (input != 20) && (input != 24)) {
		cout << "Input is invalid." << endl;
		return 0;
	}
	string filenames, sorted_filenames;
	vector<int> data, sorted_data;
	switch (input) {
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
	ifstream file(filenames);
	if (file.fail()) {
		cerr << ("The file cannot be opened.") << endl;
		return 0;
	}
	if (file.is_open()) {
		int value;
		int size = 0;
		while (!file.eof()) {
			while (file >> value) {
				data.push_back(value);
				size++;
			}
		}
	}
	counter = 0;
	bubbleSort(data);
	cout << "\nThe sorted array is in the following:" << endl;
	printVector(data);
	cout << endl << "The total times of swaps for bubble sort for this file: " << counter << endl;
	writeResult(data, sorted_filenames);

	//We then try sorting the sorted file.
	cout << "Now it is the time to try sorting the sorted array!" << endl;
	counter = 0;
	ifstream sorted_file(sorted_filenames);
	if (sorted_file.fail()) {
		cerr << ("The file cannot be opened.") << endl;
		return 0;
	}
	if (sorted_file.is_open()) {
		int value;
		int size = 0;
		while (!sorted_file.eof()) {
			while (sorted_file >> value) {
				sorted_data.push_back(value);
				size++;
			}
		}
	}
	cout << "The total times of swaps for the corresponding SORTED vector is: " << counter << endl;

	//system("pause");
	return 0;
}
void bubbleSort(vector<int> &v)
{
	int temp;
	for (unsigned int i = 0; i < v.size(); i++)
	{
		for (unsigned j = 0; j<v.size() - 1; j++)
		{
			//Swapping element in if statement    
			if (v[j]>v[j + 1])
			{
				temp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = temp;
				counter++;
			}
		}
	}

}

void printVector(const vector<int>&v) {
	for (unsigned i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

void writeResult(const vector<int>& v, const string & filenames)
{
	ofstream file(filenames);
	if (file.fail()) {
		cerr << ("The file cannot be opened.") << endl;
		return;
	}

	if (file.is_open()) {
		for (unsigned i = 0; i < v.size(); i++)
			file << v[i] << " ";
	}

}
