#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.name = "Lili";
	data.description = "very beautiful Yorkies";
	data.value = 42;
	std::cout << "--------------------------------" << std::endl;
	std::cout << data << std::endl;
	std::cout << "--------------------------------" << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw: " << raw << std::endl;
	std::cout << "--------------------------------" << std::endl;
	Data	*ptr = Serializer::deserialize(raw);
	std::cout << *ptr << std::endl;
	std::cout << "--------------------------------" << std::endl;

	return 0;
}
