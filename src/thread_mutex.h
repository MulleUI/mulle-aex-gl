/* Copyright 2024 Kinglet B.V.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef THREAD_MUTEX_H
#define THREAD_MUTEX_H

#include <mulle-core/mulle-core.h>

#ifdef __cplusplus
extern "C" {
#endif

struct thread_mutex
{
   mulle_thread_mutex_t   native_mutex_;
};

void   thread_mutex_init( struct thread_mutex *m);
void   thread_mutex_cleanup( struct thread_mutex *m);

/* Finalize initialization, including any allocation or construction that may fail.
 * Returns non-zero upon failure, zero upon success. */
int   thread_mutex_finish_initialization( struct thread_mutex *m);

void   thread_mutex_enter( struct thread_mutex *m);
void   thread_mutex_leave( struct thread_mutex *m);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* THREAD_MUTEX_H */
