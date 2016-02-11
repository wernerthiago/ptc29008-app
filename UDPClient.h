/*
 * UDPClient.h
 *
 *  Created on: Dec 16, 2015
 *      Author: werner
 */

#ifndef UDPCLIENT_H_
#define UDPCLIENT_H_

#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

class UDPClient
{
public:
	UDPClient(
		boost::asio::io_service& io_service,
		const std::string& host,
		const std::string& port
	) : io_service_(io_service), socket_(io_service, udp::endpoint(udp::v4(), 0)) {
		udp::resolver resolver(io_service_);
		udp::resolver::query query(udp::v4(), host, port);
		udp::resolver::iterator iter = resolver.resolve(query);
		endpoint_ = *iter;
	}

	~UDPClient()
	{
		socket_.close();
	}

	void send(const std::string& msg) {
		socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
	}

	boost::array<std::string,10> recv(){
		boost::array<std::string,10> recv_buf;
		socket_.receive_from(boost::asio::buffer(recv_buf), sendponit_);
		return recv_buf;
	}

	udp::socket get_socket(){
		return this->socket_;
	}

private:
	boost::asio::io_service& io_service_;
	udp::socket socket_;
	udp::endpoint endpoint_;
	udp::endpoint sendponit_;
};

//To EXECUTE:
//boost::asio::io_service io_service;
//UDPClient client(io_service, "localhost", "1337");
//client.send("Hello, World!");

#endif /* UDPCLIENT_H_ */
