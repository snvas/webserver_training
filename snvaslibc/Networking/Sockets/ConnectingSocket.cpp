/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConnectingSocket.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:08:27 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/22 23:09:40 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ConnectionSocket.hpp"


// Constructor
SNVAS::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol,
				    int port, u_long interface)
    : SimpleSocket(domain, service, protocol, port, interface)
{
	set_connection(connect_to_network(get_sock(), get_address()));
	test_connection(get_connection());
}

//definition of connect_to_network virtual function
int SNVAS::ConnectingSocket::connect_to_network(int sock,
					     struct sockaddr_in address)
{
	return connect(sock, (struct sockaddr *)&address, sizeof(address));
}