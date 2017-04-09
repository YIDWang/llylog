
# llylog                                                                                                                                                                                       
## 设计概要
日志库主要分为前端信息接受处理器,后端日志信息输出器,中间缓存队列,配置解析器。  
 
 - 配置解析器：主要功能解析配置文件，提供给信息处理器，做配置选项。
 - 信息处理器：主要功能接受用户输入信息，格式信息结构体，按级别分发日志
 - 信息输出器：主要功能接收日志信息，把日志信息写入文件，日志的滚动切割（时间和大小）
 - 日志缓存队列：主要功能用于异步日志的缓存

### 配置解析器
    文件格式按照json格式编码，主要配置参数如下：                      
    level //默认的打印级别
    sync  //同步异步
    divWay //文件切割方式
    name //输出文件名字
    path //输出文件的路径
####设计
    设计模式使用单例模式：全局只需要唯一一份对象。考虑到后期可能修改为多线程并发解析，因此实现为线程安全的单例模式。
    对于锁的使用：利用互斥量实现自动锁，借鉴与智能指针的实现，利用对象管理上锁和解锁。同样也考虑后期封装线程池为准备。    

### 信息处理器
    ¦   ¦   ¦   ¦   ¦   否-》缓存队列
    用户信息-》格式化-同步否
    ¦   ¦   ¦   ¦   ¦   是-》日志输出器
对外接口提供为：

    New（char *path）    
    Debug（char *msg， ...）
    Info（char *msg， ...）
    Error（char *msg， ...）
    Fatal（char *msg， ...）

为了支持定义消息体额外提供对外格式函数有：

    Char（char *msg）
    Int（int msg）
    String（string msg）
    Long（long msg）
    Addr（long msg）

### 信息输出器
    主要由C++文件f系列参数，文件管理，文件操作组成。    
    
 - 文件操作类：主要以封装文件相关操作，如：文件的打开，写入，关闭，重命名相关系列操所。
 - 文件管理类：保存文件类，监督文件的打开关闭。
####设计
    主要用设计模式中的imp（桥接模式的变种），因为考虑到文件底层封装经常变化，接口随时改变，使用桥接模式可以使管理和实现实现隔离，编译速度也变快了。
    考虑到后期扩展支持更多文件操作或更换C++文件流作为文件底层操作，分割文件操作和管理。二次更改考虑添加工厂设计模式，兼容c++相关设计。

### 日志缓存队列
    主要由无锁队列和环形缓存区组成。

