#include <iostream>

class DynamicString {
public:
	DynamicString() : m_data{nullptr}, m_size{0} {}

	explicit DynamicString(const char *str) : DynamicString{} {
		if (str == nullptr)
			return;
		// First need to check the length of the [str]
		size_t length = std::strlen(str);
		if (!length)
			return;
		// Now we need to allocate memory for the [length] symbols
		m_data = new char[length + 1]; // one more symbol for the zero-termination
		// And now we can copy all symbols from the [str] to the our memory;
		for (size_t i = 0; i < length; ++i) {
			m_data[i] = str[i];
		}
		// Add one more symbol for the zero-termination
		m_data[length] = '\0';
		// Set a correct [m_size] value
		m_size = length;
	}

	// Copy ctor
	DynamicString(const DynamicString &other) : DynamicString{other.data()} {
		std::cout << "DynamicString(const DynamicString&)" << std::endl;
	}

	// Move ctor
	DynamicString(DynamicString&& other) : DynamicString{} {
		swap(other);
	}

	~DynamicString() {
		delete[] m_data;
		std::cout << "~DynamicString" << std::endl;
	}

	size_t size() const { return m_size; }
	char *data() const { return m_data; }

	// Copy assignment operator
	DynamicString& operator=(const DynamicString& rhs) {
		std::cout << "DynamicString::operator=(const DynamicString&)" << std::endl;
		DynamicString temp{rhs};
		swap(temp);
		
		return *this;
	}

	// Move assignment operator
	DynamicString& operator=(DynamicString&& rhs) {
		std::cout << "DynamicString::operator=(DynamicString&&)" << std::endl;
		swap(rhs);

		return *this;
	}

	DynamicString &operator+=(const char *str) {
		if (str == nullptr)
			return *this;
		// First check the length of the [str]
		size_t length = std::strlen(str);
		if (!length)
			return *this;

		// Allocate new memory region with size = [length] + [m_size]
		char *new_memory = new char[length + m_size + 1];

		// Copy first old symbols - from the old memory
		for (size_t i = 0; i < m_size; ++i) {
			new_memory[i] = m_data[i];
		}
		// Copy next all symbols from the [str]
		for (size_t i = 0; i < length; ++i) {
			new_memory[m_size + i] = str[i];
		}
		// Add one more symbol for zero termination
		new_memory[m_size + length] = '\0';

		// delete old memory region
		delete[] m_data;

		// Assign new memory region and size
		m_data = new_memory;
		m_size = m_size + length;

		return *this;
	}

	DynamicString &operator+=(const DynamicString &str) {
		return *this += str.data();
	}

private:
	void swap(DynamicString &rhs) {
		char * ptr = m_data;
		m_data = rhs.m_data;
		rhs.m_data = ptr;
		
		size_t size = m_size;
		m_size = rhs.m_size;
		rhs.m_size = size;
	}

	char *m_data;
	size_t m_size;
};

void example() {

	const size_t count = 3;
	DynamicString array[3];

	for (size_t i = 0; i < count; ++i) {
		DynamicString full_name;
		// enter you first name, please
		full_name += "First ";
		// enter you middle name, please
		full_name += "Middle ";
		// enter you last name, please
		full_name += "Third";
		array[i] = full_name;
	}

	std::cout << "We have next employes:" << std::endl;
	for (size_t i = 0; i < count; ++i) {
		std::cout << array[i].data() << std::endl;
	}

}

int main() {
	example();
	return 0;
}