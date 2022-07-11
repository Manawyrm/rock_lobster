# rock_lobster
Linux kernel module for providing /proc/lobster

![](https://screenshot.tbspace.de/ekbfjhrcgus.png)

### How-To
```bash
apt install build-essential linux-headers
git clone "https://github.com/Manawyrm/rock_lobster"
cd rock_lobster
make
insmod rock_lobster.ko

cat /proc/lobster
```
