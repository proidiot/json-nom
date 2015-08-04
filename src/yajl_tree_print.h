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

#ifndef _JSON_NOM_YAJL_TREE_PRINT_H_
#define _JSON_NOM_YAJL_TREE_PRINT_H_

#include <stdio.h>
#include <yajl/yajl_tree.h>

/**
 * Prints a YAJL tree, omitting any removed properties from JSON objects.
 *
 * @param node    The YAJL tree to print
 * @param outfile The file being written to
 */
void yajl_tree_print(const yajl_val node, FILE* outfile);

#endif

