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
#include "yajl_tree_print.h"
#include <stdbool.h>
#include <stdlib.h>
#include <yajl/yajl_tree.h>

void yajl_tree_print(const yajl_val node, FILE* outfile)
{
	if (node == NULL || YAJL_IS_NULL(node)) {
		fprintf(outfile, "null");
	} else if (YAJL_IS_TRUE(node)) {
		fprintf(outfile, "true");
	} else if (YAJL_IS_FALSE(node)) {
		fprintf(outfile, "false");
	} else if (YAJL_IS_STRING(node)) {
		fprintf(outfile, "\"%s\"", node->u.string);
	} else if (YAJL_IS_NUMBER(node)) {
		fprintf(outfile, "%s", node->u.number.r);
	} else if (YAJL_IS_ARRAY(node)) {
		size_t i = 0;
		bool first_post = true;
		fprintf(outfile, "[");
		for (i = 0; i < node->u.array.len; i++) {
			if (!first_post) {
				fprintf(outfile, ",");
			}
			yajl_tree_print(node->u.array.values[i], outfile);
			first_post = false;
		}
		fprintf(outfile, "]");
	} else if (YAJL_IS_OBJECT(node)) {
		size_t i = 0;
		bool first_post = true;
		fprintf(outfile, "{");
		for (i = 0; i < node->u.object.len; i++) {
			if (node->u.object.values[i] != NULL) {
				if (!first_post) {
					fprintf(outfile, ",");
				}
				fprintf(outfile, "\"%s\":",
						node->u.object.keys[i]);
				yajl_tree_print(node->u.object.values[i],
						outfile);
				first_post = false;
			}
		}
		fprintf(outfile, "}");
	}
}

