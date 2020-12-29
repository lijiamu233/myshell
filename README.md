# myshell
- **使用说明:** 运行以下命令
```
mkdir build
cd build
cmake ..
make all
```
- 然后在build里面创建.myshellrc文件,内容如下(括号内的内容自行替换):
```
export AUTHOR=(your id)
export PATH=(当前位置)/bin:/usr/local/bin:/usr/bin:/bin
```
- 然后运行
```
./myshell
```