/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestServer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snovaes <snovaes@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 01:26:15 by snovaes           #+#    #+#             */
/*   Updated: 2023/04/23 01:47:19 by snovaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TestServer_hpp
#define TestServer_hpp

#include "SimpleServer.hpp"
#include <stdio.h>
#include <unistd.h>
#include <cstring>

namespace SNVAS
{
class TestServer : public SimpleServer
{
      private:
	char buffer[30000] = {0};
	int new_socket;
	void accepter();
	void handler();
	void responder();

      public:
	TestServer();
	void launch();
};
} // namespace SNVAS

#endif /* TestServer_hpp */