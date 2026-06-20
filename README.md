# 學生成績管理系統

## 一、專案主題

本專案是使用 C++ 製作的「學生成績管理系統」。

本程式主要練習 Chapter 16 Templates 延伸出的 STL 應用，並使用 `struct`、`vector`、`sort()` 和 template function 完成學生資料管理。

## 二、專案功能

本程式提供以下功能：

1. 新增學生資料
2. 列出所有學生
3. 依成績由高到低排序
4. 依學號查詢學生
5. 顯示成績統計
6. 離開程式

## 三、學生資料結構

每位學生包含三個欄位：

```cpp
struct Student {
    string id;
    string name;
    int score;
};
```

其中：

- `id` 代表學生學號
- `name` 代表學生姓名
- `score` 代表學生成績

## 四、使用的 STL 容器

本專案使用 `vector` 儲存學生資料。

```cpp
vector<Student> students;
```

我選擇使用 `vector` 的原因是，學生資料數量可能會增加，而 `vector` 可以動態新增資料，使用上比一般陣列更方便。

## 五、使用的 STL Algorithm

本專案使用 `sort()` 對學生分數進行排序。

```cpp
sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
    return a.score > b.score;
});
```

這段程式可以讓學生資料依照成績由高到低排列。

## 六、Template Function

本專案設計了兩個 template function：`getMax` 和 `getMin`。

```cpp
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}
```

在本專案中，`getMax` 用來計算最高分，`getMin` 用來計算最低分。

## 七、編譯方式

請使用以下指令編譯程式：

```bash
g++ -std=c++17 main.cpp -o main.exe
```

## 八、執行方式

在 Windows PowerShell 中，可以使用以下指令執行：

```bash
.\main.exe
```

## 九、範例輸入

```text
1
A001
Tom
85
1
A002
Amy
92
1
A003
Ben
55
2
3
5
0
```

## 十、範例輸出

```text
Average score: 77.33
Highest score: 92
Lowest score: 55
Pass students: 2
Fail students: 1
```

## 十一、檔案結構

```text
main.cpp
README.md
report.pdf
```

## 十二、學習心得

透過這次小專題，我學會了如何使用 C++ 的 STL 容器來儲存資料，也了解 `vector` 和一般陣列的差別。

此外，我也練習了 `sort()` 的使用方式，並透過 template function 完成最高分與最低分的統計。這讓我更理解 template 不只可以用在課本範例，也可以整合到實際的小型程式中。