#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

namespace mt
{

	enum class Level
	{
		DEBUG,
		INFO,
		WARN,
		ERROR
	};

	class LogSimple
	{
	private:
		static std::ofstream m_out;
		static Level m_level;

		static std::string CurrentTime()
		{
			// Получение текущего времени
			return "11:00:01";
		}

	public:
		/*Log(const std::string& filename)
		{
			m_out.open(filename);
		}*/
		static void SetLogLevel(Level level)
		{
			m_level = level;
		}
		static void SetLogFile(const std::string& filename)
		{
			m_out.open(filename);
		}
		static void Write(const std::string& message)
		{
			std::string tmp = CurrentTime() + " " + message;

			std::cerr << tmp << std::endl;
			m_out << tmp << std::endl;
		}
		static void Debug(const std::string& message)
		{
			if (m_level == Level::DEBUG)
			{
				std::string tmp = CurrentTime() + " [DEBUG] " + message;

				std::cerr << tmp << std::endl;
				//m_out << tmp << std::endl;
			}
		}
		static void Warn(const std::string& message)
		{
			std::string tmp = CurrentTime() + " \x1B[33m[WARN]\033[0m " + message;

			std::cerr << tmp << std::endl;
			m_out << tmp << std::endl;
		}
	};

	std::ofstream LogSimple::m_out;
	Level LogSimple::m_level;

	class LogExtra
	{
	private:
		std::stringstream m_ss;
		Level m_level;
	public:

		LogExtra(Level level) : m_level(level)
		{
		}

		~LogExtra()
		{
			if(m_level == Level::DEBUG)
				std::cerr << "[DEBUG] " << m_ss.str() << std::endl;
			else if(m_level == Level::WARN)
				std::cerr << "[WARN] " << m_ss.str() << std::endl;
		}

		template<typename T>
		LogExtra& operator<<(const T& t)
		{
			m_ss << t;
			return *this;
		}
	};
}

mt::LogExtra qDebug()
{
	return mt::LogExtra(mt::Level::DEBUG);
}

mt::LogExtra qWarn()
{
	return mt::LogExtra(mt::Level::WARN);
}