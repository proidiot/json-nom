# json-nom [![Stories in Ready](https://badge.waffle.io/proidiot/json-nom.png?label=ready&title=Ready)](https://waffle.io/proidiot/json-nom)
**JSON Nested Object Masker** is a small program that will recursively take a [JSON](https://json.org/) object and, for each property within that object, remove any occurrence of that property within nested objects.

Dependencies
------------
- Run
	- [YAJL](https://github.com/lloyd/yajl)
- Build
	- [GNU Autoconf](https://www.gnu.org/software/autoconf/)
	- [GNU Automake](https://www.gnu.org/software/automake/)
	- A C compiler
	- Make
- Test
	- [DejaGnu](https://www.gnu.org/software/dejagnu/)

Installation
------------
```
./autogen.sh
./configure
make clean # best practice
make
make check # optional, but recommended
make install
```

Usage
-----
```
cat /path/to/input.json | json-nom > /path/to/output.json
```

License
-------
json-nom Copyright (C) 2015  Charles Southerland

This program is released under the terms of the GNU GPL v3 or later. This program comes with ABSOLUTELY NO WARRANTY. This is free software, and you are welcome to redistribute it under certain conditions. See [the GNU licenses site](https://www.gnu.org/licenses/) for details.

Bugs
----
Please report bugs through [github](https://github.com/proidiot/json-nom/issues).

