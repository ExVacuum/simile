#ifndef SIMILE_LOGGING_H
#define SIMILE_LOGGING_H

typedef enum {

} simile_LogLevel;

typedef struct {

} simile_Logger;

#ifdef DEBUG

#define simile_log_debug(fmt, ...)

#else

#define simile_log_debug(fmt, ...)

#endif

#endif
