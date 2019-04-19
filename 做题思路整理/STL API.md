# 这里是算法竞赛里常见的STL API记录

## 二分查找

### lower_bound

```cpp
ForwardIter lower_bound(ForwardIter first, ForwardIter last,const _Tp& val)
```

算法返回一个非递减序列[first, last)中的第一个大于等于值val的位置。

### upper_bound

```cpp
ForwardIter upper_bound(ForwardIter first, ForwardIter last, const _Tp& val)
```

算法返回一个非递减序列[first, last)中第一个大于val的位置。

## 排序

### sort

```cpp

```

## 数据结构

### 可扩展数组

#### vector

```cpp

```

### 队列

#### queue

```cpp

```

### 栈

#### stack

```cpp

```

### 堆

#### priority_queue

```cpp

```