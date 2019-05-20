# Tumbleweed Backlight

Had some trouble getting xbacklight to work on openSUSE Tumbleweed, so I wrote this
simple program that should work around it. Requires root, a workaround can be found
at [stackoverflow](https://unix.stackexchange.com/a/248495).

The value of the `fname` variable might need to be changed to the correct path
to your backlight britness file.

### Compilation:

```
g++ -std=c++11 twbl.cpp
```

### Usage (i3 config):

```
bindsym XF86MonBrightnessUp exec sudo /home/dzejrou/bin/twbl +100 # increase screen brightness
bindsym XF86MonBrightnessDown exec sudo /home/dzejrou/bin/twbl -100 # decrease screen brightness
```
