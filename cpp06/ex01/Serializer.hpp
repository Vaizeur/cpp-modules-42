#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

struct Data
{
	std::string name;
	std::string description;
	int			value;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &other);
		~Serializer();
		Serializer	&operator=(Serializer const &other);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};

std::ostream &operator<<(std::ostream &os, Data const &data);

#endif
