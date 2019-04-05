

#include "pch.h"
#include <Windows.h>
#include <iomanip>
#include <vector>
#include <iostream> 

double PCFreq = 0.0;
__int64 Start = 0;

void Counter(){

	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		std::cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart);

	QueryPerformanceCounter(&li);
	Start = li.QuadPart;
}

double GetCounter(){

	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - Start) / PCFreq;
}


bool is_prime_number(const int *n){

	if (*n < 2)
		return false;

	for (int i = 2; i*i <= *n; i++)
		if (*n%i == 0)
			return false;

	return true;
}

bool occurrence( int A_value, const std::vector<int> &B_value) {

	int sum = 0;

	for (auto i = 0; i < B_value.size(); ++i) {
		if (A_value == B_value[i]) ++sum;
	}
	
	if (sum == 0)
		return false;
	else
		return is_prime_number(&sum);
}


int main(){

	std::vector<int> A{ 2, 3, 9, 2, 5, 1, 3, 7, 10 };
	std::vector<int> B{ 2, 1, 3, 4, 3, 10, 6, 6, 1, 7, 10, 10, 10 };
	std::vector<int> C;

	Counter();


		for (auto i = 0; i < A.size(); ++i)
			if (occurrence(A[i], B) == false) C.push_back(A[i]);
	

	std::cout << "The execution time of the algorithm: " << std::fixed << std::setprecision(8) << GetCounter() << "seconds\n";

	for (auto i = 0; i < C.size(); ++i)
		std::cout << C[i] << "\t";
	
	getchar();

}
