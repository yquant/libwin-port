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

#ifndef _LIBWIN_PORT_INCL_LIBWIN_PORT_DEFS_H
#define _LIBWIN_PORT_INCL_LIBWIN_PORT_DEFS_H

#if defined(USING_LIBWIN_PORT_SHARED)
  #if defined(LIBWIN_PORT_IMPLEMENTATION)
    #define LIBWIN_PORT_EXPORT __declspec(dllexport)
  #else
    #define LIBWIN_PORT_EXPORT __declspec(dllimport)
  #endif  // defined(LIBWIN_PORT_IMPLEMENTATION)
#else // defined(USING_LIBWIN_PORT_SHARED)
  #define LIBWIN_PORT_EXPORT extern
#endif

#endif // _LIBWIN_PORT_INCL_LIBWIN_PORT_DEFS_H