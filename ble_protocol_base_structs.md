# PETRONE
***BLE / Protocol***<br>
Modified : 2017.03.23

---


**변수 형식**
-----------------
PETRONE의 데이터 송수신에는 typedef 한 변수 형식을 사용하고 있습니다.
```cpp
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
```
데이터 송수신에 사용하는 변수는 실제로는 지정된 열거형이 있는 경우라도 데이터 길이를 명확하게 표시하고자 변수형을 u8 또는 u16으로 지정하고 있습니다.



**CommandBase**
-----------------
**Protocol::CommandBase**<br>
PETRONE의 설정을 변경하거나 데이터를 요청할 때 사용하는 Command를 포함하는 명령의 기본 구조체입니다. Command, Command2, Command3, LedModeCommand, LedModeCommandIr, LedEventCommand, LedEventCommandIr 구조체에서 사용하고 있습니다.
```cpp
namespace Protocol
{
    struct CommandBase
    {
        u8 commandType;   ///< 명령 타입
        u8 option;        ///< 명령에 대한 옵션(System.h에 정의한 값을 사용)
    };
}
```


---
[Home](README.md)

