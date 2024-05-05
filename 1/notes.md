

# 3
```sh
➜  1 git:(master) ✗ cat /proc/modules | grep red
redhue 16384 0 - Live 0x0000000000000000 (OE)
➜  1 git:(master) ✗ sudo lsmod | grep red      
redhue                 16384  0
```

## 3.7
```sh
[86602.209336] Hello, world
[86602.209428] 500
[86605.816267] open
[86605.816288] read 6
[86605.816295] release
[86605.816453] open
[86605.816500] write 4096
[86605.816511] release
[86609.502318] Goodbye, world
```

