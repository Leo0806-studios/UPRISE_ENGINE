#pragma once
#ifndef _ARRAY_
#define _ARRAY_
import std;
enum type { stack, heap };
template<class T, int i, type t>
class Array {
private:
	typename std::conditional<t == stack, T[i], T*>::type data;

	long long size=i;
public:
	const type SoH = t;
	Array() {
		if constexpr (t == heap) {
			data = new T[i];
		}
		else {

		}
	}
	~Array() {
		if constexpr (t == heap) {
			delete[]data;
		}
		else {

		}
	}
	//const T& operator[](long long index) {
	//	if constexpr (t == heap) {
	//		return data[index];

	//	}
	//	else {
	//		return data[index];

	//	}

	//}
	const T& operator[](const long long index) {
		if constexpr (index > size|| index<0) {
			throw std::out_of_range("Index out of bounds");
		}
		if constexpr (t == heap) {
			return data[index];

		}
		else {
			return data[index];

		}

	}
	template<long long ind>
	const T& get() {
		if constexpr (ind > size || ind < 0) {
			throw std::out_of_range("Index out of bounds");
		}
		if constexpr (t == heap) {
			return data[ind];

		}
		else {
			return data[ind];

		}

	}

};

#endif // !_ARRAY
