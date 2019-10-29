#ifndef SKIPLIST_GLOBAL_H
#define SKIPLIST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SKIPLIST_LIBRARY)
#  define SKIPLIST_EXPORT Q_DECL_EXPORT
#else
#  define SKIPLIST_EXPORT Q_DECL_IMPORT
#endif

#endif // SKIPLIST_GLOBAL_H
