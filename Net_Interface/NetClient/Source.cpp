#include<olc_net.h>

int main()
{
	Message_Net message(type_message::type1);
	int a = 8;
	bool b = true;
	float c = 3.14159f;

	message << a << b << c;
	 
	std::cout << message.get_size_message();

}