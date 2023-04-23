/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BindingSocket.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 22:48:46 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 00:57:53 by snovaes          ###   ########.fr       */
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
      private:
	// member variables - the binding variable store the value 0 if
	// successful
	int binding;
	// member function - virtual function from parent to establish binding

	void connect_to_network(int sock, struct sockaddr_in adress);
      public:
	// Constructor - parameterized constructor is required for this class
	BindingSocket(int domain, int service, int protocol, int port,
		      u_long interface);
	// Getters
	int get_binding();
};
} // namespace SNVAS

#endif