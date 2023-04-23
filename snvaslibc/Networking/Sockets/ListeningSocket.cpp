/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListeningSocket.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:13:44 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 00:34:05 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ListeningSocket is a child of BindingSocket, specifying that once bound, the
* socket is to listen to the network on the given port for incoming connections*/

#include "ListeningSocket.hpp"

//Constructor
SNVAS::ListeningSocket::ListeningSocket(int domain, int service, int protocol,
					int port, u_long interface, int bklog)
    : BindingSocket(domain, service, protocol, port, interface)
{
	backlog = bklog;
	start_listening();
	test_connection(listening);
}

//Mutators
void SNVAS::ListeningSocket::start_listening()
{
	listening = listen(get_sock(), backlog);
}

//Getters
int SNVAS::ListeningSocket::get_listening()
{
	return listening;
}

int SNVAS::ListeningSocket::get_backlog()
{
	return backlog;
}

