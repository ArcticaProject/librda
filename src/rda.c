/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda.c - Remote Desktop Awareness

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
#include <glib/gi18n.h>

#include <rda.h>
#include <rda_ogon.h>
#include <rda_x2go.h>

guint
remote_technology = REMOTE_TECHNOLOGY_UNCHECKED;

void
rda_init (void)
{
	rda_session_is_remote();
}

gboolean
rda_session_is_local(void)
{
	if (remote_technology == REMOTE_TECHNOLOGY_NONE)
		return TRUE;

	if (g_getenv("XDG_SEAT"))
	{
		remote_technology = REMOTE_TECHNOLOGY_NONE;
		return TRUE;
	}

	return FALSE;
}

gboolean
rda_session_is_remote (void)
{
	if (rda_session_is_x2go())
		return TRUE;

	if (rda_session_is_ogon())
		return TRUE;

	/* possibly add more checks for other remote desktop technologies */

	else if (rda_session_is_local())
		remote_technology = REMOTE_TECHNOLOGY_NONE;

	else
		remote_technology = REMOTE_TECHNOLOGY_UNKNOWN;

	return FALSE;
}

guint
rda_get_remote_technology(void)
{
	if (remote_technology == REMOTE_TECHNOLOGY_UNCHECKED)
		rda_init();

	return remote_technology;
}

gchar *
rda_get_remote_technology_name (void)
{
	if (remote_technology == REMOTE_TECHNOLOGY_UNCHECKED)
		rda_init();

	gchar* remote_technology_name;

	switch(remote_technology) {

		case REMOTE_TECHNOLOGY_NONE:
			remote_technology_name = _("local");
			break;

		case REMOTE_TECHNOLOGY_X2GO:
			remote_technology_name = _("X2Go");
			break;

		case REMOTE_TECHNOLOGY_OGON:
			remote_technology_name = _("OgonRDP");
			break;

		case REMOTE_TECHNOLOGY_UNKNOWN:
			remote_technology_name = _("unknown");

		default:
			remote_technology_name = g_strdup("");

	}

	return remote_technology_name;
}

gboolean
rda_session_can_be_suspended(void)
{
	if (rda_session_is_x2go())
		return TRUE;

	if (rda_session_is_ogon())
		return TRUE;

	/* possibly add more checks for other remote desktop frameworks
	   that have a session suspension feature */

	return FALSE;
}

gboolean
rda_session_suspend(void)
{
	if (rda_session_is_x2go())
		return rda_session_suspend_x2go();

	if (rda_session_is_ogon())
		return rda_session_suspend_ogon();

	return FALSE;
}

gboolean
rda_session_terminate(void)
{
	if (rda_session_is_x2go())
		return rda_session_terminate_x2go();

	if (rda_session_is_ogon())
		return rda_session_terminate_ogon();

	return FALSE;
}
