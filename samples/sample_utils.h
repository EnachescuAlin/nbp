/*
No Bugs in Production (NBP)
Copyright (C) 2019-present Alin Enachescu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef NBP_SAMPLE_UTILS
#define NBP_SAMPLE_UTILS

#include <stdio.h>

static inline void write_message_to_file(const char* msg)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s\n", msg);
        fclose(fp);
    }
}

static inline void write_message_to_file_2(const char* msg1, const char* msg2)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s %s\n", msg1, msg2);
        fclose(fp);
    }
}

#ifdef NBP_OS_LINUX

#include <unistd.h>
#include <semaphore.h>

#define SAMPLE_FORCE_SLEEP_MS(ms) usleep(ms * 1000)

/*
 * Semaphore wrapper
 */

#define SAMPLE_SEMAPHORE_TYPE sem_t

#define SAMPLE_SEMAPHORE_DEFAULT_VALUE { .__align = 0 }

#define SAMPLE_SEMAPHORE_INIT(sem)                                             \
    sem_init(&sem, 0, 0) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_UNINIT(sem)                                           \
    sem_destroy(&sem) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_WAIT(sem)                                             \
    sem_wait(&sem) == 0 ? 0 : 1

#define SAMPLE_SEMAPHORE_RELEASE(sem)                                          \
    sem_post(&sem) == 0 ? 0 : 1

/*
 * Atomic unsigned int wrapper
 */

#define SAMPLE_ATOMIC_UINT_TYPE unsigned int

#define SAMPLE_ATOMIC_UINT_INIT(val) val

#define SAMPLE_ATOMIC_UINT_LOAD(ptr)                                           \
    __atomic_load_n((ptr), __ATOMIC_SEQ_CST)

#define SAMPLE_ATOMIC_UINT_STORE(ptr, val)                                     \
    __atomic_store_n((ptr), val, __ATOMIC_SEQ_CST)

#define SAMPLE_ATOMIC_UINT_ADD_AND_FETCH(ptr, value)                           \
    __sync_add_and_fetch((ptr), (value))

#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS

#include <Windows.h>
#define SAMPLE_FORCE_SLEEP_MS(ms) Sleep(ms)

#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#error "Not supported"
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#error "Not supported"
#endif // end if NBP_OS_CUSTOM

#ifdef SAMPLE_DISABLE_SLEEP
#define SAMPLE_SLEEP()
#else // SAMPLE_DISABLE_SLEEP not defined
#define SAMPLE_SLEEP() SAMPLE_FORCE_SLEEP_MS(200)
#endif // end if SAMPLE_DISABLE_SLEEP

#endif // end if NBP_SAMPLE_UTILS
