/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BindingSocket.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:48:39 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/22 23:00:10 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BindingSocket.hpp"

// Constructor
SNVAS::BindingSocket::BindingSocket(int domain, int service, int protocol,
				    int port, u_long interface)
    : SimpleSocket(domain, service, protocol, port, interface)
{
	set_connection(connect_to_network(get_sock(), get_address()));
	test_connection(get_connection());
}

//definition of connect_to_network virtual function
int SNVAS::BindingSocket::connect_to_network(int sock,
					     struct sockaddr_in address)
{
	return bind(sock, (struct sockaddr *)&address, sizeof(address));
}