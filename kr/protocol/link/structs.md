***PETRONE / LINK / Protocol / Structs***<br>
Modified : 2017.03.27

---

#### 데이터 송수신 시에 사용하는 구조체들을 소개합니다.

---

<br>

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
- dataType : [Protocol::DataType::Type](datatype.md#DataType)

<br>
<br>

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
- dataType : [Protocol::DataType::Type](datatype.md#DataType)

<br>
<br>

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

<br>
<br>

## <a name="Command">Protocol::Command</a>
명령 하나를 전달합니다.
```cpp
namespace Protocol
{
    struct Command
    {
        CommandBase   command;
    };
}
```
- command : [Protocol::CommandBase](base_structs.md#CommandBase)

<br>
<br>

## <a name="Command2">Protocol::Command2</a>
명령 두 개를 전달합니다.
```cpp
namespace Protocol
{
    struct Command2
    {
        CommandBase   command1;
        CommandBase   command2;
    };
}
```
- command1, command2 : [Protocol::CommandBase](base_structs.md#CommandBase)

<br>
<br>

## <a name="Command3">Protocol::Command3</a>
명령 세 개를 전달합니다.
```cpp
namespace Protocol
{
    struct Command3
    {
        CommandBase   command1;
        CommandBase   command2;
        CommandBase   command3;
    };
}
```
- command1, command2, command3 : [Protocol::CommandBase](base_structs.md#CommandBase)

<br>
<br>

## <a name="Address">Protocol::Address</a>
PETRONE BLE의 주소를 반환합니다.
```cpp
namespace Protocol
{
    struct Address
    {
        u8   address[6];
    };
}
```

<br>
<br>

## <a name="State">Protocol::State</a>
PETRONE의 현재 상태값을 반환합니다.
```cpp
namespace Protocol
{
    struct State
    {
        u8          modeVehicle;        // 동작 모드
        
        u8          modeSystem;         // 시스템 모드
        u8          modeFlight;         // 비행 모드
        u8          modeDrive;          // 주행 모드
        
        u8          sensorOrientation;  // 센서 방향
        u8          coordinate;         // 방위
        u8          battery;            // 배터리량(0 ~ 100)
    };
}
```
- modeVehicle : [System::ModeVehicle::Type](definitions.md#ModeVehicle)
- modeSystem : [System::ModeSystem::Type](definitions.md#ModeSystem)
- modeFlight : [System::ModeFlight::Type](definitions.md#ModeFlight)
- modeDrive : [System::ModeDrive::Type](definitions.md#ModeDrive)
- sensorOrientation : [System::SensorOrientation::Type](definitions.md#SensorOrientation)
- coordinate : [System::Coordinate::Type](definitions.md#Coordinate)

<br>
<br>

## <a name="Attitude">Protocol::Attitude</a>
자세값을 반환합니다.
```cpp
namespace Protocol
{
    struct Attitude
    {
        s16          roll;         // Roll
        s16          pitch;        // Pitch
        s16          yaw;          // Yaw
    };
}
```

드론의 자세를 확인할 때의 사용 범위는 다음과 같습니다.

|이름      | 형식 | 범위        | 설명                                |
|:--------:|:----:|:-----------:|:-----------------------------------:|
| roll     | s16  | -180 ~ 180  | 좌우 기울기 각도                    |
| pitch    | s16  | -180 ~ 180  | 전후 기울기 각도                    |
| yaw      | s16  |    0 ~ 360  | 중력 방향을 축으로 회전할 때의 각도 |


자이로 센서 데이터를 확인할 때의 사용 범위는 다음과 같습니다.

|이름      | 형식 | 범위            |
|:--------:|:----:|:---------------:|
| roll     | s16  | -32768 ~ 32767  |
| pitch    | s16  | -32768 ~ 32767  |
| yaw      | s16  | -32768 ~ 32767  |

<br>
<br>

## <a name="GyroBias">Protocol::GyroBias</a>
자이로 바이어스 값을 반환합니다.
```cpp
namespace Protocol
{
    struct GyroBias
    {
        s16          roll;         // Roll
        s16          pitch;        // Pitch
        s16          yaw;          // Yaw
    };
}
```

<br>
<br>

## <a name="TrimFlight">Protocol::TrimFlight</a>
비행 Trim을 조정할 때 사용합니다.
```cpp
namespace Protocol
{
    struct TrimFlight
    {
        s16          roll;         // Roll
        s16          pitch;        // Pitch
        s16          yaw;          // Yaw
        s16          throttle;     // Throttle
    };
}
```

<br>
<br>

## <a name="TrimDrive">Protocol::TrimDrive</a>
자동차 Trim을 조정할 때 사용합니다.
```cpp
namespace Protocol
{
    struct TrimDrive
    {
        s16          wheel;         // Wheel
    };
}
```

<br>
<br>

## <a name="TrimAll">Protocol::TrimAll</a>
비행 및 자동차 Trim을 한 번에 조정할 때 사용합니다.
```cpp
namespace Protocol
{
    struct TrimAll
    {
        TrimFlight   flight;
        TrimDrive    drive;
    };
}
```
- flight : [Protocol::TrimFlight](#TrimFlight)
- drive : [Protocol::TrimDrive](#TrimDrive)

<br>
<br>

## <a name="CountFlight">Protocol::CountFlight</a>
비행과 관련된 저장값을 읽을 때 사용합니다.
```cpp
namespace Protocol
{
    struct CountFlight
    {
        u64 timeFlight;             // 비행 시간
        
        u16 countTakeOff;           // 이륙 횟수
        u16 countLanding;           // 착륙 횟수
        u16 countAccident;          // 충돌 횟수
    };
}
```

<br>
<br>

## <a name="CountDrive">Protocol::CountDrive</a>
주행과 관련된 저장값을 읽을 때 사용합니다.
```cpp
namespace Protocol
{
    struct CountDrive
    {
        u64 timeDrive;              // 주행 시간
        
        u16 countAccident;          // 충돌 횟수
    };
}
```
countAccident 변수는 주행 중 충돌을 카운트 하기 위해 만든 변수이나 실제 주행 시 노면이 고르지 못할 때의 충격에 의해서도 카운트가 증가하는 문제가 있습니다. 현재로는 크게 의미가 없는 값으로 생각하시면 됩니다.

<br>
<br>

## <a name="IrMessage">Protocol::IrMessage</a>
IR 데이터를 전송하는데 사용하거나, PETRONE이 IR 데이터를 수신 받았을 때 외부 장치로 전송하는 데이터입니다.
```cpp
namespace Protocol
{
    struct IrMessage
    {
        u8  direction;               // 수신 받은 방향
        u32 irData;                  // IR 메세지
    };
}
```
- direction : [System::Direction::Type](definitions.md#Direction)

<br>
<br>

## <a name="ImuRawAndAngle">Protocol::ImuRawAndAngle</a>
자이로 센서에서 출력한 값과 내부에서 계산한 드론의 자세 값을 반환합니다.
```cpp
namespace Protocol
{
    struct ImuRawAndAngle
    {
        s16     accX;
        s16     accY;
        s16     accZ;
        s16     gyroRoll;
        s16     gyroPitch;
        s16     gyroYaw;
        s16     angleRoll;
        s16     anglePitch;
        s16     angleYaw;
    };
}
```

<br>
<br>

## <a name="Pressure">Protocol::Pressure</a>
압력 센서의 출력값을 반환합니다. d1과 d2는 MS5607에서만 출력하는 값으로 DPS310이 사용된 기체에서는 0으로 출력됩니다.
```cpp
namespace Protocol
{
    struct Pressure
    {
        s32		d1;
        s32		d2;
        s32		temperature;
        s32		pressure;
    };
}
```

<br>
<br>

## <a name="ImageFlow">Protocol::ImageFlow</a>
자세 제어에 사용하는 영상 데이터 처리 값입니다.
```cpp
namespace Protocol
{
    struct ImageFlow
    {
        s32		fVelocitySumX;
        s32		fVelocitySumY;
    };
}
```

<br>
<br>

## <a name="Button">Protocol::Button</a>
버튼 입력 값입니다.
```cpp
namespace Protocol
{
    struct Button
    {
        u8      button;
    };
}
```

<br>
<br>

## <a name="Motor">Protocol::Motor</a>
모터를 동작시키거나, 현재 모터에 입력된 값을 확인할 때 사용합니다.
```cpp
namespace Protocol
{
    struct Motor
    {
        MotorBase motor[4];
    };
}
```
- motor : [Protocol::MotorBase::Type](base_structs.md#MotorBase)


<br>

---
[Home](../../README.md)