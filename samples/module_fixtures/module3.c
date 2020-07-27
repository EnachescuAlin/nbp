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

#include <nbp.h>

NBP_MODULE(module3)
{
    NBP_MODULE_USE_SETUP(module3_setup2);
    NBP_MODULE_USE_TEARDOWN(module3_teardown2);

    NBP_MODULE_RUN(submodule5);
    NBP_MODULE_RUN(submodule6);
    NBP_MODULE_RUN(submodule7);
    NBP_MODULE_RUN(submodule8);

    NBP_MODULE_USE_SETUP(NBP_MODULE_NO_SETUP);
    NBP_MODULE_USE_TEARDOWN(NBP_MODULE_NO_TEARDOWN);

    NBP_MODULE_RUN(submodule9);
    NBP_MODULE_RUN(submodule10);

    NBP_MODULE_RESET_SETUP();
    NBP_MODULE_RESET_TEARDOWN();

    NBP_MODULE_RUN(submodule11);
    NBP_MODULE_RUN(submodule12);
}