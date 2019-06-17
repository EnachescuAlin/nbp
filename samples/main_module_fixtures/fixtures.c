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

#include <nbp.h>
#include <stdio.h>

void write_message_to_file(const char *msg)
{
    FILE *fp = fopen("output.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s", msg);
        fclose(fp);  
    }
}

NBP_SETUP_MODULE(setupMainModule)
{
    write_message_to_file("setup");
}

NBP_TEARDOWN_MODULE(teardownMainModule)
{
    write_message_to_file("teardown");
}