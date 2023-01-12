#include <stdio.h>
#include <stdarg.h>
#include <iostream>

#include "log4cpp/Category.hh"
#include "log4cpp/Appender.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Layout.hh"
//#include "log4cpp/BasicLayout.hh"
#include <log4cpp/PatternLayout.hh>
#include "log4cpp/Priority.hh"
#include "log4cpp/NDC.hh"

#include "logger.h"

log4cpp::Category* g_logger;

static log4cpp::Appender* appender;

static bool s_logger_initialized = false;

int g_debug_level = 10;

void logInit(int level, std::ostream& fout)
{
    /*log4cpp::PatternLayout* pLayout2 = new log4cpp::PatternLayout();
    pLayout2->setConversionPattern("[%d] %p %c %x: %m%n");


    log4cpp::RollingFileAppender* rollfileAppender = new log4cpp::RollingFileAppender(
        "rollfileAppender", log_file, log_size, 1);
    rollfileAppender->setLayout(pLayout2);


    root.addAppender(rollfileAppender);*/

    g_debug_level = level;

    appender = new log4cpp::OstreamAppender("default", &fout);

    log4cpp::PatternLayout* playout = new log4cpp::PatternLayout();
    playout->setConversionPattern("[%d{%Y-%m-%d %H:%M:%S:%l}]%p: %m%n");

    //appender->setLayout(new log4cpp::BasicLayout());
    appender->setLayout(playout);
	
    g_logger = &log4cpp::Category::getRoot();
    g_logger->setPriority(log4cpp::Priority::DEBUG);
    g_logger->setAppender(appender);
}

void logSetDbgLevel(int level)
{
    g_debug_level = level;
}
