# 信用卡管理系统

> C++课程设计 使用Visual Stdio 2019开发 在控制台运行，里面使用了带哨兵的链表，有查找，排序，插入，删除等操作。

## 主要功能

![111](https://raw.githubusercontent.com/chasmk/img/main/1111.png)


## 运行时出现的问题
如果运行时出现``` error C4996: 'strcpy': This function or variable may be unsafe. Consider using strcpy_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details. ``` 错误

解决方法是 解决方案资源管理器中右键点击项目名 -> 属性 -> C/C++ -> 预处理器 -> 预处理器定义 -> 编辑  把 `_CRT_SECURE_NO_WARNINGS` 加到后面，点击确定即可
