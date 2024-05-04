module;
#include <stacktrace>
export module module_that_uses_stacktrace;

export void log(std::stacktrace trace = std::stacktrace::current())
{
    
}
