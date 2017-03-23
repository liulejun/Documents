***PETRONE / BLE / Protocol / BaseStructs***<br>
Modified : 2017.03.23

---

#### 데이터 전송 시 그대로 전달되지는 않으나 다른 구조체의 일부분으로 포함되는 구조체들을 소개합니다.

---


## <a name="CommandBase">Protocol::CommandBase</a>
PETRONE의 설정을 변경하거나 데이터를 요청할 때 사용합니다.
```cpp
namespace Protocol
{
    struct CommandBase
    {
        u8 commandType;   // 명령 타입
        u8 option;        // 명령에 대한 옵션
    };
}
```
- commandType : [Protocol::CommandType::Type](ble_protocol_definitions.md#CommandType)
- option : [System::ModeVehicle::Type](ble_protocol_definitions.md#ModeVehicle), [System::Coordinate::Type](ble_protocol_definitions.md#Coordinate), [System::Trim::Type](ble_protocol_definitions.md#Trim),  [System::FlightEvent::Type](ble_protocol_definitions.md#FlightEvent), [Protocol::DataType::Type](ble_protocol_datatype.md#DataType), 


## <a name="LightModeBase">Protocol::LightModeBase</a>
LED 모드를 변경할 때 사용하는 기본 구조체입니다.
```cpp
namespace Protocol
{
    struct LightModeBase
    {
        u8 mode;         // LED 모드
        u8 color;        // LED 모드 색상(팔레트 인덱스)
        u8 interval;     // LED 모드의 갱신 주기
    };
}
```
- mode : [Light::Mode::Type](ble_protocol_definitions.md#LightMode)
- color : [Light::Colors::Type](ble_protocol_definitions.md#LightColors)


---
[Home](README.md)

