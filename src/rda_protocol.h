/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda_protocol.h - Generic protocol support for remote sessions

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
   Boston, MA  02110-1301, USA.
 */

#ifndef RDA_PROTOCOL_H
#define RDA_PROTOCOL_H

#include <glib.h>

G_BEGIN_DECLS

typedef enum {
	RDA_PROTOCOL_UNKNOWN = 0,
	RDA_PROTOCOL_NONE,
	RDA_PROTOCOL_VNC,
	RDA_PROTOCOL_RDP,
	RDA_PROTOCOL_NX,
	RDA_PROTOCOL_KDRIVE,
	RDA_PROTOCOL_MAX,
} rda_protocol_t;

extern rda_protocol_t
rda_protocol;

guint
rda_get_protocol(void);

gchar*
rda_get_protocol_name(void);

GList*
rda_supported_protocols(void);

GList*
rda_supported_protocols_by_name(void);

G_END_DECLS

#endif /* RDA_PROTOCOL_H */
