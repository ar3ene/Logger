#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "log4cpp\Category.hh"

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

extern int g_debug_level;
extern log4cpp::Category* g_logger;

extern void logInit(int level, std::ostream& fout);
extern void logSetDbgLevel(int level);

#define LOG_ERROR(x, ...) g_logger->error(x, __VA_ARGS__)
#define LOG_ALERT(x, ...) g_logger->alert(x, __VA_ARGS__)
#define LOG_INFO(x, ...)  g_logger->info(x, __VA_ARGS__)
#define LOG_DEBUG(level, fmt, ...) \
			if (level <= g_debug_level) { \
				g_logger->debug(fmt, __VA_ARGS__); \
			}

#endif