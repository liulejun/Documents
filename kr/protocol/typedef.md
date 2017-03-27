***PETRONE / BLE / Protocol / Typedef***<br>
Modified : 2017.03.24

---

#### PETRONE 프로젝트 내부에서 사용하고 있는 변수 형식을 소개합니다.

---

<br>

**변수 형식**
-----------------
PETRONE의 데이터 송수신에는 typedef 한 변수 형식을 사용하고 있습니다.
```cpp
typedef int32_t   s32;
typedef int16_t   s16;
typedef int8_t    s8;
typedef uint32_t  u32;
typedef uint16_t  u16;
typedef uint8_t   u8;
```
데이터 송수신에 사용하는 변수는 실제로는 지정된 열거형이 있는 경우라도 데이터 길이를 명확하게 표시하고자 변수형을 u8 또는 u16으로 지정하고 있습니다.



<br>

---

### PETRONE

1. [Intro](intro.md)
2. ***Typedef***
3. [DataType](datatype.md)
4. [Definitions](definitions.md)
5. [Base Structs](base_structs.md)
6. [Structs](structs.md)
7. [Structs - Light](structs_light.md)


### PETRONE Link

1. [Intro](link/intro.md)
2. [DataType](link/datatype.md)
3. [Definitions](link/definitions.md)
4. [Structs](link/structs.md)
5. [Examples](link/examples.md)

<br>

[Home](../../README.md)

