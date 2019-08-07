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

#ifndef NBP_PRIVATE_CHECK_COMPILE_FLAGS_H
#define NBP_PRIVATE_CHECK_COMPILE_FLAGS_H

/*
 * Make sure there is only one OS defined
 */
#undef NBP_PRIVATE_OS_TYPE

#ifdef NBP_OS_LINUX
#define NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_LINUX

#ifdef NBP_OS_WINDOWS
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_WINDOWS

#ifdef NBP_OS_MAC
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_MAC

#ifdef NBP_OS_CUSTOM
#ifndef NBP_PRIVATE_OS_TYPE
#define NBP_PRIVATE_OS_TYPE
#else // NBP_PRIVATE_OS_TYPE not defined
#error "More NBP_OS_* macros are defined"
#endif // end if NBP_PRIVATE_OS_TYPE
#endif // end if NBP_OS_CUSTOM

#ifndef NBP_PRIVATE_OS_TYPE
#error "Unknown OS"
#endif // end if NBP_PRIVATE_OS_TYPE

#undef NBP_PRIVATE_OS_TYPE

/*
 * Make sure there is only one defined scheduler
 */
#undef NBP_PRIVATE_SCHEDULER_TYPE

#ifdef NBP_CUSTOM_SCHEDULER
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_CUSTOM_SCHEDULER

#ifdef NBP_MT_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_MT_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_MT_SUPPORT
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_MT_SCHEDULER

#ifdef NBP_SCHEDULER
#ifdef NBP_PRIVATE_SCHEDULER_TYPE
#error "Cannot enabe NBP_SCHEDULER because another scheduler is enabled"
#else // NBP_PRIVATE_SCHEDULER_TYPE not defined
#define NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE
#endif // end if NBP_SCHEDULER

/*
 * If no scheduler is defined then define the default scheduler
 */
#ifndef NBP_PRIVATE_SCHEDULER_TYPE
#define NBP_SCHEDULER
#endif // end if NBP_PRIVATE_SCHEDULER_TYPE

#undef NBP_PRIVATE_SCHEDULER_TYPE

/*
 * If no printer is defined then enable NBP_MT_PRINTER when NPB_MT_SUPPORT
 * is enabled or enable NBP_PRINTER when NBP_MT_SUPPORT is disabled
 */
#ifndef NBP_CUSTOM_PRINTER
#if !defined NBP_MT_PRINTER && !defined NBP_PRINTER
#ifdef NBP_MT_SUPPORT
#define NBP_MT_PRINTER
#else // NBP_MT_SUPPORT not defined
#define NBP_PRINTER
#endif // end if NBP_MT_SUPPORT
#endif // end if ! NBP_MT_PRINTER && ! NBP_PRINTER
#endif // end if NBP_CUSTOM_PRINTER

#endif // end if NBP_PRIVATE_CHECK_COMPILE_FLAGS_H