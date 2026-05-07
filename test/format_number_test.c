/*
    mtr  --  a network diagnostic tool
    Copyright (C) 2026  Darafei Praliaskouski

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as
    published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "config.h"

#include <stdio.h>
#include <string.h>

#include "ui/pretty.h"


struct testcase {
    int value;
    const char *expected;
};


static int check_case(
    const struct testcase *testcase)
{
    char buf[32];

    format_pretty_int(testcase->value, 5, buf, sizeof(buf));
    if (strcmp(buf, testcase->expected) != 0) {
        fprintf(stderr, "%d formatted as '%s', expected '%s'\n",
                testcase->value, buf, testcase->expected);
        return 1;
    }

    if (strlen(buf) != 5) {
        fprintf(stderr, "%d formatted to %zu characters: '%s'\n",
                testcase->value, strlen(buf), buf);
        return 1;
    }

    return 0;
}


int main(
    void)
{
    static const struct testcase testcases[] = {
        {0, "    0"},
        {99999, "99999"},
        {100000, " 100k"},
        {999499, " 999k"},
        {999500, "1.00M"},
        {1000000, "1.00M"},
        {1010000, "1.01M"},
        {9994999, "9.99M"},
        {9995000, "10.0M"},
        {99949999, "99.9M"},
        {99950000, " 100M"},
        {999499999, " 999M"},
        {999500000, "1.00G"},
        {2147483647, "2.15G"}
    };
    size_t i;

    for (i = 0; i < sizeof(testcases) / sizeof(testcases[0]); i++) {
        if (check_case(&testcases[i]) != 0)
            return 1;
    }

    return 0;
}
