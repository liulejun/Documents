***PETRONE / BLE / Protocol / Structs***<br>
Modified : 2017.03.23

---

#### 데이터 송수신 시에 사용하는 구조체들을 소개합니다.

---


## <a name="Ack">Protocol::Ack</a>
PETRONE이 데이터를 수신 받았을 때 응답으로 보내는 데이터입니다. PETRONE의 현재 내부 시간과 수신 받은 데이터의 타입을 담아서 반환합니다. Ack와 Control을 제외한 대부분의 명령에 대해 응답을 전송합니다.
```cpp
namespace Protocol
{
    struct Ack
    {
        u32  systemTime;   // 수신 받은 시각
        u8   dataType;     // 수신 받은 데이터 타입
    };
}
```
- dataType : [Protocol::DataType::Type](ble_protocol_datatype.md#DataType)


## <a name="Request">Protocol::Request</a>
PETRONE에 데이터를 요청할 때 사용합니다.
```cpp
namespace Protocol
{
    struct Ack
    {
        u8   dataType;     // 요청할 데이터 타입
    };
}
```
- dataType : [Protocol::DataType::Type](ble_protocol_datatype.md#DataType)


## <a name="Control">Protocol::Control</a>
PETRONE을 조종할 때 사용하는 입력값입니다.
```cpp
namespace Protocol
{
    struct Control
    {
        s8   roll;        // Roll
        s8   pitch;       // Pitch
        s8   yaw;         // Yaw
        s8   throttle;    // Throttle
    };
}
```

Control 입력 값의 범위는 다음과 같습니다. Drive 모드에서는 **throttle**(전후)과 **roll**(좌우)만 사용합니다.


|이름      | 형식 | 범위        | 방향      | 음수 값(-) | 양수 값(+)    |
|:--------:|:----:|:-----------:|:---------:|:----------:|:-------------:|
| roll     | s8   | -100 ~ 100  | 좌우 이동 | 좌측       | 우측          |
| pitch    | s8   | -100 ~ 100  | 전후 이동 | 후방       | 전방          |
| yaw      | s8   | -100 ~ 100  | 좌우 회전 | 반시계     | 시계 방향     |
| throttle | s8   | -100 ~ 100  | 승하강    | 하강       | 상승          |



---
[Home](README.md)

