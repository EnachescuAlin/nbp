/*
No Bugs in Production (NBP)
https://github.com/aenachescu/nbp

Licensed under the MIT License <http://opensource.org/licenses/MIT>.
SPDX-License-Identifier: MIT
Copyright (c) 2019-2020 Alin Enachescu <https://github.com/aenachescu>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef NBP_PRIVATE_UTILS_COMPILER_H
#define NBP_PRIVATE_UTILS_COMPILER_H

#define NBP_MAYBE_UNUSED_PARAMETER

#ifdef NBP_COMPILER_GCC

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_GCC

#ifdef NBP_COMPILER_CLANG

#undef NBP_MAYBE_UNUSED_PARAMETER
#define NBP_MAYBE_UNUSED_PARAMETER __attribute__ ((unused))

#endif // end if NBP_COMPILER_CLANG

#endif // end if NBP_PRIVATE_UTILS_COMPILER_H
