***PETRONE / LINK / Protocol / Definitions***<br>
Modified : 2017.03.27

---

#### Petrone에서 사용하고 있는 기본 정의들을 소개합니다.

---

<br>

## <a name="CommandType">Protocol::CommandType::Type</a>
CommandBase 구조체에서 commandType 변수에 사용합니다.

```cpp
namespace Protocol
{
    namespace CommandType
    {
        enum Type
        {
            None = 0,               // 이벤트 없음
            
            // 설정
            ModeVehicle = 0x10,     // 동작 모드 전환
            
            // 제어
            Coordinate = 0x20,      // 방위 기준 변경
            Trim,                   // 트림 변경
            FlightEvent,            // 비행 이벤트 실행
            DriveEvent,             // 주행 이벤트 실행
            Stop,                   // 정지
            
            ResetHeading = 0x50,    // 방향 초기화
            ClearGyroBiasAndTrim,   // 자이로 바이어스와 트림 설정 초기화
            ClearTrim,              // 트림 초기화
            
            // 요청
            Request = 0x90,         // 지정한 타입의 데이터 요청
            
            EndOfType
        };
    }
}
```

<br>

---
[Home](../../../README.md)

