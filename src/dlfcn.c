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

#include <stdio.h>
#define PSAPI_VERSION 1
#include <windows.h>
#include <psapi.h>
#include <wchar.h>

#include "dlfcn.h"

static int has_error = 0;
static char error_buf[256];

static void save_error()
{
  DWORD dwError = GetLastError();
  FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                 NULL,
                 dwError,
                 MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                 error_buf,
                 sizeof(error_buf),
                 NULL);
  has_error = 1;
}

void* dlopen(const char *filename, int flag)
{
  HMODULE hModule;

  UINT uMode = SetErrorMode(SEM_FAILCRITICALERRORS);

  if (filename == NULL) {
    hModule = GetModuleHandle(NULL);
  } else {
    hModule = LoadLibraryExA(filename, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
  }

  if (hModule == NULL) {
    save_error();
  }
  
  SetErrorMode(uMode);

  return (void*)hModule;
}

char* dlerror(void)
{
  if (has_error) {
    has_error = 0;
    return error_buf;
  }
  return NULL;
}

void* dlsym(void *handle, const char *symbol)
{
  FARPROC ptr = GetProcAddress((HMODULE)handle, (LPCSTR)symbol);
  if (ptr == NULL) {
    save_error();
  }
  return (void*)ptr;
}

int dlclose(void *handle)
{
  HMODULE hModule = (HMODULE)handle;

  if (!FreeLibrary(hModule)) {
    save_error();
    return -1;
  }

  return 0;
}
