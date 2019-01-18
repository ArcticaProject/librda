/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda_ogon.c - Remote Desktop Awareness for Ogon RDP Sessions

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
   Boston, MA 02110-1301, USA.
 */

#include <config.h>
#include <glib.h>

#include <rda.h>

#ifdef WITH_REMOTE_AWARENESS_OGON

gboolean
rda_session_is_ogon (void)
{
	if (remote_technology == REMOTE_TECHNOLOGY_OGON)
		return TRUE;

	if (g_getenv("OGON_SID"))
	{
		remote_technology = REMOTE_TECHNOLOGY_OGON;
		return TRUE;
	}

	return FALSE;
}

gboolean
rda_session_suspend_ogon(void)
{
	if (!rda_session_is_ogon())
		return FALSE;

	gint exit_status = 0;
	gchar *std_out, *std_err;
	GError *error = NULL;

	g_spawn_command_line_sync("ogon-disonnect",
	                          &std_out,
	                          &std_err,
	                          &exit_status,
	                          &error);

	if (error == NULL)
	{
		return TRUE;
	} else {
		// FIXME: Maybe put some error reporting to a higher API level
		//        here...
		return FALSE;
	}
}

gboolean
rda_session_terminate_ogon(void)
{
	if (!rda_session_is_ogon())
		return FALSE;

	gint exit_status = 0;
	gchar *std_out, *std_err;
	GError *error = NULL;

	g_spawn_command_line_sync("ogon-logout",
	                          &std_out,
	                          &std_err,
	                          &exit_status,
	                          &error);

	if (error == NULL)
	{
		return TRUE;
	} else {
		// FIXME: Maybe put some error reporting to a higher API level
		//        here...
		return FALSE;
	}
}

#endif /* WITH_REMOTE_AWARENESS_OGON */
