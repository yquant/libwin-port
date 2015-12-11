/*
 * libwin-port - C library to bring some useful linux api to windows
 *
 * Copyright (C) 2015 yquant.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef _LIBWIN_PORT_INCL_DLFCN_H
#define _LIBWIN_PORT_INCL_DLFCN_H

#include "libwin_port_defs.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Following flags has no effects, the only support function is loading a shared
 * library and find symbol addresses within this loaded library.
*/
#define RTLD_LOCAL 0
#define RTLD_LAZY	1
#define RTLD_NOW	2
#define RTLD_GLOBAL	4

#define RTLD_DEFAULT 0
#define RTLD_NEXT 0

LIBWIN_PORT_EXPORT void* dlopen(const char *filename, int flag);
LIBWIN_PORT_EXPORT char* dlerror(void);
LIBWIN_PORT_EXPORT void* dlsym(void *handle, const char *symbol);
LIBWIN_PORT_EXPORT int dlclose(void *handle);

#ifdef __cplusplus
}
#endif

#endif // _LIBWIN_PORT_INCL_DLFCN_H