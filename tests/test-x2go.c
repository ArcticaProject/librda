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

#include <gtk/gtk.h>

void
test_x2go_can_suspend (void)
{
	return;
}

void
test_rda_x2go_suite (void)
{
	g_test_add_func ("/librda/x2go/can_suspend", test_x2go_can_suspend);
	return;
}

int
main (int argc, char ** argv)
{
	g_test_init (&argc, &argv, NULL);

	test_rda_x2go_suite();

	g_log_set_always_fatal(G_LOG_LEVEL_CRITICAL);

	return g_test_run();
}
