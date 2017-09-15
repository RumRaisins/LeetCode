

template <typename T>
struct my_less{
	bool operator ()(const T& a , const T& b) {
		return a > b;
	}
};



