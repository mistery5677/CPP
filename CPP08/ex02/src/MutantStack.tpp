#pragma once

template<typename T>
MutantStack<T>::MutantStack(){
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy){
    *this = copy;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& src){
    this->c = src.c;
	return  *this;
}

template<typename T>
MutantStack<T>::~MutantStack(){
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}