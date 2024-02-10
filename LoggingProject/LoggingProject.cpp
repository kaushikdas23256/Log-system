#include <iostream>
#include "Log.h"

int main() {
	Logger::log(Logger::LogLevel::DEBUG, "DEBUG MESSAGE", std::cout);
	Logger::log(Logger::LogLevel::INFO, "INFO MESSAGE", std::cout);
	Logger::log(Logger::LogLevel::WARNING, "WARNING MESSAGE", std::cout);
	Logger::log(Logger::LogLevel::ERROR, "ERROR MESSAGE", std::cerr);
	Logger::log(Logger::LogLevel::CRITICAL, "CRITICAL MESSAGE", std::cerr);

	return 0;
}
