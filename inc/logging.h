#ifndef SIMILE_LOGGING_H
#define SIMILE_LOGGING_H

typedef int simile_LoggerID;

typedef enum simile_LogLevel {
    simile_LLDBG = 1 << 0, //!< Debug
    simile_LLINF = 1 << 1, //!< Information
    simile_LLWRN = 1 << 2, //!< Warning
    simile_LLERR = 1 << 3, //!< Error
    simile_LLCRT = 1 << 4  //!< Critical
} simile_LogLevel;

typedef struct {
    
} simile_Logger;

#ifdef DEBUG

#define simile_log_debug(fmt, ...)

#else

#define simile_log_debug(fmt, ...)

#endif

#endif
