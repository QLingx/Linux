

##查看CPU

more /proc/cpuinfo

##查看CPU负载

top

top -H -p 1840

##限制CPU资源使用

0.top 查看CPU资源使用情况

1.nice 手动指定优先级，适合针对CPU密集型后台进程或批处理，多进程才会有更多比较

nice yourcmd

nice范围：-20（最高） - 19，默认为10，linux系统默认为0

重新调整nice值 renice +number pid

2.cpulimit 限制资源范围，通过不断暂停进程实现，单进程也会按限制执行

https://github.com/opsengine/cpulimit

cpulimit -l 50 yourcmd

重新调整

cpulimit -l 50 -p pid

3.cgroups 限制进程资源消耗，支持组，最强大，不仅cpu

创建控制组

sudo cgcreate -g cpu:/cpulimited1

sudo cgcreate -g cup:/cpulimited2

sudo cgcreate -g type:/yourgroupname

cpuset支持多核

sudo cgset -r cpu.shares=512 cpulimited1

默认为1024，最终按照比例分配资源

启动控制组

sudo cgexec -g cpu:cpulimited1 yourcmd

scout产品可以监控cpu和内存使用情况
