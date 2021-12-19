#include <ProtoVoxels/logger/Logger.hpp>

namespace ProtoVoxels::Logger {
    void log(const nall::string& message, LogLevel level) {
        nall::string output;
        switch (level) {
            case LogLevel::DEBUG:
                output.append(nall::string("[DEBUG] "));
                break;
            case LogLevel::INFO:
                output.append(nall::string("[INFO] "));
                break;
            case LogLevel::WARN:
                output.append(nall::string("[WARN] "));
                break;
            case LogLevel::ERROR:
                output.append(nall::string("[ERROR] "));
                break;
            case LogLevel::FATAL_ERROR:
                output.append(nall::string("[FATAL ERROR] "));
                break;
        }

        output.append(message);
        output.append("\n");

        nall::print(output);
    }
}