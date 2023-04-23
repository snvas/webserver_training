/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpleServer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:07:25 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 01:45:49 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SimpleServer_hpp
#define SimpleServer_hpp

#include <stdio.h>

#include "../snvaslib-networking.hpp"

namespace SNVAS
{
	class SimpleServer
	{
		private:
			ListeningSocket * socket;
			virtual void accepter() = 0;
			virtual void handler() = 0;
			virtual void responder() = 0;

		public:
			SimpleServer(int domain, int service, int protocol, int port, u_long interface, int bklog);
			virtual void launch() = 0;
			ListeningSocket * get_socket();
	};
}

#endif