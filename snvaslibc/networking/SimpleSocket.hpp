/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:48:34 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/22 22:57:11 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

namespace SNVAS
{
class SimpleSocket
{
      private:
	struct sockaddr_in address;
	int sock;
	int connection;

      public:
	// Constructor
	SimpleSocket(int domain, int service, int protocol, int port,
		     u_long interface);
	// virtual function connect to a network
	virtual int connect_to_network(int sock,
				       struct sockaddr_in address) = 0;
	// Function to test sockets and connections
	void test_connection(int);
	struct sockaddr_in get_address();
	int get_sock();
	int get_connection();
	//Setter functions
	void set_connection(int domain);
};
} // namespace SNVAS