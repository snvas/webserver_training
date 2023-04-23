#include "ListeningSocket.hpp"
#include <iostream>

int main(){
	std::cout << "Starting..." << std::endl;
	std::cout << "Binding Socket..." << std::endl;
	SNVAS::BindingSocket bs = SNVAS::BindingSocket(AF_INET, SOCK_STREAM, 0, 81, INADDR_ANY);
	std::cout << "Listening Socket..." << std::endl;
	SNVAS::ListeningSocket ls = SNVAS::ListeningSocket(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10);
	std::cout << "Success!" << std::endl;
}