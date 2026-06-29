#ifndef MUTANT_STACK_TPP
# define MUTANT_STACK_TPP
# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) {
	*this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &other) {
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin() {
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end() {
	return this->c.end();
}

#endif
