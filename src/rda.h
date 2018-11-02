/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda.h - Remote Desktop Awareness

   Copyright (C) 2018 Mike Gabriel
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

#ifndef RDA_H
#define RDA_H

#include <glib.h>

G_BEGIN_DECLS

enum {
	REMOTE_TECHNOLOGY_UNCHECKED,
	REMOTE_TECHNOLOGY_NONE,
	REMOTE_TECHNOLOGY_UNKNOWN,
	REMOTE_TECHNOLOGY_X2GO,
	REMOTE_TECHNOLOGY_OGON,
};

extern guint
remote_technology;

void
rda_init (void);

gboolean
rda_session_is_local(void);

gboolean
rda_session_is_remote (void);

guint
rda_get_remote_technology(void);

gchar *
rda_get_remote_technology_name (void);

gboolean
rda_session_can_be_suspended(void);

gboolean
rda_session_suspend(void);

gboolean
rda_session_terminate(void);

G_END_DECLS

#endif /* RDA_H */
