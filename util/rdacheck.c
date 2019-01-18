/*
X2Go tests for librda

Copyright 2018, Mike Gabriel <mike.gabriel@das-netzwerkteam.de>

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

#include <glib.h>
#include <glib/gi18n.h>

#include <rda.h>

int
main (int argc, char ** argv)
{
	rda_init();
	g_message(_("Currently used remote technology: %s"), rda_get_remote_technology_name());

	g_message(_("RDA supports the following remote session technologies:"));

	for(GList* tech = rda_supported_technologies_by_name(); tech; tech = tech->next) {
		gchar* item = tech->data;
		g_message("    * %s", item);
	}

	rda_supported_technologies_by_name();
}
