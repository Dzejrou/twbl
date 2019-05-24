# Tumbleweed Backlight

Had some trouble getting xbacklight to work on openSUSE Tumbleweed, so I wrote this
simple program that should work around it. Requires root, a workaround can be found
at [stackoverflow](https://unix.stackexchange.com/a/248495).

The values of the `fname` and `max_fname` variables might need to be changed to the correct path
to your backlight brightness files.

### Compilation:

```
g++ -std=c++11 -o twbl twbl.cpp
```

### Usage (i3 config):

```
bindsym XF86MonBrightnessUp exec sudo /home/dzejrou/bin/twbl +100 # increase screen brightness
bindsym XF86MonBrightnessDown exec sudo /home/dzejrou/bin/twbl -100 # decrease screen brightness
```

### TODO

- Create a Makefile
- Find a way to not need sudo
- (RFC) Maybe change granularity of increment/decrement (e.g. "./twbl +1" makes no difference at all, up until 1000)
