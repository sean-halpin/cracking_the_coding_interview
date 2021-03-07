### Build in C89

Same standard as [gstreamer project ](https://gstreamer.freedesktop.org/documentation/frequently-asked-questions/developing.html?gi-language=c)

```
gcc -g -O0 --std=c89 ./ch1.c `pkg-config --cflags --libs glib-2.0` -o ch1.elf
```

### Use Portable Libs

[glib](https://developer.gnome.org/glib/stable/glib-compiling.html) and `GObject`

### Valgrind

Use Valgrind to detect memory mismanagement.
[valgrind](http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/)

```
valgrind --tool=memcheck --leak-check=yes --show-reachable=no --num-callers=1 --track-fds=no ./ch1.elf
```

