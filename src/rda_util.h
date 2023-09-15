/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda_util.h - Miscellaneous helpers

   Copyright (C) 2023 Mihai Moldovan <ionic@ionic.de>
   All rights reserved.

   The RDA Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The RDA Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the Mate Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
   Boston, MA 02110-1301, USA.
 */

#ifndef RDA_UTIL_H
#define RDA_UTIL_H

#include <glib.h>

G_BEGIN_DECLS

#define static_arr_size(arr) (sizeof(arr) / sizeof(*arr))

G_END_DECLS

#endif /* RDA_UTIL_H */
