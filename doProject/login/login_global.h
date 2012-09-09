#ifndef LOGIN_GLOBAL_H
#define LOGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef LOGIN_LIB
# define LOGIN_EXPORT Q_DECL_EXPORT
#else
# define LOGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGIN_GLOBAL_H
