/* -*- Mode: C; c-set-style: linux indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */

/* rda_protocol.c - Generic protocol support for remote sessions

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

#include <glib.h>
#include <glib/gi18n.h>

#include <rda_protocol.h>
#include <rda.h>
#include <rda_x2go.h>
#include <rda_ogon.h>

static guint supported_protos[RDA_PROTOCOL_MAX] = { };
static gboolean supported_protos_init = FALSE;

rda_protocol_t
rda_protocol = RDA_PROTOCOL_MAX;

guint
rda_get_protocol(void)
{
	if (RDA_PROTOCOL_MAX == rda_protocol)
	{
		rda_init();
	}

	return rda_protocol;
}

static const gchar*
rda_protocol_name_nx(void)
{
	return _("NX");
}

static const gchar*
rda_protocol_name_kdrive(void)
{
	return _("KDrive");
}

static const gchar*
rda_protocol_name_rdp(void)
{
	return _("RDP");
}

static const gchar*
rda_protocol_name_vnc(void)
{
	return _("VNC");
}

gchar*
rda_get_protocol_name (void)
{
	if (RDA_PROTOCOL_MAX == rda_protocol)
		rda_init();

	gchar* rda_protocol_name;

	switch(rda_protocol) {

		case RDA_PROTOCOL_NONE:
			rda_protocol_name = g_strdup(_("local"));
			break;

		case RDA_PROTOCOL_NX:
			rda_protocol_name = g_strdup(rda_protocol_name_nx());
			break;

		case RDA_PROTOCOL_KDRIVE:
			rda_protocol_name = g_strdup(rda_protocol_name_kdrive());
			break;

		case RDA_PROTOCOL_RDP:
			rda_protocol_name = g_strdup(rda_protocol_name_rdp());
			break;

		case RDA_PROTOCOL_VNC:
			rda_protocol_name = g_strdup(rda_protocol_name_vnc());
			break;

		case RDA_PROTOCOL_UNKNOWN:
			rda_protocol_name = g_strdup(_("unknown"));

		default:
			rda_protocol_name = g_strdup("");

	}

	/*
	 * Moving g_strdup() down here might sound tempting, but don't do
	 * that.
	 *
	 * Even though, at the time of writing this comment, all functions
	 * used in here actually return a string literal (and as such, a
	 * "const gchar*"), this may not be true forever and it's too easy
	 * to leak memory by copying an already heap-allocated string.
	 */
	return rda_protocol_name;
}

static void
init_supported_protos(void)
{
	if (!(supported_protos_init))
	{
		/* Initialize the list. */
#define merge_arr(name) \
	do \
	{ \
		for (gsize i = 0; i < rda_supported_protocols_ ## name ## _len; ++i) \
		{ \
			supported_protos[rda_supported_protocols_ ## name [i]] = TRUE; \
		} \
	} \
	while (0)

#ifdef WITH_REMOTE_AWARENESS_X2GO
		merge_arr(x2go);
#endif

#ifdef WITH_REMOTE_AWARENESS_OGON
		merge_arr(ogon);
#endif

#undef merge_arr
		supported_protos_init = TRUE;
	}
}

GList*
rda_supported_protocols(void)
{
	GList *proto_list = NULL;

	init_supported_protos();

	for (gsize i = 0; i < RDA_PROTOCOL_MAX; ++i)
	{
		if (supported_protos[i])
		{
			proto_list = g_list_append (proto_list, GUINT_TO_POINTER(i));
		}
	}

	return proto_list;
}

GList*
rda_supported_protocols_by_name(void)
{
	GList *proto_list_by_name = NULL;

	init_supported_protos();

	for (gsize i = 0; i < RDA_PROTOCOL_MAX; ++i)
	{
		if (supported_protos[i])
		{
			switch (i)
			{
				case RDA_PROTOCOL_NX:
					proto_list_by_name = g_list_append (proto_list_by_name, g_strdup(rda_protocol_name_nx()));
					break;

				case RDA_PROTOCOL_KDRIVE:
					proto_list_by_name = g_list_append (proto_list_by_name, g_strdup(rda_protocol_name_kdrive()));
					break;

				case RDA_PROTOCOL_RDP:
					proto_list_by_name = g_list_append (proto_list_by_name, g_strdup(rda_protocol_name_rdp()));
					break;

				case RDA_PROTOCOL_VNC:
					proto_list_by_name = g_list_append (proto_list_by_name, g_strdup(rda_protocol_name_vnc()));
					break;
			}
		}
	}

	return proto_list_by_name;
}
