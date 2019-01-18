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

	if (rda_session_is_local())
		remote_technology = REMOTE_TECHNOLOGY_NONE;
#ifdef WITH_REMOTE_AWARENESS_X2GO
	else if (rda_session_is_x2go())
		return TRUE;
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
	else if (rda_session_is_ogon())
		return TRUE;
#endif

	/* possibly add more checks for other remote desktop technologies */

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

#ifdef WITH_REMOTE_AWARENESS_X2GO
		case REMOTE_TECHNOLOGY_X2GO:
			remote_technology_name = rda_remote_technology_name_x2go();
			break;
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
		case REMOTE_TECHNOLOGY_OGON:
			remote_technology_name = rda_remote_technology_name_ogon();
			break;
#endif

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
#ifdef WITH_REMOTE_AWARENESS_X2GO
	if (rda_session_is_x2go())
		return TRUE;
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
	if (rda_session_is_ogon())
		return TRUE;
#endif

	/* possibly add more checks for other remote desktop frameworks
	   that have a session suspension feature */

	return FALSE;
}

gboolean
rda_session_suspend(void)
{
#ifdef WITH_REMOTE_AWARENESS_X2GO
	if (rda_session_is_x2go())
		return rda_session_suspend_x2go();
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
	if (rda_session_is_ogon())
		return rda_session_suspend_ogon();
#endif

	return FALSE;
}

gboolean
rda_session_terminate(void)
{
#ifdef WITH_REMOTE_AWARENESS_X2GO
	if (rda_session_is_x2go())
		return rda_session_terminate_x2go();
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
	if (rda_session_is_ogon())
		return rda_session_terminate_ogon();
#endif

	return FALSE;
}

gchar *
rda_supported_technologies(void)
{

	g_autofree gchar * technologies;

#ifdef WITH_REMOTE_AWARENESS_X2GO
	g_message("RDA supports (stable): %s", rda_remote_technology_name_x2go());
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
	g_message("RDA supports (alpha): %s", rda_remote_technology_name_ogon());
#endif
}
