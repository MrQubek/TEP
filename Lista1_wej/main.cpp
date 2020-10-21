#include<iostream>

class Hello
{
private: 
	char *m_data;
public:
	Hello(int length) {
		m_data = new char[length+1];
		m_data[0] = (char)length;
	}

	~Hello() {
		delete[]m_data;
	}

	void set(const char* data, int length) {
		if ((int)m_data[0]>=length) {
			for (int i = 1; i <= length;i++) {
				m_data[i] = data[i-1];
			}
		}
	}

	void print() {
		for (int i = 1;i<= (int)m_data[0];i++) {
			std::cout <<(int)m_data[i]<<" ";
		}
	}

};

int main() {

	Hello h = Hello(6);
	h.set("Hello",5);
	h.print();
	return 0;
}