

# CPP11 特性演示

## 依赖库

```bash
log4cplus-2.1.0
googletest.1.12.0
```

# Debian 12

```bash
> cmake -B build
> cmake --build build
```



# Windows 10

## 设置运行环境

log4cplus库

```bash
> set Path=D:\devtools\log4cplus-2.1.0\bin;%Path%
```

gtest库
```bash
> set Path=D:\devtools\googletest.1.12.0\debug\bin;%Path%
> set Path=D:\devtools\googletest.1.12.0\bin;%Path%
```

## 运行测试
```bash
> .\unittest.exe
> .\unittest.exe --gtest_filter=PODCLASS*
> .\unittest.exe --gtest_filter=PODCLASS.IS_TRIVIALLY_COPYABLE
```