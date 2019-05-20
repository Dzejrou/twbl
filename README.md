# Tumbleweed Backlight

Had some trouble getting xbacklight to work on openSUSE Tumbleweed, so I wrote this
simple program that should work around it.

### Usage (i3 config):

```
bindsym XF86MonBrightnessUp exec sudo /home/dzejrou/bin/twbl +100 # increase screen brightness
bindsym XF86MonBrightnessDown exec sudo /home/dzejrou/bin/twbl -100 # decrease screen brightness
```
