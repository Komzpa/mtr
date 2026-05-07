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

#ifndef MTR_PRETTY_H
#define MTR_PRETTY_H

#include <stddef.h>

char *format_pretty_int(
    int value,
    int width,
    char *buf,
    size_t buf_len);

#endif
