#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>

// TCP/IP  네트워킹 맛보기 (Boost.asio Socket IOStream

using boost::asio::ip::tcp;

/*
	- tcp : 주고 받고를 명확하게 확인 합니다.
	- udp : 
*/

int main()
{
	// 네트워크의 경우 불안정한 상황이 많기 때문에 try, catch를 사용합니다.
	try
	{
		boost::asio::io_service io_service;
		                      // v4 : version, 13 : port
		tcp::endpoint endpoint(tcp::v4(), 13); 
		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Sercer started" << std::endl;
		
		for (;;)	//while(true)
		{
			const std::string message_to_send = "Hello From Server";

			boost::asio::ip::tcp::iostream stream;

			std::cout << "check 1" << std::endl;

			boost::system::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec);
		
			std::cout << "check 2" << std::endl;

			// 아래의 의미는 클라이언트가 접속이 됬다면
			if (!ec) // TODO : How to take care of multiple clients? Multi-threading?
			{
				//receive message from client
				std::string line;
				std::getline(stream, line);
				std::cout << line << std::endl;

				// send message to client
				stream << message_to_send;
				stream << std::endl;	//send std::endl to end getline of client
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}