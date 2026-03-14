#include "DX3D/Core/Logger.h"
#include <windows.h>
#include <sstream>
#include <iostream>
#include <string>


dx3d::Logger::Logger(LogLevel logLevel) : m_logLevel(logLevel)
{
	auto logString = "DirectXGame | C++ 3D Game Tutorial Series";
	auto dividerString = "-----------------------------------------";
	std::clog << logString << std::endl << dividerString << std::endl;
	std::wstringstream stream; // Use wstringstream for wide characters
	stream << logString << std::endl << dividerString << std::endl;
	OutputDebugString(stream.str().c_str());
}

void dx3d::Logger::log(LogLevel level, const char* message) const
{
	auto logLevelToString = [](LogLevel level)
	{
		switch (level)
		{
		case LogLevel::Error:
			return "Error";
		case LogLevel::Warning:
			return "Warning";
		case LogLevel::Info:
			return "Info";
		default:
			return "Unknown";
		}
	};

	if (level > m_logLevel)
		return;
	std::clog << "[DX3D " << logLevelToString(level) << "]: " << message << std::endl;
	std::wstringstream stream; // Use wstringstream for wide characters
	stream << "[DX3D " << logLevelToString(level) << "]: " << message << std::endl;
	OutputDebugString(stream.str().c_str());
}
