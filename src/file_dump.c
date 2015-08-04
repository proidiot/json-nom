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
#include "file_dump.h"
#include <stdlib.h>
#include <stdio.h>
#include <sysexits.h>

char* file_dump(FILE* infile)
{
	size_t total_size = BUFSIZ;
	size_t last_size = 0;
	char* last_data = NULL;
	char* data = (char*)malloc(BUFSIZ);
	if (data == NULL) {
		perror("Unable to allocate memory");
		return NULL;
	}
	last_data = data;
	data[0] = '\0';

	while ((last_size = fread(last_data, 1, BUFSIZ, infile)) == BUFSIZ) {
		total_size += BUFSIZ;

		data = realloc(data, total_size);
		if (data == NULL) {
			perror("Unable to allocate memory");
			return NULL;
		}

		last_data = data + total_size - BUFSIZ;
	}

	if (ferror(infile) != 0) {
		perror("Unable to determine the length of the file");
		return NULL;
	}

	/* just in case */
	last_data[last_size] = '\0';

	return data;
}

