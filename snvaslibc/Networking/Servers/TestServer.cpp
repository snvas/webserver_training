/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestServer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:29:47 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 01:46:35 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TestServer.hpp"

SNVAS::TestServer::TestServer()
    : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10)
{
	launch();
}

void SNVAS::TestServer::accepter()
{
	struct sockaddr_in address = get_socket()->get_address();
	int addrlen = sizeof(address);
	new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address,
			    (socklen_t *)&addrlen);
	read(new_socket, buffer, 30000);
}

void SNVAS::TestServer::handler()
{
	std::cout << buffer << std::endl;
}

void SNVAS::TestServer::responder()
{
	char *hello = "hello form server";
	write(new_socket, hello, strlen(hello));
	close(new_socket);
}

void SNVAS::TestServer::launch()
{
	while (true)
	{
		std::cout << "====== WAITING ========" << std::endl;
		accepter();
		handler();
		responder();
		std::cout << "====== DONE ======" << std::endl;
	}
}