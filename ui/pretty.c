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

#include "pretty.h"


char *format_pretty_int(
    int value,
    int width,
    char *buf,
    size_t buf_len)
{
    long long rounded;

    if (value < 0 || width != 5) {
        snprintf(buf, buf_len, "%*d", width, value);
    } else if (value < 100000) {
        snprintf(buf, buf_len, "%5d", value);
    } else if (value < 999500) {
        rounded = (value + 500) / 1000;
        snprintf(buf, buf_len, "%4lldk", rounded);
    } else if (value < 9995000) {
        rounded = (value + 5000) / 10000;
        snprintf(buf, buf_len, "%lld.%02lldM", rounded / 100, rounded % 100);
    } else if (value < 99950000) {
        rounded = (value + 50000) / 100000;
        snprintf(buf, buf_len, "%2lld.%lldM", rounded / 10, rounded % 10);
    } else if (value < 999500000) {
        rounded = (value + 500000) / 1000000;
        snprintf(buf, buf_len, "%4lldM", rounded);
    } else {
        rounded = ((long long) value + 5000000) / 10000000;
        snprintf(buf, buf_len, "%lld.%02lldG", rounded / 100, rounded % 100);
    }

    return buf;
}
