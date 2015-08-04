/* Copyright 2015 Charles Southerland.
 *
 * This file is part of json-nom.
 *
 * json-nom is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * json-nom is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * json-nom.  If not, see <http://www.gnu.org/licenses/>.
 *
 * More information about json-nom can be found at
 * <https://github.com/proidiot/json-nom/>.
 */

#include <config.h>
#include <argp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sysexits.h>
#include <yajl/yajl_tree.h>
#include "file_dump.h"
#include "nom.h"
#include "yajl_tree_print.h"

const char* argp_program_version = PACKAGE_STRING;

const char* argp_program_bug_address = PACKAGE_BUGREPORT;

static char doc[] = "JSON Nested Object Masker";

static struct argp argp = {0, 0, 0, doc};

int main(int argc, char** argv)
{
	char* data = NULL;
	yajl_val tree = NULL;

	argp_parse(&argp, argc, argv, 0, 0, 0);

	if (feof(stdin) != 0) {
		fprintf(stderr, "Input is empty\n");
		exit(EX_DATAERR);
	}
	if ((data = file_dump(stdin)) == NULL) {
		fprintf(stderr, "Unable to make a local copy of stdin\n");
		exit(EX_IOERR);
	}

	/* I was getting the error message from YAJL, but it was pointless. */
	if ((tree = yajl_tree_parse(data, NULL, 0)) == NULL) {
		fprintf(stderr, "Unable to parse JSON data\n");
		exit(EX_DATAERR);
	}

	nom(tree);

	yajl_tree_print(tree, stdout);
	printf("\n");

	yajl_tree_free(tree);

	free(data);

	return 0;
}

