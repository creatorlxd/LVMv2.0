# 概览

~~好啦好啦不拽英文了2333~~

## 关于本项目

LVM v2 是下一代的LML语言虚拟机.目前项目维护者是 [@createlxd](https://github.com/creatorlxd) ,另一位合作者(打酱油的蒟蒻)是 [@xsun2001](https://github.com/xsun2001) . 目前的LVM实现了一些基础功能,但是我们会将它完善成一个功能完全的,可扩展的,高性能的语言虚拟机(就像JVM一样).

## 构建运行

**警告:** 目前 LVM v2 只支持在 Visual Studio 中构建运行,而且只在 VS 2017 中测试过,我们也推荐使用 VS 2017 进行进一步的开发,其他版本的VS构建时的行为尚不明确. 下一步我们可能会使用CMake实现跨平台的构建.

1. 前置要求: [Git](https://git-scm.com/downloads), [Visual Studio](https://www.visualstudio.com/vs/) (推荐2017版本)
1. 使用如下命令将代码仓库克隆到本地 `git clone https://github.com/creatorlxd/LVMv2.0.git <dir>`. 其中的\<dir\>是你想要存储 LVM v2 代码的目录.
1. 使用 Visual Studio 打开代码根目录中的 `LVMv2.0.sln`.
1. 愉快地玩耍吧.

## 总体架构

LVM v2 属于字节码虚拟机,也就是说它执行的的是所谓的字节码,而不是原始代码文件.关于字节码指令集的更多信息,请参考 [字节码指令集(待填坑)]() , [LML](https://github.com/creatorlxd/LML) 以及 [LVMCommands.hpp](https://github.com/creatorlxd/LVMv2.0/blob/master/LVMv2.0/LVMCommands.hpp). LVM v2 身为语言虚拟机,与在其上运行的实际编程语言并没有直接联系,只要给出符合标准的字节码文件,LVM v2都会将其按照预期的方式执行.

LVM v2 中的数据类型包含整数(`int`),浮点数(`float`),逻辑值(`bool`),字符(`char`). 整数(`int`)被规定为32位的有符号整数类型. 浮点数(`float`)是单精度浮点类型. 关于基本的数值计算和位运算都在指令集中定义,更加细节上的处理(比如溢出后的行为)应当遵循c/c++语言默认的行为. 逻辑值(`bool`用于表示逻辑上的真或假,还会被用于`if`等语句的判断,其内部的实现形式随意. 关于类具体在虚拟机中的存在形式将不做限制.

LVM v2 是基于栈的虚拟机,这说明代码在内部进行处理的数据都会由操作数栈进行储存和调度,任何对于数据的访问都是基于操作数栈的基本操作弹出(pop)和压入(push)的. 所有函数的操作数栈都是共享的.