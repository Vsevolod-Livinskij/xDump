#include <cstdint>
#include <string>

#include <error_handler.h>

namespace xDump {
    uint32_t errorHandler::fatalCount = 0;
    errorHandler::Severity errorHandler::defaultSeverity = errorHandler::warning;

void errorHandler::reportError(QString message, Severity severity, const char* file, uint64_t line)
{
    QString buffer = "";
    switch (severity) {
        case debug:
            buffer += "Debug";
            break;
        case warning:
            buffer += "Warning";
            break;
        case fatal:
            buffer += "Fatal error";
            fatalCount++;
            break;
        case internal:
            buffer += "Internal error";
            break;
        case maxSeverity:
            buffer += "You can't specify maxSeverity at source";
            break;
        default:
            buffer += "You should specify severity!";
            break;
    }
    buffer += ": '" + message + "' in file " + QString(file) + " at line " + QString::number(line);

    if (severity < defaultSeverity)
        return;
    qDebug(buffer.toLatin1());
    if (severity >= internal)
        exit(0);
}

void errorHandler::checkState()
{
    if (fatalCount > 0)
        exit(0);
}
}

