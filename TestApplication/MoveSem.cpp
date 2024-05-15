#include <vector>
#include <algorithm>
#include <chrono>
#include <iostream>
struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took" << ms << "ms" << std::endl;
	}
};

class Holder {
public:
	Holder(int size) {
		m_data = new int[size];
		m_size = size;
	}
	// copy constructor
	Holder(const Holder& other) {
		m_data = new int[other.m_size];
		std::copy(other.m_data, other.m_data + other.m_size, m_data);
		m_size = other.m_size;
	}
	// Implement the assignment operator
	Holder& operator=(const Holder& other) {
		if (this == &other) return *this;
		delete[] m_data;
		m_data = new int[other.m_size];
		std::copy(other.m_data, other.m_data + other.m_size, m_data);
		m_size = other.m_size;
		return *this;
	}
	Holder createHolder(int size) {
		return Holder(size);
	}
	~Holder() {
		delete[] m_data;
	}
	int* m_data;
	size_t m_size;
};