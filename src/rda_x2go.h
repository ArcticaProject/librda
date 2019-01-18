/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda_x2go.h - Remote Desktop Awareness for X2Go Sessions

   Copyright (C) 2018-2019 Mike Gabriel
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

#ifndef RDA_X2GO_H
#define RDA_X2GO_H

#include <config.h>
#include <glib.h>

#include <rda.h>

#ifdef WITH_REMOTE_AWARENESS_X2GO

gboolean
rda_session_is_x2go (void);

gchar *
rda_remote_technology_name_x2go(void);

gboolean
rda_session_suspend_x2go(void);

gboolean
rda_session_terminate_x2go(void);

#endif /* WITH_REMOTE_AWARENESS_X2GO */

#endif /* RDA_X2GO_H */
