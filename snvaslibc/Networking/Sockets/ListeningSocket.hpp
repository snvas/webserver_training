/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ListeningSocket.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 23:13:51 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 00:33:26 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ListeningSocket_hpp
#define ListeningSocket_hpp

#include "BindingSocket.hpp"
#include <stdio.h>

namespace SNVAS
{

class ListeningSocket : public BindingSocket
{
      private:
	int backlog;
	int listening;

      public:
	ListeningSocket(int domain, int service, int protocol, int port,
			u_long interface, int bklog);
	void start_listening();
	int get_listening();
	int get_backlog();
};
} // namespace SNVAS

#endif