/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleServer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:13:08 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 01:25:28 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimpleServer.hpp"

SNVAS::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklog)
{
	socket = new ListeningSocket(domain, service, protocol, port, interface, bklog);
}

SNVAS::ListeningSocket * SNVAS::SimpleServer::get_socket()
{
	return socket;
}