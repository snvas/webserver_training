/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:48:34 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 01:03:02 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <iostream>

namespace SNVAS
{
class SimpleSocket
{
      private:
	/*Member variables*/
	// Once instantiated, sock contains the address of a socket object on
	// the network.
	// this should be a non-negative number
	int sock;
	// The address variable is a struct that contains information about the
	// protocol, type and interface of a given socket. These parameters are
	// specified and set in the constructor
	struct sockaddr_in address;

      public:
	// Constructor
	SimpleSocket(int domain, int service, int protocol, int port,
		     u_long interface);
	// virtual function connect to a network
	virtual void connect_to_network(int sock,
					struct sockaddr_in address) = 0;
	// Function to test sockets and connections
	void test_connection(int);
	// Getters
	int get_sock();
	struct sockaddr_in get_address();
	void set_connection(int domain);

};
} // namespace SNVAS

#endif