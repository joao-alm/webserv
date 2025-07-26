/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naiqing <naiqing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:59:01 by naiqing           #+#    #+#             */
/*   Updated: 2025/07/26 11:25:20 by naiqing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"
#include <cerrno>


int server::setup()
{
	this->_socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (this->_socketfd < 0) {
		std::cerr << "Error creating socket: " << strerror(errno) << std::endl;
		return -1;
	}

	//Listens on 0.0.0.0:8080 for IPv4 requests on all devices
	this->_addr.sin_family = AF_INET;// AF_INET->Address Family Internet & Set address family to IPv4
	this->_addr.sin_addr.s_addr = INADDR_ANY; // Bind to all available interfaces
	this->_addr.sin_port = htons(8080); // Set port number (e.g., 8080) and convert to network byte order big-endian
	
	// Bind the socket to the address and port
	//(struct sockaddr*)&sockaddr: pass the address information to the kernel
	if(bind(this->_socketfd, (struct sockaddr *)&this->_addr, sizeof(this->_addr)) < 0)
	{
		std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
		close(this->_socketfd);
		return -1;
	}

	// Listen for incoming connections, with a backlog of 100
	// The backlog is the maximum length of the queue of pending connections
	if(listen(this->_socketfd, 100) < 0) 
	{
		std::cerr << "Error listening on socket: " << strerror(errno) << std::endl;
		close(this->_socketfd);
		return -1;
	}
	
	return 0; // 
}

server::server()
{
}

server::~server()
{
}

server::server(const server &other)
{	
}
server &server::operator=(const server &other)
{
}

