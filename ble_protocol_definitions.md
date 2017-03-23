***PETRONE / BLE / Protocol / Definitions***<br>
Modified : 2017.03.23

---

#### Petrone에서 사용하고 있는 정의들을 소개합니다.

---

## <a name="CommandType">Protocol::CommandType::Type</a>
CommandBase 구조체에서 commandType 변수에 사용합니다.

```cpp
namespace Protocol
{
    namespace CommandType
    {
        enum Type
        {
            None = 0,                       ///< 이벤트 없음
            
            // 설정
            ModePetrone = 0x10,             ///< 페트론 동작 모드 전환
            
            // 제어
            Coordinate = 0x20,              ///< 방위 기준 변경
            Trim,                           ///< 트림 변경
            FlightEvent,                    ///< 비행 이벤트 실행
            DriveEvent,                     ///< 주행 이벤트 실행
            Stop,                           ///< 정지
            
            ResetHeading = 0x50,            ///< 방향을 리셋(앱솔루트 모드 일 때 현재 heading을 0도로 변경)
            ClearGyroBiasAndTrim,           ///< 자이로 바이어스와 트림 설정 초기화
            ClearTrim,                      ///< 트림 초기화
            
            // 통신[Bluetooth]
            PairingActivate = 0x80,         ///< 페어링 활성화
            PairingDeactivate,              ///< 페어링 비활성화
            AdvertisingStart,               ///< 장치를 검색 가능한 상태로 변경
            AdvertisingStop,                ///< 장치를 검색 불가능한 상태로 변경
            TerminateConnection,            ///< 연결 종료
            ClearBondList,                  ///< 본딩된 장치 리스트 제거
            
            // 요청
            Request = 0x90,                 ///< 지정한 타입의 데이터 요청
            
            EndOfType
        };
    }
}
```


## <a name="LightMode">Light::Mode::Type</a>
LED 모드 또는 이벤트 명령 시 동작 모드를 지정할 때 사용합니다.

```cpp
namespace Light
{
    namespace Mode
    {
        enum Type
        {
            None,
            
            EyeNone = 0x10,
            EyeHold,            // 지정한 색상을 계속 켬
            EyeMix,             // 순차적으로 LED 색 변경
            EyeFlicker,         // 깜빡임         
            EyeFlickerDouble,   // 깜빡임(두 번 깜빡이고 깜빡인 시간만큼 꺼짐)
            EyeDimming,         // 밝기 제어하여 천천히 깜빡임
            
            ArmNone = 0x40,     
            ArmHold,            // 지정한 색상을 계속 켬
            ArmMix,             // 순차적으로 LED 색 변경
            ArmFlicker,         // 깜빡임         
            ArmFlickerDouble,   // 깜빡임(두 번 깜빡이고 깜빡인 시간만큼 꺼짐)
            ArmDimming,         // 밝기 제어하여 천천히 깜빡임
            ArmFlow,            // 앞에서 뒤로 흐름           
            ArmFlowReverse,     // 뒤에서 앞으로 흐름 
            
            EndOfType
        };
    }
}
```


---
[Home](README.md)

