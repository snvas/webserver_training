/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:48:26 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 00:55:05 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimpleSocket.hpp"

// Default constructor
SNVAS::SimpleSocket::SimpleSocket(int domain, int service, int protocol,
				  int port, u_long interface)
{
	// define address structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interface);
	// define socket
	sock = socket(domain, service, protocol);
	test_connection(sock);
}

// test connection virtual function
void SNVAS::SimpleSocket::test_connection(int item_to_test)
{
	// check if the socket is connected
	if (item_to_test < 0)
	{
		perror("Failed to connect...");
		exit(EXIT_FAILURE);
	}
}

// Getter functions
struct sockaddr_in SNVAS::SimpleSocket::get_address()
{
	return address;
}

int SNVAS::SimpleSocket::get_sock()
{
	return sock;
}

// Setter functions
void SNVAS::SimpleSocket::set_connection(int con)
{
	sock = con;
}