/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BindingSocket.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:48:46 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/22 23:07:49 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This class implements a call to the bind() function fo sockets as a definition
 * of the connect_to_network virtual function from SimpleSocket*/

#ifndef BindingSocket_hpp
#define BindingSocket_hpp

#include "SimpleSocket.hpp"
#include <stdio.h>

namespace SNVAS
{
class BindingSocket : public SimpleSocket
{
      public:
	// Constructor
	BindingSocket(int domain, int service, int protocol, int port,
		      u_long interface);
	// Virtual function from parent
	int connect_to_network(int sock, struct sockaddr_in address);
};
} // namespace SNVAS

#endif