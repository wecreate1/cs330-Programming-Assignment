CS 330 Programming Assignment
=============================

Unlock code: `103401`

Lock code: `103404`

This has been tested on Kubuntu 22.04 and testing on Ubuntu 22.04 is requested.

Dependencies
------------

Build system: meson
Build system backend: ninja
Unit Test Coverage (optional): gcovr

And other system dependencies.

To install these dependencies on Ubuntu, run the following command as root:

```sh
apt install build-essential meson gcovr ninja-build
```

Building
--------

To build the program after installing the dependencies, run the following
commands:

```sh
meson setup builddir
meson compile -C builddir
```

Running
-------

To run the program after building the project, run the following commands:

```sh
./builddir/main
```

The program can be exited by sending a SIGINT (Ctrl-C) or EOT(Ctrl-D).

Note: the program does not echo the input.

The program created for part 2 of the assignment can be run with the following
commands:

```sh
./builddir/stats
```

The program can be exited by sending a SIGINT (Ctrl-C).

Testing
-------

To run unit tests after building the project, run the following commands:

```sh
meson test -C builddir
ninja coverage -C builddir
```

Test Coverage
-------------

To generate unit test coverage reports after running the tests, run the
following commands:

```sh
ninja coverage -C builddir
```

Other Goodies
-------------

This repo includes a document which includes my analysis for part 2 and a state transition diagram. The source for both is included.
