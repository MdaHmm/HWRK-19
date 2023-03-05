#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

template <typename T>
T nod(T a, T b) {
	for (int i = a; i > 0; i--)
		if (a % i == 0 && b % i == 0)
			return i;
}

int mirror_number(int num) {
	int mirror = 0;
	while (num) {
		mirror = mirror * 10 + num % 10;
		num /= 10;
	}
	return mirror;
}

template <typename T>
void fill_arr(T arr[], const int length){
	srand(time(NULL));
	for (int i{}; i < length; i++)
		arr[i] = rand() % 20;
}

void print_arr(int arr[], const int length) {
	std::cout << "[";
	for (int i{}; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}	

template <typename T>
void arr_spec_sort(T arr[], const int length, int num) {
	int first_index;
	for (int i{}; i < length; i++)
		if (arr[i] == num){
			first_index = i;
			std::cout << "����� " << num << " ��� " << first_index << "-� ������� �������." << std::endl;
			break;
		}
	for (int i{ length - 1 }; i > first_index + 1; i--)
		for (int j{ first_index + 1 }; j < i; j++) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
}

template <typename T>
void random_from_a_to_b(T arr[], const int l, int a, int b) {
	srand(time(NULL));
	if (b < a)
		std::swap(a, b);
	for (int i{}; i < l; i++)
		arr[i] = rand() % (b - a) + a;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n, m, a, b;

	// ������ 1.

	std::cout << "������ 1.\n" << nod(3, 25) << "\n";

	// ������ 2.
	std::cout << "������ 2.\n������� ����� -> ";
	std::cin >> n;
	std::cout << "���������� ��������� = " << mirror_number(n) << "\n";

	// ������ 3.
	
	const int size = 10;
	int arr[size];
	fill_arr(arr, size);
	std::cout << "������ 3.\n����������� ������:";
	print_arr(arr, size);
	std::cout << "�������� ����� -> ";
	std::cin >> m;
	arr_spec_sort(arr, size, m);
	print_arr(arr, size);

	// ������ 4.
	const int size4 = 10;
	int arr4[size4]{};
	std::cout << "\n������ 4.\n������� ������ � ����� ��������� -> ";
	std::cin >> a >> b;
	random_from_a_to_b(arr4, size4, a, b);
	print_arr(arr4, size4);

	return 0;
}