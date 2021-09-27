#ifndef PROTOBETTER_DYNAMIC_LIB_GLOBAL_H
#define PROTOBETTER_DYNAMIC_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PROTOBETTER_DYNAMIC_LIB_LIBRARY)
#  define PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT Q_DECL_EXPORT
#elif defined(PROTOBETTER_DYNAMIC_LIB_OBJECT)
#  define PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT
#else
#  define PROTOBETTER_DYNAMIC_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#ifdef __GNUC__
#  define UNUSED(x) UNUSED_ ## x __attribute__((__unused__))
#else
#  define UNUSED(x) UNUSED_ ## x
#endif

#ifdef __GNUC__
#  define UNUSED_FUNCTION(x) __attribute__((__unused__)) UNUSED_ ## x
#else
#  define UNUSED_FUNCTION(x) UNUSED_ ## x
#endif

#endif // PROTOBETTER_DYNAMIC_LIB_GLOBAL_H
