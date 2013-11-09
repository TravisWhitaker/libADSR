// libadsr Copyright (C) Travis Whitaker Stephen Demos 2013

#ifndef ADSR_DEBUG_H
#define ADSR_DEBUG_H

#ifdef DEBUG_MSG_ENABLE
#define DEBUG_MSG(msg) printf("libadsr: %s:%d: %s: %s\n", __FILE__, __LINE__, __func__, msg)
#else
#define DEBUG_MSG(ignore) ((void) 0)
#endif

#endif
