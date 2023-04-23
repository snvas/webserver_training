/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConnectionSocket.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:04:51 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 01:48:10 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This class implements a call to the connect() function of sockets as a definition to the connect_to_network virtual function from SimpleSocket*/

#ifndef ConnectingSocket_hpp
#define ConnectingSocket_hpp

#include <stdio.h>
#include "SimpleSocket.hpp"

namespace SNVAS
{
class ConnectingSocket : public SimpleSocket
{
      public:
	// Constructor
	ConnectingSocket(int domain, int service, int protocol, int port,
		      u_long interface);
	// Virtual function from parent
	void connect_to_network(int sock, struct sockaddr_in address);
};
} // namespace SNVAS


#endif //* ConnectingSocket
