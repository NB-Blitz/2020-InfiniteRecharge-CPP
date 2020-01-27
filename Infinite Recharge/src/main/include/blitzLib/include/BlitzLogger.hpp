/*
 * BlitzLogger.hpp
 *
 *  Created on: Aug 5, 2017
 *      Author: Sam
 */

//DEPRICATED because IDK how the hell it works or if it works

#pragma once

#include <iostream>
#include <fstream>

namespace Blitz
{
	class BlitzLogger
	{
	public :
		BlitzLogger(int logLevel);

		//Variables
		FILE * logfile;

		int logLevel = 0;

		//Non-logging functions
		void init();
		std::string getTimeStamp();
		std::string getTicksElapsed();
		std::string spaceToUnderscore(std::string input);
		void close();

		//Logging Functions
		void log(std::string currentStage, std::string level, std::string message);
		void info(std::string currentStage, std::string message);
		void debug(std::string currentStage, std::string message);
		void warning(std::string currentStage, std::string message);
		void error(std::string currentStage, std::string message);
		void trace(std::string currentStage, std::string message);

		enum Stage
		{
			Auto = 0,
			Tele = 1
		};

		enum LogLevel
		{
			Error = 0,
			Warning = 1,
			Info = 2,
			Debug = 3,
			Trace = 4
		};
	};
}