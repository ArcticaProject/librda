/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda_x2go.c - Remote Desktop Awareness for X2Go Sessions

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

#include <glib.h>
#include <glib/gi18n.h>

#include <rda.h>

#ifdef WITH_REMOTE_AWARENESS_X2GO

gboolean
rda_session_is_x2go (void)
{
	if (remote_technology == REMOTE_TECHNOLOGY_X2GO)
		return TRUE;

	if (g_getenv("X2GO_SESSION"))
	{
		remote_technology = REMOTE_TECHNOLOGY_X2GO;
		return TRUE;
	}

	return FALSE;
}

gchar *
rda_remote_technology_name_x2go(void)
{
	return _("X2Go");
}

gboolean
rda_session_suspend_x2go(void)
{
	if (!rda_session_is_x2go())
		return FALSE;

        gint exit_status = 0;
	gchar *std_out, *std_err;
	GError *error = NULL;

	g_spawn_command_line_sync("x2gosuspend-session",
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
rda_session_terminate_x2go(void)
{
	if (!rda_session_is_x2go())
		return FALSE;

	gint exit_status = 0;
	gchar *std_out, *std_err;
	GError * error = NULL;

	g_spawn_command_line_sync("x2goterminate-session",
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

#endif /* WITH_REMOTE_AWARENESS_X2GO */
