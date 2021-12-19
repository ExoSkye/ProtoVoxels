#pragma once

#include <nall/string.hpp>

#undef DEBUG
#undef ERROR

namespace ProtoVoxels::Logger {
    enum LogLevel {
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL_ERROR
    };

    void log(const nall::string& message, LogLevel level = LogLevel::INFO);
}