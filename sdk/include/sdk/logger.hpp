#ifndef SDK_LOGGER_HPP
#define SDK_LOGGER_HPP

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <windows.h>

namespace sdk {
    class logger {
    public:
        explicit logger(const char* name) : mName(name) {}
        ~logger() = default;

        enum level : uint8_t {
            l_none,
            l_info,
            l_warn,
            l_error,
            l_debug
        };

        void error(const char* message, auto... data) const {
            if (!is_level_enabled(l_error))
                return;

            set_console_color(FOREGROUND_RED);
            labelled_print(mName + "/ERROR", message, data...);
            reset_console_color();
        }

        void warn(const char* message, auto... data) const {
            if (!is_level_enabled(l_warn))
                return;

            set_console_color(FOREGROUND_RED | FOREGROUND_GREEN);
            labelled_print(mName + "/WARN", message, data...);
            reset_console_color();
        }

        void info(const char* message, auto... data) const {
            if (!is_level_enabled(l_info))
                return;

            reset_console_color();
            labelled_print(mName + "/INFO", message, data...);
        }

        void debug(const char* message, auto... data) const {
            if (!is_level_enabled(l_debug))
                return;

            set_console_color(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            labelled_print(mName + "/DEBUG", message, data...);
            reset_console_color();
        }

        static void enable_global_level(level l) {
            gLevel |= ~l;
        }

        void enable_level(level l) {
            mLevel |= ~l;
        }

        bool is_level_enabled(level l) const {
            return gLevel >= l || mLevel >= l;
        }
    private:
        static void set_console_color(int color) {
            const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, color);
        }

        static void reset_console_color() {
            set_console_color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        static void labelled_print(std::string_view label, const char* message, ...) {
            std::ostringstream buffer;
            std::time_t t = std::time(nullptr);
             std::tm tm = *std::localtime(&t);
            buffer << std::put_time(&tm, "%a %b %d %H:%M:%S %Y");

            printf("[%s %s] ", buffer.str().data(), label.data());
            va_list args;
            va_start(args, message);
            vprintf(message, args);
            va_end(args);
            printf("\n");
        }

        const std::string mName;
        uint8_t mLevel = l_error;
        static inline uint8_t gLevel = l_error;
    };
}

#endif //SDK_LOGGER_HPP
