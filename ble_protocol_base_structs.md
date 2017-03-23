# PETRONE
***BLE / Protocol***<br>
Modified : 2017.03.23

---

#### 데이터 전송 시 그대로 전달되지는 않으나 다른 구조체의 일부분으로 포함되는 구조체들을 먼저 소개합니다.


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
        u8 option;        ///< 명령에 대한 옵션
    };
}
```


---
[Home](README.md)

