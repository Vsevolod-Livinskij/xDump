#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <cstdint>
#include <string>

#include <QString>

namespace xDump {

class errorHandler
{
public:
    enum Severity
    {
        debug,
        warning,
        fatal,
        internal,
        maxSeverity
    };

    // Print error or update internal state
    static void reportError (QString message, Severity severity, const char* file = "", uint64_t line = 0);
    // Abort execution if we have non-zero number of fatal errors
    static void checkState ();

private:
    static uint32_t fatalCount;
    static Severity defaultSeverity;
};

}
#endif // ERROR_HANDLER_H